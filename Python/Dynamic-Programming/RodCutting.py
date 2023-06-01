#Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, find the optimal way to cut the rod into smaller rods to maximize profit.

import sys
 
 
# Function to find the best way to cut a rod of length `n`
# where the rod of length `i` has a cost `price[i-1]`
def rodCut(price, n):
 
    # base case
    if n == 0:
        return 0
 
    maxValue = -sys.maxsize
 
    # one by one, partition the given rod of length `n` into two parts of length
    # (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0) and take maximum
    for i in range(1, n + 1):
 
        # rod of length `i` has a cost `price[i-1]`
        cost = price[i - 1] + rodCut(price, n - i)
 
        if cost > maxValue:
            maxValue = cost
 
    return maxValue
 
 
if __name__ == '__main__':
 
    price = [1, 5, 8, 9, 10, 17, 17, 20]
 
    # rod length
    n = 4
 
    print('Profit is', rodCut(price, n))
 

