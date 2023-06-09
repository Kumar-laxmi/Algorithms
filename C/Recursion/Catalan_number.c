// Author: K.om Senapati
// Github username: KOMNOOB

// Problem Statement: Catalan Number

// Problem Description:
// The Catalan numbers form a sequence of natural numbers that occur in various counting problems, often involving recursive structures.
// Given an integer n, your task is to find the nth Catalan number using recursion.

// Write a function catalan(n) that takes in an integer n and returns the nth Catalan number.

// Input:
// An integer n representing the position of the Catalan number to be found. (0 <= n < 20)
// Output:
// An integer representing the nth Catalan number.

#include <stdio.h>

unsigned long int catalan(unsigned int n)
{
    if (n <= 1)
        return 1;

    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}

int main()
{
    int n;
    printf("Enter the n value : ");
    scanf("%d", &n);

    printf("\nCatalan(%d) = %lu", n, catalan(n));
}
