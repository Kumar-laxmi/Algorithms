"""-----------------------------------------------------Introduction------------------------------------------------------------------------*/
    /*The Chinese Remainder Theorem is used to solve modular arithmetic problems efficiently.Modular arithmetic involves performing 
    arithmetic operations on remainders. For example, if we divide 13 by 5, the remainder is 3. In modular arithmetic notation, we 
    would write this as 13 ≡ 3 (mod 5), which means that 13 is congruent to 3 modulo 5."""
"""-----------------------------------------------------Algorithm----------------------------------------------------------------------------"""
      """start with 1 and one by one increment it and check if dividing it with given elements in
     num[] produces corresponding remainders in rem[]. Once we find such an x, we return it. """

# A Python3 program to demonstrate
# working of Chinise remainder Theorem

#Function to find the smallest no that will produce respective remainder.
def findMinX(num, rem, k):
	x = 1 # Initialize result

	
	while(True):
		
		# Check if remainder of
		# x % num[j] is rem[j]
		# or not (for all j from
		# 0 to k-1)
		j = 0
		while(j < k):
			if (x % num[j] != rem[j]):
				break
			j += 1

		# If all remainders
		# matched, we found x
		if (j == k):
			return x

		# Else try next number
		x += 1

# Driver Code
num=[]
n=int(input("Number of elements in  num array:"))
for i in range(0,n):
   g=int(input())
   num.append(g)

#rem = [2, 3, 1]
rem=[]
m=int(input("Number of elements in rem array:"))
for i in range(0,m):
   t=int(input())
   rem.append(t)

k = len(num)
print("x is", findMinX(num, rem, k))

