/*
Diffie-Hellman key exchange is a method of digital encryption that securely exchanges cryptographic keys 
between two parties over a public channel without their conversation being transmitted over the internet.
The two parties use symmetric cryptography to encrypt and decrypt their messages.

The values of P and G are fixed to 23 and 5 respectively.

shared secret is the same for both Alice and Bob, which allows them to communicate securely using this 
shared secret as a symmetric key for encryption and decryption.

![Screenshot (358)](https://user-images.githubusercontent.com/80022302/225057307-de493fae-448a-482c-b1e7-e73dee946ceb.png)


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P 23 // modulus
#define G 5  // base

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
    int a, b; // private keys
    int A, B; // public keys
    int secretA, secretB; // shared secrets

    // Alice's private key
    printf("Enter Alice's private key: ");
    scanf("%d", &a);

    // Bob's private key
    printf("Enter Bob's private key: ");
    scanf("%d", &b);

    // Alice's public key
    A = power(G, a, P);
    printf("Alice's public key: %d\n", A);

    // Bob's public key
    B = power(G, b, P);
    printf("Bob's public key: %d\n", B);

    // shared secrets
    secretA = power(B, a, P);
    secretB = power(A, b, P);

    printf("Shared secret between Alice and Bob: %d\n", secretA);
    printf("Shared secret between Bob and Alice: %d\n", secretB);

    return 0;
}

