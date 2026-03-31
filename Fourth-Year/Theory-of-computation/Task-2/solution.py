transitions = {
    'q0': {'a': {'q0', 'q1'}, 'b': {'q0'}},
    'q1': {'b': {'q1', 'q2'}},
    'q2': {},
}

initial_state = 'q0'
final_states = {'q2'}

input_string = input("Enter input string (a's and b's): ")

current_states = {initial_state}
for symbol in input_string:
    if symbol not in ('a', 'b'):
        print("Rejected (invalid symbol)")
        exit()
    next_states = set()
    for state in current_states:
        next_states |= transitions[state].get(symbol, set())
    current_states = next_states

if current_states & final_states:
    print("Accepted")
else:
    print("Rejected")
