import java.util.Arrays;
public class StoogeSort {
    // Function to swap two elements
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // Stooge Sort function
    public static void stoogeSort(int[] arr, int low, int high) {
        if (low >= high)
            return;
        // If the first element is greater than the last element, swap them
        if (arr[low] > arr[high])
            swap(arr, low, high);
        // If there are more than 2 elements in the array
        if (high - low + 1 > 2) {
            int t = (high - low + 1) / 3;
            // Sort the first two-thirds of the array
            stoogeSort(arr, low, high - t);
            // Sort the last two-thirds of the array
            stoogeSort(arr, low + t, high);
            // Sort the first two-thirds of the array again
            stoogeSort(arr, low, high - t);
        }
    }
    // Function to print the array
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    // Driver Code
    public static void main(String[] args) {
        int[] arr = { 10, 5, 8, 2, 1, 6 };
        System.out.print("Original array: ");
        printArray(arr);
        stoogeSort(arr, 0, arr.length - 1);
        System.out.print("Sorted array: ");
        printArray(arr);
    }
}
