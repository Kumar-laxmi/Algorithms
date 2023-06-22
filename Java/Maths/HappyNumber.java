import java.util.HashSet;
import java.util.Scanner;

public class HappyNumber {

    public static boolean isHappy(int n) {
        HashSet<Integer> seen = new HashSet<>();

        while (n != 1) {
            int current = n;
            int sum = 0;

            while (current != 0) {
                int digit = current % 10;
                sum += digit * digit;
                current /= 10;
            }

            if (seen.contains(sum)) {
                return false; // Entered a cycle containing 4, so it's an unhappy number
            }

            seen.add(sum);
            n = sum;
        }

        return true; // Reached 1, so it's a happy number
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        boolean isHappyNumber = isHappy(number);
        System.out.println(number + " is a happy number: " + isHappyNumber);
    }
}
