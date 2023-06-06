# Python implementation of Jump Search Algorithm
import math

def jumpSearch(array, size, key):
    start = 0
    end = int(math.sqrt(size))  # the square root of array length

    while array[end] <= key and end < size:
        start = end  # if it is not the correct block then shift block
        end += int(math.sqrt(size))

        if end > size - 1:
            end = size  # if right exceeds then bound the range

    # perform linear search in selected block
    for i in range(start, end):
        if array[i] == key:
            return i  # the correct position of the key

    return -1


# taking input of number of elements and key
n, key = map(int, input().split())
arr = list(map(int, input().split()))

# function call
ind = jumpSearch(arr, n, key)

if ind >= 0:  # key is present in the array
    print("Key found at location:", ind)
else:  # key is not present in the array
    print("Key not found in the array")
