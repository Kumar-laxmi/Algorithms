/*
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    INPUT :-  23            --> First number
              17            --> Second number
              211           --> GCD of chosen number
              Dharnish38    --> Message to be encrypted

    OUTPUT :- 6 183 97 420 222 315 172 183 74 -52   --> Encrypted message
              Dharnish38                            --> Decrypted message

 ----------------------------------------------- RSA Cryptography --------------------------------------------------------

    Rivest Shamir Adleman (RSA) cryptography algorithm.It s an asymmetric cryptography algorithm. Asymmetric actually means
    that it works on two different keys i.e. Public Key and Private key.

    Example:

            1) A client (for example a browser) sends its public key to the server and requests some data.
            2) The server encrypts the data using the client’s public key and sends the encrypted data.
            3) The client receives this data and decrypts it.

 ------------------------------------------------ RSA Algorithm -----------------------------------------------------------

    1) Select two large prime numbers, p and q.

    2) Multiply these numbers to find n = p x q, where n is called the modulus for encryption and decryption.

    3) Choose a number e less than n, such that n is relatively prime to (p - 1) x (q -1).
       It means that e and (p - 1) x (q - 1) have no common factor except

    4) Choose "e" such that 1<e < φ (n), e is prime to φ (n),

                                          gcd (e,d(n)) =1

    4) If n = p x q, then the public key is <e, n>. A plaintext message m is encrypted using a public key <e, n>.
       To find ciphertext from the plain text following formula is used to get ciphertext C.

                                           C = me mod n

        Here, m must be less than n. A larger message (>n) is treated as a concatenation of messages, each of which is
        encrypted separately.
    5) To determine the private key, we use the following formula to calculate the d such that:

                                    de mod {(p - 1) x (q - 1)} = 1
                                                Or
                                        de mod φ (n) = 1

    6) The private key is <d, n>. A ciphertext message c is decrypted using a private key <d, n>. To calculate
       plain text m from the ciphertext c following formula is used to get plain text m.

                                          m = cd mod n

 ------------------------------------------------ Complexities -----------------------------------------------------------

    Time Complexity  :- BigO(n^3)
    Space Complexity :- BigO(n)

 */
import java.util.Scanner; //Importing scanner class to get input
public class RSA_Algorithm {
    // Declaring static variables so that we can use anywhere in the program
    static Scanner sc;
    static long number1,number2,number;
    static long psi_of_number;
    static long choice;
    static long gcd,t1,t2,mmi;
    static long [] temp;
    static String Plain_Text;
    static long[] encrypted;
    static long[] decrypted;
    public static void main(String[] args)
    {
        //Initializing the scanner class
        sc = new Scanner(System.in);
        // Calling the key generation method to get numbers input and validate them.
        keyGeneration();
    }
    // Method that performs the key generation.
    private static void keyGeneration()
    {
        System.out.println("ENTER TWO LARGE PRIME NUMBERS");
        // Validating whether the numbers' user enters are meeting the condition of gcd = 1;
        while(true)
        {
            // Reading the numbers from the user.
            System.out.print("Enter first number = ");
            number1 = sc.nextLong();
            System.out.print("Enter second number = ");
            number2 = sc.nextLong();
            // Calling the mmi method to check the two numbers are suitable or not.
            long result = modular_multiplicative_inverse(number1,number2);
            // if the numbers are suitable then break
            if(result == 1)
            {
                break;
            }
            // If  numbers are not suitable then we have to re-enter
            else
            {
                System.out.println("\nTHESE NUMBERS ARE NOT CO-PRIME TO EACH OTHER");
                System.out.println("Enter a pair of CO-PRIME numbers,");
            }
        }
        // Calculating the relatively prime number's multiple
        number = number1 * number2;
        // Calculating the psi of the two numbers.
        psi_of_number = (number1- 1) * (number2 - 1);
        // Choosing the value of e which should be inbetween number and psi_of_number and their gcd should be equal to 1
        System.out.println("Choose a number inbetween 1 and "+ psi_of_number);
        System.out.println("THE GCD OF THE CHOOSEN NUMBER AND " + psi_of_number + " SHOULD BE = 1");
        // Checking whether the numbers are co-prime to each other.
        while (true)
        {
            // Reading a number from the given range.
            choice =  sc.nextLong();
            // Check whether the gcd of the number is = 1
            gcd = modular_multiplicative_inverse(choice,psi_of_number);
            // If gcd = 1 then it is suitable.
            if(gcd == 1)
            {
                mmi = ((t1%(psi_of_number)) + psi_of_number)%psi_of_number;
                System.out.println(mmi);
                break;
            }
            // If the chosen number is not suitable then continue the selection of number until suitable.
            System.out.println("The choosen number is not co-prime with the number "+ psi_of_number);
            System.out.print("So, Choose another number = ");
        }
        // Public and Private keys
        System.out.println("\nThe PUBLIC KEY = { " + choice + ", "+ number + " }");
        System.out.println("The PRIVATE KEY = { " + mmi + ", "+ number + " }\n");
        // Encrypting data
        encryption();
    }
    // Method that encrypt the plain message.
    private static void encryption()
    {
        // Initializing the variable to store the encrypted text.
        encrypted = new long[100];
        // Initializing the variable to store the decrypted text.
        decrypted = new long[100];
        temp = new long[100];
        // Initializing the iterating variables.
        long character, encrypt, k;
        // Reading the message from the user.
        System.out.print("Enter the message = ");
        sc.nextLine();
        Plain_Text = sc.nextLine();
        // Initializing the iterating variable.
        int i = 0;
        // Loop that performs the encryption operation.
        while (i != Plain_Text.length())
        {
            // Converting the character to long type.
            character = Plain_Text.charAt(i) - 96;
            k = 1;
            // encrypting the character taken.
            for(int j = 0; j < choice; j++)
            {
                k = (k * character)%number;
            }
            temp[i] = k;
            encrypt = k + 96;
            encrypted[i] = encrypt;
            i++;
        }
        encrypted[i] = -1;
        // Printing the encrypted message.
        System.out.print("\nEncrypted message = ");
        for (i = 0; encrypted[i] != -1; i++)
        {
            System.out.print(encrypted[i] + " ");
        }
        // Calling the decryption function
        decryption();
    }
    // Method that decrypts the encrypted text.
    private static void decryption()
    {
        // Initializing the iterating variables.
        long pt, encrypt, k;
        int i = 0;
        // Loop that performs the decryption operation.
        while (encrypted[i] != -1)
        {
            encrypt = temp[i];
            k = 1;
            for (int j = 0; j < mmi; j++)
            {
                k = (k * encrypt)%number;
            }
            pt = k + 96;
            decrypted[i] = pt;
            i++;
        }
        decrypted[i] = -1;
        //Printing the decrypted message.
        System.out.print("\nDecrypted message = ");
        for (i = 0; decrypted[i] != -1; i++)
        {
            System.out.print((char)decrypted[i]);
        }
        System.out.println();
    }
    // Method that calculates the modular multiplicative inverse.
    private static long modular_multiplicative_inverse(long number, long modulo)
    {
        if(number ==0)
        {
            t1=0;
            t2 = 1;
            return modulo;
        }

        // Finding the remainder of the number with modulo
        long remainder = modulo%number;

        // Recursively calling the function to find gcd so we can say that the mmi exist or not.
        long gcd = modular_multiplicative_inverse(remainder,number);

        // Finding the quotient of the number with modulo
        long quotient = modulo/number;

        // The Extended Euclidean Algorithm
        // To find the value of MMI
        long temp = t1;
        t1 = t2-quotient*t1;
        t2 = temp;

        // Returning the gcd to check whether the inverse exist or not
        return gcd;
    }
}