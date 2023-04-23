def fib(n, dp):
    if n <= 0:
        print(-1)
        return -1
    f1 = -1
    f2 = -1
    if n == 2:
        print(f"{n-2} {n-1} ", end="")
        dp[(n-2)] = (n-2)
        dp[(n-1)] = (n-1)
        return (n-1)
    if n == 1:
        print(f"{n-1} ")
        dp[(n-1)] = (n-1)
        return (n-1)
    for i in range(n):
        if dp[i] != -1 and i == (n-2):
            f1 = dp[i]
        if dp[i] != -1 and i == (n-3):
            f2 = dp[i]
    if f1 == -1:
        f1 = fib(n-1, dp)
        dp[n-2] = f1
    for i in range(n):
        if dp[i] != -1 and i == (n-2):
            f1 = dp[i]
        if dp[i] != -1 and i == (n-3):
            f2 = dp[i]
    dp[n-1] = (f1+f2)
    print(f"{f1+f2} ", end="")
    return (f1+f2)


n = int(input("Enter a Number : "))
dp = [-1 for i in range(n)]
fib(n, dp)
 
