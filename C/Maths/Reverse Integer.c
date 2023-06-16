/*
  This C code takes an integer from the user and returns the reverse of it.
  -author~ Akhil Agrawal
  Github :- @swastik-akhil
The provided code is a C program that prompts the user to enter an integer, converts it to a string representation, reverses the string, and then prints the reversed number. 

First, the necessary header files, `stdlib.h` and `string.h`, are included. 

The `reverse` function takes a pointer to a character array and reverses the characters in the string using a loop and a temporary variable. 

In the `main` function, an integer variable `num` and a character array `strNum` are declared. 

The user is prompted to enter an integer using `printf`. 

The entered integer is read using `scanf` and stored in `num`. 

The `sprintf` function converts `num` to a string representation in `strNum` with zero-padding of 5 digits. 

The `reverse` function is called, passing `strNum` as an argument. 

Finally, the reversed number is printed using `printf`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    int num;
    char strNum[20];

    printf("Enter an integer: ");
    scanf("%d", &num);

    sprintf(strNum, "%05d", num);

    reverse(strNum);

    printf("Reversed number: %s\n", strNum);

    return 0;
}
