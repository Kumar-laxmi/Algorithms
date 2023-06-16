// Author : K.om Senapati
// Github username : KOMNOOB
// Problem Statement: Fibonacci Number
// Problem Description
// The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones. Given an integer n, your task is to find the nth Fibonacci number.

// Write a function fibonacci(n) that takes in an integer n and returns the nth Fibonacci number.

// Input :
// An integer n representing the position of the Fibonacci number to be found. (0 <= n <= 30)
// Output :
// An integer representing the nth Fibonacci number.

#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 0)
    {
        printf("n must be greater than 0\n");
        return -1;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }

    int memo[n + 1];
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int result = fibonacci(n);
    printf("The Fibonacci number at position %d is %d\n", n, result);

    return 0;
}
