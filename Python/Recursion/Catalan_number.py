"""
Author: K.om Senapati
Github username: KOMNOOB

Problem Statement: Catalan Number

Problem Description:
The Catalan numbers form a sequence of natural numbers that occur in various counting problems, often involving recursive structures.
Given an integer n, your task is to find the nth Catalan number using recursion.

Write a function catalan(n) that takes in an integer n and returns the nth Catalan number.

Input:
An integer n representing the position of the Catalan number to be found. (0 <= n <= 30)
Output:
An integer representing the nth Catalan number.
"""


def catalan(n: int) -> int:
    if n <= 1:
        return 1

    res = 0
    for i in range(n):
        res += catalan(i) * catalan(n - i - 1)

    return res


if __name__ == "__main__":
    n = int(input("Enter the n value : "))
    print(f"Catalan({n}) = {catalan(n)}")
