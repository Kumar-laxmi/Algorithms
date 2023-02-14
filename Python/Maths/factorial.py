'''

                        FACTORIAL PROGRAM                         
Factorial is represented by !. It is calculated by mutiplying natural
numbers upto that number, i.e., n! = 1 x 2 x 3... x n. 
(n should be positive)
Note: 0! = 1 and 1! = 1

'''

def factorial(num):
    if(num == 0 or num == 1): return 1 # factorial of 0 and 1 is 1
    else: return num * factorial(num-1)

num = int(input("Enter a number: ")) # factorial of this no will be calculated
res = factorial(num)
print("Factorial of" , num, "is", factorial(num))
