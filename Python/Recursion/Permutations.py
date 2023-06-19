def permutations(p, up):
    # Base case: If the remaining characters to be permuted is empty, print the permutation
    if len(up) == 0:
        print(p)
        return

    ch = up[0]

    for i in range(len(p) + 1):
        # Split the permutation string into two parts
        f = p[:i]  # First part
        s = p[i:]  # Second part

        # Recursive call: Generate permutations by inserting the current character at each possible position
        permutations(f + ch + s, up[1:])


permutations("", "abc")