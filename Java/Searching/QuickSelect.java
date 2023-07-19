// Path: Java\Searching\QuickSelect.java
// Java program to kth smallest element using quickSelect Algorithm.
// Time-Complexity: O(N^2), where N is the size of array.

import java.util.Random;

public class QuickSelect {

    // Function to swap two elements in the array
    private static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    // Partition function to rearrange elements around the pivot
    private static int partition(int[] arr, int left, int right, int pivotIndex) {
        int pivotValue = arr[pivotIndex];
        swap(arr, pivotIndex, right); // Move pivot to the end
        int storeIndex = left;

        for (int i = left; i < right; i++) {
            if (arr[i] < pivotValue) {
                swap(arr, i, storeIndex);
                storeIndex++;
            }
        }
        swap(arr, storeIndex, right); // Move pivot to its final place
        return storeIndex;
    }

    // Quickselect function
    private static int quickSelect(int[] arr, int left, int right, int k) {
        if (left == right)
            return arr[left];

        int pivotIndex = left + new Random().nextInt(right - left + 1);
        pivotIndex = partition(arr, left, right, pivotIndex);

        if (k == pivotIndex)
            return arr[k];
        else if (k < pivotIndex)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }

    public static void main(String[] args) {
        int[] arr = {3, 8, 2, 5, 1, 4, 7, 6};
        int k = 4; // Find the 4th smallest element

        int result = quickSelect(arr, 0, arr.length - 1, k - 1);
        System.out.println("The " + k + "-th smallest element is: " + result);
    }
}
