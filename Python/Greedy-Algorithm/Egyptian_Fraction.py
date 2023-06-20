# Python program to print a fraction in Egyptian Form using Greedy Algorithm

def egyptianFraction(n, d):
    # When Both Numerator and denominator becomes zero then we simply return;
    if d == 0 or n == 0:
        return
    if d % n == 0:
        print("1/", d // n, sep='', end='')
        return
    if n % d == 0:
        print(n // d, end='')
        return
    if n > d:
        print(n // d, " + ", end='')
        egyptianFraction(n % d, d)
        return
    x = d // n + 1
    print("1/", x, " + ", end='', sep='')
    egyptianFraction(n * x - d, d * x)

# Main Function
numerator = int(input("Enter Numerator: "))
denominator = int(input("Enter Denominator: "))
print("Egyptian Fraction representation of", numerator, "/", denominator, "is")
egyptianFraction(numerator, denominator)