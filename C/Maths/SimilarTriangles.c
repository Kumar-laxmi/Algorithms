// Similar Triangles Program
// It can be used to check whether the two traingles are similar or not.
// Author: @swastik-akhil


#include <stdio.h>
int main(void) {

// SSS property
    int a1 = 3, b1 = 4, c1 = 5;
    int a2 = 6, b2 = 8, c2 = 10;
    if (a1/a2 == b1/b2 && b1/b2 == c1/c2) {
         printf("The triangles are similar\n");
    } else {
         printf("The triangles are not similar\n");
    }
    

// AA property

    int x1 = 40, x2 = 70;
    int y1 = 40, y2 = 70;
    if(x1==y1 && x2==y2){
        printf("The triangles are similar\n");
    } else {
        printf("The triangles are not similar\n");
    }


//SAS property 


    int a3= 3,m = 50, b3 = 4 ;
    int a4 = 6, n = 50, b4 = 8;
    if (a3/a4 == b3/b4 && m == n) {
         printf("The triangles are similar\n");
    } else {
         printf("The triangles are not similar\n");
    }
}
