/*Recursion Implementation
Recursion is a technique where a function calls itself to solve a problem.
This definition says that the nth term of the sequence is the sum of the (n-1)th and (n-2)th terms.
The base cases are when n equals 0 or 1, in which case the function returns n.
The Fibonacci sequence can be defined recursively as follows:*/

// Fibonacci Series using Recursion

#include <stdio.h>

// Function to compute nth Fibonacci number using recursion
int fibonacci(int n) {
   // Base cases
   if (n == 0 || n == 1)
      return n;
   // Recursive case
   else
      return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
   int n, i;
   printf("Enter the number of terms: ");
   scanf("%d", &n);
   printf("Fibonacci Series: ");
   for (i = 0; i < n; i++)
      printf("%d ", fibonacci(i)); // calling recursive function for each i
   return 0;
}


/*Dynamic Programming Implementation:
Dynamic programming (DP) is a technique for solving problems by breaking them down into smaller sub-problems and solving each sub-problem only once.
The DP solution for the Fibonacci sequence uses a table to store the intermediate results so that they can be reused to compute subsequent terms.*/

// Function to compute nth Fibonacci number using dynamic programming

#include <stdio.h>

int fibonacci(int n) {
   int fib[n+1]; // Declare an array to store intermediate results
   int i;
   fib[0] = 0; // Initialize the first two terms
   fib[1] = 1;
   // Compute subsequent terms using previously computed results
   for (i = 2; i <= n; i++) {
      fib[i] = fib[i-1] + fib[i-2];
   }
   return fib[n];
}

int main() {
   int n, i;
   printf("Enter the number of terms: ");
   scanf("%d", &n);
   printf("Fibonacci Series: ");
   for (i = 0; i < n; i++)
      printf("%d ", fibonacci(i)); // calling dp function for each i
   return 0;
}