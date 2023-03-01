''' 
function implementing Kadane's Algorithm
Kadane Algorithm is used to find Largest Sum Contiguous Subarray
It works in O(N) Time Complexity and O(1) Space Complexity
 '''


def maxSubArraySum(nums):
    # Initialize the maxSoFar variable with the first element of the array
    maxSoFar = nums[0]
    # Initialize the maxEndingHere variable with the first element of the array
    maxEndingHere = nums[0]
    # iterate through the array starting from the second element
    for i in range(1, len(nums)):
        # update maxEndingHere with the maximum of the current element or current element plus maxEndingHere
        maxEndingHere = max(nums[i], maxEndingHere + nums[i])
        # update maxSoFar with the maximum of maxSoFar and maxEndingHere
        maxSoFar = max(maxSoFar, maxEndingHere)
    # return the final maxSoFar value
    return maxSoFar


def main():
    # input code
    n = int(input("Enter array size : "))
    print("Enter array elements :", end=" ")
    ar = [int(i) for i in input().split()][:n]
    # function call & output
    # Get the maximum sum of a contiguous subarray by calling the maxSubArraySum function
    print("Max Sum : ", maxSubArraySum(ar))


# call the main function
main()
