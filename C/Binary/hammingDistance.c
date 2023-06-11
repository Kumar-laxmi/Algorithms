#include <stdio.h>

int main(){
    /*  
          XOR TABLE
            X Y Z
            0 0 0
            0 1 1
            1 0 1
            1 1 0
    */
    int x = 0, y =0, count=0; // taking two values as test cases
    printf("Enter the value of X: ");
    scanf("%d",&x);

    printf("Enter the value of Y: ");
    scanf("%d",&y);

    int res = x ^ y ; // taking xor of the two values to get different bits

    // counting number of 1 present in the res 
    while(res>0){
        count += res & 1;
        res >>= 1;
    }
    printf("The result is : %d",count);// printing the value of bits
    return 0;
}