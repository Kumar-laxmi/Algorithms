# Python program to check if the number is an Armstrong number or not

number = int(input('Enter a number to check if it is armstrong or not: '))

length = len(str(number)) # to get the number of digits in the given number

s = 0 # initializing sum for the number
temp = number 

# finding the sum of digits with the power of length
while temp > 0:
    last_digit = temp%10
    s = s + last_digit**length
    temp //= 10

# checking if sum is equal to the given number
if s == number:
    print(number, "is an Armstrong number")
else:
    print(number, "is not an Armstrong number")

"""
Case 1:
Enter a number to check if it is armstrong or not: 153
153 is an Armstrong number

Case 2:
Enter a number to check if it is armstrong or not: 233
233 is not an Armstrong number

Case 3:
Enter a number to check if it is armstrong or not: 1634
1634 is an Armstrong number
"""

# Python program to check if the number is an Armstrong number or not using for loop
num =input("enter a number:")
sum=0
for i in num:
    sum+=int(i)**3
    if num==sum:
        print("yes")
    else:
        print('no')
