import java.util.Scanner;

public class selection {
    public static void main(String args[]) {
        int num;

        try (Scanner s = new Scanner(System.in)) {
            System.out.print("ENTER THE NUMBER OF ELEMENTS: ");

            num = s.nextInt();

            // Array input
            int[] array = new int[num];
            System.out.println("ENTER THE ELEMENTS OF ARRAY: ");
            for (int i = 0; i < num; i++) {
                array[i] = s.nextInt();
            }

            // Prining unsorted array
            System.out.println("UNSORTED ARRAY: ");
            for (int i = 0; i < num; i++) {
                System.out.println(array[i]);
            }

            // selection sort
            for (int i = 0; i < num - 1; i++) {
                int smallest = i;
                for (int j = i + 1; j < num; j++) {
                    if (array[smallest] > array[j]) {
                        smallest = j;
                    }
                }

                // swapping
                int temp = array[smallest];
                array[smallest] = array[i];
                array[i] = temp;
            }

            // Prining sorted array
            System.out.println("SORTED ARRAY: ");
            for (int i = 0; i < num; i++) {
                System.out.println(array[i]);
            }
        }

    }

}
