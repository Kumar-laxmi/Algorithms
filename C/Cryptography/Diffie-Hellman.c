#include <stdio.h>

// Power function to return value of a ^ b mod P
long long int power(long long int base, long long int exponent, long long int modulus)
{
    if (exponent == 1)
        return base;
    else
        return (((long long int)base * base) % modulus);
}

// Driver program
int main()
{
    long long int prime, primitive_root, private_key_user1, private_key_user2, public_key_user1, public_key_user2, secret_key_user1, secret_key_user2;

    // Both the persons will agree upon the public keys: prime and primitive_root
    printf("Enter a prime number (P): ");
    scanf("%lld", &prime);
    printf("Enter a primitive root (G) for P: ");
    scanf("%lld", &primitive_root);
    printf("\n");

    // User 1 will choose the private key
    printf("Enter the private key for User 1: ");
    scanf("%lld", &private_key_user1);
    long long int generated_key_user1 = 1; // Initialize generated_key_user1 with 1
    for (int i = 0; i < private_key_user1; i++)
    {
        generated_key_user1 = power(primitive_root, generated_key_user1, prime); // gets the generated key
    }

    // User 2 will choose the private key
    printf("Enter the private key for User 2: ");
    scanf("%lld", &private_key_user2);
    long long int generated_key_user2 = 1; // Initialize generated_key_user2 with 1
    for (int i = 0; i < private_key_user2; i++)
    {
        generated_key_user2 = power(primitive_root, generated_key_user2, prime); // gets the generated key
    }

    // Generating the public keys
    public_key_user1 = generated_key_user1;
    public_key_user2 = generated_key_user2;

    printf("\nPublic key of User 1: %lld\n", public_key_user1);
    printf("Public key of User 2: %lld\n\n", public_key_user2);

    // Generating the secret keys
    secret_key_user1 = 1; // Initialize secret_key_user1 with 1
    for (int i = 0; i < private_key_user1; i++)
    {
        secret_key_user1 = power(public_key_user2, secret_key_user1, prime); // Secret key for User 1
    }

    secret_key_user2 = 1; // Initialize secret_key_user2 with 1
    for (int i = 0; i < private_key_user2; i++)
    {
        secret_key_user2 = power(public_key_user1, secret_key_user2, prime); // Secret key for User 2
    }

    printf("Secret key for User 1: %lld\n", secret_key_user1);
    printf("Secret key for User 2: %lld\n", secret_key_user2);

    return 0;
}
