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

// =========================== CODE with Java ========================
import java.util.*;
class Main
{
 //  prints all occurrences of pattern in string s using Zalgorithm
    public static void index(String s,String pattern)
    {
    // Create concatenated string "P#s"
        String concat=pattern + "#" + s;
        int k=concat.length();
        int a[]=new int[k];
        // Construct a array
        make_zarray(a,concat);
         // now looping through a array for matching condition
        for(int i=0;i<k;i++)
        {
         // if a[i] (matched region) is equal to pattern
            // length we got the pattern
            if(a[i]==pattern.length()){
                System.out.println("Pattern found at index:"+(i-pattern.length()-1));
            }
        }
    }
    // Fills a array for given string s[]
    private static void make_zarray(int a[],String s)
    {
        int n=s.length();
         
        // [l,r] make a window which matches with
        // prefix of s
        //l=left and r=right
        int l=0,r=0;
        for(int i=1;i<n;i++)
        {
         // if i>r nothing matches so we will calculate.
            // a[i] using naive way.
            if(i>r)
            {
                l=r=i;
                while(r<n && s.charAt(r-l)==s.charAt(r))
                r++;
                a[i]=r-l;
                r--;
            }
            else
            {
            
                // m = i-l so k corresponds to number which
                // matches in [l,r] interval.
                int m=i-l;
                if(a[m]<r-i+1)
                a[i]=a[m];
                else
                {
                  // else start from right and check manually
                    l=i;
                    while(r<n && s.charAt(r-l)==s.charAt(r))
                    r++;
                    a[i]=r-l;
                    r--;
                }
            }
        }
    }
     // Driver program
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String s,pattern;
        System.out.println("Enter the string:\n");
        s=sc.nextLine();
        System.out.println("Enter the pattern:\n");
        pattern=sc.nextLine();
        index(s,pattern);
    }
}

