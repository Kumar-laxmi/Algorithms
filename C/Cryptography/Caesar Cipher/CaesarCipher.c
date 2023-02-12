/*Definition:
 Caesar Cipher is a simple substitution cipher that replaces each letter in the plaintext 
 with a letter shifted a certain number of places down the alphabet. For example, with a 
 shift of 1, A would be replaced by B, B would become C, and so on
 
Input: 
 Opton: First the code asks for Encryption or decryption. 
 Plain text: On choosing encrypt the code asks for plaintext.
 Cipher text: On choosing decrypt the code asks for cipher text to decrypt. 
 Shift value: The code asks for a shift value which shifts the alphabet by that number.
Output: 
 On choosing encrypt the output will be a string called cipher text. And on choosing decryption 
 the output will be plaintext.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*This is the function to encrypt the message*/
void encrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            char ch = (char) (message[i] + shift);
            if (islower(message[i])) {
                if (ch > 'z') {
                    ch = (char) (ch - 26);
                }
            } else {
                if (ch > 'Z') {
                    ch = (char) (ch - 26);
                }
            }
            message[i] = ch;
        }
    }
}

/*This is the function to decrypt the cipher text*/
void decrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            char ch = (char) (message[i] - shift);
            if (islower(message[i])) {
                if (ch < 'a') {
                    ch = (char) (ch + 26);
                }
            } else {
                if (ch < 'A') {
                    ch = (char) (ch + 26);
                }
            }
            message[i] = ch;
        }
    }
}

int main() {
    int choice, shift;
    char message[100];

    /*Asks you if you want to encrypt a message or decrypt a ciphertxt*/
    printf("1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    /*In case Encrypt is chosen. it asks for a plaintext to encrypt and shift value which is used to shift the alphabets*/
    if (choice == 1) {
        printf("Enter a message to be encrypted: ");
        fgets(message, 100, stdin);
        message[strlen(message) - 1] = '\0';
        printf("Enter a shift value: ");
        scanf("%d", &shift);

        /*Here encryption of the message is done and the output obtained is a cipher text*/
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {

        /*In case Decrypt is chosen the code asks for a cipher text to decrypt and a shift value which is used to shift the alphabets*/
        printf("Enter a message to be decrypted: ");
        fgets(message, 100, stdin);
        message[strlen(message) - 1] = '\0';
        printf("Enter a shift value: ");
        scanf("%d", &shift);

        /*Here the decryption of cipher text is done and the output obtained is a plaintext*/
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
