/*
  This C code takes an integer from the user and returns the reverse of it.
  Author: Anjali Singh
  Github :- @kookie3478

This program takes an integer input from the user and prints the reverse integer, for example if the user inputs "1234" it will output "4321".
first of all the required header files in c that is <stdio.h> and <math.h> are entered and then a integer is declared as n.
Now this is taken as input from user.
After that, we put on a while loop until n is greater than 0.
Then, we take the mod 10 value in order to find out the last digit of the entered number, then we take a zero initialised rev variable whole value we change again and again.

If we take an example, lets say the input is 1234, then for the first cycle, rev is zero, p is 4 and rev becomes 0+4 that is 4; again the number is divided by ten
to exclude the last digit, now for thr second cycle the number becomes 123 and rev is 4, so p is now 3 and then rev becomes after second cycle, 4*10+3 that is 43,
again the number is divided by 10, and this time it becomes 12.
As n is still greater than 0 so cycle continues.
for third time p=2, rev becomes 43*10+2 that is 432 and again the number is divided by 10;Now the number is 1 and it is greater than zero so cycle continues once more
and we get the value of rev as 432*10+1 that is 4321, after this the loop terminates as n becomes zero. So, our output is 4321.
*/
#include<stdio.h>
#include<math.h>
int main(){
    int n,rev=0,p;
    scanf("%d", &n);
    while(n>0){
        p=n%10;
        rev=rev*10+p;
        n/=10;
    }
    printf("%d\n", rev);
    return 0;
}
