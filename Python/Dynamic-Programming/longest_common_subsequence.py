#!/usr/bin/env python

"""Longest Common Subsequence

This script demonstrates a dynamic programming approach to solving the longest
common subsequence (LCS) problem. A subsequence is formed by selecting characters
from a string while maintaining their relative order. 
    e.g. string: 'ABCDEFGH' -> subsequences: 'ACH', 'BDEF', 'ADFGH', 'ABCDEFGH', etc.

The user enters two strings through standard input; the longest common subsequence
between the two strings is printed to standard output.

Time complexity: O(m * n)
Space complexity: O(m * n)

where,
    m = length of first string
    n = length of second string

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""


def compute_lengths(first_string: str, second_string: str) -> list:
    """Builds a table storing lengths of longest common subsequences for
    all subproblems (i.e., pairs of substrings) with a dynamic programming
    approach. The bottom-right cell of the table stores the length for our
    target strings.

    Args:
        first_string (str): First string for computing LCS
        second_string (str): Second string for computing LCS

    Returns:
        list: m x n table storing lengths of LCS for subproblems
    """
    m, n = len(first_string), len(second_string)
    dp_table = [[0] * n] * m  # m x n matrix

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:  # length of first string is 0 (Base case 1)
                dp_table[i][j] = 0
            elif j == 0:  # length of second string is 0 (Base case 2)
                dp_table[i][j] = 0
            elif first_string[i - 1] == second_string[j - 1]:
                # when current characters are same, we increment the length
                # from the previous cell along the diagonal
                dp_table[i][j] = dp_table[i - 1][j - 1] + 1
            else:
                # when current characters are not same, we propagate the longer of
                # the lengths from previous cells to the top and left
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1])

    return dp_table


def build_lcs(first_string: str, second_string: str, dp_table: list) -> str:
    """Builds the longest common subsequence string using the computed table of
    lengths for all subproblems. String is built in reverse from bottom-right of
    the table, moving along whichever direction holds the greater length values.
    At the end the characters are reversed and concatenated to form the LCS.

    Args:
        first_string (str): First string for computing LCS
        second_string (str): Second string for computing LCS
        dp_table (list): m x n table storing lengths of LCS for subproblems

    Returns:
        str: longest common subsequence for the two strings
    """
    m, n = len(first_string), len(second_string)
    lcs = []

    i, j = m, n
    # starting from bottom-right and moving towards top-left, mirroring the
    # process of building the dp_table
    while i > 0 and j > 0:
        # if characters are same, we move diagonally top-left
        # and add the character to the LCS
        if first_string[i - 1] == second_string[j - 1]:
            lcs.append(first_string[i - 1])
            i -= 1
            j -= 1
        # if characters are not same, we move in the direction holding greater lengths
        elif dp_table[i - 1][j] > dp_table[i][j - 1]:
            i -= 1
        else:
            j -= 1
    # reversed since we started building from the last character
    lcs = "".join(reversed(lcs))
    return lcs


def lcs() -> None:
    """Accepts two strings from the user and prints the longest common subsequence
    for the two strings. Strings input by the user are converted to lowercase, thus
    ignoring mixed case characters in strings. The longest common subsequence will
    also be in lowercase.
    """
    first_string = input("\nEnter first string: ").strip().lower()
    second_string = input("Enter second string: ").strip().lower()
    dp_table = compute_lengths(first_string, second_string)
    lcs = build_lcs(first_string, second_string, dp_table)
    print(f"\nLongest common subsequence for given strings: {lcs}\n")


if __name__ == "__main__":
    lcs()
