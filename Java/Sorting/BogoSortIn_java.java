import java.util.Random;

public class BogoSortIn_java {

    private static final int SIZE = 10;

    public static void shuffle(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int j = (int) (Math.random() * array.length);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    public static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        return true;
    }

    public static void bogosort(int[] array) {
        int shuffles = 0;
        while (!isSorted(array)) {
            shuffle(array);
            shuffles++;
        }
        // System.out.println("Number of shuffles: " + shuffles);
    }

    public static void main(String[] args) {
        int[] array = new int[SIZE];
        for (int i = 0; i < array.length; i++) {
            array[i] = (int) (Math.random() * 100);
        }

        System.out.print("The unsorted array is:\t");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        bogosort(array);

        System.out.print("The sorted array is:\t");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
