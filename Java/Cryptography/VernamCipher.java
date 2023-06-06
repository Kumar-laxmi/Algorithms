/*
 ------------------------------------------------ Prerequisite -----------------------------------------------------------

    --> The length of the key should be equal to the length of the text message going to be sent.

 ---------------------------------------------- Problem Statement --------------------------------------------------------

    Given a string which needed to be encrypted based on vernam cipher and decrypt it.

    INPUT  :- Steve Rogers

    OUTPUT :- UTTOM EQGTKA  --> Encrypted text
              Steve Rogers  --> Decrypted text

 ------------------------------------------------ Vernam Cipher ----------------------------------------------------------

    The Vernam cipher is a substitution cipher where each plain text character is encrypted using its own key.
    This key — or key stream — is randomly generated or is taken from a one-time pad, e.g. a page of a book.
    The key must be equal in length to the plain text message. The fact that each character of the message is encrypted
    using a different key prevents any useful information being revealed through a frequency analysis of the cipher text.

 ------------------------------------------------- Algorithm -------------------------------------------------------------

    1) Obtain the 8-bit ASCII code for each letter of the plain text

    2) Obtain the 8-bit ASCII code for each letter of the key

    3) Carry out the XOR operation, applying it to each corresponding pair of bits

    4) Obtain the binary code for each character of the cipher text

    5) Obtain the 8-bit ASCII code for each letter of the key

    6) Carry out the XOR operation, applying it to each corresponding pair of bits it will decrypt the message.

 ------------------------------------------------ Complexities -----------------------------------------------------------

    Time Complexity  :- BigO(n)  --> where n is the length of the string
    Space Complexity :- BigO(26) --> Since we need an additional string to store all the alphabets, it's length is 26.

 */
import java.util.Scanner; // Importing scanner class to get input from user.
public class VernamCipher{
    public static void main(String[] args) {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);
        // Reading the text message from the user which is needed to be encrypted.
        System.out.print("Enter the text message = ");
        String text = sc.nextLine();
        // Calling the key generation method to generate a key
        keyGeneration(text);
    }
    // Method that generates a random key whose length will be as same as the text message.
    private static void keyGeneration(String text) {
        // Finding the length of the text message.
        int length = text.length();
        // Initializing a variable alphabet so that we can know the index numbers of the A-Z letters.
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Initializing a empty string variable to store the key
        String key = "";
        // Loop that generates the key.
        for(int i = 0; i < length; i++)
        {
            int key_index = (int)(Math.random()*25);
            key += alphabet.charAt(key_index);
        }
        //Printing the key
        System.out.println("The key = "+ key);
        // Calling the encryption method to encrypt the text.
        encryption(text,key);
    }
    private static void encryption(String text, String keyword) {
        // Initializing a variable alphabet so that we can know the index numbers of the A-Z letters.
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Converting the lowercase letters to uppercase letters
        String texts = text.toUpperCase();
        // Initializing a empty string variable to store the encrypted message
        String encrypted = "";
        // Loop to iterate through the text and encrypt it based on the index numbers of the letters.
        for (int i=0;i<texts.length();i++)
        {
            // If the character of the text is not alphabet then we are not going to touch that.
            int ascii = (int)texts.charAt(i);
            if(!(ascii>64 && ascii<91))
            {
                // Simply adding the non alphabet character to the string encrypted
                encrypted+=texts.charAt(i);
                continue;
            }
            // Storing the index of the characters of the message and keyword.
            int text_number = alphabet.indexOf(texts.charAt(i));
            int key_number = alphabet.indexOf(keyword.charAt(i));
            // Encryption of the text character
            int encrypt_number = (text_number+key_number)%26;
            // Storing encrypted text to a variable encrypted.
            encrypted+=alphabet.charAt(encrypt_number);
        }
        //Printing the encrypted string
        System.out.println("Encrypted text is = " + encrypted);
        // Calling the function to decrypt the message.
        decryption(text,encrypted,keyword);
    }
    // Method to decrypt the message.
    private static void decryption(String text,String encrypted, String keywords) {
        // Initializing a variable alphabet so that we can know the index numbers of the A-Z letters.
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Initializing a empty string variable to store the decrypted message
        String decrypted = "";
        // Loop to iterate through the text and decrypt it based on the index numbers of the letters.
        for (int i=0;i<encrypted.length();i++)
        {
            // If the character of the text is not alphabet then we are not going to touch that.
            int ascii = (int)encrypted.charAt(i);
            if(!(ascii>64 && ascii<91))
            {
                // Simply adding the non alphabet character to the string encrypted
                decrypted+=encrypted.charAt(i);
                continue;
            }
            // Storing the index of the characters of the message and keyword.
            int text_number = alphabet.indexOf(encrypted.charAt(i));
            int key_number = alphabet.indexOf(keywords.charAt(i));
            // Decryption of the encrypted text character
            int encrypt_number = (text_number-key_number)%26;
            if(encrypt_number<0)
            {
                encrypt_number=26+encrypt_number;
            }
            // Since the message is the combination of both upper and lower case we have to decrypt it based on it.
            if(Character.isLowerCase(text.charAt(i)))
            {
                char temp = alphabet.charAt(encrypt_number);
                temp = Character.toLowerCase(temp);
                decrypted+=temp;
            }
            else
            {
                decrypted+=alphabet.charAt(encrypt_number);
            }
        }
        // Printing the decrypted string.
        System.out.println("The decrypted text is = " + decrypted);
    }
}