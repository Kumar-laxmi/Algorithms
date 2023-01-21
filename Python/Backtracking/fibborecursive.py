def fibborecursive(n):
    if n==0:
        return 0
    elif(n==1):
        return 1
    else:
        return fibborecursive(n-1) + fibborecursive(n-2)

if __name__ == "__main__":
    num = int(input("Enter a number"))
    print(f"The value using recursion method: fibbonacci({num}) is {fibborecursive(num)}")
    