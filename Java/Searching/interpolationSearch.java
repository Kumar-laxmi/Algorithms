import java.util.Scanner;

public class interpolationSearch {
    public static int interpolationSearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right && target >= arr[left] && target <= arr[right]) {
            if (left == right) {
                if (arr[left] == target)
                    return left;
                return -1;
            }

            int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

            if (arr[pos] == target)
                return pos;

            if (arr[pos] < target)
                left = pos + 1;
            else
                right = pos - 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];
        System.out.println("Enter the sorted elements of the array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the target element to search: ");
        int target = scanner.nextInt();

        int index = interpolationSearch(arr, target);

        if (index != -1)
            System.out.println("Element found at index " + index);
        else
            System.out.println("Element not found");

        scanner.close();
    }
}
