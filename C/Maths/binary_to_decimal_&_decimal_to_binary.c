/* C program to convert binary number to decimal and decimal to binary */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n  ; 
    int binary_to_decimal();  //This function returns given binary to decimal number
    int decimal_to_binary();  //This function returns given decimal to binary number
    
    printf("\n1.Binary to Decimal\t2.Decimal to Binary\t3.Exit");
    while(1)
    {
        printf("\n\nEnter you choice:");
        scanf("%d", &n);
    switch(n)
    {
        case 1 : binary_to_decimal() ; 
        break ; 
        
        case 2 : decimal_to_binary() ;
        break ; 
        
        case 3 : exit(0) ; 
        break ; 
        
    }
}
    return 0 ; 
}

    int binary_to_decimal() {
        long long num  ;  /*The convert_to_dec function takes the long long integer "num" as the input given by the user 
                          The reason "num" can have  a datatype "long long" because the size is 8 memory bytes(64 bits ) */
        int deci; 
        int convert_to_dec(long long);
        printf("\nEnter the binary number:  ");
        scanf("%lld", &num);
        int st = clock() ; //st = start time 
        deci = convert_to_dec(num) ; 
        int et = clock() ; //et = total time 
        int tt = et - st ; //tt = total time (Returns number of ticks since the function was launched )
        double total_t = (double)(et - st)/CLOCKS_PER_SEC ; //Returns total time in seconds 
        
        printf("\nBINARY EQUIVALENT OF %lld IS %d\n", num, deci);
        printf("\nStart time: %d \nEnd Time:%d " , st , et );
        printf("\nNumber of clock ticks elapsed: %d\n" , tt) ;
        printf("\nTotal time taken(in seconds): %f\n ",total_t);
        
        return 0;
    }

    int convert_to_dec(long long num) {
        int decimal = 0, i = 0, rem;

        while (num > 0) {  
          rem = num % 10;  //Divide "num" by 10 using modulo operator 
          num = num/10;    //Divide using division operator  inorder to discard the rightmost digit 
          decimal += rem * pow(2, i); //Iteratively add rem*pow(2,i) to "decimal" variable 
          ++i;  //The power of 2 is used since binary is base 2 representation 
        }
   return decimal;
}



    int decimal_to_binary() {
        int num;
        long long binary;
        long long convert_to_bin(int);
        printf("\nEnter the decimal number: ");
        scanf("%d", &num);
        int st = clock() ; 
        binary = convert_to_bin(num);
        int et = clock() ; 
        int tt= et - st  ;
        double total_t = (double)(et - st)/CLOCKS_PER_SEC ;
        printf("\nDECIMAL EQUIVALENT OF %d  %lld\n", num, binary);
        printf("\nStart time: %d \nEnd Time: %d " , st , et );
        printf("\nNumber of clock ticks elapsed: %d\n" , tt) ;
        printf("\nTotal time taken(in seconds): %f\n ",total_t);
       return 0;
    }

   long long convert_to_bin(int num) {
        long long binary = 0;
        int rem, i = 1;
        
        while (num > 0) {
         rem = num % 2; //Divide "num" by 2 using modulo operator , returns remainder .  
         num = num/2;   //Divide "num" by 2 using division operator.The value obtained is passed to while loop  
         binary += rem * i; //Iteratively add rem*i to "binary" variable 
         i = i * 10;  //Since decimal is base 10 representation 
        }
    return binary;
}