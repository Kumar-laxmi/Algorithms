// C program to check if the number is an Armstrong number or not

#include <stdio.h>
#include <math.h>

// Function to return the number of digits of a number
int digits(long number){
    int d = 0;
    while (number > 0){
        number = number/10;
        d++;
    }
    return d;
}

// Function to find the sum of digits with the power of length
int sumPowerOflen(long number, int length){
    int sum = 0;
    while(number){
        int r = number%10;
        sum += round(pow(r, length));
        number /= 10;
    }
    return sum;
}

int main(){
    long number;
    printf("Enter a number to check if it is armstrong or not: ");
    scanf("%ld", &number);

    // Calling digits() function
    int length = digits(number);

    // Calling sumPowerOflen() function
    int sum = sumPowerOflen(number, length);

    // Checking if sum is equal to the given number
    if (sum == number)
        printf("%ld is an Armstrong number", number);
    else
        printf("%ld is not an Armstrong number", number);
    return 0;
}

/*******************************************************
Case 1:
Enter a number to check if it is armstrong or not: 153
153 is an Armstrong number

Case 2:
Enter a number to check if it is armstrong or not: 233
233 is not an Armstrong number

Case 3:
Enter a number to check if it is armstrong or not: 1634
1634 is an Armstrong number
*******************************************************/