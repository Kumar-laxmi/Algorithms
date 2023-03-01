/*
  ------------------------------------------------- PREREQUISITE ---------------------------------------------------------

    --> Modular Multiplicative inverse exist when two numbers are CO-PRIME to each other in other words the two numbers gcd = 1
    --> Modular Multiplicative inverse changes with respective modulo value and not remain same for the number.

  ---------------------------------------- Modulo Multiplicative Inverse(MMI) --------------------------------------------

    Inverse of a number (A) will be = A^-1 or we can say that --> A * A^-1 will be equal to 1
    but incase of modular multiplicative inverse of a number (A) is when the expression below is true

                    (A*A^-1) mod (C) = 1

    from the expression we can say that A^-1 will be the inverse of A.

    Example:-
         We have to find the Modulo Multiplicative inverse of 2 whose mod is 5
         From the formula
            (A*A^-1) mod (C) = 1 now will be --> (2*A^-1) mod (5) = 1
         we have to find the A^-1 value
         simply we can use a loop to iterate upto the mod value and find the inverse by the below method
            (2*A^-1) mod (5) = 1 now,
           --> (2*1)%5 = 2 which is not equal to 1 so increment
           --> (2*2)%5 = 4 which is not equal to 1 so increment
           --> (2*1)%5 = 1 which is equal to 1 so,
           for the number 2 the modular multiplicative inverse will be 3 when modulo is 5. If modulo changes the modulo multiplicative
           inverse changes.

  ------------------------------------------- The Problem Statement ------------------------------------------------------

   Given two numbers, the first one is the number which we want to find the modulo multiplicative inverse and
   the second one is the modulo value

   INPUT :- 2 <-- number which we want to find modulo multiplicative inverse
            5 <-- the respective modulo value

   OUTPUT :- 3

  ---------------------------------------- The Problem of normal approach ------------------------------------------------

    To find mmi we can simply use a for loop starting from 0 to value of mod in-between the mmi exist a BigO(n) approach,
    it is good for small numbers,the problem starts when the modulo is increased lets say the value of modulo is 21783,
    in this case the loop runs for 21783 times to find the mmi in worst case which takes a huge time to compute for that
    we go for an algorithm called the EXTENDED EUCLIDEAN ALGORITHM to find the mmi which takes BigO(log(n)) time which is
    a significant reduction in time complexity, log(21783) = 4.338 so the loop at worst case itself runs 4 times only.

  ------------------------------------------ Extended Euclidean Algorithm ------------------------------------------------

    a.x + b.y = gcd                      --(1)

    And x1 and y1 are results for inputs b%a and a
    (b%a).x1 + a.y1 = gcd

    When we put b%a = (b – ([b/a]).a) in above,
    we get following. Note that [b/a] is floor(b/a)
    (b – ([b/a]).a).x1 + a.y1  = gcd

    Above equation can also be written as below
    b.x1 + a.(y1 – ([b/a]).x1) = gcd      --(2)

    After comparing coefficients of ‘a’ and ‘b’ in (1) and (2), we get following,
    x = y1 – (b/a) * x1
    y = x1

  ----------------------------------------------- Complexities -----------------------------------------------------------

    Time Complexity  --> BigO(log(n))
    Space Complexity --> BigO(1)
    Space Complexity --> BigO(n) --> In case of recursion.


 */

// Importing necessary things.
#include<stdio.h>

// The main function which performs the mmi
int main()
{
	// Declaring the number and modulus variable
	int number,modulus;
	
	// Alerting the user about the number and modulo value
	printf("TO FIND MMI THE TWO NUMBERS SHOULD BE COPRIME TO EACH OTHER OR THE GCD OF TWO NUMBERS SHOULD BE EQUAL TO 1, \n");
	printf("OTHERWISE THE INVERSE DOESNT EXSIST\n");
	
	// Reading the value of the number which user want to find inverse
	printf("\nEnter a number you want to find inverse = ");
	scanf("%d",&number);
	
	// Reading the modulo value
	printf("Enter the modulo value = ");
	scanf("%d",&modulus);
	
	// When the modulus is 1 then the inverse will be 0
	if(modulus ==1)
	{
		printf("\nThe multiplicative inverse of %d is %d when their modulo %d ",number,0,modulus);
	}
	
	// Computing the value of modulo multiplicative inverse
	else
	{
		// Declaring the necessary variables 
		int num = number;
		int modulo = modulus;
    	int t1=0;
    	int t2=1;
    	
    	// The staring and ending point of the loop
    	while(number > 1)
    	{
    		// Finding the quotient of the number with modulo
        	int quo = number/modulus;
        	
        	// Storing the value of modulus since it will be changed.
        	int t = modulus;
        	
        	// Finding the remainder of the number with modulo
        	int rem = number%modulus;
        	
        	// Changing the value of modulus
        	modulus = rem;
        	
        	// Changing the value of number which want to find inverse
        	number = t;
        	
        	// The Extended Euclidean Algorithm
        	// To find the value of MMI
        	t = t1;
        	t1 = t2-quo*t1;
        	t2 = t;
    	}
    	
    	// Converting the mmi value to positive if it is negative.
    	if(t2<0)
    	{
        	t2+=modulo;
    	}
    	
    	// Printing the value of Modulo Multiplicative Inverse
    	printf("\nThe multiplicative inverse of %d is %d when their modulo %d ",num,t2,modulo);
	}	
}
