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
import java.math.BigInteger;
import java.util.Scanner;

public class BinetFormula {

    // Fibonacci number calculation using Binet formula
    static BigInteger binet_formula_fib(int n)
    {
        double phi = (1 + Math.sqrt(5)) / 2;
        return BigInteger.valueOf((long) ((Math.pow(phi, n) - Math.pow(-phi, -n)) / Math.sqrt(5)));
    }

    // Fibonacci number calculation using simple iterative method
    static BigInteger iterative_fib(int n)
    {
        BigInteger a = BigInteger.valueOf(0);
        BigInteger b = BigInteger.valueOf(1);
        BigInteger c;
        for (int i = 2; i <= n; i++)
        {
            c = a.add(b);
            a = b;
            b = c;
        }
        return n == 0 ? BigInteger.valueOf(0) : b;
    }

    // Fibonacci number calculation using recursion
    static BigInteger recursive_fib(int n)
    {
        if (n <= 1)
        {
            return BigInteger.valueOf(n);
        }
        else
        {
            return recursive_fib(n - 1).add(recursive_fib(n - 2));
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the value of n:");
        int n = scan.nextInt();
        System.out.println("Fibonacci number using Binet formula: " + binet_formula_fib(n));
        System.out.println("Fibonacci number using Iterative method: " + iterative_fib(n));
        System.out.println("Fibonacci number using Recursion: " + recursive_fib(n));
        scan.close();
    }
}
