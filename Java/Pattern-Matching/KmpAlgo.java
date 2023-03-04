/*

👉 KMP stands for Knuth Morris Pratt Algorithm.

👉 A pattern matching algorithm which checks the occurrence of a pattern in a given test string.

👉 Time Complexity : O(n), n = length of test string
    Space Complexity : O(m), m = length of pattern string

*/

import java.util.Scanner; // for input

class KmpAlgo {
    static void kmpAlgo(String tst, String pat) {
        int lpsArray[] = new int[pat.length()]; // array of longest prefix suffix values of pattern
        lpsArray[0] = 0;
        int len = 0; // length of previous longest prefix suffix

        // find longest prefix suffix values of pattern
        for (int i = 1; i < pat.length();) {
            if (pat.charAt(i) == pat.charAt(len)) {
                ++len;
                lpsArray[i] = len;
                ++i;
            } else {
                if (len != 0)
                    len = lpsArray[len - 1];
                else {
                    lpsArray[i] = len;
                    ++i;
                }
            }
        }

        for (int i = 0, j = 0; tst.length() - i >= pat.length() - j;) {
            if (pat.charAt(j) == tst.charAt(i)) {
                ++i;
                ++j;
            }
            // pattern found
            if (j == pat.length()) {
                System.out.println("PATTERN FOUND AT : " + (i - j));
                j = lpsArray[j - 1];
            } 
            // mismatch after j no. of matches
            else if (i < tst.length() && pat.charAt(j) != tst.charAt(i)) {
                // skip 0 to j - 1 characters in lps array (v)
                if (j != 0) j = lpsArray[j - 1];
                else ++i;
            }
        }
    }

    public static void main(String[] args) {
        String tst = "", pat = "";

        Scanner s = new Scanner(System.in);

        // input test and pattern strings
        System.out.println("\t=== KMP Algorithm ===");
        System.out.print("\nEnter the string : ");
        tst += s.nextLine();

        System.out.print("\nEnter pattern string : ");
        pat += s.nextLine();

        kmpAlgo(tst, pat); // function call

        s.close();
    }
}