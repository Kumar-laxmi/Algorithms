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
