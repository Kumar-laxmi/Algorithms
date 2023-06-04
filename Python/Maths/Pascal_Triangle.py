# 
#     1
#    1 1
#   1 2 1
#  1 3 3 1
# 1 4 6 4 1

# Each number in the triangle is the sum of the two numbers directly above it.

# we take number of rows as input
# And we know that to find any element at particular position (i.e at ith row and cth column) we can use the combination formula nCr.
#   nCr=factorial(n)/(factorial(r)*factorial(n-r))

def factorial(n):
    result = 1
    for c in range(1, n+1):
        result *= c
    return result

n = int(input("Enter the number of rows you wish to see in Pascal's Triangle:\n"))

for i in range(n):
    for c in range(n - i - 1):
        print(" ", end="")

    for c in range(i + 1):
        coeff = factorial(i) // (factorial(c) * factorial(i - c))
        print(coeff, end=" ")

    print()
