/*
The choice of using the Binet formula, iteration, or recursion to calculate Fibonacci numbers depends on various factors 
such as the size of the input, the required accuracy, and the computational resources available.

   * Binet formula: It is useful when the value of n is large and you need to calculate the nth Fibonacci number quickly and accurately.
                    However, this method is not recommended for small values of n because it can be computationally expensive and may not
                    be accurate for small values of n due to limitations of floating-point precision.

   * Iteration: Iterative methods, such as the simple iterative method, are useful when the value of n is small to medium-sized and you need
                to calculate the nth Fibonacci number quickly. This method is simple and easy to implement, but it can become slow for larger
                values of n.

   * Recursion: Recursive methods are useful when you need to calculate multiple Fibonacci numbers in sequence and the size of the input
               is not known in advance. Recursive methods can be more memory-efficient than iterative methods, but they can also be slower
               for large values of n because of the overhead of multiple function calls.

Note : It is important to note that the performance of each method can also depend on the specific implementation and the computer resources available.
It's always good to have a general understanding of different methods and choose the best one based on the specific requirements of the application.

for reference visit : https://www.geeksforgeeks.org/advanced-c-boost-library/
*/
#include <iostream>
#include <cmath>
using namespace std;

// Fibonacci number calculation using Binet formula
long long binet_formula_fib(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (pow(phi, n) - pow(-phi, -n)) / sqrt(5);
}

// Fibonacci number calculation using simple iterative method
long long iterative_fib(int n)
{
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return n == 0 ? 0 : b;
}

// Fibonacci number calculation using recursion
long long recursive_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursive_fib(n - 1) + recursive_fib(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >>n;
    cout << "Fibonacci number using Binet formula: " << binet_formula_fib(n) << endl;
    cout << "Fibonacci number using Iterative method: " << iterative_fib(n) << endl;
    cout << "Fibonacci number using Recursion: " << recursive_fib(n) << endl;
    return 0;
}
