import java.util.Arrays;

class shell_sort {
    public static void shellSort(int[] arr) {
        int n = arr.length;

        // Start with a big gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order.
            // Keep adding one more element until the entire array is gap sorted.
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > temp) {
                    // Shift earlier gap-sorted elements up until the correct location for a[i] is found.
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                // Put temp (the original a[i]) in its correct location.
                arr[j] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {9, 8, 1, 7, 4, 3};
        System.out.println("Array before sorting:");
        System.out.println(Arrays.toString(arr));
        shellSort(arr);
        System.out.println("Array after sorting:");
        System.out.println(Arrays.toString(arr));
    }
}