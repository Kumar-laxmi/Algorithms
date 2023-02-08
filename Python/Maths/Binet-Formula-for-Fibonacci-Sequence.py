
# The choice of using the Binet formula, iteration, or recursion to calculate Fibonacci numbers depends on various factors 
# such as the size of the input, the required accuracy, and the computational resources available.
#    * Binet formula: It is useful when the value of n is large and you need to calculate the nth Fibonacci number quickly and accurately.
#                     However, this method is not recommended for small values of n because it can be computationally expensive and may not
#                     be accurate for small values of n due to limitations of floating-point precision.
#    * Iteration: Iterative methods, such as the simple iterative method, are useful when the value of n is small to medium-sized and you need
#                 to calculate the nth Fibonacci number quickly. This method is simple and easy to implement, but it can become slow for larger
#                 values of n.
#    * Recursion: Recursive methods are useful when you need to calculate multiple Fibonacci numbers in sequence and the size of the input
#                is not known in advance. Recursive methods can be more memory-efficient than iterative methods, but they can also be slower
#                for large values of n because of the overhead of multiple function calls.
# Note : It is important to note that the performance of each method can also depend on the specific implementation and the computer resources available.
# It's always good to have a general understanding of different methods and choose the best one based on the specific requirements of the application.
# for reference visit : https://www.geeksforgeeks.org/advanced-c-boost-library/

# Python code to calculate fibonacci numbers using different methods
import math

# Fibonacci number calculation using Binet formula
def binet_formula_fib(n):
    phi = (1 + math.sqrt(5)) / 2
    return int((pow(phi, n) - pow(-phi, -n)) / math.sqrt(5))

# Fibonacci number calculation using simple iterative method
def iterative_fib(n):
    a, b = 0, 1
    for i in range(2, n+1):
        c = a + b
        a, b = b, c
    return b if n > 0 else a

# Fibonacci number calculation using recursion
def recursive_fib(n):
    if n <= 1:
        return n
    else:
        return recursive_fib(n-1) + recursive_fib(n-2)

# Main function
if __name__ == "__main__":
    n = int(input("Enter the value of n: "))
    print("Fibonacci number using Binet formula:", binet_formula_fib(n))
    print("Fibonacci number using Iterative method:", iterative_fib(n))
    print("Fibonacci number using Recursion:", recursive_fib(n))
