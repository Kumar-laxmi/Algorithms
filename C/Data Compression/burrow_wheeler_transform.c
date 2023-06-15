/*  =============== PROBLEM STATEMENT ============= 

Implement the Burrows-Wheeler Transform (BWT) and its inverse. 
Given an input string s, the program should compute its BWT and then reconstruct the original string using the inverse BWT.

============= SOLUTION ==============
The bwt function takes a string and returns its Burrows-Wheeler transform bwt. 
1. The function generates the suffix array by using the iota function to fill a vector sa with values from 0 to n - 1, where n is the length of the input string. 
2. The modified_quicksort function is then used to sort the suffixes lexicographically. 
3. Finally, the transform bwt is constructed by concatenating the last characters of each sorted suffix, with a special sentinel character $ appended to the end.


The inverse_bwt function takes the transformed string bwt and returns the original string. 
1. The function first constructs the first column of the Burrows-Wheeler matrix by sorting the transform bwt. 
2. It then iteratively constructs t by adding the last character of the previous iteration to the beginning of the string. 
3. The index of the next character is determined by counting the number of occurrences of the current character up to and including the current index in the transformed string bwt, and then finding the index of the nth occurrence of the character in the first column of the Burrows-Wheeler matrix.

Sample Input: 
banana

Sample Output: 
BWT of banana$ is annb$aa
Inverse BWT of annb$aa is banana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two suffixes for sorting
int compare_suffixes(const void* a, const void* b) {
    const char* suffixA = *(const char**)a;
    const char* suffixB = *(const char**)b;
    return strcmp(suffixA, suffixB);
}

// Function to perform the Burrows-Wheeler Transform
char* bwt(char* s) {
    strcat(s, "$");
    // Length of the input string
    int len = strlen(s);

    // Create an array of rotations
    char** rotations = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        rotations[i] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(rotations[i], s + i);
        strncat(rotations[i], s, i);
    }

    // Sort the rotations lexicographically
    qsort(rotations, len, sizeof(char*), compare_suffixes);

    // Construct the transformed string
    char* bwt = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        bwt[i] = rotations[i][len - 1];
    }
    bwt[len] = '\0';

    // Free memory allocated for rotations
    for (int i = 0; i < len; i++) {
        free(rotations[i]);
    }
    free(rotations);

    return bwt;
}

char* inverse_bwt(char* bwt_string) {
    // Count the occurrences of each character
    int counts[256] = {0};
    int len = strlen(bwt_string);
    for (int i = 0; i < len; i++) {
        counts[bwt_string[i]]++;
    }

    // Generate the sorted list of characters
    char sorted_chars[256];
    int sorted_count = 0;
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            sorted_chars[sorted_count++] = i;
        }
    }

    // Construct the first column of the transformation matrix
    char first_column[len];
    int first_column_index = 0;
    for (int i = 0; i < sorted_count; i++) {
        char current_char = sorted_chars[i];
        int count = counts[current_char];
        for (int j = 0; j < count; j++) {
            first_column[first_column_index++] = current_char;
        }
    }

    // Perform the reverse transformation
    int index = 0;
    char* original_string = (char*)malloc((len + 1) * sizeof(char));
    original_string[len] = '\0';
    for (int i = 0; i < len; i++) {
        char current_char = bwt_string[index];
        original_string[len - i - 1] = current_char;
        index = -1;
        for (int j = 0; j < len; j++) {
            if (first_column[j] == current_char) {
                index = j;
                first_column[j] = '\0';
                break;
            }
        }
    }
    char* new_string = original_string + 1; // new string that starts from the second character (since pointer)
    return new_string;
}

int main() {
    char input[100];  // Declare an array to store user input

    // Get input from the user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character

    // Burrows-Wheeler Transform
    char* bwt_transform = bwt(input);
    printf("Transformed string: %s\n", bwt_transform);

    // Inverse Burrows-Wheeler Transform
    char* original = inverse_bwt(bwt_transform);
    printf("Original string: %s\n", original);

    free(bwt_transform);
    free(original);

    return 0;
}