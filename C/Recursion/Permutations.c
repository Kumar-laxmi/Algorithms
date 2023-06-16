#include <stdio.h>
#include <string.h>

void permutations(char p[], char up[]) {
    // Base case: If the remaining characters to be permuted is empty, print the permutation
    if (up[0] == '\0') {
        printf("%s\n", p);
        return;
    }
    
    char ch = up[0];
    int len = strlen(p);

    for (int i = 0; i <= len; i++) {
        // Split the permutation string into two parts
        char f[100], s[100];
        strncpy(f, p, i); // First part
        f[i] = '\0';
        strcpy(s, p + i); // Second part
        
        // Recursive call: Generate permutations by inserting the current character at each possible position
        permutations(strcat(strcat(f, &ch), s), up + 1);
    }
}

int main() {
    char str[] = "abc";
    permutations("", str);
    return 0;
}

