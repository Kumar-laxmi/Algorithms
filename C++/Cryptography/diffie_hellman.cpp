/*
Diffie-Hellman key exchange is a method of digital encryption that securely exchanges cryptographic keys 
between two parties over a public channel without their conversation being transmitted over the internet.
The two parties use symmetric cryptography to encrypt and decrypt their messages.

The values of P and G are fixed to 23 and 5 respectively.

shared secret is the same for both Alice and Bob, which allows them to communicate securely using this 
shared secret as a symmetric key for encryption and decryption.

![Screenshot (359)](https://user-images.githubusercontent.com/80022302/225057920-7fba4d37-65cd-446a-85f3-2679cb5ea983.png)

*/




#include <iostream>
#include <cmath>

using namespace std;

int power(int a, int b, int p) {
    int result = 1;
    a = a % p;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % p;
        b = b >> 1;
        a = (a * a) % p;
    }
    return result;
}

int main() {
    int p = 23; // modulus
    int g = 5;  // base
    int a, b;   // private keys
    int A, B;   // public keys
    int secretA, secretB; // shared secrets

    // Alice's private key
    cout << "Enter Alice's private key: ";
    cin >> a;

    // Bob's private key
    cout << "Enter Bob's private key: ";
    cin >> b;

    // Alice's public key
    A = power(g, a, p);
    cout << "Alice's public key: " << A << endl;

    // Bob's public key
    B = power(g, b, p);
    cout << "Bob's public key: " << B << endl;

    // shared secrets
    secretA = power(B, a, p);
    secretB = power(A, b, p);

    cout << "Shared secret between Alice and Bob: " << secretA << endl;
    cout << "Shared secret between Bob and Alice: " << secretB << endl;

    return 0;
}

