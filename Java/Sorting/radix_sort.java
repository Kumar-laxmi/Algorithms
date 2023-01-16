import java.util.Arrays;
import java.util.Scanner;

public class radix_sort {
    public static void main(String[] args) {
        // import scanner to take user input
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the size of the array");
        int size = sc.nextInt();
        System.out.println("enter the element in the array");
        int[] arr = new int[size];
        // store the inputed elements in the array
        for(int i = 0; i<size; i++) {
            arr[i] = sc.nextInt();
        }
        // call our sorting function
        radixSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    public static void radixSort(int[] arr) {
        // search for the maximum number to know the number of digits
        int max = getMax(arr);
        // do counting sort here
        for (int exp = 1; max/exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }
    
    public static void countingSort(int[] arr, int exp) { // sort the array by each digit starting with the least significant digit in the array
        int[] output = new int[arr.length]; // the final array in which we will store our answer
        int[] count = new int[10]; // the counting array

        // store all the counting occourences in count array
        for (int i = 0; i < arr.length; i++) {
            count[(arr[i]/exp)%10]++;
        }

        // change our element at count[i] to count[i-1] so that this contains actual position of the digit in output array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // create our output array
        for (int i = arr.length - 1; i >= 0; i--) {
            output[count[(arr[i]/exp)%10] - 1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }

        // store the output array in our ans array, so that numbers that are sorted now can be stored
        for (int i = 0; i < arr.length; i++) {
            arr[i] = output[i];
        }
    }

    // normal function to find the max value in our array
    public static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}
