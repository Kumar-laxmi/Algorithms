#Approach and Explanation

# 1. The function `power_set` takes a set `s` as input.

# 2. The set `s` is converted into a list using `list(s)`. This is done to make the set subscriptable, as sets do not support indexing.

# 3. The length of the set is obtained using `n = len(s)`. This will be used in the subsequent steps.

# 4. An empty list `power_set` is initialized to store the subsets of the input set `s`.

# 5. The outer loop iterates from `0` to `2^n - 1`. This corresponds to generating all possible binary numbers of length `n`. Each binary number represents a possible subset of the set `s`.

# 6. Within the outer loop, an empty list `subset` is initialized to store the elements of the current subset being constructed.

# 7. The inner loop iterates from `0` to `n - 1`, representing the positions of the bits in the binary number.

# 8. For each position `j`, `(i >> j) & 1` is used to check whether the j-th bit of the binary number `i` is set to `1`. If it is, it means that the corresponding element from the original set `s` should be included in the subset.

# 9. If the j-th bit is set to `1`, the element `s[j]` is appended to the `subset` list.

# 10. After the inner loop completes, the `subset` list represents a valid subset of the set `s`.

# 11. The `subset` list is appended to the `power_set` list, representing one of the subsets of the original set `s`.

# 12. Once all possible subsets have been generated, the `power_set` list is returned as the final result.


# Source Code:

def power_set(s):
    # Convert the set into a list
    s = list(s)

    # Get the length of the set
    n = len(s)

    # Initialize an empty list to store the power set
    power_set = []

    # Generate all possible binary numbers from 0 to 2^n - 1
    for i in range(2**n):
        # Initialize an empty subset
        subset = []

        # Check each bit of the binary number
        for j in range(n):
            # If the j-th bit of i is 1, add the j-th element of the set to the subset
            if (i >> j) & 1:
                subset.append(s[j])

        # Add the subset to the power set
        power_set.append(subset)

    return power_set


# Example usage
my_set = {1, 2, 3}
result = power_set(my_set)
for subset in result:
    print(subset)
