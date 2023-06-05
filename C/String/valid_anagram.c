/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/


// <---------------> Code <------------------->

bool isAnagram(char * s, char * t){
    int len1 = strlen(s);
    int len2 = strlen(t);

    // Anagrams must have the same length
    if (len1 != len2) {
        return 0;
    }

    // Count the frequency of characters in both strings
    int freq[256] = {0}; // Assuming ASCII characters

    for (int i = 0; i < len1; i++) {
        freq[(int)s[i]]++;
        freq[(int)t[i]]--;
    }

    // Check if all character frequencies are zero
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }

    return 1; // Strings are anagrams
}