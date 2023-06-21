import java.util.Scanner;

public class QuickSelect {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input array
        System.out.print("Enter the array elements separated by spaces: ");
        String[] inputarray = scanner.nextLine().split(" ");
        int[] array = new int[inputarray.length];
        for (int i = 0; i < inputarray.length; i++) {
            array[i] = Integer.parseInt(inputarray[i]);
        }

        // Input k
        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        // Call Quick Select algorithm
        int result = quickselect(array, 0, array.length - 1, k);
        System.out.println("The k'th smallest element is: " + result);
        scanner.close();
    }

    public static int quickselect(int[] array, int low, int high, int k) {
        //if only 1 element is present in the array
        if (low == high) {
            return array[low];
        }

        //partitioning the array to get the pivot element
        int pivotIndex = partition(array, low, high);

            // If the pivot index is equal to k, we have found the kth smallest element
        if (k == pivotIndex) {
            return array[pivotIndex];}
            // If k is less than the pivot index, recurse on the left subarray
         else if (k < pivotIndex) {
            return quickselect(array, low, pivotIndex - 1, k);}
            // If k is greater than the pivot index, recurse on the right subarray
         else {
            return quickselect(array, pivotIndex + 1, high, k);
        }
    }

    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            // Swap elements if they are smaller than or equal to the pivot
            if (array[j] <= pivot) {
                i++;
                swap(array, i, j);
            }
        }

        swap(array, i + 1, high);

        return i + 1;
    }
//swapping the vaiables
    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
