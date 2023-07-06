/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/*Problem Description
Program to convert  text sentence in CamelCase format .
Examples:
 1] INPUT: "this is camel case"
    OUTPUT "thisIsCamelCase"
 2] INPUT: "Hi Atul here"
   OUTPUT: "hiAtulHere"
Example Explanation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int main() {
    int testCase;
    printf("Enter the no of test cases: ");
    scanf("%d", &testCase);
    printf("\n");

    while (getchar() != '\n'); // Clear the input buffer

    while (testCase--) {
        char str[1000];
        int flag = 0;
        printf("Enter a sentence: ");
        fgets(str, sizeof(str), stdin);
        
        printf("\nOriginal: %s", str); 
        for (int i = 0 ; i < strlen(str) ; i++) {
            if (i == 0) str[i] = tolower(str[i]);  //Converts to lowercase 
            else if (str[i] == ' ') flag = 1; // Check for spaces in the sentence
            else if (flag && str[i] != ' ') {
                str[i] = toupper(str[i]);  //Converts to uppercase
                flag = 0;
            }
            else str[i] = tolower(str[i]);  //Converts to lowercase
        }
        char camelCase[sizeof(str)];
        int i, j = 0;
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ') {
                camelCase[j++] = str[i];
            }
        }
        printf("Camel Case: %s\n", camelCase);
        printf("\n");
    }

    return 0;
}
