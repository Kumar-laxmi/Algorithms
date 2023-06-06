/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    First line of the input consist of text that is to be encrypted and second line of input consist of depth of the rail
    fence and the first line of output consist of encrypted text and second line is the decrypted text.

    INPUT  :- Money Power Women Drugs!!! --> Text Message
              3                          --> Depth of the rail fence
    OUTPUT :- MywWnu!oe oe oe rg!!nPrmDs --> Encrypted text for the depth of rail fence.
              Money Power Women Drugs!!! --> Decrypted text

 ---------------------------------------------- Rail Fence Cipher --------------------------------------------------------

    Rail fence cipher comes under the category of transposition cipher. As the name says the text is encoded in a rail fence
    form (ie, zigzag form). Since the user only sees the encrypted text the user doesn't know about that the text is encoded
    in this algorithm only.

 ------------------------------------------------ Complexities -----------------------------------------------------------

    Time Complexity  :- BigO(n*m)
    Space Complexity :- BigO(n*m)

 */
import java.util.Scanner; // Import Scanner class to get input from the user
public class Rail_Fence_Cipher {
    // Main Class
    public static void main(String[] args) {
        // Initializing the scanner class
        Scanner sc = new Scanner(System.in);

        // Reading the text message from the user
        System.out.print("Enter the text :- ");
        String text = sc.nextLine();

        // Reading the depth of the zigzag pattern
        System.out.print("Enter the key value:- ");
        int key = sc.nextInt();

        // Calling the encrypt method to encrypt the message
        encryption(text,key);
    }

    // The encryption method which encrypts the text
    private static void encryption(String text, int key) {
        // Initializing the encrypted text to empty which is used to save the encrypted text at the end.
        String encrypted_text = "";

        // Changing the direction to down or up of the zigzag pattern to put the values.
        boolean direction =  false;

        // The matrix column is the value of the key which is the length of the text of the zigzag.
        int column = text.length();

        // Variable to iterate over the matrix created.
        int j =0;

        // Initializing the char array to store the zigzag formation.
        char[][] a = new char[key][column];

        // The for loop which puts the character of the text to railfence form.
        for(int i=0;i<column;i++)
        {
            // If the value of j reaches the bottom or the j == 0 of the matrix we have to change the direction.
            if( j==0 || j == key-1)
            {
                direction = !direction;
            }
            // We have to add the characters of the message given by the user in the rail fence form of diagnols is done here.
            a[j][i] = text.charAt(i);
            // If we want to change direction of rail fence is done by this condition.
            if(direction)
            {
                j++;
            }
            else
            {
                j--;
            }
        }

        // Adding the characters of the message to the diagnols to form rail fence form is done by this.
        for(int i = 0; i< key; i++)
        {
            for(int k=0;k<column;k++)
            {
                if(a[i][k]!=0)
                {
                    encrypted_text+=a[i][k];
                }
            }
        }

        // Printing the encrypted text.
        System.out.println("Encrypted text = " + encrypted_text);

        // Calling the decryption method to decrypt the encrypted text.
        decryption(encrypted_text,key);
    }

    // Method which implements the decryption of the encrypted text.
    private static void decryption(String encrypted_text, int key) {
        // Initializing the decrypted text to empty which is used to save the decrypted text at the end.
        String decrypted_text = "";

        // Changing the direction to down or up to put the values.
        boolean direction =  false;

        // The matrix column is the value of the key which is the length of the text of the zigzag.
        int column = encrypted_text.length();

        // Variable to iterate over the matrix created.
        int j =0;

        // Initializing the char array to store the zigzag formation.
        char[][] a = new char[key][column];

        // Converting the encrypted text to the railfence form.
        for(int i=0;i<column;i++)
        {
            // If the value of j reaches the bottom or the j == 0 of the matrix we have to change the direction.
            if( j==0 || j == key-1)
            {
                direction = !direction;
            }
            // Putting the symbol of asterik in rail fence order
            a[j][i] = '*';
            // If we want to change direction of rail fence is done by this condition.
            if(direction)
            {
                j++;
            }
            else
            {
                j--;
            }
        }

        // Since we have changed the direction variable we have to set it to false.
        direction = false;

        // Initializing the index variable which puts the encrypted text into rail fence form in matrix.
        int index = 0;

        // Loop to put the encrypted text in rail fence form in place of asterik symbol.
        for(int i = 0; i< key; i++)
        {
            for(int k =0;k<column;k++)
            {
                if(a[i][k] == '*' && index<column)
                {
                    a[i][k] = encrypted_text.charAt(index++);
                }
            }
        }

        // Since we have changed the variable j we have to set it to 0.
        j=0;
        for(int i=0;i<column;i++)
        {
            // Changing the direction variable when it is not in place of text.
            if( j==0 || j == key-1)
            {
                direction = !direction;
            }
            // Assigning the characters of text in rail fence order to the decrypted text variable.
            decrypted_text+=a[j][i];
            // Changing the value of j until it is in place of a character.
            if(direction)
            {
                j++;
            }
            else
            {
                j--;
            }
        }

        // Printing the decrypted text.
        System.out.println("Decrypted text :- " + decrypted_text);
    }
}