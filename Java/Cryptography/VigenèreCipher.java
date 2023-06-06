/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    Given a string which needed to be encrypted based on vigenère cipher and decrypt it.

    INPUT  :- Steve Rogers

    OUTPUT :- UTTOM EQGTKA  --> Encrypted text
              Steve Rogers  --> Decrypted text

 ------------------------------------------------ Vigenère Cipher --------------------------------------------------------

    Vigenère cipher uses a keyword to encrypt a message by replacing each letter of the message with a letter that is shifted
    a certain number of places down the alphabet based on the corresponding letter of the keyword. The same keyword is used
    for each letter of the message but shifted to a different position for each letter of the message. This makes the
    Vigenère cipher much more secure than simple substitution ciphers, such as the Caesar cipher.

 --------------------------------------------------- Algorithm -----------------------------------------------------------

    1 The plaintext message and the keyword are both converted to uppercase.

    2 The alphabet is defined, usually as the 26 letters, all uppercase in English alphabet.

    3 For each letter in the plaintext message, the corresponding letter in the keyword is found.

    4 The index of the plaintext letter in the alphabet is added to the index of the keyword letter
      in the alphabet (modulo 26) to get the index of the encrypted letter in the alphabet.

    5 The encrypted letter is the letter at the calculated index in the alphabet.

    6 The above process is repeated for each of the letters in the plaintext.

 --------------------------------------------------- Complexities --------------------------------------------------------

    Time Complexity  :- BigO(n) --> where n is the length of the string
    Space Complexity :- BigO(26) --> Since we need an additional string to store all the alphabets, it's length is 26.

 */
import java.util.Scanner; // Importing scanner class to get input from user.
public class VigenèreCipher {
    public static void main(String[] args) {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);
        // Reading the text message from the user which is needed to be encrypted.
        System.out.print("Enter the text message = ");
        String text = sc.nextLine();
        // Reading the key from the user which is used to encrypt and decrypt the user message
        System.out.print("Enter the key text = ");
        String keyword = sc.nextLine();
        // Calling the method to generate the keyword to encrypt and decrypt the key
        keywordGeneration(text,keyword);
    }
    // Method to generate keyword
    private static void keywordGeneration(String text, String keyword) {
        // Initializing a iterating variable
        int i = 0;
        // Loop to iterate until the length of the text and keyword matches.
        while (text.length() != keyword.length()) {
            i = i % keyword.length();
            keyword += keyword.charAt(i++);
        }
        // Calling the encryption method to encrypt the text.
        encryption(text,keyword);
    }
    // Method to encrypt the text message.
    private static void encryption(String text, String keyword) {
        // Initializing a variable alphabet so that we can know the index numbers of the A-Z letters.
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // Converting the lowercase letters to uppercase letters
        String texts = text.toUpperCase();
        String keywords = keyword.toUpperCase();
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
            int key_number = alphabet.indexOf(keywords.charAt(i));
            // Encryption of the text character
            int encrypt_number = (text_number+key_number)%26;
            // Storing encrypted text to a variable encrypted.
            encrypted+=alphabet.charAt(encrypt_number);
        }
        //Printing the encrypted string
        System.out.println("Encrypted text is = " + encrypted);
        // Calling the function to decrypt the message.
        decryption(text,encrypted,keywords);
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