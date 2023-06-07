#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::string longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D table to store the lengths of common subsequences
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Build the table using bottom-up approach
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, increment the length of common subsequence
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Characters don't match, take the maximum length from either excluding the last character of text1 or text2
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Retrieve the longest common subsequence
    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            // Characters match, add it to the result and move diagonally up-left
            result = text1[i - 1] + result;
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

    return result;
}

int main() {
    string txt1,txt2;
    cout<<"Enter string 1 - ";
    cin>>txt1;
    cout<<"Enter string 2 - ";
    cin>>txt2;    

    std::string lcs = longestCommonSubsequence(txt1, txt2);

    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
    return 0;
}
