/*Binary exponentiation (also known as exponentiation by squaring)is a trick which allows to 
calculate a^n using only O(log n) multiplications (instead of 
O(n) multiplications required by the naive approach).

The final complexity of this algorithm is O(log n): we have to compute log n powers of 
a, and then have to do at most  log n multiplications to get the final answer from them.
*/

#include <stdio.h>

long long int binary(int Base, int Exponent){
     if (Exponent==0)
         return 1 ;
     long long res = binary(Base , Exponent / 2);
     while (Exponent > 0 ){
      if (Exponent %2 ==0)
         return res * res ;
     else 
         return res * res * Base ;
     
     }
    
 }
 int main(){
     int Base , Exponent ; 
     printf("Enter the Base : ");
     scanf("%d" , &Base);
     printf("Enter the Exponent : ");
     scanf("%d", &Exponent);
     long long int Answer = binary(Base,Exponent);
     printf("\n%d^%d =  %lld",Base , Exponent , Answer);
     return 0 ; 
     
 }
 
 
 
 
