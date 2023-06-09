'''
Author : K.om Senapati
Github username : KOMNOOB
Problem Statement: Fibonacci Number
Problem Description
The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones. Given an integer n, your task is to find the nth Fibonacci number.

Write a function fibonacci(n) that takes in an integer n and returns the nth Fibonacci number.

Input :
An integer n representing the position of the Fibonacci number to be found. (0 <= n <= 30)
Output :
An integer representing the nth Fibonacci number.
'''
def fibonacci(n: int) -> int:
    """
    Returns nth fibonacci number
    """
    if n <= 0:
        raise Exception("n must be higher than 0")
    if n in (1,2): # Base case for handling errors
        return 1
    memo = [0] * (n+1)

    memo[0] = 0
    memo[1] = 1

    for i in range(2,n+1):
        memo[i] = memo[i-1] + memo[i-2]

    return memo[n]

if __name__ == "__main__":
    n = int(input("Enter the n value : "))
    print(f"The fibonacci number at position n = {fibonacci(n)}")