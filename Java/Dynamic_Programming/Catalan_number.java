/* Author: K.om Senapati
Github username: KOMNOOB

Problem Statement: Catalan Number

Problem Description:
The Catalan numbers form a sequence of natural numbers that occur in various counting problems, often involving recursive structures.
Given an integer n, your task is to find the nth Catalan number using dynamic programming.

Write a function catalan(n) that takes in an integer n and returns the nth Catalan number.

Input:
An integer n representing the position of the Catalan number to be found. (0 <= n <= 30)
Output:
An integer representing the nth Catalan number. */

import java.util.Scanner;

public class Catalan_number {
    public static int catalan(int n) {
        if (n <= 1) {
            return 1;
        }

        int[] catalan = new int[n + 1];
        catalan[0] = 1;
        catalan[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        return catalan[n];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the n value: ");

        int n = scanner.nextInt();
        scanner.close();
        
        System.out.println("Catalan(" + n + ") = " + catalan(n));
    }
}

