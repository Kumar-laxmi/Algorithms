#!/usr/bin/env python

"""Counting Sort

This script demonstrates the counting sort algorithm, which sorts the elements
in linear time, but is more useful when the elements are in a limited range.
User inputs the elements of an unsorted array and they are output in sorted order.

    Time complexity = O(m + n)
    Space complexity = O(m)
where,
    m = range of elements
    n = number of elements


Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import List


def read_input() -> List[int]:
    """Reads input from standard input, removes leading/trailing
    whitespace, and casts the values to their appropriate datatypes.

    Returns:
        List[int]: List of integers representing the unsorted array
    """
    try:
        arr = list(map(int, input("Enter unsorted array: ").strip().split()))
    except ValueError:
        sys.exit("Only integer values expected for sorting.")

    return arr


def counting_sort(unsorted: List[int]) -> List[int]:
    """Sorts the elements of input list using the counting sort algorithm
    and returns a new sorted list.
    Algorithm:
        1. Find the minimum and maximum elements to find the range.
        2. Initialize empty list (counter) with size as the range,
        for counts of possible elements.
        3. Iterate over the unsorted array and store the counts of elements
        in the counter list.
        4. Updated counter list to have cumulative counts from minimum to maximum
        element. This will give the position of element in sorted array.
        5. Build the sorted array using the updated counter list.

    Args:
        unsorted (List[int]): Unsorted array

    Returns:
        List[int]: Sorted version of input array
    """
    size = len(unsorted)
    minm, maxm = min(unsorted), max(unsorted)  # Step 1
    counter = [0] * (maxm - minm + 1)  # Step 2

    for element in unsorted:  # Step 3
        counter[element - minm] += 1  # treating minm element as zero index

    for idx in range(1, maxm - minm + 1):  # Step 4
        counter[idx] += counter[idx - 1]

    # Step 5
    result = [0] * size
    n = size - 1
    while n >= 0:
        # processing unsorted elements in reverse order
        # sorted list is built without any particular order
        current = unsorted[n]
        result[counter[current - minm] - 1] = current
        counter[current - minm] -= 1  # update count after processing an element
        n -= 1
    return result


if __name__ == "__main__":
    unsorted = read_input()
    result = counting_sort(unsorted)
    print(f"Sorted elements: {result}\n")
