/*Recursion Implementation
Recursion is a technique where a function calls itself to solve a problem.
This definition says that the nth term of the sequence is the sum of the (n-1)th and (n-2)th terms.
The base cases are when n equals 0 or 1, in which case the function returns n.
The Fibonacci sequence can be defined recursively as follows:*/

// Fibonacci Series using Recursion

import java.util.Scanner;

public class FibonacciRecursion {
   // Function to compute nth Fibonacci number using recursion
   public static int fibonacci(int n) {
      // Base cases
      if (n == 0 || n == 1)
         return n;
      // Recursive case
      else
         return fibonacci(n-1) + fibonacci(n-2);
   }

   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter the number of terms: ");
      int n = scanner.nextInt();
      System.out.print("Fibonacci Series: ");
      for (int i = 0; i < n; i++) {
         System.out.print(fibonacci(i) + " "); // calling recursive function for each i
      }
      scanner.close();
   }
}