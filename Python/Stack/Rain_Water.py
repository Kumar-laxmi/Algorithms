#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Description
#Program to find the maximum trap water by using stack .
#Examples:
 #1] INPUT: {1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6};
  #  OUTPUT 31 */
# Python implementation of the approach
# Function to return the maximum
# water that can be stored
def RainWater(height):
	# Stores the indices of the bars
	stack = []
	# size of the array
	n = len(height)
	# Stores the final result
	ans = 0
	# Loop through the each bar
	for i in range(n):
		# Remove bars from the stack
		# until the condition holds
		while(len(stack) != 0 and (height[stack[-1]] < height[i])):
			# store the height of the top
			# and pop it.
			pop_height = height[stack[-1]]
			stack.pop()
			# If the stack does not have any
			# bars or the popped bar
			# has no left boundary
			if(len(stack) == 0):
				break
			# Get the distance between the
			# left and right boundary of
			# popped bar
			distance = i - stack[-1] - 1
			# Calculate the min. height
			min_height = min(height[stack[-1]], height[i])-pop_height
			ans += distance * min_height
		# If the stack is either empty or
		# height of the current bar is less than
		# or equal to the top bar of stack
		stack.append(i)
	return ans
# Main code
if __name__ == '__main__':
	arr = [1, 1, 5, 2, 1, 8 , 1, 0, 2, 1, 2, 6]
	print(RainWater(arr))