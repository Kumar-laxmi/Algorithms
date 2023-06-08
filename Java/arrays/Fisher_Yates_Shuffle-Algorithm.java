import java.util.Arrays;
import java.util.Random;

public class FisherYatesShuffle {

    // Function to perform Fisher-Yates shuffle
    public static void fisherYatesShuffle(int[] arr) {
        int n = arr.length;
        Random rand = new Random();

        for (int i = n - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1); // Generate a random index between 0 and i (inclusive)
            // Swap the elements at indices i and j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static void main(String[] args) {
        // Create an array of integers
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Print the original array
        System.out.println("Original array: " + Arrays.toString(numbers));

        // Shuffle the array using Fisher-Yates shuffle
        fisherYatesShuffle(numbers);

        // Print the shuffled array
        System.out.println("Shuffled array: " + Arrays.toString(numbers));
    }
}
