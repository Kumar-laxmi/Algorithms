#include <stdio.h>
#include <string.h>

// Function to find minimum of three numbers
int min(int x, int y, int z) {
    return (x < y) ? (x < z ? x : z) : (y < z ? y : z);
}

// A Naive recursive C program to find minimum number
// of operations to convert s1 to s2
int editDistRec(char *s1, char *s2, int m, int n) {
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0) return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0) return m;

    // If last characters of two strings are same, nothing
    // much to do. Get the count for
    // remaining strings.
    if (s1[m - 1] == s2[n - 1])
        return editDistRec(s1, s2, m - 1, n - 1);

    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1 + min(editDistRec(s1, s2, m, n - 1),    // Insert
                   editDistRec(s1, s2, m - 1, n),    // Remove
                   editDistRec(s1, s2, m - 1, n - 1) // Replace
                   );
}

int main() {
    char s1[] = "GEEXSFRGEEKKS";
    char s2[] = "GEEKSFORGEEKS";
    printf("%d\n", editDistRec(s1, s2, strlen(s1), strlen(s2)));
    return 0;
}