/*

👉 In cryptography, the Vigenère Cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar Cipher.

Steps
=====
⇒ Convert all uppercase character into lowercase in the plain text.
⇒ Check if plain text has no intergral characters.
⇒ Input cipher key.
⇒ No. all characters from a - z as 0 - 25.
⇒ Find cipher text by : (characterNum + keyNum) mod 26.
, where characterNum and keyNum are the no.s associated with plain text and cipher key characters.

*/

// including header files
#include<iostream> // input-output statements
#include<map> // for alphabetic codes
#include<vector> // for vector
#include<algorithm> // for find() : find element in vector, transform() : to convert to lowercase
using namespace std;

// function for encryption
string encryptPlainText(string plainText, string key, map<char, int> map) {
    vector<int> cipherCode; // for integer codes of cipher text
    string cipherTxt = ""; // for cipher text

    // convert into cipher code
    for(int i = 0; i < plainText.length(); i++)
        // cipher value = (plain + key) % 26
        cipherCode.push_back((map[plainText[i]] + map[key[i]]) % 26);

    // decode cipher value into cipher text
    for(int i : cipherCode) {
        // search cipher code in alphabetic code map
        for(auto j : map) {
            // get character associated with code
            if(j.second == i) cipherTxt += j.first;
        }
    }
    
    return cipherTxt; // return obtained cipher text
}

// main function
int main() {
    string plainTxt, key; // for plain & cipher key
    map<char, int> alphaCode; // for integer codes for alphabets

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

    cout << "\t====== VIGENERE CIPHER =======" << endl;
    
    // input plain text
    cout << "\nEnter Plain Text : ";
    getline(cin, plainTxt);
    // input cipher key
    cout << "\nEnter Cipher Key : ";
    cin >> key;

    // convert all characters in plain text to lowercase
    transform(plainTxt.begin(), plainTxt.end(), plainTxt.begin(), ptr_fun<int, int>(tolower));

    // if key & plain text not of equal length
    if(key.length() < plainTxt.length()) {
        // append 
        for(int i = 0; key.length() < plainTxt.length(); i++) key += key[i];
    }

    // display output
    cout << "\nPLAIN TEXT : " << plainTxt << endl;
    cout << "CIPHER TEXT (Encrypted Text) : " << encryptPlainText(plainTxt, key, alphaCode); // function call

    return 0;
}