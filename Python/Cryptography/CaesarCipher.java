"""
Definition:
 Caesar Cipher is a simple substitution cipher that replaces each letter in the plaintext 
 with a letter shifted a certain number of places down the alphabet. For example, with a 
 shift of 1, A would be replaced by B, B would become C, and so on
 
Input: 
 Opton: First the code asks for Encryption or decryption. 
 Plain text: On choosing encrypt the code asks for plaintext.
 Cipher text: On choosing decrypt the code asks for cipher text to decrypt. 
 Shift value: The code asks for a shift value which shifts the alphabet by that number.
Output: 
 On choosing encrypt the output will be a string called cipher text. And on choosing decryption 
 the output will be plaintext.
 """

import java.util.Scanner;

public class CaesarCipher {
    public static void main(String[] args) {
        
        """Asks the used if he wants to encrypt or decrypt a piece of text"""
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Encrypt\n2. Decrypt\nEnter your choice: ");
        int choice = sc.nextInt();
        sc.nextLine();
        
        """In case Encrypt is chosen. it asks for plaintext to encrypt and shift value which is used to shift the alphabets"""
        if (choice == 1) {
            System.out.print("Enter a message to be encrypted: ");
            String message = sc.nextLine();
            System.out.print("Enter a shift value: ");
            int shift = sc.nextInt();

        """Here encryption ofthe message is taking place and the output is a cipher text"""
            String encryptedMessage = encrypt(message, shift);
            System.out.println("Encrypted message: " + encryptedMessage);
        } else if (choice == 2) {
        
        """in case Decrypt is chosen the code asks for a cipher text and a shift value"""
            System.out.print("Enter a message to be decrypted: ");
            String message = sc.nextLine();
            System.out.print("Enter a shift value: ");
            int shift = sc.nextInt();

        """Here the decryption of cipher text and the potput is a plaintext"""
            String decryptedMessage = decrypt(message, shift);
            System.out.println("Decrypted message: " + decryptedMessage);
        } else {
            System.out.println("Invalid choice");
        }
    }

    """Function to encrypt the message"""
    public static String encrypt(String message, int shift) {
        char[] chars = message.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (Character.isLetter(chars[i])) {
                char ch = (char) (chars[i] + shift);
                if (Character.isLowerCase(chars[i])) {
                    if (ch > 'z') {
                        ch = (char) (ch - 26);
                    }
                } else {
                    if (ch > 'Z') {
                        ch = (char) (ch - 26);
                    }
                }
                chars[i] = ch;
            }
        }
        return new String(chars);
    }

    """Function to decrypt the cipher text"""
    public static String decrypt(String message, int shift) {
        char[] chars = message.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (Character.isLetter(chars[i])) {
                char ch = (char) (chars[i] - shift);
                if (Character.isLowerCase(chars[i])) {
                    if (ch < 'a') {
                        ch = (char) (ch + 26);
                    }
                } else {
                    if (ch < 'A') {
                        ch = (char) (ch + 26);
                    }
                }
                chars[i] = ch;
            }
        }
        return new String(chars);
    }
}
