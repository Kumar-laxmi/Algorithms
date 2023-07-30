// Path: C\Cryptography\playfair_cipher.c
// C program to implement playfair cipher algorithm.

// The Playfair cipher algorithm is a symmetric encryption technique that uses a 5x5 grid of letters to encrypt plaintext.
// It employs the rules of letter substitution and rearrangement based on pairs of letters to generate ciphertext.

// Rules for Encryption using playfair cipher Algorithm
// 1). 5 X 5 matrix -> Table
// 2). Digraphs (3 conditions):
// i). same row
// ii). same column
// iii). different row and column

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include<ctype.h>

// Size of the table
#define SIZE 5

// Function to prepare the input string
void prepareString(char *line)
{
    int i;
    int len = strlen(line);
    for (i = 0; i < len; i++)
    {
        line[i] -= 32;
        if (line[i] == 'J')
            line[i] = 'I';
        else if (line[i] == ' ')
            strcpy(&line[i], &line[i + 1]);
    }
    line[i] = '\0';
}

// Function to construct the table based on the key
void constructTable(char *key, char table[][SIZE])
{
    int visited[26] = {0};
    int row = 0, col = 0, i;

    // First, fill the key in the table
    int len = strlen(key);
    for (i = 0; i < len; i++)
    {
        if (visited[key[i] - 'A'] == 0)
        {
            table[row][col] = key[i];
            visited[key[i] - 'A'] = 1;
            if (col == SIZE - 1)
            {
                row++;
                col = 0;
            }
            else
                col++;
        }
    }

    // Then, fill the remaining characters from A to Z
    for (i = 0; i < 26; i++)
    {
        if (visited[i] == 0)
        {
            if (i + 'A' == 'J')
                continue;
            table[row][col] = i + 'A';
            visited[i] = 1;
            if (col == SIZE - 1)
            {
                row++;
                col = 0;
            }
            else
                col++;
        }
    }
}

// Function to split the plain text into digraphs
char *digraphPlainText(char *plainText)
{
    int i, j = 0;
    int len = strlen(plainText);
    char *res = (char *)malloc((2 * len + 1) * sizeof(char));

    for (i = 0; i < len; i++)
    {
        if (i == len - 1 || plainText[i] == plainText[i + 1])
        {
            res[j++] = plainText[i];
            res[j++] = 'X';
        }
        else
        {
            res[j++] = plainText[i];
            res[j++] = plainText[i + 1];
            i++;
        }
    }
    res[j] = '\0';
    return res;
}

// Function to get the coordinates of a character in the table
void getCoordinates(char table[][SIZE], char ch, int *row, int *col)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (table[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
    *row = -1;
    *col = -1;
}

// Function to encrypt the plain text
void encrypt(char *plainText, char table[][SIZE], char *cipherText)
{
    int i = 0, j = 0;
    int len = strlen(plainText);

    while (i < len - 1)
    {
        int row1, col1, row2, col2;
        getCoordinates(table, plainText[i], &row1, &col1);
        getCoordinates(table, plainText[i + 1], &row2, &col2);

        // Case 1: Same row
        if (row1 == row2)
        {
            col1 = (col1 + 1) % SIZE;
            col2 = (col2 + 1) % SIZE;
        }
        // Case 2: Same column
        else if (col1 == col2)
        {
            row1 = (row1 + 1) % SIZE;
            row2 = (row2 + 1) % SIZE;
        }
        // Case 3: Rectangle
        else
        {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        cipherText[j++] = table[row1][col1];
        cipherText[j++] = table[row2][col2];
        i += 2;
    }
    cipherText[j] = '\0';
}

int main()
{
    char key[SIZE * SIZE], plainText[100], cipherText[100];
    char table[SIZE][SIZE];

    printf("Enter Key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Enter Plain Text: ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0';

    prepareString(key);
    prepareString(plainText);

    constructTable(key, table);
    char *digraphPlain = digraphPlainText(plainText);

    printf("\nCipher text: ");
    encrypt(digraphPlain, table, cipherText);
    printf("%s\n", cipherText);

    printf("\nDeciphered text: %s\n", digraphPlain);

    return 0;
}