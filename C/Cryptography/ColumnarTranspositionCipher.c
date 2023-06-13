#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Key for Columnar Transposition
const char key[] = "HACK";
int keyMap[MAX_SIZE];

void setPermutationOrder()
{
    // Add the permutation order into the map
    for (int i = 0; i < strlen(key); i++)
    {
        keyMap[key[i]] = i;
    }
}

// Encryption
void encryptMessage(char msg[], char cipher[])
{
    int row, col, j;
    char matrix[MAX_SIZE][MAX_SIZE] = {'\0'};

    // Calculate the number of columns in the matrix
    col = strlen(key);

    // Calculate the maximum number of rows in the matrix
    row = strlen(msg) / col;

    if (strlen(msg) % col != 0)
    {
        row += 1;
    }

    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (j = 0; j < col;)
        {
            if (msg[k] == '\0')
            {
                // Adding the padding character '_'
                matrix[i][j] = '_';
                j++;
            }

            if (isalpha(msg[k]) || msg[k] == ' ')
            {
                // Adding only space and alphabets into the matrix
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }

    int index = 0;
    for (int l = 0; key[l] != '\0'; l++)
    {
        keyMap[key[l]] = index++;
    }

    k = 0;
    for (int l = 0; key[l] != '\0'; l++)
    {
        j = keyMap[key[l]];
        for (int i = 0; i < row; i++)
        {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
            {
                cipher[k++] = matrix[i][j];
            }
        }
    }
    cipher[k] = '\0';
}

// Decryption
void decryptMessage(char cipher[], char decryptedMsg[])
{
    int col = strlen(key);

    int row = strlen(cipher) / col;
    char cipherMat[MAX_SIZE][MAX_SIZE];

    int k = 0;
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cipherMat[i][j] = cipher[k++];
        }
    }

    int index = 0;
    for (int l = 0; key[l] != '\0'; l++)
    {
        keyMap[key[l]] = index++;
    }

    char decCipher[MAX_SIZE][MAX_SIZE];
    int l = 0, j;
    for (; key[l] != '\0';)
    {
        j = keyMap[key[l++]];
        for (int i = 0; i < row; i++)
        {
            decCipher[i][j] = cipherMat[i][l - 1];
        }
    }

    // Getting message using matrix
    k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j1 = 0; j1 < col; j1++)
        {
            if (decCipher[i][j1] != '_')
            {
                decryptedMsg[k++] = decCipher[i][j1];
            }
        }
    }
    decryptedMsg[k] = '\0';
}

int main()
{
    char msg[MAX_SIZE];
    char cipher[MAX_SIZE];
    char decryptedMsg[MAX_SIZE];

    printf("Enter the Plain Text: ");
    scanf("%[^\n]s", msg);

    setPermutationOrder();

    // Calling encryption function
    encryptMessage(msg, cipher);
    printf("Encrypted Message: %s\n", cipher);

    // Calling Decryption function
    decryptMessage(cipher, decryptedMsg);
    printf("Decrypted Message: %s\n", decryptedMsg);

    return 0;
}
