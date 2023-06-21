# Python3 program of Quick Select

# Partition i.e considering the last element as pivot and move all smaller element to left of it and greater elements to right

def partition(array, l, r):
	
	x = array[r]
	i = l
	for j in range(l, r):
		if array[j] <= x:
			array[i], array[j] = array[j], array[i]
			i += 1
	array[i], array[r] = array[r], array[i]
	return i

# Finds the kth position (of the sorted array)
# Assuming: all elements in arr[] are distinct
def kthsmallest(arr, l, r, k):

	# If k is smaller than number of elements in array
	if (k > 0 and k <= r - l + 1):

		# Partition the array around last element and get position of pivot element
		index = partition(arr, l, r)

		# If position is same as k
		if (index - l == k - 1):
			return arr[index]

		# If position is more, recur for left subarray
		if (index - l > k - 1):
			return kthsmallest(arr, l, index - 1, k)

		# Else recur for right subarray
		return kthsmallest(arr, index + 1, r, k - index + l - 1)
	print("index out of bound")

	
#driver code	
n = int(input("Enter the number of elements (n): "))
array = []
for i in range(n):
    element = int(input(f"Enter element {i+1}: "))
    array.append(element)
print("Array:", array)
m=len(array)
k=int(input("Enter the value of k: "))
print("k'th smallest element is ", end = "")
print(kthsmallest(array, 0, m - 1, k))
