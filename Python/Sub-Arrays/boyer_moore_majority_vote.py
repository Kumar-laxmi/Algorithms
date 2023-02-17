#!/usr/bin/env python

"""Boyer-Moore Majority Vote algorithm

This script takes a list of integers as input and finds the majority element.
The majority element is defined as the element with number of occurances
greater than N/2, where N is the length of the array. If no majority element
is present, it displays None.
Comparison of time and space complexity:
    1. Brute force approach: O(n^2) time and O(1) space
    2. Map approach: O(n) time and O(1) space
    3. Boyer-Moore algorithm: O(n) time and O(1) space

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import List


def find_majority_element(arr: List[int]) -> int:
    """Finds the majority element in the list of integers using
    Boyer-Moore majority vote algorithm. Returns None if no majority
    element exists.
    Algorithm:
        1. Start with count = 0 and num = 0
        2. Iterate over the elements of the array
        3. If count = 0, assign element to num
        4. If current element = num, increment count
           else decrement count
        5. After completion of one pass, reset count = 0
        6. Current value in num should be majority element, if valid.
           Iterate over the array and find count of num.
        7. If count > N/2, num is majority element else there is none.

    Args:
        arr (List[int]): array of integers to be searched

    Returns:
        int: majority element if it exists, else None
    """
    num = 0
    count = 0  # Step 1
    for x in arr:  # Step 2
        if count == 0:  # Step 3
            num = x
        if num == x:  # Step 4
            count += 1
        else:
            count -= 1

    count = 0  # Step 5
    for x in arr:
        if x == num:
            count += 1  # Step 6

    if count > len(arr) // 2:  # Step 7
        return num
    else:
        return None


def read_input() -> List[int]:
    """Reads from standard input and converts it to a list
    of integers. Exits the program if invalid input is found.

    Returns:
        List[int]: array of integers to be searched
    """
    try:
        arr = list(map(int, input("Input integer array: ").strip().split()))
    except ValueError:
        sys.exit("Only integers expected.")

    return arr


if __name__ == "__main__":
    arr = read_input()
    num = find_majority_element(arr)
    print(f"Majority element: {num}\n")
