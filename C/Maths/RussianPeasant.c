#include <stdio.h>
// Function to multiply two numbers using Russian Peasant method
int russianPeasant(int a, int b) {
    // Initialize the result
    int res = 0;

    // While the second number doesn't become 1
    while (b > 0) {
        // If the second number becomes odd, add the first number to the result
        if (b & 1) {
            res = res + a;
        }

        // Double the first number and halve the second number
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
// Driver program
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int result = russianPeasant(a, b);
    printf("The result of multiplication is: %d\n", result);
    return 0;
}
