/*Recursion Implementation
Recursion is a technique where a function calls itself to solve a problem.
This definition says that the nth term of the sequence is the sum of the (n-1)th and (n-2)th terms.
The base cases are when n equals 0 or 1, in which case the function returns n.
The Fibonacci sequence can be defined recursively as follows:*/

// Fibonacci Series using Recursion

#include <iostream>
using namespace std;

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
   cout << "Enter the number of terms: ";
   cin >> n;
   cout << "Fibonacci Series: ";
   for (i = 0; i < n; i++)
      cout << fibonacci(i) << " "; // calling recursive function for each i
   return 0;
}
