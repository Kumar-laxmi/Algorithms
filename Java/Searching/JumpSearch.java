// Java implementation of Jump Search Algorithm
import java.util.*;

public class JumpSearch {
    public static int jumpSearch(int[] array, int size, int key) {
        int start = 0;
        int end = (int)Math.sqrt(size); // the square root of array length

        while (array[end] <= key && end < size) {
            start = end; // if it is not the correct block then shift block
            end += (int)Math.sqrt(size);
            if (end > size - 1) {
                end = size; // if right exceeds then bound the range
            }
        }

        // perform linear search in selected block
        for (int i = start; i < end; i++) {
            if (array[i] == key) {
                return i; // the correct position of the key
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //taking input of number of elements and key
        int n = sc.nextInt();
        int key = sc.nextInt();
        int[] arr = new int[n]; // create an array of size n

        // taking input of array elements
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // function call
        int ind = jumpSearch(arr, n, key);

        if (ind >= 0) { // key is present in the array
            System.out.println("Key found at location: " + ind);
        }
        else { // key is not present in the array
            System.out.println("Key not found in the array");
        }

        sc.close();
    }
}
