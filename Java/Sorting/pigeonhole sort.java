import java.util.Scanner;

public class PigeonholeSortExample {
    public static void pigeonholeSort(int[] arr) {
        int min = arr[0], max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        int range = max - min + 1;
        int[] pigeonholes = new int[range];

        for (int i = 0; i < arr.length; i++) {
            pigeonholes[arr[i] - min]++;
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            while (pigeonholes[i] > 0) {
                arr[index++] = i + min;
                pigeonholes[i]--;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        pigeonholeSort(arr);

        System.out.print("Sorted array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

}
