/*

👉 In cryptography, the Vernam Cipher encypts the alphabetic text. It's a substitution technique to convert the plain text into cipher text.

👉 It's also called ONE TIME PAD Cipher Algorithm.

Steps
=====
⇒ Generate a random key from 26 alphabetic characters.
⇒ Assign a number to each character of the plain-text and the key according to alphabetical order.
⇒ Add the assigned numbers and store the same in a new array/vector.
⇒ Subtract 26 from the added values, if they are greater than 26.
⇒ Assign the characters associated to the final subtracted values to obtain the cipher text.

*/

#include<iostream> // for general input output
#include<vector> // for vector -> dynamic array
#include<map> // for alphabetic codes
#include<cstdlib> // for rand() -> generate random number
using namespace std;

// array for characters of random key
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                  'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u',
                  'v', 'w', 'x', 'y', 'z'};

// for random key generation
string generateKey(long long n) {
    string key = "";
    // generate random key
    for(int i = 0; i < n; i++) key += alpha[rand() % 26];
    return key;
}

int main() {
    string plainTxt, key = "", cipherTxt = "";
    map<char, int> alphaCode; // for integer codes for alphabets
    vector<int> addedCode; // for added alphabetic codes

    // input plain text 
    cout << "\nEnter Plain Text : ";
    getline(cin, plainTxt);

    // alphabet codes
    alphaCode['a'] = 0;
    alphaCode['b'] = 1;
    alphaCode['c'] = 2;
    alphaCode['d'] = 3;
    alphaCode['e'] = 4;
    alphaCode['f'] = 5;
    alphaCode['g'] = 6;
    alphaCode['h'] = 7;
    alphaCode['i'] = 8;
    alphaCode['j'] = 9;
    alphaCode['k'] = 10;
    alphaCode['l'] = 11;
    alphaCode['m'] = 12;
    alphaCode['n'] = 13;
    alphaCode['o'] = 14;
    alphaCode['p'] = 15;
    alphaCode['q'] = 16;
    alphaCode['r'] = 17;
    alphaCode['s'] = 18;
    alphaCode['t'] = 19;
    alphaCode['u'] = 20;
    alphaCode['v'] = 21;
    alphaCode['w'] = 22;
    alphaCode['x'] = 23;
    alphaCode['y'] = 24;
    alphaCode['z'] = 25;

    key = generateKey(plainTxt.size()); // generate cipher key

    cout << "\nGenerated Key : " << key << endl;

    // create added alphabetic code vector/array
    for(int i = 0; i < plainTxt.size(); i++) 
        addedCode.push_back(alphaCode[plainTxt[i]] + alphaCode[key[i]]);

    // create subtraced alphabetic code vector/array
    for(int i : addedCode) if(i > 26) i = i - 26;

    // generate cipher text
    for(int i : addedCode) {
        // find alphabetic character associated with respective added value
        for(auto j : alphaCode) {
            if(i == j.second) {
                cipherTxt += j.first; // append cipher text character
                break;
            }
        }
    }

    // display output
    cout << "\nPLAIN TEXT : " << plainTxt << endl;
    cout << "CIPHER TEXT (Encripted Text) : " << cipherTxt;

    return 0;
}