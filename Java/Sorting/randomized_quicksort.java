import java.util.Random;

public class randomized_quicksort {
    public static int partition(int[] arr, int p, int r) {
        int x = arr[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++) {
            if (arr[j] <= x) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, r);
        return i + 1;
    }

    public static int randomizedPartition(int[] arr, int p, int r) {
        int i = p + new Random().nextInt(r - p + 1);
        swap(arr, i, r);
        return partition(arr, p, r);
    }

    public static void randomizedQuicksort(int[] arr, int p, int r) {
        if (p < r) {
            int q = randomizedPartition(arr, p, r);
            randomizedQuicksort(arr, p, q - 1);
            randomizedQuicksort(arr, q + 1, r);
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {78, 9, 10, -1, 2, -45, 91};
        int n = arr.length;
        randomizedQuicksort(arr, 0, n - 1);
        System.out.println("Sorted array using Randomized quicksort is:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
