package algos;

public class code1 {

    // Function to find the minimum number of insertions to make a string palindrome
    public static int findMinimumInsertions(String str) {
        int n = str.length();
        int[][] dp = new int[n][n];

        // Fill the dp array using bottom-up approach
        for (int gap = 1; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                dp[i][j] = (str.charAt(i) == str.charAt(j))
                        ? dp[i + 1][j - 1] // Characters match, no extra insertion needed
                        : Math.min(dp[i][j - 1], dp[i + 1][j]) + 1; // Characters don't match, add one insertion
            }
        }
        return dp[0][n - 1]; // Minimum number of insertions required to make the entire string palindrome
    }

    public static void main(String[] args) {
        String str = "abcde";
        int minInsertions = findMinimumInsertions(str);
        System.out.println("Minimum insertions to make the string palindrome: " + minInsertions);
    }
}
