"""----------------------------------------------Introduction---------------------------------------------------------------------------
 * The Exponential_search class provides an implementation of the exponential search algorithm in Java.
 * It can be used to search for an element in a sorted array.
 """

"""---------------------------------------------Algorithm------------------------------------------------------------------------------
  * The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until 
  last element of a subarray is not greater. Once we find an index i (after repeated doubling of i), we know that the
   element must be present between i/2 and i
  """

 #  Searches for a target element in a sorted array using Binary search.
def binary_search(arr, target, left, right):
    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # Element not found

  # Searches for a target element in a sorted array using exponential search.
def exponential_search(arr, target):
    if arr[0] == target:
        return 0

    n = len(arr)
    i = 1
    while i < n and arr[i] <= target:
        i *= 2 #jumps to the two timed index.

    return binary_search(arr, target, i // 2, min(i, n - 1))


<<<<<<< HEAD
arr = [2, 4, 8, 16, 32, 64, 128, 256]
target = 32
=======


arr = []
n = int(input("Number of elements in the array: "))
for i in range(n):
    k = int(input("Enter an element: "))
    arr.append(k)

arr.sort()  # Sort the array in ascending order

target = int(input("Enter the target element: "))


result = exponential_search(arr, target)
if result == -1:
    print("Element not found")
else:
    print(f"Element found at index {result}")