/*
Algorithm:
    1. Define a substitution dictionary: In this step, the algorithm defines a dictionary 
    that maps each letter in the plaintext message to one or more substitute characters 
    in the ciphertext message.

    2. Prompt for plaintext input: The algorithm prompts the user to enter the plaintext 
    message that they want to encrypt.

    3. Apply the substitution: The algorithm applies the substitution rules defined in 
    the dictionary to each letter in the plaintext message. If a letter has multiple 
    possible substitutes, one is chosen at random.

    4. Generate the ciphertext: The resulting substitute characters are concatenated to 
    form the ciphertext message.

    5. Output the ciphertext: The algorithm outputs the resulting ciphertext to the user.

Input:
    A string which is also called a plain text.
Output:
    A string called cipher text which changes everytime the same plaintext is entered.
    It substitutes the value of letters randomly to make the cipher text.
*/

import java.util.Scanner;

public class HomophonicSubstitution {

    // Define a 6x5 array representing the homophonic substitution table
    static char[][] homophonic = {
            {'a', 'b', 'c', 'd', 'e'},
            {'f', 'g', 'h', 'i', '\0'},
            {'j', 'k', 'l', 'm', 'n'},
            {'o', 'p', 'q', 'r', '\0'},
            {'s', 't', 'u', 'v', '\0'},
            {'w', 'x', 'y', 'z', '\0'}
    };

    // Define a function to perform homophonic substitution on a message
    public static String homophonicSubstitution(String message) {
        StringBuilder result = new StringBuilder(); // Define a StringBuilder to hold the substituted message
        int j;
        for (int i = 0; i < message.length(); i++) {
            if (Character.isLowerCase(message.charAt(i))) { // Check if the character is a lowercase letter
                j = message.charAt(i) - 'a'; // Calculate the index of the corresponding row in the substitution table
                result.append(homophonic[j % 6][i % 4]); // Substitute the character with the corresponding homophonic letter
            }
            else if (Character.isUpperCase(message.charAt(i))) { // Check if the character is an uppercase letter
                j = message.charAt(i) - 'A'; // Calculate the index of the corresponding row in the substitution table
                result.append((char) (homophonic[j % 6][i % 4] - 32)); // Substitute the character with the corresponding homophonic letter (converted to uppercase)
            }
            else { // If the character is not a letter, just copy it to the result
                result.append(message.charAt(i));
            }
        }
        return result.toString(); // Return the substituted message
    }

    // Define the main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter message: ");
        String message = scanner.nextLine(); // Read the input message from the user
        System.out.println("Homophonic substitution: " + homophonicSubstitution(message)); // Perform homophonic substitution and print the result
        scanner.close();
    }
}
