import java.util.Scanner;

class bubble_sort {
    public static void main(String args[]) {
        int num;
        int temp = 0;
        try (Scanner s = new Scanner(System.in)) {
            System.out.print("ENTER THE NUMBER OF ELEMENTS: ");

            num = s.nextInt();

            int[] array = new int[num];
            System.out.println("ENTER THE ELEMENTS OF ARRAY: ");
            for (int i = 0; i < num; i++) {
                array[i] = s.nextInt();
            }
            System.out.println("UNSORTED ARRAY: ");

            for (int i = 0; i < num; i++) {
                System.out.println(array[i]);
            }

            for (int i = 0; i < num; i++) {
                for (int j = 1; j < (num - i); j++) {
                    if (array[j - 1] > array[j]) {

                        temp = array[j - 1];
                        array[j - 1] = array[j];
                        array[j] = temp;
                    }

                }
            }
            System.out.println("SORTED ARRAY: ");
            for (int i = 0; i < num; i++) {
                System.out.println(array[i]);
            }
        }

    }

}