//O(n) time | O(n) space
import java.util.HashSet;

public class ZeroSumSubarray {

    public static boolean zeroSumSubarray(int[] nums) {
        HashSet<Integer> sums = new HashSet<>(); // Set to store cumulative sums
        int currentSum = 0; // Variable to store the current sum
        for (int num : nums) {
            currentSum += num; // Add the current number to the current sum
            if (currentSum == 0 || sums.contains(currentSum) || num == 0) {
                // If current sum is zero or already exists in the set, or the current number is zero,
                // then there is a zero sum subarray
                return true;
            }
            sums.add(currentSum); // Add the current sum to the set
        }
        return false; // No zero sum subarray found
    }

    public static void main(String[] args) {
        int[] nums = { 4, 2, -3, 1, 6 };

        if (zeroSumSubarray(nums)) {
            System.out.println("Subarray with zero sum exists");
        } else {
            System.out.println("Subarray with zero sum does not exist");
        }
    }
}
