from itertools import product as iproduct

# ───────────────────────────────────────────────────────────────
# Membership checkers
# ───────────────────────────────────────────────────────────────

def is_in_L1(s):
    """L1 = {0^n 1^m 0^(nm) : n,m >= 0}"""
    i = 0
    while i < len(s) and s[i] == '0': i += 1
    n = i
    while i < len(s) and s[i] == '1': i += 1
    m = i - n
    while i < len(s) and s[i] == '0': i += 1
    nm = i - n - m
    return i == len(s) and nm == n * m

def is_in_L2(s):
    """L2 = {0^n 1^m : n < 3m}"""
    i = 0
    while i < len(s) and s[i] == '0': i += 1
    n = i
    while i < len(s) and s[i] == '1': i += 1
    m = i - n
    return i == len(s) and n < 3 * m

def run_dfa_L3(s):
    """DFA for 1*01*01*. Returns True if accepted."""
    # q0: no 0 seen | q1: one 0 seen | q2: two 0s seen (accept) | q3: dead
    transitions = {
        0: {'0': 1, '1': 0},
        1: {'0': 2, '1': 1},
        2: {'0': 3, '1': 2},
        3: {'0': 3, '1': 3},
    }
    state = 0
    for c in s:
        if c not in transitions[state]:
            return False
        state = transitions[state][c]
    return state == 2

def can_pump(s, p, in_L):
    """Return (True, (x,y,z)) if s can be pumped under pumping length p, else (False, None)."""
    for xy_len in range(1, min(p, len(s)) + 1):
        for x_len in range(0, xy_len):
            x = s[:x_len]
            y = s[x_len:xy_len]
            z = s[xy_len:]
            if not y:
                continue
            if all(in_L(x + y * i + z) for i in range(0, 12)):
                return True, (x, y, z)
    return False, None

# ───────────────────────────────────────────────────────────────
# Q1: Prove L = {0^n 1^m 0^(nm) | n,m >= 0} is NOT regular
# ───────────────────────────────────────────────────────────────

print("=" * 65)
print("Q1: Prove L = {0^n 1^m 0^(nm) | n,m ≥ 0} is NOT regular")
print("=" * 65)
print("""
Proof by contradiction using the Pumping Lemma:

  Assume L is regular with pumping length p.

  Choose: s = 0^p 1^p 0^(p²)
    · |s| = p + p + p² ≥ p  ✓
    · s ∈ L  with n=p, m=p, nm=p²  ✓

  By the pumping lemma ∃ x,y,z  with  s = xyz,  |xy| ≤ p,  |y| ≥ 1,
  and  xy^i z ∈ L  for all  i ≥ 0.

  Since |xy| ≤ p, the substring xy lies entirely inside the
  leading 0^p block  ⟹  y = 0^k  for some  1 ≤ k ≤ p.

  Pump with i = 2:
    xy²z  =  0^(p+k) 1^p 0^(p²)

  For xy²z ∈ L we would need  (p+k)·p = p²:
    p² + kp = p²  ⟹  kp = 0
  But k ≥ 1 and p ≥ 1  ⟹  kp ≥ 1.  ✗ Contradiction!

  ∴ L is NOT regular.  □
""")

p = 5
s = '0'*p + '1'*p + '0'*(p*p)
k = 1
s_pumped = '0'*(p+k) + '1'*p + '0'*(p*p)
print(f"Concrete example (p={p}, k={k}):")
print(f"  s     = 0^{p} 1^{p} 0^{p*p}   → in L? {is_in_L1(s)}")
print(f"  xy²z  = 0^{p+k} 1^{p} 0^{p*p}  → in L? {is_in_L1(s_pumped)}  ✗")

# ───────────────────────────────────────────────────────────────
# Q2: Prove L = {0^n 1^m | n < 3m} is NOT regular
# ───────────────────────────────────────────────────────────────

print("\n" + "=" * 65)
print("Q2: Prove L = {0^n 1^m | n < 3m} is NOT regular")
print("=" * 65)
print("""
Proof by contradiction using the Pumping Lemma:

  Assume L is regular with pumping length p.

  Choose: s = 0^(3p−1) 1^p
    · |s| = 4p − 1 ≥ p  ✓
    · n = 3p−1 < 3p = 3m  ⟹  s ∈ L  ✓

  By the pumping lemma ∃ x,y,z  with  s = xyz,  |xy| ≤ p,  |y| ≥ 1,
  and  xy^i z ∈ L  for all  i ≥ 0.

  Since |xy| ≤ p < 3p−1, the substring xy lies entirely inside
  the leading 0^(3p−1) block  ⟹  y = 0^k  for some  1 ≤ k ≤ p.

  Pump with i = 2:
    xy²z  =  0^(3p−1+k) 1^p

  For xy²z ∈ L we would need  3p−1+k < 3p:
    k < 1
  But k ≥ 1.  ✗ Contradiction!

  ∴ L is NOT regular.  □
""")

p = 4
n_val = 3*p - 1
s = '0'*n_val + '1'*p
k = 1
s_pumped = '0'*(n_val+k) + '1'*p
print(f"Concrete example (p={p}, k={k}):")
print(f"  s     = 0^{n_val} 1^{p}   → in L?  {is_in_L2(s)}  (need {n_val} < {3*p})")
print(f"  xy²z  = 0^{n_val+k} 1^{p}  → in L?  {is_in_L2(s_pumped)}  (need {n_val+k} < {3*p})  ✗")

# ───────────────────────────────────────────────────────────────
# Q3: Minimum pumping length for 1*01*01*
# ───────────────────────────────────────────────────────────────

print("\n" + "=" * 65)
print("Q3: Minimum pumping length for  1*01*01*")
print("=" * 65)
print("""
Minimal DFA for 1*01*01*  (4 states):

  State  | on '0' | on '1' | Notes
  -------|--------|--------|--------------------------------
  →q0   |  q1    |  q0    | initial; no '0' seen yet
   q1   |  q2    |  q1    | one '0' seen
  *q2   |  q3    |  q2    | two '0's seen  (accepting)
   q3   |  q3    |  q3    | dead state (>2 zeros)
""")

# Collect all strings in L3 up to length 9
MAX = 9
L3 = [''.join(b) for n in range(MAX+1)
                 for b in iproduct('01', repeat=n)
                 if run_dfa_L3(''.join(b))]

# Find minimum pumping length
min_p = None
for p in range(1, MAX + 1):
    candidates = [s for s in L3 if len(s) >= p]
    if not candidates:
        continue
    failing = next((s for s in candidates if not can_pump(s, p, run_dfa_L3)[0]), None)
    if failing is None:       # all strings pumpable → p is sufficient
        min_p = p
        break

# Show why min_p-1 fails
prev = min_p - 1
prev_candidates = [s for s in L3 if len(s) >= prev]
failing_prev = next((s for s in prev_candidates if not can_pump(s, prev, run_dfa_L3)[0]), None)

print(f"  Searching strings in L up to length {MAX}...\n")

if failing_prev is not None:
    print(f"  p = {prev} is NOT sufficient:")
    print(f"    s = \"{failing_prev}\"  ∈ L,  |s| = {len(failing_prev)} ≥ {prev}")
    print(f"    No valid xyz decomposition works for all i ≥ 0.\n")

print(f"  p = {min_p} IS sufficient:")
print(f"    Every string in L of length ≥ {min_p} contains at least one '1'")
print(f"    within its first {min_p} characters (strings in L have exactly 2 zeros,")
print(f"    so 3 chars can't be all zeros). Choosing y = that '1' keeps any")
print(f"    pumped string in L since 1*01*01* allows any number of 1s per run.\n")

print(f"  ══> Minimum pumping length for 1*01*01*  =  {min_p}")

# Show example decompositions for all length-min_p strings in L
samples = [s for s in L3 if len(s) == min_p]
print(f"\n  Valid decompositions for all length-{min_p} strings in L:")
print(f"  {'s':<8} {'x':<6} {'y':<5} {'z':<6}  pumped strings (i=0,1,2,3)")
print(f"  {'-'*65}")
for s in samples:
    ok, decomp = can_pump(s, min_p, run_dfa_L3)
    if ok:
        x, y, z = decomp
        pumped = [x + y*i + z for i in range(4)]
        pumped_str = ',  '.join(f'"{p}"' for p in pumped)
        print(f"  {s:<8} \"{x}\"  \"{y}\"  \"{z}\"    {pumped_str}")
