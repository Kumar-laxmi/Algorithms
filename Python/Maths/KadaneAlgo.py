# function implementing Kadane's Algorithm
def maxSum(ar, n):
    maxSumCurrIdx = ar[0]
    maxSum = 0
    for i in range(n):
        maxSumCurrIdx += ar[i]
        if(maxSum < maxSumCurrIdx):
            maxSum = maxSumCurrIdx
        if(maxSumCurrIdx < 0):
            maxSumCurrIdx = 0
    return maxSum

def main():
    # input code
    n = int(input("Enter array size : "))
    print("Enter array elements :", end=" ")
    ar = [int(i) for i in input().split()][:n]
    # function call & output
    print("Max Sum : ", maxSum(ar, n))

main()