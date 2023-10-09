/**
 * Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1
 * Input: s = "cabbad"
 * Output: "abba"
 * 
 * Example 2
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * Author: Frank Garcia (https://github.com/frank-xyz)
 */

public class LongestPalindromicSubstring {
    public static void main(String[] args) {
        System.out.println(new LongestPalindromicSubstring().longestPalindrome("cabbad"));
    }

    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) return s; // base case: empty input string
        
        int start = 0; // the start boundary for the longest palindromic substring in s 
        int end = 0; // the end boundary for the longest palindromic substring in s
        
        for (int i = 0; i < s.length(); i++) { // loop to iterate through the input string
            int lenOdd = expandFromMiddle(s, i, i); // get the length of the palindrome with an odd number of characters
            int lenEven = expandFromMiddle(s, i, i + 1); // get the length of the palindrome with an even number of characters
            int lenMax = Math.max(lenOdd, lenEven); // the maximum length between lenOdd and lenEven
            
            // end - start + 1 = length of current longest palindrome
            if (lenMax > (end - start + 1)) { // if lenMax is greater than the length of the current longest palindrome
                start = i - ((lenMax - 1) / 2); // update the start boundary of the new longest palindromic substring
                end = i + (lenMax / 2); // update the end boundary of the new longest palindromic substring 
            }
        }
        
        return s.substring(start, end + 1); // return the substring found between these boundaries
    }
    
    private int expandFromMiddle(String s, int left, int right) {
        if (s == null || left > right) return 0; // boundary check
        
        // loop while the substring in s between index left and index right is a palindrome 
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--; // decrement left to move left (i.e. expand from middle)
            right++; // increment right to move right (i.e. expand from middle)
        }
        
        return right - left - 1; // return the length of the palindromic substring
    }
    // time: O(n^2), where n is the number of characters from the center of the string to the beginning AND to the end of the string
    // space: O(n)
}
