import java.util.Scanner;

public class QuickSort {
    public static void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        i++;
        swap(arr, high, i);
        return i;
    }

    void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot;
            pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    void prtArr(int[] arr, int n) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        QuickSort qs = new QuickSort();
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter the size of the array : ");
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the Elements of the array : ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        // Printing The Array Before Sorting
        qs.prtArr(arr, n);
        qs.quickSort(arr, 0, n - 1);
        // Printing The Array After Sorting
        qs.prtArr(arr, n);
        sc.close();
    }

}
