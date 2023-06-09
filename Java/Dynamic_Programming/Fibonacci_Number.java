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

import java.util.Scanner;

public class Fibonacci_Number {
    public static int fibonacci(int n) {
        if (n <= 0) {
            System.out.println("n must be greater than 0");
            return -1;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        int[] memo = new int[n + 1];
        memo[0] = 0;
        memo[1] = 1;

        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();
        int fib = fibonacci(n);
        System.out.println("The Fibonacci number at position " + n + " is " + fib);

        scanner.close();
    }
}
