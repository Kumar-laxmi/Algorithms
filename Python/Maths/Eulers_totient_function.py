#-------------------------------Introduction------------------------------------------------------
# A  python program to calculate
# Euler's Totient Function i.e phi(n)=no of positive integers  less than n that are realtiveli prime to n.

#--------------------------------Algorithm------------------------------------------------------*/
"""1. we first list down all the no's less than n starting from 1.
  2. then we find the gcd of each and every integer with n.
  3.then we compare if the gcd is =1 we count it in result and hence display the result i.e the phi(n) 
  """
 """A simple python program to calculate
 Euler's Totient Function"""
 
 #Function to return gcd of a and b
def gcd(a, b):

	if (a == 0):
		return b
	return gcd(b % a, a)

# A simple method to evaluate
# Euler Totient Function
def phi(n):

	result = 1
	for i in range(2, n): #starting from 2 as gcd of any no with 1 is always 1
		if (gcd(i, n) == 1):
			result+=1
	return result

# Driver Code
for n in range(1, 21):
	print("phi(",n,") = ",
		phi(n), sep = "")
			
# This code is contributed kritika singh

