// Path: C++\Cryptography\playfair_cipher.cpp
// C++ program to implement playfair cipher algorithm.

// The Playfair cipher algorithm is a symmetric encryption technique that uses a 5x5 grid of letters to encrypt plaintext.
// It employs the rules of letter substitution and rearrangement based on pairs of letters to generate ciphertext.

// Rules for Encryption using playfair cipher Algorithm
// 1). 5 X 5 matrix -> Table
// 2). Digraphs (3 conditions):
// i). same row
// ii). same column
// iii). different row and column

#include <iostream>
#include <string>
using namespace std;

// Size of the table
#define SIZE 5

// Function to prepare the input string
void prepareString(string &line)
{
    for (int i = 0; i < line.length(); i++)
    {
        line[i] -= 32;
        if (line[i] == 'J')
            line[i] = 'I';
        else if (line[i] == ' ')
            line.erase(i, 1);
    }
}

// Function to construct the table based on the key
void constructTable(string &key, char table[][SIZE])
{
    int visited[26] = {0};
    int row = 0, col = 0;

    // First, fill the key in the table
    for (int i = 0; i < key.length(); i++)
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
    for (int i = 0; i < 26; i++)
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
string digraphPlainText(string plainText)
{
    string res = "";
    for (int i = 0; i < plainText.length(); i++)
    {
        if (i == plainText.length() - 1 || plainText[i] == plainText[i + 1])
        {
            res += plainText[i];
            res += 'X';
        }
        else
        {
            res += plainText[i];
            res += plainText[i + 1];
            i++;
        }
    }
    return res;
}

// Function to get the coordinates of a character in the table
void getCoordinates(char table[][SIZE], char ch, int &row, int &col)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (table[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
    row = -1;
    col = -1;
}

// Function to encrypt the plain text
void encrypt(string plainText, char table[][SIZE], string &cipherText)
{
    int i = 0;
    while (i < plainText.length() - 1)
    {
        int row1, col1, row2, col2;
        getCoordinates(table, plainText[i], row1, col1);
        getCoordinates(table, plainText[i + 1], row2, col2);

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

        cipherText += table[row1][col1];
        cipherText += table[row2][col2];
        i += 2;
    }
}

int main()
{
    string key, plainText, cipherText;
    char table[SIZE][SIZE];

    cout << "Enter Key: ";
    getline(cin, key);

    cout << "Enter Plain Text: ";
    getline(cin, plainText);

    prepareString(key);
    prepareString(plainText);

    constructTable(key, table);
    string digraphPlain = digraphPlainText(plainText);

    cout << "\nCipher text: ";
    encrypt(digraphPlain, table, cipherText);
    cout << cipherText << endl;

    cout << "\nDeciphered text: " << digraphPlain << endl;

    return 0;
}