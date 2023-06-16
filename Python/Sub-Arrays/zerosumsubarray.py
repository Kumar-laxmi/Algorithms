# O(n) time | O(n) space
def zeroSumSubarray(nums):
    sums = set()  # Set to store cumulative sums
    currentSum = 0  # Variable to store the current sum
    for num in nums:
        currentSum += num  # Add the current number to the current sum
        if currentSum == 0 or currentSum in sums or num == 0:
            # If current sum is zero or already exists in the set, or the current number is zero,
            # then there is a zero sum subarray
            return True
        sums.add(currentSum)  # Add the current sum to the set
    return False  # No zero sum subarray found
