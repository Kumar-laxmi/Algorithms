#include <cmath>
#include <iostream>

using namespace std;

// Power function to return value of a ^ b mod P
long long int power(long long int base, long long int exponent, long long int modulus)
{
    if (exponent == 1)
        return base;
    else
        return (((long long int)pow(base, exponent)) % modulus);
}

// Driver program
int main()
{
    long long int prime, primitive_root, private_key_user1, private_key_user2, public_key_user1, public_key_user2, secret_key_user1, secret_key_user2;

    // Both the persons will agree upon the public keys: prime and primitive_root
    cout << "Enter a prime number (P): ";
    cin >> prime;

    cout << "Enter a primitive root (G) for P: ";
    cin >> primitive_root;

    // User 1 will choose the private key
    cout << "Enter the private key for User 1: ";
    cin >> private_key_user1;

    long long int generated_key_user1 = power(primitive_root, private_key_user1, prime); // gets the generated key

    // User 2 will choose the private key
    cout << "Enter the private key for User 2: ";
    cin >> private_key_user2;

    long long int generated_key_user2 = power(primitive_root, private_key_user2, prime); // gets the generated key

    // Generating the public keys
    public_key_user1 = generated_key_user1;
    public_key_user2 = generated_key_user2;

    cout << "\nPublic key of User 1: " << public_key_user1 << endl;
    cout << "Public key of User 2: " << public_key_user2 << endl;

    // Generating the secret keys
    secret_key_user1 = power(public_key_user2, private_key_user1, prime); // Secret key for User 1
    secret_key_user2 = power(public_key_user1, private_key_user2, prime); // Secret key for User 2

    cout << "\nSecret key for User 1: " << secret_key_user1 << endl;
    cout << "Secret key for User 2: " << secret_key_user2 << endl;

    return 0;
}
