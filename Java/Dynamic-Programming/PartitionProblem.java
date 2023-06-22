import java.util.Arrays;
import java.util.Scanner;
 
class PartitionProblem
{
    // Returns true if there exists a subarray of array `nums[0…n]`
    // with the given sum
    public static boolean subsetSum(int[] nums, int n, int sum)
    {
        // return true if the sum becomes 0 (subset found)
        if (sum == 0) {
            return true;
        }
 
        // base case: no items left or sum becomes negative
        if (n < 0 || sum < 0) {
            return false;
        }
 
        // Case 1. Include the current item `nums[n]` in the subset and recur
        // for remaining items `n-1` with the remaining total `sum-nums[n]`
        boolean include = subsetSum(nums, n - 1, sum - nums[n]);
 
        // return true if we get subset by including the current item
        if (include) {
            return true;
        }
 
        // Case 2. Exclude the current item `nums[n]` from the subset and recur for
        // remaining items `n-1`
        boolean exclude = subsetSum(nums, n - 1, sum);
 
        // return true if we get subset by excluding the current item
        return exclude;
    }
 
    // Returns true if given array `nums[0…n-1]` can be divided into two
    // subarrays with equal sum
    public static boolean partition(int[] nums)
    {
        int sum = Arrays.stream(nums).sum();
 
        // return true if the sum is even and the array can be divided into
        // two subarrays with equal sum
        return (sum & 1) == 0 && subsetSum(nums, nums.length - 1, sum/2);
    }
 
    public static void main(String[] args)
    {
        // Input: a set of items
        Scanner sc = new Scanner(System.in);
        int n = 0;
        System.out.println("Enter size of array");
        n=sc.nextInt();  
        int[] nums = new int[n];
        System.out.println("Enter elements of array");
        for(int i=0; i<n; i++)  
            {  
            //reading array elements from the user   
            nums[i]=sc.nextInt();  
            }         
 
        if (partition(nums)) {
            System.out.println("Set can be partitioned");
        }
        else {
            System.out.println("Set cannot be partitioned");
        }
        sc.close();
    }
}

