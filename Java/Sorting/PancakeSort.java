import java.util.Arrays;

class PancakeSort {
    // Reverses the array from index 0 to i
    static void flip(int arr[], int i) {
        int temp, start = 0;
        while (start < i) {
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

    // Returns the index of the maximum element in the array
    static int findMax(int arr[], int n) {
        int max = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] > arr[max])
                max = i;
        return max;
    }

    // Sorts the array using Pancake Sort
    static void pancakeSort(int arr[], int n) {
        for (int curr_size = n; curr_size > 1; --curr_size) {
            int max = findMax(arr, curr_size);

            if (max != curr_size - 1) {
                flip(arr, max);
                flip(arr, curr_size - 1);
            }
        }
    }

    // Utility function to print an array
    static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver program
    public static void main(String args[]) {
        int arr[] = { 23, 10, 20, 11, 12, 6, 7 };
        int n = arr.length;

        System.out.print("Original array: ");
        printArray(arr);

        pancakeSort(arr, n);

        System.out.print("Sorted array: ");
        printArray(arr);
    }
}
