import java.util.Arrays;

public class PanCakeSort {
    public static void flip(int[] arr, int i) {
        int start = 0;
        while (start < i) {
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

    public static int findMaxIndex(int[] arr, int n) {
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public static void pancakeSort(int[] arr) {
        int n = arr.length;
        for (int currSize = n; currSize > 1; currSize--) {
            int maxIndex = findMaxIndex(arr, currSize);
            if (maxIndex != currSize - 1) {
                flip(arr, maxIndex);
                flip(arr, currSize - 1);
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 6, 3, 9, 2, 5 };

        System.out.print("Original array: ");
        System.out.println(Arrays.toString(arr));

        pancakeSort(arr);

        System.out.print("Sorted array: ");
        System.out.println(Arrays.toString(arr));
    }
}
