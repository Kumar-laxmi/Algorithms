def numberOfWays(coins, n, sum):
    dp = [[0 for i in range(sum+1)] for j in range(n+1)] #declaring a dp

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, sum+1):
            if coins[i-1]<=j:
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]
            
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][sum]         

n = int(input())    
sum = int(input())  

coins = list(map(int,input().strip().split()))

print(numberOfWays(coins,n,sum))