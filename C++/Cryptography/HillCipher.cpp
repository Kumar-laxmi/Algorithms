/*

👉 In classical cryptography, the Hill cipher is a polygraphic substitution cipher based on linear algebra. 

👉 Invented by Lester S. Hill in 1929, it was the first polygraphic cipher in which it was practical to operate on more than three symbols at once.

Steps
=====
⇒ Generate a cipher key 2x2 matrix by replacing characters with numerical values.
⇒ Generate a vector of 2x1 matrices with numeric codes of plain text characters.
⇒ Multiply the key mtx. with each 2x1 matrix in plain text matrix vector & mod the result with 26, to obtain the cipher text numeric values.
⇒ Convert these numeric values back to alphabetic characters to obtain the cipher text.

*/

#include<iostream> // for general input output
#include<string> // for erase() -> erase a character at a position
#include<vector> // for vector -> dynamic array
#include<process.h> // for exit() -> terminate program
using namespace std;

int keyMtx[2][2]; // 2x2 mtx for cipher key
vector<int> v; // dummy array to store 2x1 mtx.
vector<vector<int>> plainTxtMtxArr; // for array of plain text mtx.
vector<vector<int>> cipherTxtMtxArr; // for array of cipher text mtx.

// function to generate key matrix
void generateKeyMtx(string key) {
    int k = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            // fill key mtx. with number code of respective character
            keyMtx[i][j] = (key[k]) % 65;
            ++k;
        }
    }
}

// function to generate cipher text matrix
void hillCipherEncription() {
    for(int i = 0; i < plainTxtMtxArr.size(); i++) {
        // cipher text mtx. = key mtx. * plain text mtx.
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 1; k++) {
                v[i] = 0;
                for(int l = 0; l < 2; l++)
                    v[j] = (keyMtx[j][l] * plainTxtMtxArr[l][k]) % 26;
                
                cipherTxtMtxArr.push_back(v);
                v.clear();
            }
        }
    }
}

// main function
int main() {
    string plainTxt, key = "", cipherTxt = ""; 

    cout << "\n\tHILL CIPHER"; 

    // input plain text
    cout << "\nEnter Plain Text : ";
    getline(cin, plainTxt);
    // input cipher key
    cout << "\nEnter Cipher Key (LENGTH 4) : ";
    cin >> key;

    // check if key length is not 4
    if(key.length() > 4) {
        // pop last character until length is 4
        while(key.length() != 4) key.erase(key.begin() + key.length() - 1);
        cout << "\n\tEDITED KEY : " << key; // display edited key
    }
    else if(key.length() < 4) {
        cout << "\n*** INVALID KEY ***";
        exit(0); // terminate program
    }

    generateKeyMtx(key); // function call for key mtx. generation

    // generate plain text vector (2x1 mtx.)
    for(int i = 0; i < plainTxt.length(); i += 2) {
        if(plainTxt[i] != ' ' and plainTxt[i + 1] != ' ') {
            v.push_back(plainTxt[i] % 65);
            v.push_back(plainTxt[i + 1] % 65);
        }
        else if(plainTxt[i] != ' ') v.push_back(plainTxt[i] % 65);
        plainTxtMtxArr.push_back(v);
        v.clear();
    }

    hillCipherEncription(); // function call for cipher mtx. generation

    // convert cipher text values to characters
    for(int i = 0; i < cipherTxtMtxArr.size(); i++) {
        for(int j = 0; j < 2; j++) cipherTxt += cipherTxtMtxArr[i][j] + 65;
    }

    // display output
    cout << "\nPLAIN TEXT : " << plainTxt << endl;
    cout << "CIPHER TEXT : " << cipherTxt;

    return 0;
}