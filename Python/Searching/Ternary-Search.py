

#-> Ternary search is a technique for finding the minimum or maximum value of a unimodal function and it can be useful in optimization problems.
#-> It is somehow similiar to binary search but here search space is divided into 3 part

#* The search space is divided into three space:
#-> First part - [l,m1]
#-> Middle part - [m1,m2]
#-> Third part - [m2,r]

#Here l=left index, r=right index, m1=middle 1 and m2=middle 2

#* Steps to perform Ternary Search:
#1. First, we compare the key with the element at mid1. If found equal, we return mid1.
#2. If not, then we compare the key with the element at mid2. If found equal, we return mid2.
#3. If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
#4. If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
#5. If not, then we recur to the second (middle) part.

#For more reference visit: https:	//www.geeksforgeeks.org/ternary-search/

import math as mt
def ternary_search(left, right, key, arr):
    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
 
        # Check if x is present at mid1
        if (arr[mid1] == key):
            return mid1
 
        # Check if x is present at mid2
        if (arr[mid2] == key):
            return mid2
 
        # Since key is not present at mid, check in which region it is present
        if (key < arr[mid1]):
            right = mid1 - 1
        elif (key > arr[mid2]):
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1
 
    # Key not found
    return -1
 
# Driver code
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
key = 5
result = ternary_search(0, len(arr) - 1, key, arr)
if result == -1:
    print("Element not found")
else:
    print("Element found at index", result)


# When to use:
#       * When you have a large ordered array or list and need to find the position of a specific value.
#       * When you need to find the maximum or minimum value of a function.
#       * When you need an alternative algorithm for binary search with an efficient time complexity.
#       * When you are interested in reducing the number of comparisons.

#  Note : It is efficient than linear search and in some cases better than binary seach.
 
