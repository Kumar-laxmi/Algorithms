import math

def fact(n):
    factn = 1
    for i in range(1, n + 1):
        factn *= i
    return factn

print("Enter in (1+x)^n the values of x and n respectively")
x = int(input())
n = int(input())
nf = fact(n)
arr = [0] * (n + 1)

for i in range(n + 1):
    ncr = nf // (fact(i) * fact(n - i))
    arr[i] = ncr * pow(x, i)
    arr[n - i] = ncr * pow(x, n - i)

for i in arr:
    print(i, end=" ")
print()
