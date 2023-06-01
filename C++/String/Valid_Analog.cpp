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


// <----------- Approach - 02 ------------->

class Solution {
public:
    bool isAnagram(string s, string t) {
          
        //sort the both strings   
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        // is s.size() == t.size then 
        // check each character of s with each character of t
        // if both are equal than continue 
        //other wise return false
        if(s.size() == t.size()){
            for(int i=0;i<s.size();i++){
                if(s[i] == t[i]){
                    continue;
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
    //both strings are equal so we will return true
    return true;
    }
};