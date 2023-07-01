
#----------------------------

#problem - Given a sorted integer array and a target, 
# determine if the target exists in the array or not using an interpolation search algorithm. 
# If the target exists in the array, return the index of it.

#------------------------

#it is same as binary search but it use this formula to calculate mid -
 # mid = low + ((target – A[low]) * (high – low) / (A[high] – A[low]));

#-----------------------

#variables - 
#start - starting index also know as low or low (low most element )
#end - ending index also know as high or right ( right most element)
#target - element to be search in the array
#size - size of the array 
  
#-----------------------------


def interpolationSearch(array, start, end, target):

	# Since array is sorted, an element present
    # search space is array[low…high]
	if (start <= end and target >= arr[start] and target <= array[end]):

		# Probing the position with keeping
		# uniform distribution in mind.
		mid = start + ((end - start) // (array[end] - array[start]) *
					(target - arr[start]))

		# #target value found
		if array[mid] == target:
			return mid

		# If x is larger, x is in right subarray
		if array[start] < target:
			return interpolationSearch(array, mid + 1,
									end, target)

		# If x is smaller, x is in left subarray
		if array[mid] > target:
			return interpolationSearch(array, start,
									mid - 1, target)
	return -1

# Driver code


# Array of items in which
# search will be conducted
arr = [10, 12, 13, 16, 18, 19, 20,
	21, 22, 23, 24, 33, 35, 42, 47]
n = len(arr)

# Element to be searched
x = 18
index = interpolationSearch(arr, 0, n - 1, x)

if index != -1:
	print("Element found at index", index)
else:
	print("Element not found")


# code is contributed by rajendra mandliya