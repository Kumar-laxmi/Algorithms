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
