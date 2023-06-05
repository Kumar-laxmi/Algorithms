"""

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

"""

# <----------------> Approach - 01  <-------------------->
class Solution(object):
    def isAnagram(self, s, t):

        # In case of different length of thpse two strings...
        if len(s) != len(t):
            return False
        
        for idx in set(s):
            # Compare s.count(l) and t.count(l) for every index i from 0 to 26...
            # If they are different, return false...
            if s.count(idx) != t.count(idx):
                return False
            
        return True     # Otherwise, return true...





# <----------------> Approach - 02 (Single Line Solution Code) <-------------------->

"""
class Solution(object):
    def isAnagram(self, s, t):

        return sorted(s) == sorted(t)

"""



