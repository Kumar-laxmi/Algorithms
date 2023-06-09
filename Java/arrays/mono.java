import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

mono Main{ 
    public static boolean isMonotonic(List<Integer> nums) {
        int n = nums.size();
    int s = 0, e = n - 1;
        while (s < e) {
            if (nums.get(s) <= nums.get(s + 1) && nums.get(s) <= nums.get(e) && e == n - 1) {
                s++;
            } 
            else if (nums.get(e) <= nums.get(e - 1) && nums.get(e) <= nums.get(s) && s == 0) {
                e--;
            } 
            else {
                break;
            }
        }
        return (s == n - 1 || e == 0);
    }

    public static void main(String[] args) {        
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the number of elements in the array: ");
            int n = scanner.nextInt();
            System.out.println("Enter the elements of the array: ");
            List<Integer> nums = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int element = scanner.nextInt();
                nums.add(element);
            }

            if (isMonotonic(nums)) {
                System.out.println("The array is monotonic.");
            } else {
                System.out.println("The array is not monotonic.");
            }
    }
}
// MONOTONIC ARRAY IN Java
// This Program Tells if an array is monotonic or not.
