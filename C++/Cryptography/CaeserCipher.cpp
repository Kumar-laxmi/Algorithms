/*

▶ In cryptography, the Caesar cipher is one of the simplest and best known encryption techniques. 

▶ It is a type of substitution cipher where each letter in the plaintext is replaced with a letter representing a certain number of digits in the alphabet. 

Steps
=====
⇒ Convert all uppercase character into lowercase in the plain text.
⇒ Check if plain text has no intergral characters.
⇒ No. all characters from a - z as 0 - 25.
⇒ Find encripted value by : (characterNum + key) mod 26.
⇒ Convert the encripted value to equivalent alphabetic character (Cipher Text).

*/

// including header files
#include<iostream> // input-output statements
#include<map> // for alphabetic codes
#include<vector> // for vector
#include<algorithm> // for find() : find element in vector, transform() : to convert to lowercase
using namespace std;

int main() {
    string plainTxt, cipherTxt = ""; // for plain and cipher texts
    long long key; // for cipher key
    int encrpitValue; // for encripted value
    map<char, int> alphaCode; // for integer codes for alphabets
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // for integral values in plain text
    
    cout << "\t====== CAESER CIPHER =======" << endl;
    
    // input plain text
    cout << "\nEnter Plain Text : ";
    getline(cin, plainTxt);
    // input cipher key
    cout << "\nEnter Cipher Key : ";
    cin >> key;

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

    // convert all characters in plain text to lowercase
    transform(plainTxt.begin(), plainTxt.end(), plainTxt.begin(), ptr_fun<int, int>(tolower));

    for(int i = 0; i < plainTxt.size(); i++) {
        /*
        check if :
            -> ith character in plain text is space
            -> ith character in plain text is integer
        */
        if(plainTxt[i] != ' ' || find(v.begin(), v.end(), plainTxt[i]) != v.end()) {
            // find encripted value
            encrpitValue = (alphaCode[plainTxt[i]] + key) % 26;

            // find alphabetic character associated with respective encripted value
            for(auto i : alphaCode) {
                if(i.second == encrpitValue) {
                    cipherTxt += i.first; // append cipher text character
                    break;
                }
            }
        }
    }

    cout << "\nPLAIN TEXT : " << plainTxt << endl;
    cout << "CIPHER TEXT (Encripted Text) : " << cipherTxt;

    return 0;
}