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



/*  <--------- Code ----------->  */

class Solution {
    public boolean isAnagram(String s, String t) {
        boolean b = true;
        // Calculate length of string s
        int len = s.length();   

        // agar string s or string t ki length equal nhi hai to false return kr do
        if (s.length() != t.length()) {
            b = false;
        }

        //Convert string s to character array test1
        char[] test1 = s.toCharArray();
        //sort the character array test1
        Arrays.sort(test1);

        //Convert string t to character array test2
        char[] test2 = t.toCharArray();
        //sort the character array test2
        Arrays.sort(test2);

        for (int i = 0; i < test1.length && i < test2.length; i++) {
            // if both strings are not equal than bolean b ko false kr do
            if (test1[i] != test2[i]) {
                b = false;
            }
        }

        // if both are equal than return true
        return b;
    }
}