#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Statement: Python program to find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted.
#Example:
#1] INPUT: int arr[] = {12, 15, 17, 23, 31, 38, 34, 36, 37, 55, 62};
#OUTPUT: The unsorted subarray which makes the given array
#sorted lies between indices 5 and 8.
# Python3 program to find the Minimum length Unsorted Subarray,
# sorting which makes the complete array sorted
def UnsortedArray(arr, n):
	b = n-1
	#Start searching the element from left to right and find the first most element which is greater than the next element.
	for a in range(0,n-1):
		if arr[a] > arr[a+1]:
			break	
	if a == n-1:
		print ("The complete array is sorted")
		exit()
	#Search element which is smaller than the next element.
	b= n-1
	while b > 0:
		if arr[b] < arr[b-1]:
			break
		b -= 1
	#Find the minimum and maximum values in the given array.
	max = arr[a]
	min = arr[a]
	for i in range(a+1,b+1):
		if arr[i] > max:
			max = arr[i]
		if arr[i] < min:
			min = arr[i]		
	#Find the first element which is greater than minimum and change a to index of this element.
	for i in range(a):
		if arr[i] > min:
			a = i
			break
	#Find the last element which is smaller than maximum.
	i = n-1
	while i >= b+1:
		if arr[i] < max:
			b = i
			break
		i -= 1
	#Print a and b.
	print ("The unsorted subarray which makes the given array")
	print ("sorted lies between the indexes %d and %d"%( a, b))
arr = [12, 15, 17, 23, 31, 38, 34, 36, 37, 55, 62]
arr_size = len(arr)
UnsortedArray(arr, arr_size)