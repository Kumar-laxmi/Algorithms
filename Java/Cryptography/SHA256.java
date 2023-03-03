/*
Definition:
    SHA-256 (Secure Hash Algorithm 256) is a widely-used cryptographic hashing 
    algorithm that produces a fixed-size 256-bit (32-byte) hash value. The 
    SHA-256 algorithm takes an input message of any length and processes it in 
    512-bit (64-byte) blocks. The message is first padded with a 1-bit followed 
    by zeros to make it a multiple of 512 bits. The last 64 bits of the padded 
    message are used to store the length of the original message in bits. The 
    output of the SHA-256 algorithm is a 256-bit hash value that is typically 
    represented as a sequence of 64 hexadecimal digits. The hash value is unique 
    to the input message, and even a small change to the message will result 
    in a completely different hash value. This makes the SHA-256 algorithm useful 
    for verifying the integrity of data, as well as for password hashing and 
    digital signatures.
Input:
    Option: the code asks the user if they want to encrypt or verify a hash
    Message: in case the user wants to encrypt, the code asks the user for a message to encrypt.
    Hash: if the user wants to verify a hash, then the code asks the user for the original 
    hash and the original message.
Output:
    Hash: If the user wants to encrypt a message, the code gives a hash as the output.
    Verification: If the user wanted to verify a hash and has given the necessary inputs, the code 
    will either say the hash is verified in case of successful verification or it will say that 
    the hash does not match, indicating the hash or message for this hash is invalid.
*/

import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class SHA256 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        """This loop asks the user whether to encrypt or verify a hash. here we use 
        loop to ask the user multiple times whether to encrypt ot verify in case the 
        user enters the wrong input"""
        while (true) {
            System.out.print("Do you want to encrypt or verify a hash? (e/v): ");
            String action = scanner.nextLine();

            if (action.equalsIgnoreCase("e")) {
                """In case the user wants to encrypt, prompt for message and compute hash"""
                System.out.print("Enter a string to hash: ");
                String inputStr = scanner.nextLine();
                String hashResult = sha256(inputStr);
                System.out.println("The SHA-256 hash of the input string is: " + hashResult);
                break;
            } else if (action.equalsIgnoreCase("v")) {
                """If user wants to verify a hash, prompt for original message and hash"""
                System.out.print("Enter the original string: ");
                String inputStr = scanner.nextLine();
                System.out.print("Enter the original hash: ");
                String originalHash = scanner.nextLine();
                String verifyResult = sha256(inputStr);

                if (verifyResult.equals(originalHash)) {
                    """If computed hash matches original hash, that means verification is successful"""
                    System.out.println("The hash is verified.");
                } else {
                    """If computed hash does not match original hash, that means verification is unsuccessful"""
                    System.out.println("The hash does not match.");
                }
                break;
            } else {
                """If user enters invalid input, prompt again"""
                System.out.println("Invalid input. Please enter 'e' or 'v'.");
            }
        }

        scanner.close();
    }

    """Method to compute SHA-256 hash of a string entered as input"""
    public static String sha256(String str) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(str.getBytes(StandardCharsets.UTF_8));
            StringBuilder hexString = new StringBuilder();

            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) {
                    hexString.append('0');
                }
                hexString.append(hex);
            }

            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

}
