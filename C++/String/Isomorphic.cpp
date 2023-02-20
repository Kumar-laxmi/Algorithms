/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
#include <iostream>
#include <unordered_map>
using namespace std;
bool isIsomorphic(string s, string t) 
{
    // Create two hash maps to store the mappings between s and t, and t and s
    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;
    // Iterate through each character in the strings and compare their corresponding mappings
    for (int i = 0; i < s.length(); i++) {
        // If there is a mismatch in either of the hash maps, the strings are not isomorphic
        if (s_to_t.count(s[i]) && s_to_t[s[i]] != t[i]) 
        {
            return false;
        }
        if (t_to_s.count(t[i]) && t_to_s[t[i]] != s[i]) 
        {
            return false;
        } 
        // Add the new mappings to both hash maps
        s_to_t[s[i]] = t[i];
        t_to_s[t[i]] = s[i];
    }
    // If we reach the end of the strings without finding a mismatch, the strings are isomorphic
    return true;
}
int main() 
{
    // Take input from the user
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;
    // Check if the strings are isomorphic and print the result
    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }
    return 0;
}