#include <iostream>
#include <map>
#include <string>

using namespace std;

string key = "HACK";
map<int, int> keyMap;

void setPermutationOrder()
{
    int n = key.length();
    for (int i = 0; i < n; i++)
    {
        keyMap[key[i]] = i;
    }
}

// Encryption
string encrypt(string plainText)
{
    int row, column, j;
    string cipherText = "";
    column = key.length();
    row = plainText.length() / column;

    if (plainText.length() % column)
    {
        row += 1;
    }
    char matrix[row][column];
    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < column;)
        {
            if (plainText[k] == '\0')
            {
                matrix[i][j] = '_';
                j++;
            }
            if (isalpha(plainText[k]) || plainText[k] == ' ')
            {
                matrix[i][j] = plainText[k];
                j++;
            }
            k++;
        }
    }
    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
    {
        j = ii->second;
        for (int i = 0; i < row; i++)
        {
            // isalpha function checks if the passed character is an alphabet or not
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
            {
                cipherText += matrix[i][j];
            }
        }
    }
    return cipherText;
}

// Decryption
string decrypt(string cipherText)
{
    int col = key.length();

    int row = cipherText.length() / col;
    char cipherMatrix[row][col];

    for (int j = 0, k = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cipherMatrix[i][j] = cipherText[k++];
        }
    }
    int index = 0;
    for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
    {
        ii->second = index++;
    }
    char decCipher[row][col];
    map<int, int>::iterator ii = keyMap.begin();
    int k = 0;
    for (int l = 0, j; key[l] != '\0'; k++)
    {
        j = keyMap[key[l++]];
        for (int i = 0; i < row; i++)
        {
            decCipher[i][k] = cipherMatrix[i][j];
        }
    }

    // Getting message using matrix
    string message = "";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (decCipher[i][j] != '_')
            {
                message += decCipher[i][j];
            }
        }
    }
    return message;
}

int main()
{
    string message;
    fflush(stdin);
    printf("Enter the Plain Text: ");
    getline(cin, message);
    setPermutationOrder();
    string cipher = encrypt(message);
    cout << "Cipher (Encrypted) Text: " << cipher << endl;

    string plainText = decrypt(cipher);
    cout << "Decrypted Text: " << plainText << endl;
}