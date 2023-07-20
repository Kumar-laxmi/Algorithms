import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class PowerSet {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the original set: ");
        int numElements = scanner.nextInt();

        List<Character> originalSet = new ArrayList<>();
        System.out.println("Enter the elements of the original set: ");
        for (int i = 0; i < numElements; i++) {
            originalSet.add(scanner.next().charAt(0));
        }

        // Remove duplicates from the original set
        Set<Character> uniqueSet = new HashSet<>(originalSet);
        originalSet.clear();
        originalSet.addAll(uniqueSet);

        // Generate the power set
        int n = originalSet.size();
        int numSubsets = (int) Math.pow(2, n);
        List<List<Character>> powerSet = new ArrayList<>();

        for (int i = 0; i < numSubsets; i++) {
            List<Character> subset = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    subset.add(originalSet.get(j));
                }
            }
            powerSet.add(subset);
        }

        // Print the power set
        System.out.println("Power Set:");
        for (List<Character> subset : powerSet) {
            System.out.print("{ ");
            for (Character element : subset) {
                System.out.print(element + " ");
            }
            System.out.println("}");
        }
    }
}