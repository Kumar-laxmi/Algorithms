/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Each number in the triangle is the sum of the two numbers directly above it.

we take number of rows as input
And we know that to find any element at particular position (i.e at ith row and cth column) we can use the combination formula nCr.
  nCr=factorial(n)/(factorial(r)*factorial(n-r))
*/
import java.util.Scanner;

public class Pascal_Triangle {
    public static long factorial(int n) {
        long result = 1;
        for (int c = 1; c <= n; c++) {
            result *= c;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of rows you wish to see in Pascal's Triangle:");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= (n - i - 2); c++) {
                System.out.print(" ");
            }

            for (int c = 0; c <= i; c++) {
                long coeff = factorial(i) / (factorial(c) * factorial(i - c));
                System.out.print(coeff + " ");
            }

            System.out.println();
        }
        scanner.close();
    }
}
