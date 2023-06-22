#include <stdio.h>

int isHappy(int n) {
    int seen[1000] = {0};

    while (n != 1) {
        int current = n;
        int sum_of_squares = 0;

        while (current != 0) {
            int digit = current % 10;
            sum_of_squares += digit * digit;
            current /= 10;
        }

        if (seen[sum_of_squares] == 1) {
            return 0; // Entered a cycle containing 4, so it's an unhappy number
        }

        seen[sum_of_squares] = 1;
        n = sum_of_squares;
    }

    return 1; // Reached 1, so it's a happy number
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int isHappyNumber = isHappy(number);
    printf("%d is a happy number: %s\n", number, isHappyNumber ? "true" : "false");
    return 0;
}
