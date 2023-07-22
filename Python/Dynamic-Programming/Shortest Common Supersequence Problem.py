# Function to find the length of the shortest common supersequence of
# sequences `X[0…m-1]` and `Y[0…n-1]`
def SCSLength(X, Y, m, n):
 
    # if the end of either sequence is reached, return
    # the length of another sequence
    if m == 0 or n == 0:
        return n + m
 
    # if the last character of `X` and `Y` matches
    if X[m - 1] == Y[n - 1]:
        return SCSLength(X, Y, m - 1, n - 1) + 1
 
    # last character of `X` and `Y` don't match
    return min(SCSLength(X, Y, m, n - 1) + 1, SCSLength(X, Y, m - 1, n) + 1)
 
 
if __name__ == '__main__':
 
    X = 'ABCBDAB'
    Y = 'BDCABA'
 
    m = len(X)
    n = len(Y)
 
    print('The length of the shortest common supersequence is', SCSLength(X, Y, m, n))