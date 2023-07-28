def russian_peasant(a, b):
    res = 0
    while b > 0:
        if b & 1:
            res += a
        a <<= 1
        b >>= 1
    return res
def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    result = russian_peasant(a, b)
    print("Result:", result)
if __name__ == "__main__":
    main()
