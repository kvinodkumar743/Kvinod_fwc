from itertools import product

def logic_function(a, b, c, d):
    # Define MUX inputs
    I0 = c
    I1 = int(not d)
    I2 = c & d
    I3 = 0

    # Select based on A and B
    sel = (a << 1) | b
    inputs = [I0, I1, I2, I3]

    return inputs[sel]

# Generate the minterms
minterms = []
print("A B C D | Output")
for a, b, c, d in product([0,1], repeat=4):
    output = logic_function(a, b, c, d)
    print(f"{a} {b} {c} {d} |   {output}")
    if output == 1:
        index = (a << 3) | (b << 2) | (c << 1) | d
        minterms.append(index)

print("\nMinterms where output is 1:")
print("F = Σm(", ', '.join(map(str, sorted(minterms))), ")")
