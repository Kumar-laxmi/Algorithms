import java.util.Scanner;

public class LongestCommonSubsequence {

    public static String longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        // Create a 2D table to store the lengths of common subsequences
        int[][] dp = new int[m + 1][n + 1];

        // Build the table using bottom-up approach
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // Characters match, increment the length of common subsequence
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Characters don't match, take the maximum length from either excluding the last character of text1 or text2
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Retrieve the longest common subsequence
        StringBuilder result = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                // Characters match, add it to the result and move diagonally up-left
                result.insert(0, text1.charAt(i - 1));
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Length of common subsequence from text1[0...i-1] is greater, move up
                i--;
            } else {
                // Length of common subsequence from text2[0...j-1] is greater, move left
                j--;
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first string: ");
        String text1 = scanner.nextLine();

        System.out.print("Enter the second string: ");
        String text2 = scanner.nextLine();

        String lcs = longestCommonSubsequence(text1, text2);

        System.out.println("Longest Common Subsequence: " + lcs);

        scanner.close();
    }
}
