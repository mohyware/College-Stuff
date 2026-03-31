import os
import sys
import json
import time
import random
import socket
import threading

# Configuration
NODE_ID = int(os.environ.get('NODE_ID', 1))
PORT = int(os.environ.get('PORT', 10030))
PEERS_ENV = os.environ.get('PEERS', '')

# Parse PEERS format: host:port,host:port,...
PEERS = []
if PEERS_ENV:
    for p in PEERS_ENV.split(','):
        host, port = p.split(':')
        PEERS.append((host, int(port)))

# Paxos State Guard
lock = threading.Lock()

# Persistent Acceptor State
promised_id = [0, 0]  # [sequence_number, node_id]
accepted_id = [0, 0]
accepted_value = None

# Proposer state
SEQUENCE_NUMBER = 0 # To generate unique IDs
promises_received = [] # List of tuples: (accepted_id, accepted_val)

# Learner state
# tracks number of ACCEPTED messages per proposal tuple -> set of node_ids
learner_tracker = {}
consensus_reached = False

# UDP Socket setup
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# We bind to 0.0.0.0 because in Docker, container internal IP differs from localhost
sock.bind(('0.0.0.0', PORT))

def send_msg(peer, msg):
    """Sends a JSON encoded message to a peer (host, port) tuple"""
    try:
        sock.sendto(json.dumps(msg).encode('utf-8'), peer)
    except Exception as e:
        print(f"[{NODE_ID}] Error sending msg to {peer}: {e}", file=sys.stderr)

def broadcast(msg):
    """Broadcasts a message to all peers (including self)"""
    for peer in PEERS:
        send_msg(peer, msg)

def is_greater(a, b):
    """Compare two proposal IDs in the format [seq, node_id]"""
    if a[0] > b[0]: return True
    if a[0] == b[0] and a[1] > b[1]: return True
    return False

def is_greater_or_equal(a, b):
    """Compare two proposal IDs for >= in the format [seq, node_id]"""
    if a[0] > b[0]: return True
    if a[0] == b[0] and a[1] >= b[1]: return True
    return False

def proposer_thread():
    global SEQUENCE_NUMBER, promised_id, accepted_id, accepted_value, promises_received, consensus_reached
    
    # 1. Random delay (1 to 30 seconds) to simulate network latency & race
    delay = random.uniform(1.0, 30.0)
    print(f"[{NODE_ID}] Started. Delaying for {delay:.2f} seconds before prioritizing as Proposer.")
    time.sleep(delay)
    
    if consensus_reached:
        return
        
    print(f"[{NODE_ID}] Woke up as Proposer. Initiating Paxos Phase 1.")
    
    while not consensus_reached:
        with lock:
            if consensus_reached: break
            SEQUENCE_NUMBER += 1
            proposal_id = [SEQUENCE_NUMBER, NODE_ID]
            promises_received = []
            
        print(f"[{NODE_ID}] [Phase 1] Sending PREPARE with ID {proposal_id}")
        msg = {
            'type': 'PREPARE',
            'proposal_id': proposal_id,
            'sender_id': NODE_ID
        }
        broadcast(msg)
        
        # Wait a bit for promises to gather
        time.sleep(3.0)
        
        with lock:
            if consensus_reached: break
            
            # Quorum requires majority (3 out of 5)
            if len(promises_received) >= 3:
                print(f"[{NODE_ID}] [Phase 2] Received {len(promises_received)} PROMISES. Proceeding to ACCEPT.")
                
                # Pick the value with the highest accepted_id returned in promises. If none, pick a new random [1-10]
                max_acc_id = [0, 0]
                val_to_propose = random.randint(1, 10) 
                
                for acc_id, acc_val in promises_received:
                    if acc_val is not None:
                        if is_greater(acc_id, max_acc_id):
                            max_acc_id = acc_id
                            val_to_propose = acc_val
                
                print(f"[{NODE_ID}] [Phase 2] Sending ACCEPT_REQUEST with value {val_to_propose} for ID {proposal_id}")
                accept_msg = {
                    'type': 'ACCEPT_REQUEST',
                    'proposal_id': proposal_id,
                    'value': val_to_propose,
                    'sender_id': NODE_ID
                }
                broadcast(accept_msg)
            else:
                print(f"[{NODE_ID}] Proposer failed to get quorum (only {len(promises_received)} promises). Retrying...")
                
        # Wait before retrying (if consensus not reached)
        time.sleep(random.uniform(3.0, 6.0))

def server_loop():
    global promised_id, accepted_id, accepted_value, promises_received, consensus_reached
    while not consensus_reached:
        try:
            sock.settimeout(1.0)
            data, addr = sock.recvfrom(4096)
        except socket.timeout:
            continue
        except Exception as e:
            if consensus_reached: break
            print(f"[{NODE_ID}] Socket error: {e}", file=sys.stderr)
            continue
            
        try:
            msg = json.loads(data.decode('utf-8'))
        except:
            continue
            
        with lock:
            if consensus_reached:
                break
                
            m_type = msg.get('type')
            prop_id = msg.get('proposal_id') # [seq, id]
            sender_id = msg.get('sender_id')
            
            # Learner logic needs to execute regardless of Phase 1/2 success
            if m_type == 'ACCEPTED':
                val = msg.get('value')
                # Dictionary key must be hashable, convert list to tuple
                key = (tuple(prop_id), val)
                if key not in learner_tracker:
                    learner_tracker[key] = set()
                learner_tracker[key].add(sender_id)
                
                if len(learner_tracker[key]) >= 3 and not consensus_reached:
                    consensus_reached = True
                    print("\n" + "="*50)
                    print(f"[{NODE_ID}] Consensus reached: Executing Function {val}")
                    print("="*50 + "\n")
                    break
                    
            elif m_type == 'PREPARE':
                # Acceptor Phase 1 Response
                if is_greater(prop_id, promised_id):
                    promised_id = prop_id
                    print(f"[{NODE_ID}] [Acceptor] Promised to ID {prop_id}")
                    
                    reply = {
                        'type': 'PROMISE',
                        'proposal_id': prop_id,
                        'accepted_id': accepted_id,
                        'accepted_value': accepted_value,
                        'sender_id': NODE_ID
                    }
                    
                    # Send response directly to the proposer
                    # Find peer corresponding to sender_id
                    proposer_peer = next((p for p in PEERS if p[0] == f"p{sender_id}"), None)
                    if proposer_peer:
                        send_msg(proposer_peer, reply)
                    else:
                        # Fallback to broadcast if we can't cleanly map it
                        broadcast(reply)
            
            elif m_type == 'PROMISE':
                # Proposer Phase 1 Receiving
                # We only care if we are currently proposing this exact ID
                if prop_id == [SEQUENCE_NUMBER, NODE_ID]:
                    acc_id = msg.get('accepted_id')
                    acc_val = msg.get('accepted_value')
                    promises_received.append((acc_id, acc_val))
                    
            elif m_type == 'ACCEPT_REQUEST':
                # Acceptor Phase 2 Response
                val = msg.get('value')
                if is_greater_or_equal(prop_id, promised_id):
                    promised_id = prop_id
                    accepted_id = prop_id
                    accepted_value = val
                    print(f"[{NODE_ID}] [Acceptor] Accepted value {val} for ID {prop_id}")
                    
                    # Notify Learners by broadcasting the ACCEPTED msg to all nodes
                    accept_msg = {
                        'type': 'ACCEPTED',
                        'proposal_id': prop_id,
                        'value': val,
                        'sender_id': NODE_ID
                    }
                    broadcast(accept_msg)

if __name__ == '__main__':
    print(f"[{NODE_ID}] Starting Node on port {PORT}")
    proposer = threading.Thread(target=proposer_thread, daemon=True)
    proposer.start()
    
    server_loop()
    
    print(f"[{NODE_ID}] Node execution finished. Idling gracefully.")
    # Allow container to idle to fulfill project requirement ("idling showing the same final value")
    while True:
        time.sleep(60)
