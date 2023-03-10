#include<stdio.h>
int main()
{
	// Declaring the variables.
	int base,power,modulo;
	// Reading the base,power,modulo values from the user.
	printf("Enter base value = ");
	scanf("%d",&base);
	printf("Enter power value = ");
	scanf("%d",&power);
	printf("Enter modulo value = ");
	scanf("%d",&modulo);
	// Update base if it is more than or equal to modulo
	base = base % modulo;
	// Initializing the result variable to store the modular exponentiation value.
    int result = 1;
    // In case base is divisible by modulo;
    if (base == 0)
    {
    	printf("0");	
	}
    while (power > 0)
    {
    	// If power is odd, multiply base with result
        if ((power & 1) != 0)
        {
        	result = (result * base) % modulo;	
		}
		// power must be even now
        // power = power/2
        power = power >> 1;
        base = (base * base) % modulo;
    }
    // Printing the modular exponentiation value.
    printf("Modular Exponentiation = %d ",result);
    return 0;
}
