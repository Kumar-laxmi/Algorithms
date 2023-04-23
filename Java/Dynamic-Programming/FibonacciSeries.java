import java.util.Scanner;
import java.util.Arrays;

class FibonacciSeries {
    
    static int fib(int n, int dp[]) {
        int f1 = -1, f2 = -1;
        if (n == 2) {
            System.out.print((n - 2) + " " + (n - 1) + " ");
            dp[n - 2] = (n - 2);
            dp[n - 1] = (n - 1);
            return (n - 1);
        }
        if (n == 1) {
            System.out.print((n - 1) + " ");
            dp[n - 1] = (n - 1);
            return n - 1;
        }
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] != (-1) && i == (n - 2)) {
                f1 = dp[i];
            }
            if (dp[i] != (-1) && i == (n - 3)) {
                f2 = dp[i];
            }
        }
        if (f1 == -1) {
            f1 = fib(n - 1, dp);
            dp[n - 2] = f1;
        }
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] != (-1) && i == (n - 2)) {
                f1 = dp[i];
            }
            if (dp[i] != (-1) && i == (n - 3)) {
                f2 = dp[i];
            }
        }
        System.out.print((f1 + f2) + " ");
        return (f1 + f2);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Number : ");
        int n = sc.nextInt();
        int dp[] = new int[n];
        Arrays.fill(dp, -1);
        fib(n, dp);
        sc.close();
    }
}