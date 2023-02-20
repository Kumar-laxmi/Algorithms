// C program to check if the number is a Perfect number or not

#include<stdio.h>

int main() {
   
    // initialize variable for loop, input number and to store sum 
    int i, num, sum = 0;
    
    // take user input 
    printf("\nEnter a number : ");
    scanf("%d", &num);
    
    // iterate from 1 to N and if the number is a factor of N then add it to sum
    for(i=1; i<num; i++) {
        if(num%i == 0) {
            sum += i;
        }
    }
    
    // if sum of factors of N is equal to N then it is a perfect number
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
