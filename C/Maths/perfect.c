// C program to check if the number is a Perfect number or not

#include<stdio.h>

int main() {
    int i, num, sum = 0;
    printf("\nEnter a number : ");
    scanf("%d", &num);
    for(i=1; i<num; i++) {
        if(num%i == 0) {
            sum += i;
        }
    }
    if(sum == num) {
        printf("\n%d is a Perfect Number\n", num);
    } else {
        printf("\n%d is not a Perfect Number\n", num);
    }
    return 0;
}


/*******************************************************
Case 1:
Enter a number : 153
153 is not a Perfect Number

Case 2:
Enter a number : 496
496 is a Perfect Number
*******************************************************/
