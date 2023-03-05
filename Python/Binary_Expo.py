"""
Binary exponentiation (also known as exponentiation by squaring)
is a trick which allows to calculate a^n using only O(log n) multiplications (instead of 
O(n) multiplications required by the naive approach).

The final complexity of this algorithm is 
O(log n): we have to compute log n powers of 
a, and then have to do at most  log n multiplications to get the final answer from them.
"""

def binary(Base, Exponent):
    if Exponent == 0:
        return 1
    res = binary(Base, Exponent // 2)
    if Exponent % 2 == 0:
        return res * res
    else:
        return res * res * Base

Base = int(input("Enter the Base: "))
Exponent = int(input("Enter the Exponent: "))
Answer = binary(Base, Exponent)
print("Answer is", Answer)

 
