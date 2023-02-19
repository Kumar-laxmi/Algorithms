#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
# Problem Statement: C++ program to find find the minimum number of jumps to reach the other end of the array starting from the 0th index. And if the end isn’t reachable, return -1 as the output.
#Example:
#1] INPUT: int arr[] = { 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 };
#OUTPUT: Minimum number of jumps to reach the other end is 2 */
# Python3 program to find Minimum number of jumps to reach end
# Returns minimum number of jumps to reach arr[n-1] from arr[0]
def minJump(arr, x):
	jump = [0 for i in range(x)]
	if (x == 0) or (arr[0] == 0):
		return float('inf')
	jump[0] = 0
	# To Find the minimum number of jumps to reach arr[i] from
	for i in range(1, x):
		jump[i] = float('inf')
		for j in range(i):
			if (i <= j + arr[j]) and (jump[j] != float('inf')):   # arr[0] and assign this value to jumps[i]
				jump[i] = min(jump[i], jump[j] + 1)
				break
	return jump[x-1]
# Main Function
arr = [ 1, 9, 4, 7, 3, 7, 2, 1, 8, 9, 5 ]
size = len(arr)
print('Minimum number of jumps to reach',
	'end is', minJump(arr, size))