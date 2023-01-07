#0-1 Knapsack Problem in best possible Time & Space Complexity
#Time complexity = O(N*N)
#Space complexity = O(N)

def knapSack(W, wt, val, n):

    dp = [0 for i in range(W+1)]
    
    for i in range(n):
        for j in range(W, 0, -1):
            if j-wt[i]>=0:
                dp[j] = max(dp[j], val[i]+dp[j-wt[i]])
                
    return dp[-1]

print('Enter the maximum capacity of Knapsack:')
W = int(input())

print('Enter the number of items available:')
n = int(input())

print('Enter the weights of items (in space separated format):')
wt = [int(i) for i in input().split(' ')]

print('Enter the values of items (in space separated format):')
val = [int(i) for i in input().split(' ')]

res = knapSack(W, wt, val, n)

print('Maximum value that can be attained: {}'.format(res))
