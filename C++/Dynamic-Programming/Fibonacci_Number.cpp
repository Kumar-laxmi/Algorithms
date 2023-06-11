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

#include <iostream>
using std::cout, std::cin;

int fibonacci(int n)
{
    if (n <= 0)
    {
        cout << "n must be higher than 0\n";
        return -1;
    }
    else if (n == 1 || n == 2)
        return 1;

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
    cout << "Enter the n value : ";
    int n;
    cin >> n;
    int fib = fibonacci(n);
    cout << "\nThe fibonacci number at position n = " << fib;

    return 0;
}