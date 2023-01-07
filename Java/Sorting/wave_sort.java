import java.util.Arrays;

public class wave_sort {
    public static void wave_sort(int[] arr) {
        // Sorting the array in ascending order
        Arrays.sort(arr);

        // Swapping the elements in pairs
        for (int i = 0; i < arr.length - 1; i += 2) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        waveSort(arr);

        System.out.println(Arrays.toString(arr));  // [2, 1, 4, 3, 6, 5, 8, 7, 9]
    }
}
