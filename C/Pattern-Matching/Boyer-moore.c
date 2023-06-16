
/*------------------------------------------------INTRODUCTION-------------------------------------------------------------------------*/
/*Boyer-Moore-Horspool is an algorithm for finding substrings into strings. This algorithm compares each characters of substring to find 
a word or the same characters into the string from right to left. When characters do not match, the search jumps to the next matching 
position in the pattern by the value indicated in the Bad Match Table.
value is calculated using 
"value=length(substring)-index(last occurance)-1."

The Bad Match Table indicates how many jumps should it move from the current position to the next.*/

/*----------------------------------------------ALGORITHM-----------------------------------------------------------------------------
1.first it finds out the lenght of both the strings.
2.bad match table is prepared using the value formula for substring and it include characters only once no repeated element is 
  considered elements out of the substring that are present in main string are considered under *.
3.now it compares each char of substring from right to left with parent string if not found moves from the current position to next 
  by the corresponding value of that character in bad match table.
4.after all successful comparisions the index is returned at which is was matched.
*/
#include <stdio.h>
#include<String.h>
#include <stdlib.h>

// Function to create the bad character shift table with default value as length of substring.
int* createBadCharacterTable(const char* pattern) {
    int patternLength = strlen(pattern);
    int* table = (int*)malloc(sizeof(int) * 256);

 // Initialize the table with default shift value (patternLength) 
    for (int i = 0; i < 256; i++) {
        table[i] = patternLength;
    }
/* Compute the shift value for each character in the pattern except the last character as last char is fiexed with value as length 
   of substring.*/
    for (int i = 0; i < patternLength - 1; i++) {
        table[(int)pattern[i]] = patternLength - 1 - i;
    }
    return table;
}

// Function to perform the Boyer-Moore-Horspool algorithm

int* boyerMooreHorspool(const char* text, const char* pattern, int* occurrences) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    // If the pattern is empty, return an empty occurrences array
    if (patternLength == 0) {
        return occurrences;
    }
// Create the bad character shift table
    int* badCharacterTable = createBadCharacterTable(pattern);

    int i = 0;
    while (i <= textLength - patternLength) {
        int j = patternLength - 1;

        // Compare the pattern characters from right to left with the corresponding text characters
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        // If a match is found, record the occurrence and move to the next position in the text
        if (j == -1) {
            occurrences[i] = 1;
            i++;
        } 
        // If a mismatch occurs, compute the shift amount using the bad character table
        else {
            int charShift = badCharacterTable[(int)text[i + patternLength - 1]];
            i += charShift;
        }
    }
    //return the index at which it occurred.

    return occurrences;
}

int main() {
    const char* text = "ABABDABACDABABCABAB";//parent string
    const char* pattern = "ABABCABAB";//substring
    int textLength = strlen(text);//finds length of parent string
    int patternLength = strlen(pattern);//finds length of sustring

    // Create an array to record the occurrences of the pattern in the text
    int* occurrences = (int*)malloc(sizeof(int) * textLength);

    // Initialize the occurrences array with zeros
    memset(occurrences, 0, sizeof(int) * textLength);

    // Call the Boyer-Moore-Horspool function to find occurrences
    occurrences = boyerMooreHorspool(text, pattern, occurrences);

    printf("Occurrences found at indices: ");
    for (int i = 0; i < textLength; i++) {
        if (occurrences[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the memory allocated for the occurrences array
    free(occurrences);
    return 0;
}

