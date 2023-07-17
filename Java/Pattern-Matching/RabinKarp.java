// =========================== Problem Statement ==============================================================
/*
Rabin-Karp algorithm is an algorithm used for searching/matching patterns in the text using a hash function.
Unlike Naive string matching algorithm, it does not travel through every character in the initial phase rather
it filters the characters that do not match and then performs the comparison.

Rabin-Karp Algo using Java

Example:-

Input:
Text: "AABAACAADAABAABA"
Pattern: "AABA"

Output:
Occurrences found at indices: 0, 9, 12
*/

import java.util.*;

public class RabinKarp {
  final static int d = 5;

  static void search(String pattern, String text, int q) {

    int sizep = pattern.length();
    int sizet = text.length();

    int p = 0, t = 0, h = 1;

    // h=d^(sizep-1) to calculate the rolling hash
    for (int i = 0; i < sizep - 1; i++)
      h = (h * d) % q;

    // calculating the hash values of pattern and portions of text
    for (int i = 0; i < sizep; i++) {
      p = (d * p + pattern.charAt(i)) % q;
      t = (d * t + text.charAt(i)) % q;
    }

    // checking for the presence of pattern within the text
    System.out.print("Occurences found at indices :");
    int check = 0;
    for (int i = 0; i <= sizet - sizep; i++) {
      if (p == t) {
        int j = 0;
        while (j < sizep) {
          // checking for spurious hits
          if (text.charAt(i + j) != pattern.charAt(j))
            break;
          j++;
        }

        // printing the index of starting of pattern within text
        if (j == sizep)
          System.out.print(" " + i);
        check = 1;
      }

      // calculating the rolling hash for next set of characters
      if (i < sizet - sizep) {
        t = (d * (t - text.charAt(i) * h) + text.charAt(i + sizep)) % q;
        if (t < 0)
          t = (t + q);
      }
    }
    if (check == 0)
      System.out.print("NULL");
  }

  public static void main(String[] args) {
    // inputs:
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the pattern :");
    String pattern = sc.nextLine();
    System.out.println("Enter the text :");
    String txt = sc.nextLine();

    // taking q as a large prime number to prevent hash value from becoming too large a value
    int q = 19;
    search(pattern, txt, q);//calling function
  }
}
