'''

============================PROBLEM STATEMENT============================
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:

Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

============================LOGIC============================
The problem can be solved using dynamic programming when the sum of the elements is not too big. 
We can create a 2D array dp[n+1][(sum/2)+1] where n is number of elements in given set and sum is sum of all elements. 
We can construct the solution in bottom up manner maximizing the sum of a partion having sum less than or equal to (sum/2).

'''




#User function Template for python3
def minDifference(arr, n):
		#	sum of all elements in the array
		sum1 = sum(arr)															
  
		#	dp[i][j] stores the maximum sum of subset of a[0...i-1] such that sum of subset is less than or equal to j
		dp = [[0 for _ in range((sum1//2)+1)] for _ in range(n+1)]				
  		
		
		
		#	Initialisation of dp matrix
		for i in range(1,n+1):
		   
		    for j in range (1,(sum1//2)+1):
		        if arr[i-1] <=j:
					# if a[i-1] is less than or equal to j then we have two options either to include a[i-1] or not
		            dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j])  
		        
		        else:
					# if a[i-1] is greater than j then we have only one option that is not to include a[i-1]
		            dp[i][j] = dp[i-1][j]
		
  		# x stores the minimum difference between the two subsets
		x = abs(sum1-2*dp[n][(sum1//2)])
		
		return(x)


if __name__ == '__main__':
    
    n = int(input("Enter the size of the array: "))
    arr = [int(i) for i in input("Enter {0} elements: ".format(n)).split()]

    print("Minimum difference between the sum of partions is",minDifference(arr, n))