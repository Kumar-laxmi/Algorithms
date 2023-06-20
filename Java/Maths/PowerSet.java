//Program to generate power set of a set of elements in C language.


//APPROACH

/*In Java, you can find the power set of a set of elements using a recursive approach. 
The power set of a set is the set of all possible subsets of that set, including the empty set and the set itself.*/



//EXPLANATION
/*
1. The powerSet method takes a list of integers as input and returns a list of lists, representing the power set of the input set.

2. The result list is initialized to store the subsets.

3. Initially, an empty set is added to the result list.

4. The generateSubsets method is a recursive helper function that generates subsets.

5. In the generateSubsets method, the base case checks if all elements have been processed (index is greater than or equal to the size of the set), in which case the method returns.

6. The current element at the given index is added to the current list, representing the current subset being generated. This subset is then added to the result list.

7. Recursive calls are made to generate subsets, including the current element (by incrementing the index), and subsets excluding the current element (by removing the last element from the current list).

8. The main method demonstrates the usage of the powerSet method by creating a sample set and printing the generated power set.
*/

//SOURCE CODE

import java.util.ArrayList;
import java.util.List;

public class PowerSet {

    public static List<List<Integer>> powerSet(List<Integer> set) {
        List<List<Integer>> result = new ArrayList<>();

        // Add an empty set as the first subset
        result.add(new ArrayList<>());

        // Generate subsets recursively
        generateSubsets(set, 0, new ArrayList<>(), result);

        return result;
    }

    private static void generateSubsets(List<Integer> set, int index, List<Integer> current, List<List<Integer>> result) {
        // Base case: if all elements have been processed, return
        if (index >= set.size()) {
            return;
        }

        // Include the current element in the subset
        current.add(set.get(index));
        result.add(new ArrayList<>(current));

        // Generate subsets including the current element
        generateSubsets(set, index + 1, current, result);

        // Exclude the current element from the subset
        current.remove(current.size() - 1);

        // Generate subsets excluding the current element
        generateSubsets(set, index + 1, current, result);
    }

    public static void main(String[] args) {
        List<Integer> set = List.of(1, 2, 3);
        List<List<Integer>> powerSet = powerSet(set);

        System.out.println("Power Set:");
        for (List<Integer> subset : powerSet) {
            System.out.println(subset);
        }
    }
}
