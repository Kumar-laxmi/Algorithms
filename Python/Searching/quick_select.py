# Path: Python\Searching\quick_select.py
# Python program to kth smallest element using quickSelect Algorithm.
# Time-Complexity: O(N^2), where N is the size of array.

import random

# Function to swap two elements in the list
def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]

# Partition function to rearrange elements around the pivot
def partition(arr, left, right, pivotIndex):
    pivotValue = arr[pivotIndex]
    swap(arr, pivotIndex, right) # Move pivot to the end
    storeIndex = left

    for i in range(left, right):
        if arr[i] < pivotValue:
            swap(arr, i, storeIndex)
            storeIndex += 1
    swap(arr, storeIndex, right) # Move pivot to its final place
    return storeIndex

# Quickselect function
def quickSelect(arr, left, right, k):
    if left == right:
        return arr[left]

    pivotIndex = left + random.randint(0, right - left)
    pivotIndex = partition(arr, left, right, pivotIndex)

    if k == pivotIndex:
        return arr[k]
    elif k < pivotIndex:
        return quickSelect(arr, left, pivotIndex - 1, k)
    else:
        return quickSelect(arr, pivotIndex + 1, right, k)

if __name__ == "__main__":
    arr = [3, 8, 2, 5, 1, 4, 7, 6]
    k = 4  # Find the 4th smallest element

    result = quickSelect(arr, 0, len(arr) - 1, k - 1)
    print(f"The {k}-th smallest element is: {result}")
