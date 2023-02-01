#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
# Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. 
# And if the end isn’t reachable, return -1 as the output.
#Example:Given an array and a value, find if there is a triplet in the array whose sum is equal to the given value. 
#If there is such a triplet present in the array, then print the triplet and return true. Else return false.
#EXAMPLES:
#1] Input: array = { 7, 10, 6, 14, 4, 9 }, sum = 25;
#Output: Triplet is 4, 7, 14 */
# Python program to find a triplet
def Triplet(A, arr_size, sum):
	# Sort the elements
	A.sort()
	# fix the first element and one by one and find the other two elements
	for i in range(0, arr_size-2):
		# To find the other two elements, start two index variables from two corners of the array and
		# move them toward each other index of the first element in the remaining elements
		x = i + 1
		# index of the last element
		y = arr_size-1
		while (x < y):
			if( A[i] + A[x] + A[y] == sum):
				print("Triplet is", A[i],
					', ', A[x], ', ', A[y]);
				return True
			elif (A[i] + A[x] + A[y] < sum):
				x += 1
			else:
				y -= 1
	# no triplet was found
	return False
# Main Function
A = [ 7, 10, 6, 14, 4, 9 ]
sum = 25
arr_size = len(A)
Triplet(A, arr_size, sum)