#include <stdio.h>
#include <string.h>

#define SIZE 100000 + 1

int P[SIZE * 2];

// Transform S into new string Q with special characters inserted to avoid bound checking.
void convertToNewString(const char* s, char* newString) {
    int i;

    newString[0] = '@';
    int len = strlen(s);

    for (i = 0; i < len; i++) {
        newString[2 * i + 1] = '#';
        newString[2 * i + 2] = s[i];
    }

    newString[2 * len + 1] = '#';
    newString[2 * len + 2] = '$';
    newString[2 * len + 3] = '\0';
}

char* longestPalindromeSubstring(const char* s, char* result) {
    char Q[SIZE * 2];
    int c = 0, r = 0; // current center, right limit

    convertToNewString(s, Q);

    int len = strlen(Q);

    for (int i = 1; i < len - 1; i++) {
        // find the corresponding letter in the palindrome substring
        int iMirror = c - (i - c);

        if (r > i) {
            P[i] = (r - i) < P[iMirror] ? (r - i) : P[iMirror];
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]) {
            P[i]++;
        }

        // Update c, r in case if the palindrome centered at i expands past r
        if (i + P[i] > r) {
            c = i; // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in P
    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < len - 1; i++) {
        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    strncpy(result, s + (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
    result[maxPalindrome] = '\0';

    return result;
}

int main() {
    char s[SIZE];
    char result[SIZE];
    fgets(s, sizeof(s), stdin);
    printf("%s\n", longestPalindromeSubstring(s, result));

    return 0;
}
