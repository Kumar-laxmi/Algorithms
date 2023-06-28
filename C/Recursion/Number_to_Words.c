/*
------------------------------------- Number To Words Convertor -------------------------------------

Approach

1. Initialize global vectors containing the words for digits, denominations (thousand, million, etc.), tens, and ties.

2. Read an input number as a string from the user.

3. Pad the input number with leading zeros if its size is not a multiple of 3.

4. Reverse the input number for easier processing.

5. Recursively convert the input number to words by processing it in groups of three digits.

6. Extract the one's, ten's, and hundred's digits from the current group.

7. Build the word representation by appending the corresponding words for the digits, tens, and hundreds.

8. Append the appropriate denomination (thousand, million, etc.) based on the current level.

9. Recursively process the remaining digits.

10. Print the resulting word representation of the input number.

Below is the implementation of Number-to-Words Conversion in C Language.
*/

// Program starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialising global variables of name of words
char* digit[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

char* denominations[] = {"", "Thousand ", "Million ", "Billion ", "Trillion "};

char* tens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

char* ties[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


// Function to concatenate two strings with a space between them
void add(char* s1, char* s2) {
    if (strlen(s1) > 0 && strlen(s2) > 0) {
        strcat(s1, " ");
    }
    strcat(s1, s2);
}

// Function to convert any number into words recursively
char* convert(int idx, int level, char* input) {
    // Base condition to check whether current index is greater than or equal to the size of the input number
    if (idx >= strlen(input)) {
        char* emptyString = malloc(1);
        emptyString[0] = '\0';
        return emptyString;
    }

    char* cur = malloc(100);
    cur[0] = '\0';

    int od, td, hd;
    od = input[idx] - '0';  // One's digit
    td = input[idx + 1] - '0';  // Ten's digit
    hd = input[idx + 2] - '0';  // Hundred's digit

    if (hd != 0) {
        add(cur, digit[hd]);
        add(cur, "Hundred");
    }

    if (td != 0) {
        if (td == 1) {
            add(cur, tens[od]);  // If the ten's digit is 1, use the corresponding value from the 'tens' array
        } else {
            add(cur, ties[td - 1]);  // If the ten's digit is not 1, use the corresponding value from the 'ties' array
            if (od != 0) {
                add(cur, digit[od]);  // Add the one's digit if it's not zero
            }
        }
    } else if (od != 0) {
        add(cur, digit[od]);  // If the ten's digit is zero, only add the one's digit
    }

    if (strlen(cur) > 0) {
        add(cur, denominations[level]);  // Add the current level's denomination (thousand, million, billion, etc.) to the string
    }

    char* remaining = convert(idx + 3, level + 1, input);  // Recursively convert the remaining digits
    char* result = malloc(strlen(cur) + strlen(remaining) + 1);
    strcpy(result, remaining);
    strcat(result, cur);

    free(cur);
    free(remaining);

    return result;
}

// Driver function
int main() {
    char input[100];
    
    // Taking input from the user
    printf("\nEnter Number: ");
    scanf("%s", input);

    printf("\n%s in Words: ", input);

    while (strlen(input) % 3 != 0) {
        memmove(input + 1, input, strlen(input) + 1);
        input[0] = '0';  // Pad the input number with leading zeros to make its size a multiple of 3
    }

    strrev(input);  // Reverse the input number for easier processing

    if (strcmp(input, "000") == 0) {
        printf("Zero\n");  // If the input number is all zeros
    } else if (strlen(input) > 15) {
        printf("This is a very large number !\n");  // If the input number exceeds the supported range
    } else {
        char* result = convert(0, 0, input);  // Convert the input number to words
        printf("%s\n", result);  // Print the result
        free(result);
    }

    printf("\n");

    return 0;
}
