from sympy import symbols, simplify_logic
from sympy.logic.boolalg import SOPform

# Define Boolean variables
X, Y, Z = symbols('X Y Z')

# ----------- Logic Gate Functions Using def -----------
def NOT(a):
    return ~a

def AND(*args):
    result = args[0]
    for val in args[1:]:
        result = result & val
    return result

def OR(*args):
    result = args[0]
    for val in args[1:]:
        result = result | val
    return result

# ----------- Define the function using K-map minterms -----------
# Minterms: 1 (001), 2 (010), 4 (100)
minterms = [1, 2, 4]
variables = [X, Y, Z]

minimized = SOPform(variables, minterms)

# ----------- Define options using gate functions -----------
A = OR(AND(NOT(X), Y, Z), AND(X, NOT(Y), Z))
B = OR(AND(NOT(X), NOT(Y), Z), AND(X, NOT(Y), Z))
C = OR(AND(NOT(X), Y, Z), AND(Y, NOT(Z)))
D = OR(AND(X, Y), AND(NOT(Y), Z))

# ----------- Display question -----------
print("Q.52 A minimized form of the function F is:")
print("K-map Minterms (F = 1):", minterms)

# ----------- Display all options -----------
print("\nOptions:")
print("A) F =", A)
print("B) F =", B)
print("C) F =", C)
print("D) F =", D)

# ----------- Match correct option -----------
options = {'A': A, 'B': B, 'C': C, 'D': D}
for key, expr in options.items():
    if simplify_logic(minimized) == simplify_logic(expr):
        print(f"\n✅ Correct Answer: Option {key}")
