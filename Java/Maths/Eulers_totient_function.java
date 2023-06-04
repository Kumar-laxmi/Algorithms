/*--------------------------------Introduction------------------------------------------------------*/
// A  java program to calculate
// Euler's Totient Function i.e phi(n)=no of positive integers  less than n that are realtiveli prime to n.

/*--------------------------------Algorithm------------------------------------------------------*/
/*1. we first list down all the no's less than n starting from 1.
  2. then we find the gcd of each and every integer with n.
  3.then we compare if the gcd is =1 we count it in result and hence display the result i.e the phi(n) 
  */ 
import java.io.*;

class Eulers_totient_function {

	// Function to return GCD of a and b
	static int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	
	//calculates eurel totient function.
	static int phi(int n)
	{
		int result = 1;
		for (int i = 2; i < n; i++)//starting from 2 as gcd of any no with 1 is always 1.
			if (gcd(i, n) == 1)//checks if gcd if the no's is 1 or not.
				result++;
		return result;
	}

	// Driver code
	public static void main(String[] args)
	{
		int n;

		for (n = 1; n <= 20; n++)
			System.out.println("phi(" + n + ") = " + phi(n));
	}
}

// This code is contributed by kritika singh.
