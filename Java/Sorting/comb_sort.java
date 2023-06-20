import java.util.Scanner;

public class comb_sort {
    public static int getNextGap(int gap) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            return 1;
        return gap;
    }

    public static void combSort(int[] a) {
        int n = a.length;
        int gap = n;
        boolean swapped = true;
        while (gap != 1 || swapped) {
            gap = getNextGap(gap);
            swapped = false;
            for (int i = 0; i < n - gap; i++) {
                if (a[i] > a[i + gap]) {
                    int temp = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = temp;
                    swapped = true;
                }
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
        combSort(a);
        System.out.println("\nSorted array:");
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        scanner.close();
    }
}
