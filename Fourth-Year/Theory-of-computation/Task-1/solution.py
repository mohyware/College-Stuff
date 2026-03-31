transitions = {
    'q0': {'0': 'q0', '1': 'q1'},
    'q1': {'0': 'q2', '1': 'q1'},
    'q2': {'0': 'q0', '1': 'q1'},
}

initial_state = 'q0'
final_states = {'q2'}

input_string = input("Enter input string (0s and 1s): ")

current_state = initial_state
for symbol in input_string:
    if symbol not in ('0', '1'):
        print("Rejected (invalid symbol)")
        exit()
    current_state = transitions[current_state][symbol]

if current_state in final_states:
    print("Accepted")
else:
    print("Rejected")
