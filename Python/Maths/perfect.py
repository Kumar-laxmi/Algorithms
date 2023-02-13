# Python program to check if the number is a Perfect number or not

num = int(input("Enter a number : "))
sum = 0
for i in range (1,num):
    if(num % i == 0):
        sum = sum + i
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
