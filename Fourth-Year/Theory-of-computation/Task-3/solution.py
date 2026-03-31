# NFA definition
nfa_transitions = {
    'q0': {'0': {'q0', 'q1'}, '1': {'q1'}},
    'q1': {'0': set(),        '1': {'q0', 'q1'}},
}
nfa_initial = 'q0'
nfa_finals  = {'q1'}
alphabet    = ['0', '1']

def move(states, symbol):
    result = set()
    for s in states:
        result |= nfa_transitions.get(s, {}).get(symbol, set())
    return frozenset(result)

def subset_construction():
    start = frozenset({nfa_initial})
    dfa_states = [start]
    dfa_transitions = {}
    unvisited = [start]

    while unvisited:
        current = unvisited.pop()
        dfa_transitions[current] = {}
        for symbol in alphabet:
            next_state = move(current, symbol)
            dfa_transitions[current][symbol] = next_state
            if next_state not in dfa_states:
                dfa_states.append(next_state)
                unvisited.append(next_state)

    return dfa_states, dfa_transitions

def state_name(fs):
    if not fs:
        return '∅'
    return '{' + ', '.join(sorted(fs)) + '}'

def is_final(fs):
    return bool(fs & nfa_finals)

dfa_states, dfa_transitions = subset_construction()

# Print DFA Transition Table
col = 20
header = f"{'State':<{col}}" + "".join(f"{s:<{col}}" for s in alphabet)
print("DFA Transition Table")
print("-" * len(header))
print(header)
print("-" * len(header))

for state in dfa_states:
    marker = '*' if is_final(state) else ' '
    arrow  = '->' if state == frozenset({nfa_initial}) else '  '
    label  = f"{arrow}{marker}{state_name(state)}"
    row    = f"{label:<{col}}"
    for symbol in alphabet:
        row += f"{state_name(dfa_transitions[state][symbol]):<{col}}"
    print(row)

print("-" * len(header))
print("\nLegend: -> = initial state, * = final/accepting state, ∅ = dead state")
