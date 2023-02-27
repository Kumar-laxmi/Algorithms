# Python program to check if the number is a Perfect number or not

# take user input 
num = int(input("Enter a number : "))

# initialize variable to store sum 
sum = 0

# iterate from 1 to N and if the number is a factor of N then add it to sum
for i in range (1,num):
    if(num % i == 0):
        sum = sum + i
        
# if sum of factors of N is equal to N then it is a perfect number
if(sum == num):
    print(num," is a perfect number")
else:
    print(num," is not a perfect number")

"""
Case 1:
Enter a number: 153
153 is not a perfect number

Case 2:
Enter a number: 496
496 is a perfect number
"""
