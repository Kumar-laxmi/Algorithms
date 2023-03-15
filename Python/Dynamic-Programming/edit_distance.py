#!/usr/bin/env python

"""Edit-distance problem - Dynamic Programming solution

This script demonstrates a dynamic programming approach to solve the edit-distance
problem, which counts the minimum number of operations in the form of insertion, 
removal, or replacement of characters to convert one string to another.
User enters two strings through standard input, the base string and the target string. 
The minimum number of edits required is printed to standard output.

Time complexity: O(m * n)
Space complexity: O(m * n)

where,
    m = length of first string
    n = length of second string

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""


def count_operations(first_string: str, second_string: str) -> int:
    """Calculates the number of operations/edits required to convert first_string
    to second_string through insertion, removal or replacement of characters.
    Dynamic programming approach: table/matrix of dimensions m+1 x n+1 is initialized,
    where, m = length of first_string and n = length of second_string. The cells of
    the table denote sub-problems which represent conversion of a sub-string of the
    first_string to a sub-string of the second_string. Bottom-right cell of the table
    represents our target problem.

    Args:
        first_string (str): Base string to be converted
        second_string (str): Target string

    Returns:
        int: Number of operations/edits required to convert first_string to second_string.
    """
    m = len(first_string)
    n = len(second_string)
    dp_table = [[0 for j in range(n + 1)] for i in range(m + 1)]  # m+1 x n+1 matrix

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:  # first_string is empty
                # no. of insertions required = length of second string
                dp_table[i][j] = j

            elif j == 0:  # second_string empty
                # no. of insertions required = length of first string
                dp_table[i][j] = i

            elif first_string[i - 1] == second_string[j - 1]:  # last characters same
                # no operations required
                dp_table[i][j] = dp_table[i - 1][j - 1]

            else:  # operation required to make changes
                dp_table[i][j] = 1 + min(
                    dp_table[i][j - 1],  # insert
                    dp_table[i - 1][j],  # delete
                    dp_table[i - 1][j - 1],  # replace
                )

    return dp_table[m][n]


def edit_distance() -> None:
    """Accepts two strings as input and prints the number of edits required
    to convert the first string to the second string. Edits can be in the form
    of insertion, removal or replacement of characters, one at a time.
    """
    first_string = input("Enter first string: ").strip().lower()
    second_string = input("Enter second string: ").strip().lower()
    num_edits = count_operations(first_string, second_string)
    print(f"\nNumber of edits required = {num_edits}")


if __name__ == "__main__":
    edit_distance()
