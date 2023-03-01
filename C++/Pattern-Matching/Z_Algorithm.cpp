// =========================== Problem Statement ========================
/*
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
Output: (index of the position in string where pattern is found.)
Pattern found at index:5
Time Complexity

The Z algorithm runs in  O(n) time. Characters are never compared at positions less than r, and every time a match is found, r is increased by one, so there are at most n comparisons.This makes it especially useful for easily searching for pattern in a string in less time.

*/

// =========================== CODE with C++ ========================
#include <iostream>

using namespace std;
void make_zarray(int a[],string s)
{
    int n=s.length();
    int l,r,k;
        //l=left and r=right
        // [l,r] make a window which matches with prefix of s
    l=r=0;
    for(int i=1;i<n;i++)
    {
     // if i>r nothing matches so we will calculate.
        // a[i] using naive way.
        if(i>r)
        {
            l=r=i;
             // r-l = 0 in starting, so it will start
            // checking from 0'th index. 
            while(r<n && s[r-l]==s[r])
            r++;
            a[i]=r-l;
            r--;
        }
        else
        {
         // k = i-l so k corresponds to number which
            // matches in [l,r] interval.
            k=i-l;
            // if a[k] is less than remaining interval
            // then a[i] will be equal to a[k].
            if(a[k]<r-i+1)
            a[i]=a[k];
            else
            {
             // else start from right and check manually
                l=i;
                while(r<n && s[r-l]==s[r])
                r++;
                a[i]=r-l;
                r--;
            }
        }
    }
}
void index(string s,string pattern)
{
 // Create concatenated string "P#s with additional character"
    string concat=pattern +"#" + s;
    int l=concat.length();
    // Constructing a array
    int a[l];
    make_zarray(a,concat);
    // now looping through a array for matching condition
    for(int i=0;i<l;i++)
    {
      // if a[i] (matched region) is equal to pattern
        // length we got the pattern
        if(a[i]==pattern.length())
        cout<<"Pattern found at index:"
        <<i-pattern.length()-1<<endl;
    }
}
// Driver program
int main()
{
    string s,pattern;
    cout<<"Enter the string:"<<endl;
    cin>>s;
    cout<<"Enter the pattern:"<<endl;
    cin>>pattern;
    index(s,pattern);
    return 0;
}

