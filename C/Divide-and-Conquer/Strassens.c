/* Strassens multiplication is a recursive algorithm for multiplying n*n matrices ( here , 2*2 matrices)
The time complexity for :
1) Strassens multiplication --> O(n^2.8) . 
2) Matrix multiplication --> O(n^3) . 
 
The time complexity is less compared to matrix multiplication . 

There will be 2 matrix A and B , to calculate A X B , we need to calculate using seven multiplications .
The seven multplications are : 
1) p1 = a * (f - h )
2) p2 = (a + b ) * h  
3) p3 = (c + d ) * e  
4) p4 = d * (g - e)
5) p5 = (a + d)*(e + h)
6) p6 = (b - d)* (g + h)
7) p7 = (a - c ) * (e + f)

To calculate Matrix C (also known as A X B) :
r = p5 + p4 - p2 + p6
s = p1 + p2 
t = p3 + p4 
u = p5 + p1 - p3 - p7


Matrix A = [ a , b]     Matrix B = [e , f]       Matrix C = [r , s]  
           [ c , d]                [g , h]                  [t , u]
       
*/      

#include<stdio.h>
int main(){
    int  a ,b ,c ,d ,e ,f ,g, h,p1 , p2 , p3 , p4 , p5 , p6 , p7 ,r,s,t,u , i ;
    printf("Enter values for matrix A (2*2): \n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf(" __________\n");
    printf("| %d  | %d  |\n",a ,b );
    printf("|____| ___|\n");
    printf("| %d  | %d  |\n",c, d);
    printf("|____| ___|\n");
    
    printf("\nEnter values for matrix B (2*2): \n");
    scanf("%d %d %d %d", &e, &f, &g, &h);
    
    printf(" __________\n");
    printf("| %d  | %d  |\n",e ,f );
    printf("|____| ___|\n");
    printf("| %d  | %d  |\n",g, h);
    printf("|____| ___|\n");

p1 = a * (f - h );
p2 = (a + b ) * h ; 
p3 = (c + d ) * e ; 
p4 = d * (g - e);
p5 = (a + d)*(e + h);
p6 = (b - d)* (g + h);
p7 = (a - c ) * (e + f);


r = p5 + p4 - p2 + p6;
s = p1 + p2 ;
t = p3 + p4 ;
u = p5 + p1 - p3 - p7;

printf("\nThe solution A X B matrix is :\n");
printf(" ________ \n");
printf("|%d  | %d |\n",r ,s );
printf("|____|____|\n");
printf("|%d  |%d  |\n",t, u);
printf("|____|____|\n");


}
