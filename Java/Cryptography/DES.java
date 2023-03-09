/* 
Algorithm:
    The algorithm requires a 64-bit encryption key as its input for key generation. 
    Initially, the key undergoes a permutation function that yields a 56-bit key.    
    and then it is divided into two halves, each containing 28-bits. Each half is 
    separately subjected to a series of shifts and permutations, generating 16 subkeys, each 48 bits long.

    Initial permutation: The 64-bit plaintext is now permuted according to the fixed permutation 
    table. This step is designed to add confusion to the plaintext.

    Feistel rounds: The permuted plaintext is divided into two halves, each containing 
    The 32-bit input is split into two halves, which are then processed through 16 rounds, with each round comprising    
    of the following operations:

    Expansion involves taking the 32-bit right half and transforming it into a 48-bit value using a fixed permutation table.
    
    b. XOR: The expanded right half is XORed with the 48-bit subkey generated during the key generation step.

    c. Substitution: The XOR output is divided into eight 6-bit blocks, which are then substituted.
    A collection of eight separate S-boxes is utilized in this procedure, wherein each of these maps 
    a 6-bit input into a 4-bit output.     
    After the S-boxes have generated their output, a fixed permutation table is used to permute the resulting values.
    
    e. XOR: The permuted output of the S-boxes is XORed with the left half of the plaintext.

    f. Swap: The left and right halves of the plaintext are swapped before the next round.

    Final permutation: The output of the 16th Feistel round is permuted according to a fixed 
    permutation table to produce the final ciphertext.

Input:
    1. The user is prompted to indicate whether they wish to perform encryption or decryption.
    2. If user chooses to encrypt the code asks the user to input a string to encrypt.
    3. If the user chooses to decrypt, the code asks the user for the key in hexadecimal format. 
       Then it asks the user to enter the key(IV) in hexadecimal format. 
       Then it finally asks the user to enter the ciphertext.

Output:
    1. In case the user chooses to encrypt, the code outputs a key, key(IV) and cipher text in hexadecimal format.
    2. In case the user chosses to decrypt, the code outputs the plaintext that was encrypted with the keys.
*/

import java.util.Scanner;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

public class DES {

    // Set the encryption algorithm constant and key algorithm constant
    private static final String KEY_ALGORITHM = "DESede";
    private static final String ENCRYPTION_ALGORITHM = "DESede/ECB/PKCS5Padding";

    // Generate a random secret key using the key algorithm
    public static SecretKey generateKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance(KEY_ALGORITHM);
        return keyGenerator.generateKey();
    }

    // Here Encryption of a message using a secret key is done
    public static String encrypt(String message, SecretKey key) throws Exception {
        Cipher cipher = Cipher.getInstance(ENCRYPTION_ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encryptedBytes = cipher.doFinal(message.getBytes(StandardCharsets.UTF_8));
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    // Here Decryption of an encrypted message(ciphertext) using the same secret key is done
    public static String decrypt(String encryptedMessage, SecretKey key) throws Exception {
        Cipher cipher = Cipher.getInstance(ENCRYPTION_ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedMessage);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes, StandardCharsets.UTF_8);
    }

    // Main method
    public static void main(String[] args) throws Exception {
        // Initialize a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Generate a random secret key
        SecretKey key = generateKey();
        
        // Convert the secret key to a string and print it
        String keyStr = Base64.getEncoder().encodeToString(key.getEncoded());
        System.out.println("Generated Key: " + keyStr);

        // Initialize a flag to determine if the program should continue running
        boolean isRunning = true;
        
        // Begin a loop to prompt the user for an encryption/decryption choice
        while (isRunning) {
            System.out.println("Enter your choice:");
            System.out.println("1: Encrypt");
            System.out.println("2: Decrypt");
            System.out.println("3: Exit");

            // Read the user's choice
            int choice = scanner.nextInt();
            scanner.nextLine();

            // Switch on the user's choice
            switch (choice) {
                case 1:
                    System.out.print("Enter message to encrypt: ");
                    String messageToEncrypt = scanner.nextLine();

                    // Encrypt the message using the generated secret key
                    String encryptedMessage = encrypt(messageToEncrypt, key);
                    System.out.println("Encrypted message: " + encryptedMessage);
                    break;
                case 2:
                    System.out.print("Enter message to decrypt: ");
                    String encryptedMessageStr = scanner.nextLine();

                    // Decrypt the message using the generated secret key
                    String decryptedMessage = decrypt(encryptedMessageStr, key);
                    System.out.println("Decrypted message: " + decryptedMessage);
                    break;
                case 3:
                    isRunning = false;
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }

        // Close the scanner
        scanner.close();
    }
}

