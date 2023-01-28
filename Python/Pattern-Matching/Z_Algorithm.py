 """ =========================== Problem Statement ========================

The problem that the above code is solving is to find all occurrence of a pattern  in a string , which is common string searching problem using Z Algorithm

 Z algorithm is a linear time string matching algorithm.It works Z by maintaining an auxiliary array which stores the length of the longest substring, starting from the current index, that also it's prefix. This means that each index stores the number of characters, matching the starting characters, starting from this index. This implies that if auxiliary array has a value k for any index, it means that k characters after this index match the first k characters of the string. This is the fundamental part of Z algorithm.

Here is the formal problem statement:
Input: Two strings s and pattern are passed.These two strings are concatenated to give new-String.
String-a b c d e a a b b t a a b d f g
Pattern-a a b b
New string-a a b b # a b c d e a a b b t a a b d f g
New string-a a b b # a b c d e a a b b t a a b d f g
Z-array-   0 1 0 0 0 1 0 0 0 0 4 1 0 0 0 3 1 0 0 0 0
 We then search for the index with value equal to length of the search pattern and our element is found at that index.
Output: index of the position in string where pattern is found.
Time Complexity

The Z algorithm runs in  O(n) time. Characters are never compared at positions less than r, and every time a match is found, r is increased by one, so there are at most n comparisons.This makes it especially useful for easily searching for pattern in a string in less time.

 =========================== CODE with Python ========================"""
def make_zarray(string, a):
    n = len(string)
 # Fills a array for given string
    L, r, m = 0, 0, 0
     # [L,R] make a window which matches
    # with prefix of s
    #L=left and r=right
    for i in range(1, n):
        if i > r:
         # if i>r nothing matches so we will calculate.
        # a[i] using naive way.
            L, r = i, i
     
            # r-L = 0 in starting, so it will start
            # checking from 0'th index.
            while r< n and string[r - L] == string[r]:
                r += 1
            a[i] = r - L
            r -= 1
        else:
         # m = i-L so k corresponds to number which
            # matches in [l,r] interval.
            
            m = i - L
 
            # if a[k] is less than remaining interval
            # then a[i] will be equal to a[k].
            if a[m] < r - i + 1:
                a[i] = a[m]
 
           
            else:
 
             # else start from r and check manually
                L= i
                while r< n and string[r - L] == string[r]:
                    r+= 1
                a[i] = r - L
                r -= 1
    # prints all occurrences of pattern
# in string using Z algo

def index(s, pattern):
 
    # Create concatenated string "P#s"
    concat = pattern + "#" + s
    k = len(concat)
   # Construct a array
    a = [0] * k
    make_zarray(concat, a)
  # now looping through a array for matching condition
    for i in range(k):
         # if a[i] (matched region) is equal to pattern
        # length we got the pattern
        if a[i] == len(pattern):
            print("Pattern found at index",
                      i - len(pattern) - 1)
 
# Driver Code
if __name__ == "__main__":
    s = input("Enter the string:")
    pattern=input("Enter the pattern:")
    
    index(s, pattern)


