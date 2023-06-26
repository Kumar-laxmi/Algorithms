//AFFINE CIPHER
//The Affine cipher is a standard substitution cipher.
//Encryption:
//        Cipher Text, C=(aX+b) mod 26
//        where a, b are key values and X is letter to be encrypted.
//Decryption:
//        Plain Text, X=[a^-1(C-b)] mod 26
//        where alphabets from (a-z) are numbered sequentially from (0-25).

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a, b; //Key values for affine cipher
int m = 26;

string cipher(const string& plainText) {
    string ciphertext;
    for (size_t i = 0; i < plainText.length(); i++) {
    char t = plainText[i];
    int alphaVal = t - 'a'; // 'a' has ASCII value 97
    int c = (a * alphaVal + b) % m;
    char changedChar = c + 'a';
    ciphertext += changedChar;
}

    return ciphertext;
}

string decipher(const string& ciphertext) {
    string plaintext;
    int inverseA;
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            inverseA = i;
            break;
        }
    }

 for (size_t i = 0; i < ciphertext.length(); i++) {
    char c = ciphertext[i];
    int alphaVal = c - 'a';
    int decipherT = (inverseA * (alphaVal - b + m)) % m;
    char changedChar = decipherT + 'a';
    plaintext += changedChar;
}

    return plaintext;
}

bool isCoprime(int a, int b) {
    int gcd = __gcd(a, b);
    return gcd == 1;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Should not reach here if a and m are coprime
}

int main() {
    cout << "Enter plain text: ";
    string plainText;
    getline(cin, plainText);

    cout << "Enter keys a and b: ";
    cin >> a >> b;

    if (!isCoprime(a, m)) {
        cout << "Key 'a' and modulus 'm' are not coprime. Choose different keys.\n";
        return 0;
    }

    string ciphertext = cipher(plainText);
    cout << "Cipher text:\n" << ciphertext << "\n";

    string decryptedText = decipher(ciphertext);
    cout << "Decrypted text:\n" << decryptedText << "\n";

    return 0;
}

