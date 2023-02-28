/*

👉 KMP stands for Knuth Morris Pratt Algorithm.

👉 A pattern matching algorithm which checks the occurrence of a pattern in a given test string.

👉 Time Complexity : O(n), n = length of test string
    Space Complexity : O(m), m = length of pattern string

*/

#include<iostream> // basic input output streams
#include<vector> // for a dynamic array

using namespace std;

string tst, patt; // test and pattern string

// function for KMP algorithm
void kmpAlgo() {
    vector<int> v; // dynamic array of longest prefix suffix values of pattern
    v.push_back(0);
    int len = 0; // length of previous longest prefix suffix

    // find longest prefix suffix values of pattern
    for(int i = 1; i < patt.length();) {
        if(patt[i] == patt[len]) {
            ++len;
            v.push_back(len);
            ++i;
        }
        else {
            if(len) len = v[len - 1];
            else { v.push_back(0); ++i; }
        }
    }

    for(int i = 0, j = 0; tst.length() - i >= patt.length() - j;) {
        if(patt[j] == tst[i]) { ++j; ++i; }
        // pattern found
        if(j == patt.length()) {
            cout << "\nPATTERN FOUND AT : " << i - j;
            j = v[j - 1];
        }
        // mismatch after j no. of matches
        else if(i < tst.length() and patt[j] != tst[i]) {
            // skip 0 to j - 1 characters in lps array (v)
            if(j) j = v[j - 1];
            else ++i;
        }
    }
}

// main function
int main() {
    // input test and pattern strings
    cout << "\t=== KMP Algorithm ===";
    cout << "\nEnter string : ";
    getline(cin, tst);
    cout << "\nEnter pattern string : ";
    cin >> patt;

    kmpAlgo(); // function call
    
    return 0;
}
