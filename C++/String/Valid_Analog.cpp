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


/* <-------------  Complexity --------------->

Time Complexity : O(m+n)

*/

// <----------- Approach - 01 ------------->

class Solution {
public:
    bool isAnagram(string s, string t) {

        //make a frequency Table array of size 256 
        //and initialize all with 0
        int freqTable[256] = {0};

        //add freq of each char of string s into freqtable
        for(int i=0;i<s.size();i++){
            freqTable[s[i]]++;
        }
        //decreament freq of each char of string t into freqtable
        for(int i=0;i<t.size();i++){
            freqTable[t[i]]--;
        }

        for(int i=0;i<256;i++){
            //agar freq table 0 nhi hai to false return kr do
           if(freqTable[i] != 0)
                return false;
        }

        return true;

    }
};