/*
 ------------------------------------------------ Prerequisite -----------------------------------------------------------

    --> The message should be in the form of, if the is number of letters in key is even then the number of letters in
        the text should also be even (similarly for odd) for smooth message transfer.

 ---------------------------------------------- Problem Statement --------------------------------------------------------

    Given a string which needed to be encrypted based on hill cipher and decrypt it.

    INPUT  :- Password  --> Text message
              text      --> Key

    OUTPUT :- ZHYCGSXG  --> Encrypted text
              Password  --> Decrypted text

 -------------------------------------------------- Hill Cipher -----------------------------------------------------------

    Hill cipher is a poly graphic substitution cipher based on linear algebra.Each letter is represented by a number modulo 26.
    Often the simple scheme A = 0, B = 1, …, Z = 25 is used, but this is not an essential feature of the cipher. To encrypt
    a message, each block of n letters (considered as an n-component vector) is multiplied by an invertible n × n matrix,
    against modulus 26. To decrypt the message, each block is multiplied by the inverse of the matrix used for encryption.
    The matrix used for encryption is the cipher key, and it should be chosen randomly from the set of invertible
    n × n matrices (modulo 26).

 --------------------------------------------------- Algorithm -----------------------------------------------------------

    1) Our key is text (2x2), Convert this key using a substitution scheme into a 2x2 key matrix

    2) We will convert our plain text into vector form. Since the key matrix is 2x2, the vector must be 2x1 for matrix multiplication.
      (Suppose the key matrix is 3x3, a vector will be a 3x1 matrix.)

    3) Multiply the key matrix with each 2x1 plain text vector, and take the modulo of result (2x1 vectors) by 26.
       Then concatenate the results.

    4) Calculate the inverse of the key matrix. First, we need to find the determinant of the key matrix (must be between 0-25)
       The Extended Euclidean algorithm is used to get modulo multiplicative inverse of key matrix determinant

    5) we multiply the 2x1 blocks of ciphertext and the inverse of the key matrix. The resultant block after concatenation
       is the plain text that we have encrypted.

 --------------------------------------------------- Complexities --------------------------------------------------------

    Time Complexity  :- BigO(n^2) --> Traversing a 2D array message matrix.
    Space Complexity :- BigO(n^2) --> A 2D array is required for storing the message.

 */
import java.util.Scanner; // Importing scanner class to get input from user.
public class HillCipher
{
    public static void main(String[] args) 
    {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);
        // Reading the text message from the user which is needed to be encrypted.
        System.out.print("Enter the text message = ");
        String text = sc.nextLine();
        // Reading the key from the user which is used to encrypt and decrypt the user message
        System.out.print("Enter a key = ");
        String key = sc.nextLine();
        // Calling the method to encrypt the message of the usr.
        encryption(text,key);
    }
    // Method that encrypt the user message.
    private static void encryption(String text, String key) 
    {
        // Storing the text message in temp string.
        String text_message = text;
        // Converting the lowercase letters to uppercase letters
        text = text.toUpperCase();
        key = key.toUpperCase();
        // If the text length is odd making it even.
        int lenChk = 0;
        if (text.length() % 2 != 0)
        {
            text += "0";
            lenChk = 1;
        }
        // Initializing a 2D matrix of length of key as row and text message length as column.
        int[][] text2D = new int[2][text.length()];
        // Initializing the iterating variables to look into the 2D array of text message.
        int itr1 = 0;
        int itr2 = 0;
        // Converting the messages into array form.
        for (int i = 0; i < text.length(); i++)
        {
            if (i%2 == 0)
            {
                text2D[0][itr1] = ((int)text.charAt(i)) - 65;
                itr1++;
            }
            else
            {
                text2D[1][itr2] = ((int)text.charAt(i)) - 65;
                itr2++;
            }
        }
        // Initializing a 2D matrix of length of key as row and column.
        int[][] key2D = new int[2][2];
        // Initializing the iterating variable to look into the 2D array of key.
        int itr3 = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                key2D[i][j] = (int)key.charAt(itr3)-65;
                itr3++;
            }
        }
        // Validating the key
        // Finding determinant of key matrix
        int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
        // Calling the modulo function to perform the modulo operation
        deter = moduloFunction(deter);
        // Calling the multiplicative inverse function to check whether the key is valid or not.
        int mulInverse = multiplicativeInverse(deter);
        // If the key is invalid this condition occurs,
        if (mulInverse == -1)
        {
            System.out.println("invalid key");
            System.exit(1);
        }
        // Empty variable to store the encrypted text.
        String encryptText = "";
        int itrCount = text.length() / 2;
        // If text length % 2 = 0 (ie, regular length text)
        if (lenChk == 0)
        {
            // Loop to perform encryption with the key and add it to the encryptText string.
            for (int i = 0; i < itrCount; i++)
            {
                int temp1 = text2D[0][i] * key2D[0][0] + text2D[1][i] * key2D[0][1];
                encryptText += (char)((temp1 % 26) + 65);
                int temp2 = text2D[0][i] * key2D[1][0] + text2D[1][i] * key2D[1][1];
                encryptText += (char)((temp2 % 26) + 65);
            }
        }
        // If text length % 2 != 0 (ie, irregular length text)
        else
        {
            // Loop to perform encryption with the key and add it to the encryptText string.
            for (int i = 0; i < itrCount-1; i++)
            {
                int temp1 = text2D[0][i] * key2D[0][0] + text2D[1][i] * key2D[0][1];
                encryptText += (char)((temp1 % 26) + 65);
                int temp2 = text2D[0][i] * key2D[1][0] + text2D[1][i] * key2D[1][1];
                encryptText += (char)((temp2 % 26) + 65);
            }
        }
        // Printing the encrypted text.
        System.out.println("Encrypted Text: " + encryptText);
        // Calling the decrypt function to perform the decryption operation.
        decryption(encryptText,key,text_message);
    }
    // Function that decrypts the encrypted text message.
    private static void decryption(String encryptText, String key, String text)
    {
        // If the text length is odd making it even.
        int lenChk = 0;
        if (encryptText.length() % 2 != 0)
        {
            encryptText += "0";
            lenChk = 1;
        }
        // Initializing a 2D matrix of length of key as row and encrypt message length as column.
        int[][] encryptText2D = new int[2][encryptText.length()];
        // Initializing the iterating variables to look into the 2D array of text message.
        int itr1 = 0;
        int itr2 = 0;
        // Converting the encrypted message into array form.
        for (int i = 0; i < encryptText.length(); i++)
        {
            if (i%2 == 0)
            {
                encryptText2D[0][itr1] = ((int)encryptText.charAt(i)) - 65;
                itr1++;
            }
            else
            {
                encryptText2D[1][itr2] = ((int)encryptText.charAt(i)) - 65;
                itr2++;
            }
        }
        // Initializing a 2D matrix of length of key as row and column.
        int[][] key2D = new int[2][2];
        // Initializing the iterating variable to look into the 2D array of key.
        int itr3 = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                key2D[i][j] = (int)key.charAt(itr3)-65;
                itr3++;
            }
        }
        // Validating the key
        // Finding determinant of key matrix
        int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
        // Calling the modulo function to perform the modulo operation
        deter = moduloFunction(deter);
        // Calling the multiplicative inverse function to check whether the key is valid or not.
        int mulInverse = multiplicativeInverse(deter);
        // If the key is invalid this condition occurs,
        if (mulInverse == -1)
        {
            System.out.println("invalid key");
            System.exit(1);
        }
        // Calculating adjugate matrix or adjoint matrix
        // swapping the values
        int swapTemp = key2D[0][0];
        key2D[0][0] = key2D[1][1];
        key2D[1][1] = swapTemp;
        // Changing signs of the value
        key2D[0][1] *= -1;
        key2D[1][0] *= -1;
        // Calling the modulo function to decrypt the message.
        key2D[0][1] = moduloFunction(key2D[0][1]);
        key2D[1][0] = moduloFunction(key2D[1][0]);
        // Multiplying multiplicative inverse with adjoint matrix
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                key2D[i][j] *= mulInverse;
            }
        }
        // Initializing the key with the modulo of the character value.
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                key2D[i][j] = moduloFunction(key2D[i][j]);
            }
        }
        // Initializing an empty string variable to store the decryptText message.
        String decryptText = "";
        int itrCount = encryptText.length() / 2;
        // If text length % 2 = 0 (ie, regular length text)
        if (lenChk == 0)
        {
            // Loop to perform encryption with the key and add it to the encryptText string.
            for (int i = 0; i < itrCount; i++)
            {
                int temp1 = encryptText2D[0][i] * key2D[0][0] + encryptText2D[1][i] * key2D[0][1];
                decryptText += (char)((temp1 % 26) + 65);
                int temp2 = encryptText2D[0][i] * key2D[1][0] + encryptText2D[1][i] * key2D[1][1];
                decryptText += (char)((temp2 % 26) + 65);
            }
        }
        // If text length % 2 != 0 (ie, irregular length text)
        else
        {
            // Loop to perform encryption with the key and add it to the encryptText string.
            for (int i = 0; i < itrCount-1; i++)
            {
                int temp1 = encryptText2D[0][i] * key2D[0][0] + encryptText2D[1][i] * key2D[0][1];
                decryptText += (char)((temp1 % 26) + 65);
                int temp2 = encryptText2D[0][i] * key2D[1][0] + encryptText2D[1][i] * key2D[1][1];
                decryptText += (char)((temp2 % 26) + 65);
            }
        }
        // Using a string buffer class to convert the text into correct case.
        StringBuffer decrypted = new StringBuffer(decryptText);
        // Loop to iterate to change the uppercase letter to lower case letter.
        for(int i=0;i<decryptText.length();i++)
        {
            // Checking it is lower case or not in the message
            if(Character.isLowerCase(text.charAt(i)))
            {
                // Converting the uppercase letter to lower case using string builder.
                decrypted.setCharAt(i, Character.toLowerCase(decryptText.charAt(i)));
            }
        }
        // Printing the decrypted message.
        System.out.println("Decrypted Text: " + decrypted);
    }
    // Function that performs modulo operation.
    private static int moduloFunction(int a)
    {
        // Storing modulo of the value. 
        int result = a % 26;
        // In case the modulo is negative, we are making it as positive by this condition.
        if (result < 0)
        {
            result += 26;
        }
        // Returning the modulo value which is used to find the multiplicative inverse.
        return result;
    }
    // unction that say's that the key is valid or not using multiplicative inverse.
    private static int multiplicativeInverse(int deter)
    {
        // Initializing an iterating variable to store the value of multiplicative inverse
        int mulInverse;
        for (int i = 0; i < 26; i++)
        {
            int tempInv = deter * i;
            // If the modulo of the key value is 1 then the key is suitable for us.
            if (moduloFunction(tempInv) == 1)
            {
                mulInverse = i;
                // Returning the multiplicative inverse
                return mulInverse;
            }
        }
        // In case key is not suitable for us then we will return -1. 
        return -1;
    }
}