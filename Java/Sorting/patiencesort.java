import java.util.*;
import java.util.stream.Collectors;

class Stack extends ArrayList<Integer> implements Comparable<Stack> {
    @Override
    public int compareTo(Stack other) {
        return this.get(this.size() - 1).compareTo(other.get(other.size() - 1));
    }
}

public class patiencesort {
    public static List<Integer> patienceSort(List<Integer> collection) {
        List<Stack> stacks = new ArrayList<>();

        for (Integer element : collection) {
            Stack newStack = new Stack();
            newStack.add(element);
            int i = Collections.binarySearch(stacks, newStack);
            if (i >= 0) {
                stacks.get(i).add(element);
            } else {
                stacks.add(-(i + 1), newStack);
            }
        }

        List<Integer> sorted = stacks.stream()
                .flatMap(Collection::stream)
                .collect(Collectors.toList());

        return sorted;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter numbers separated by a comma:");
        String userInput = scanner.nextLine().trim();
        List<Integer> unsorted = Arrays.stream(userInput.split(","))
                .map(Integer::parseInt)
                .collect(Collectors.toList());
        List<Integer> sorted = patienceSort(unsorted);
        System.out.println("Sorted Array:");
        System.out.println(sorted);
    }
}