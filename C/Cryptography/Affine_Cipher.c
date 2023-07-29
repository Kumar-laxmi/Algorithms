//AFFINE CIPHER:
//The Affine cipher is a standard substitution cipher.
//Encryption:
//        Cipher Text, C=(aX+b) mod 26
//        where a, b are key values and X is letter to be encrypted.
//Decryption:
//        Plain Text, X=[a^-1(C-b)] mod 26
//        where alphabets from (a-z) are numbered sequentially from (0-25).
#include <stdio.h>
#include <string.h>

int a, b;
int m = 26;

int isCoprime(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    return gcd == 1;
}

int modInverse(int a, int m) {
    a = a % m;
    int x;
    for (x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void cipher(const char* plain_text, char* ciphertext) {
    int len = strlen(plain_text);
    for (int i = 0; i < len; i++) {
        char t = plain_text[i];
        int alphaVal = (int)t - 97; // 'a' has ASCII value 97
        int c = (a * alphaVal + b) % m;
        char changedChar = (char)(c + 97);
        ciphertext[i] = changedChar;
    }
    ciphertext[len] = '\0';
}

void decipher(const char* ciphertext, char* plaintext) {
    int len = strlen(ciphertext);
    int inverseA = modInverse(a, m);

    for (int i = 0; i < len; i++) {
        char c = ciphertext[i];
        int alphaVal = (int)c - 97;
        int decipherT = (inverseA * (alphaVal - b + m)) % m;
        char changedChar = (char)(decipherT + 97);
        plaintext[i] = changedChar;
    }
    plaintext[len] = '\0';
}

int main() {
    printf("Enter plain text: ");
    char plainText[100];
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0';

    printf("Enter keys a and b: ");
    scanf("%d %d", &a, &b);

    if (!isCoprime(a, m)) {
        printf("Key 'a' and modulus 'm' are not coprime. Choose different keys.\n");
        return 0;
    }

    char ciphertext[100];
    cipher(plainText, ciphertext);
    printf("Cipher Text after Encryption:\n%s\n", ciphertext);

    char plaintext[100];
    decipher(ciphertext, plaintext);
    printf("Decrypted Text/Plain Text after Decryption:\n%s\n", plaintext);

    return 0;
}

