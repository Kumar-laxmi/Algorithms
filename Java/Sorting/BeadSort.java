import java.util.Arrays;
import java.util.Scanner;

public class BeadSort {
    public static void display(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void beadSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int len = arr.length;
        int[][] beads = new int[len][max];

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < arr[i]; j++) {
                beads[i][j] = 1;
            }
        }

        for (int j = 0; j < max; j++) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += beads[i][j];
                beads[i][j] = 0;
            }
            for (int i = len - sum; i < len; i++) {
                beads[i][j] = 1;
            }
        }

        for (int i = 0; i < len; i++) {
            int j;
            for (j = 0; j < max && beads[i][j] != 0; j++) {
            }
            arr[i] = j;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        System.out.print("Enter the elements of the array: ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Original array: ");
        display(arr);

        beadSort(arr);

        System.out.print("Sorted array: ");
        display(arr);
    }
}