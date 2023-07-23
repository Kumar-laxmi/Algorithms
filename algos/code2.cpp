#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Specify the subsystem as Console
#ifdef _WIN32
#include <windows.h>
#pragma comment(linker, "/subsystem:console /ENTRY:mainCRTStartup")
#endif

// Function to find the minimum number of insertions to make a string palindrome
int findMinimumInsertions(string str) {
    int n = str.length();
    int dp[n][n];

    // Fill the dp array using bottom-up approach
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            dp[i][j] = (str[i] == str[j])
                    ? dp[i + 1][j - 1] // Characters match, no extra insertion needed
                    : min(dp[i][j - 1], dp[i + 1][j]) + 1; // Characters don't match, add one insertion
        }
    }
    return dp[0][n - 1]; // Minimum number of insertions required to make the entire string palindrome
}

int main() {
    string str = "abcde";
    int minInsertions = findMinimumInsertions(str);
    cout << "Minimum insertions to make the string palindrome: " << minInsertions << endl;
    return 0;
}
