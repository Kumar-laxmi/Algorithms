import java.io.*;
import java.util.*;

class KadaneAlgo {
    // function implementing Kadane's Algorithm
    static int maxSum(int ar[], int n) {
        int maxSum = Integer.MIN_VALUE, maxSumCurrIdx = 0;
        for(int i = 0; i < n; i++) {
            maxSumCurrIdx += ar[i];
            if(maxSum < maxSumCurrIdx) maxSum = maxSumCurrIdx;
            if(maxSumCurrIdx < 0) maxSumCurrIdx = 0;
        }
        return maxSum;
    }

    public static void main(String[] args) {
        // input code
        Scanner s = new Scanner(System.in);
        System.out.print("Enter array size : ");
        int n = s.nextInt();
        int[] ar = new int[n];
        System.out.print("Enter array elements : ");
        for(int i = 0; i < n; i++) ar[i] = s.nextInt();

        // function call & output
        System.out.println("Max Sum : " + maxSum(ar, n));
    }
}