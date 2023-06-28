/*
------------------------------------- Number To Words Convertor -------------------------------------

Approach

1. Initialize global vectors containing the words for digits, denominations (thousand, million, etc.), tens, and ties.

2. Read an input number as a string from the user.

3. Pad the input number with leading zeros if its size is not a multiple of 3.

4. Reverse the input number for easier processing.

5. Recursively convert the input number to words by processing it in groups of three digits.

6. Extract the one's, ten's, and hundred's digits from the current group.

7. Build the word representation by appending the corresponding words for the digits, tens, and hundreds.

8. Append the appropriate denomination (thousand, million, etc.) based on the current level.

9. Recursively process the remaining digits.

10. Print the resulting word representation of the input number.

Below is the implementation of Number-to-Words Conversion in Java Language.
*/

// Program starts
import java.util.*;

public class Number_to_Words {
    // Initializing global variables for word representations
    private static final String[] digit = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    private static final String[] denominations = {"", "Thousand", "Million", "Billion", "Trillion"};
    
    private static final String[] tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    private static final String[] ties = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    // Function to concatenate two strings with a space between them
    private static String add(String s1, String s2) {
        if (!s1.isEmpty() && !s2.isEmpty()) {
            return s1 + " " + s2;
        }
        return s1 + s2;
    }

    // Function to convert any number into words recursively
    private static String convert(int idx, int level, String input) {
        // Base condition to check whether the current index is greater than or equal to the size of the input number
        if (idx >= input.length()) {
            return "";
        }
        String cur = "";
        int od, td, hd;
        od = Character.getNumericValue(input.charAt(idx));  // One's digit
        td = Character.getNumericValue(input.charAt(idx + 1));  // Ten's digit
        hd = Character.getNumericValue(input.charAt(idx + 2));  // Hundred's digit

        if (hd != 0) {
            cur = add(cur, add(digit[hd], "Hundred"));  // Add the hundred's digit to the current string
        }

        if (td != 0) {
            if (td == 1) {
                cur = add(cur, tens[od]);  // If the ten's digit is 1, use the corresponding value from the 'tens' array
            } else {
                cur = add(cur, ties[td - 1]);  // If the ten's digit is not 1, use the corresponding value from the 'ties' array
                if (od != 0) {
                    cur = add(cur, digit[od]);  // Add the one's digit if it's not zero
                }
            }
        } else if (od != 0) {
            cur = add(cur, digit[od]);  // If the ten's digit is zero, only add the one's digit
        }

        if (!cur.isEmpty()) {
            cur = add(cur, denominations[level]);  // Add the current level's denomination (thousand, million, billion, etc.) to the string
        }

        return add(convert(idx + 3, level + 1, input), cur);  // Recursively convert the remaining digits and concatenate with the current string
    }

    // Driver function
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Taking input from the user
            System.out.print("\nEnter Number: ");
            String input = scanner.nextLine();

            System.out.print("\n" + input + " in Words: ");
            
            while (input.length() % 3 != 0) {
                input = "0" + input;  // Pad the input number with leading zeros to make its size a multiple of 3
            }

            StringBuilder reversedInput = new StringBuilder(input).reverse();  // Reverse the input number for easier processing

            if (input.equals("000")) {
                System.out.println("Zero");  // If the input number is all zeros
            } else if (input.length() > 15) {
                System.out.println("This is a very large number !");  // If the input number exceeds the supported range
            } else {
                System.out.println(convert(0, 0, reversedInput.toString()));  // Convert the input number to words and print the result
            }
        }
        System.out.println("\n");
    }
}
