/*

=============================Problem Statement=============================
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, 
then if we assume Subset1 has m elements, 
Subset2 must have n-m elements 
the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:

Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

============================LOGIC============================
The problem can be solved using dynamic programming when the sum of the elements is not too big. 
We can create a 2D array dp[n+1][(sum/2)+1] where n is number of elements in given set and sum is sum of all elements. 
We can construct the solution in bottom up manner maximizing the sum of a partion having sum less than or equal to (sum/2).

then minimum difference between partion is (sum-2*dp[n][sum/2])


*/

import java.util.Scanner;

public class minimum_sum_partition {

    public static int minDiff(int a[], int n) {
        int sum1 = 0;                                            // sum1 stores the sum of all elements of array a
        for (int i = 0; i < n; i++) {
            sum1 += a[i];
        }

        int t1 = n + 1;
        int t2 = (sum1 / 2) + 1;
        int[][] dp = new int[t1][t2];                            // dp[i][j] stores the maximum sum of subset of a[0...i-1] such that sum of
                                                                 // subset is less than or equal to j

        for (int i = 1; i < (n + 1); i++) {
            for (int j = 1; j < t2; j++) {
                if (a[i - 1] <= j) {                             // if a[i-1] is less than or equal to j then we have two options either to
                                                                 // include a[i-1] or not
                    int x = a[i - 1] + dp[i - 1][j - a[i - 1]];
                    int y = dp[i - 1][j];
                    dp[i][j] = x > y ? x : y;                    // we choose the maximum of both options

                } else {
                    dp[i][j] = dp[i - 1][j];                     // if a[i-1] is greater than j then we have only one option that is not to
                                                                 // include a[i-1]
                }
            }
        }

        int x = (sum1 - 2 * dp[n][sum1 / 2]);                    // x stores the difference between sum of subset of a[0...n-1] and
                                                                 // sum of subset of a[0...n-1] such that sum of subset is less than or
                                                                 // equal to sum1/2

        x = x > 0 ? x : -x;                                      // if x is negative then we take -x as minimum difference is always positive

        return x;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("enter number of elements:");
        int n = sc.nextInt();
        int[] a = new int[n];

        System.out.println("Enter " + n + " elements: ");

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int b = minDiff(a, n);

        System.out.println("minimum difference between partion is " + b);

    }

}