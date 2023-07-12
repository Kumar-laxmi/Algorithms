import java.util.Scanner;

public class bingo_Sort {
    public static void bingoSort(int[] arr) {
        int min = arr[0], max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min)
                min = arr[i];
            else if (arr[i] > max)
                max = arr[i];
        }

        int[] flags = new int[max - min + 1];
        for (int i = 0; i < arr.length; i++)
            flags[arr[i] - min] = 1;

        int index = 0;
        for (int i = 0; i < max - min + 1; i++) {
            if (flags[i] == 1) {
                arr[index] = i + min;
                index++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the length of the array: ");
        int n = scanner.nextInt();
        int[] a = new int[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++)
            a[i] = scanner.nextInt();

        System.out.println("Original array:");
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println();

        bingoSort(a);

        System.out.println("Sorted array:");
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
}
