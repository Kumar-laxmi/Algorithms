#The Fibonacci numbers are the numbers in the following integer sequence.
#0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

#In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

#Fn = Fn-1 + Fn-2
#with seed values 

#F0 = 0 and F1 = 1.

#Given a number n, print n-th Fibonacci Number. 

#Examples: 

#Input  : n = 2
#Method:- Dynamic Programming

#Time complexity: O(n) for given n
#Auxiliary space: O(n)

#Code is as follows:- */
# Fibonacci Series using Dynamic Programming
def fibonacci(n):
	
	# Taking 1st two fibonacci numbers as 0 and 1
	f = [0, 1]
	
	
	for i in range(2, n+1):
		f.append(f[i-1] + f[i-2])
	return f[n]
	
print(fibonacci(9))

# Output - 34