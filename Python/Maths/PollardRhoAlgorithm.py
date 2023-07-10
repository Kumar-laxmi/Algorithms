import random
# Function to efficiently calculate (base^exponent) % modulus
def modular_pow(base, exponent, modulus):
    result = 1
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent = exponent >> 1
        base = (base * base) % modulus
    return result
# Pollard's Rho algorithm to find a non-trivial divisor of n
def PollardRho(n):
    if n == 1:
        return n
    if n % 2 == 0:
        return 2
    # Randomly choose initial values
    x = random.randint(2, n - 2)
    y = x
    c = random.randint(1, n - 1)
    d = 1
    while d == 1:
        # Generate next values for x and y
        x = (modular_pow(x, 2, n) + c + n) % n
        y = (modular_pow(y, 2, n) + c + n) % n
        y = (modular_pow(y, 2, n) + c + n) % n
        
        # Calculate GCD of absolute difference and n
        d = gcd(abs(x - y), n)        
        # If d is equal to n, recursion is needed
        if d == n:
            return PollardRho(n)
    return d

# Helper function to calculate the greatest common divisor of a and b
def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
n = 10967535067
print(f"The divisor for {n} is {PollardRho(n)}")
