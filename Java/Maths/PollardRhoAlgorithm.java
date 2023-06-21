/* Java program to find a prime factor of composite using Pollard's Rho algorithm */
import java.util.*;
class PollardRhoAlgorithm
{
static long modular_pow(long base, int exponent,long modulus)
{
	long result = 1;
	while (exponent > 0)
	{
			if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

static long PollardRho(long n)
{
	Random rand = new Random();
	if (n == 1) return n;
	if (n % 2 == 0) return 2;
	long x = (long)(rand.nextLong() % (n - 2)) + 2;
	long y = x;
	long c = (long)(rand.nextLong()) % (n - 1) + 1;
	long d = 1L;
	while (d == 1)
	{
		x = (modular_pow(x, 2, n) + c + n) % n;
		y = (modular_pow(y, 2, n) + c + n) % n;
		y = (modular_pow(y, 2, n) + c + n) % n;
		d = __gcd(Math.abs(x - y), n);
		if (d == n) return PollardRho(n);
	}
	return d;
}

static long __gcd(long a, long b)
{
return b == 0? a:__gcd(b, a % b);	
}
public static void main(String[] args)
{
	long n = 10967535067L;
	System.out.printf("the divisors for " + n + " is " +	PollardRho(n));
}
}


