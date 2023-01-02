//Rabin-Karp algorithm is an algorithm used for searching/matching patterns in the text using a hash function. 
//Unlike Naive string matching algorithm, it does not travel through every character in the initial phase 
//rather it filters the characters that do not match and then performs the comparison.
// Rabin-Karp algorithm in Java
public class Rabin_karp {
  public final static int d = 10;

  static void search(String pattern, String txt, int q) {
    int m = pattern.length(); //this will store the length of pattern we need to search
    int n = txt.length(); //this will store the length of the text 
    int i, j;
    int p = 0;  //local variable 
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++) 
      h = (h * d) % q;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
      p = (d * p + pattern.charAt(i)) % q; //hash value for pattern 
      t = (d * t + txt.charAt(i)) % q; //hash value for text 
    }

    // Find the match
    for (i = 0; i <= n - m; i++) {
      if (p == t) {  //if the hash value matches then below code will be executed 
        for (j = 0; j < m; j++) {
          if (txt.charAt(i + j) != pattern.charAt(j)) //we check is pattern is present
            break;
        }

        if (j == m) 
          System.out.println("Pattern is found at position: " + (i + 1));//we print the index at which pattern is found 
      }

      if (i < n - m) {
        t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + m)) % q; 
        if (t < 0)
          t = (t + q);
      }
    }
  }

  public static void main(String[] args) { //main function
    String txt = "ABCCDDAEFG"; //text 
    String pattern = "CDD"; //pattern we want to search
    int q = 13; //integer given to take mod with for both plain text and pattern 
    search(pattern, txt, q);//calling the search function
  }
}
