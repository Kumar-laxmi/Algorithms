import java.util.Scanner;

public Manachers_Algorithm{
    private static final int SIZE = 100000 + 1;
    private static int[] P = new int[SIZE * 2];

    // Transform S into new string Q with special characters inserted to avoid bound checking.
    private static String convertToNewString(String s) {
        StringBuilder newString = new StringBuilder("@");

        for (int i = 0; i < s.length(); i++) {
            newString.append("#").append(s.charAt(i));
        }

        newString.append("#$");
        return newString.toString();
    }

    private static String longestPalindromeSubstring(String s) {
        String Q = convertToNewString(s);
        int c = 0, r = 0; // current center, right limit

        for (int i = 1; i < Q.length() - 1; i++) {
            // find the corresponding letter in the palindrome substring
            int iMirror = c - (i - c);

            if (r > i) {
                P[i] = Math.min(r - i, P[iMirror]);
            }

            // expanding around center i
            while (Q.charAt(i + 1 + P[i]) == Q.charAt(i - 1 - P[i])) {
                P[i]++;
            }

            // Update c,r in case if the palindrome centered at i expands past r
            if (i + P[i] > r) {
                c = i; // next center = i
                r = i + P[i];
            }
        }

        // Find the longest palindrome length in p
        int maxPalindrome = 0;
        int centerIndex = 0;

        for (int i = 1; i < Q.length() - 1; i++) {
            if (P[i] > maxPalindrome) {
                maxPalindrome = P[i];
                centerIndex = i;
            }
        }

        return s.substring((centerIndex - 1 - maxPalindrome) / 2, (centerIndex - 1 - maxPalindrome) / 2 + maxPalindrome);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        System.out.println(longestPalindromeSubstring(s));
    }
}
