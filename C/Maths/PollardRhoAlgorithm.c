#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to efficiently calculate (base^exponent) % modulus
long long modular_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// Helper function to calculate the greatest common divisor of a and b
long long gcd(long long a, long long b);

// Pollard's Rho algorithm to find a non-trivial divisor of n
long long PollardRho(long long n) {
    if (n == 1)
        return n;
    if (n % 2 == 0)
        return 2;
    
    // Seed the random number generator
    srand(time(NULL));
    
    long long x = (rand() % (n - 2)) + 2;
    long long y = x;
    long long c = (rand() % (n - 1)) + 1;
    long long d = 1L;

    while (d == 1) {
        x = (modular_pow(x, 2, n) + c + n) % n;
        y = (modular_pow(y, 2, n) + c + n) % n;
        d = gcd(abs(x - y), n);
        if (d == n)
            return PollardRho(n);
    }

    return d;
}
// Helper function to calculate the greatest common divisor of a and b
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    long long n = 10967535067LL;
    printf("The divisor for %lld is %lld\n", n, PollardRho(n));
    return 0;
}
