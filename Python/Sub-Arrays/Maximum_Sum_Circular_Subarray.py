
""" Maximum Sum Circular Subarray

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Python: 3.10.8
External packages: None

Author: Sitam Meur (github.com/sitamgithub-MSIT)
"""

import sys
from typing import List


def maxSubarraySumCircular(arr: List[int]) -> int:
    """Finds the maximum sub-array sum in the list of integers using
    Kadane algorithm. Returns the maximum sub-array sum.
    Algorithm:
        1. Calculate the maximum subarray maxSum using Kadane's algorithm.
        2. Calculate the minimum subarray minSum using Kadane's algorithm, by using Math.min() instead of Math.max().
        3. Corner case where the max-element in the array is negative or zero then return that only. 
        4. Else, return max(global_max, sum - global_min).

    Args:
        arr (List[int]): array of integers to be used

    Returns:
        int: maximum sub-array sum
    """
    # Corner Case

    if max(arr)<=0:
        return max(arr)
    
    # Initialize every variable
	# with first value of array.

    global_min, local_min = arr[0], arr[0]
    global_max, local_max = arr[0], arr[0]

    # Concept of Kadane's Algorithm

    for i in range(1,len(arr)):

        # Kadane's Algorithm to find Maximum subarray sum.

        local_max = max(local_max, local_max + arr[i])
        global_max = max(global_max, local_max)

        # Kadane's Algorithm to find Minimum subarray sum.

        local_min = min(local_min, local_min + arr[i])
        global_min = min(global_min, local_min)

    # returning the maximum value

    return(max(global_max, sum(arr) - global_min))
    



def read_input() -> List[int]:
    """Reads from standard input and converts it to a list
    of integers. Exits the program if invalid input is found.

    Returns:
        List[int]: array of integers to be used to find the maximum sub-array sum. 
    """
    try:
        arr = list(map(int, input("Input integer array: ").strip().split()))
    except ValueError:
        sys.exit("Only integers expected.")

    return arr


if __name__ == "__main__":
    arr = read_input()
    num = maxSubarraySumCircular(arr)
    print(f"Maxiumum Sub-array Sum: {num}\n")
