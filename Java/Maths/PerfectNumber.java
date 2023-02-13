// Java program to check if the number is an Perfect number or not

import java.util.Scanner;

public class PerfectNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int N = sc.nextInt();
        int i, sum = 0;
        for (i = 1; i < N; i++) {
            if (N % i == 0) {
                sum += i;
            }
        }
        if (sum == N) {
            System.out.print(N + " is a Perfect Number\n");
        } else {
            System.out.print(N + " is not a Perfect Number\n");
        }
    }
}


/*******************************************************
Case 1:
Enter a number: 153
153 is not a Perfect number

Case 2:
Enter a number : 496
496 is a Perfect Number
*******************************************************/
