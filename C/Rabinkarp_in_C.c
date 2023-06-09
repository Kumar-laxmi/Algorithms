#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 101

void search(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (n < m)
        return;

    long patternHash = 0;
    long textHash = 0;
    int i, j;

    for (i = 0; i < m; i++) {
        patternHash += pattern[i] * (long)pow(PRIME, i);
        textHash += text[i] * (long)pow(PRIME, i);
    }

    for (i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m) {
                printf("Pattern found at index: %d\n", i);
            }
        }
        if (i < n - m) {
            textHash = (textHash - text[i]) / PRIME + text[i + m] * (long)pow(PRIME, m - 1);
        }
    }
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // remove trailing newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  // remove trailing newline

    search(text, pattern);

    return 0;
}
