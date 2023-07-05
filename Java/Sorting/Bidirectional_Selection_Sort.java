import java.util.Scanner;

public class Main {
    public static void bidirectionalSelectionSort(int[] arr) {
        int left = 0, right = arr.length - 1;

        while (left < right) {
            int minimum = arr[left];
            int maximum = arr[right];
            int minIndex = left;
            int maxIndex = right;

            for (int i = left +1; i <= right; i++) {
                if (arr[i] < minimum) {
                    minimum = arr[i];
                    minIndex = i;
                }
                if (arr[i] > maximum) {
                    maximum = arr[i];
                    maxIndex = i;
                }
            }

            if (minIndex == right) {
                int temp = arr[left];
                arr[left] = arr[minIndex];
                arr[minIndex] = temp;
            } else {
                int temp = arr[left];
                arr[left] = arr[minIndex];
                arr[minIndex] = temp;

                temp = arr[right];
                arr[right] = arr[maxIndex];
                arr[maxIndex] = temp;
            }

            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        int[] array = new int[n];

        System.out.print("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        System.out.print("Original array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        bidirectionalSelectionSort(array);

        System.out.print("Sorted array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
