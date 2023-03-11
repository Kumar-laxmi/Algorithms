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

    4) Choose "e" such that 1<e < ? (n), e is prime to ? (n),

                                          gcd (e,d(n)) =1

    4) If n = p x q, then the public key is <e, n>. A plaintext message m is encrypted using a public key <e, n>.
       To find ciphertext from the plain text following formula is used to get ciphertext C.

                                           C = me mod n

        Here, m must be less than n. A larger message (>n) is treated as a concatenation of messages, each of which is
        encrypted separately.
    5) To determine the private key, we use the following formula to calculate the d such that:

                                    de mod {(p - 1) x (q - 1)} = 1
                                                Or
                                        de mod ? (n) = 1

    6) The private key is <d, n>. A ciphertext message c is decrypted using a private key <d, n>. To calculate
       plain text m from the ciphertext c following formula is used to get plain text m.

                                          m = cd mod n

 ------------------------------------------------ Complexities -----------------------------------------------------------

    Time Complexity  :- BigO(n^3)
    Space Complexity :- BigO(n)

 */
#include<bits/stdc++.h>
using namespace std;
// Declaring the global variables.
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
// Declaring the methods that are going to be used.
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
// Method to check whether the number is prime or not.
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
        {
        	return 0;	
		}
    }
    return 1;
}
int main()
{
	// Reading the first number
    cout << "Enter first prime number = ";
    cin >> p;
    flag = prime(p);
    // Checking whether the number is prime or not.
    if (flag == 0)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    // Reading the second number
    cout << "Enter second prime number = ";
    cin >> q;
    flag = prime(q);
    // Checking whether the number is prime or not.
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    // Reading the message from the user.
    cout << "Enter message = ";
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != '\0'; i++)
    {
    	m[i] = msg[i];	
	}
    // Calculating the relatively prime number's multiple
    n = p * q;
    // Calculating the psi of the two numbers.
    t = (p - 1) * (q - 1);
    // Calling the method to calculate the possible values of the public and private keys.
    ce();
    // Calling the encrypt function to perfrom the encryption.
    encrypt();
    // Calling the decryption function to perform the decryption.
    decrypt();
    return 0;
}
// Method to calculate the possible values of the public and private keys.
void ce()
{
	// Initialing the iterating variables. 
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
        {
            continue;	
		}
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
            {
            	break;
			}
        }
    }
}
// Method to check whether the gcd = 1
long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
        {
        	return (k / x);	
		}
    }
}
// Method to encrypt the text message.
void encrypt()
{
	// Initialing the iterating variables.
    long int pt, ct, key = e[0], k, len;
    i = 0;
    // Calculating the length using length function.
    len = strlen(msg);
    // Loop that encrypts the text.
    while (i != len)
    {
    	// Converting the character to long int type.
        pt = m[i];
        pt = pt - 96;
        k = 1;
        // Encrypting the character taken.
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    // Printing the encrypted message.
    cout <<"The encrypted message is = ";
    for (i = 0; en[i] != -1; i++)
    {
		cout<<static_cast<char>(en[i]);	
	}
}
// Method to decrypt the encrypted message.
void decrypt()
{
	// Initialing the iterating variables.
    long int pt, ct, key = d[0], k;
    i = 0;
    // Loop that encrypts the text.
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        // Decrypting the character taken.
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    // Printing the decrypted message.
    cout << "\nThe decrypted message is = ";
    for (i = 0; m[i] != -1; i++)
    {
        cout<<static_cast<char>(m[i]);
	}
}
