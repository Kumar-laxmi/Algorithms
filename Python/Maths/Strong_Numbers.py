"""
Name :  Hardik Goyal
Github username : HardikGoyal2003
Repositary name : Algorithms

What is a strong number?
A strong number is a positive integer whose sum of factorials of its digits equals the number itself. In other words, if we take the 
digits of a number and calculate the factorial of each digit, then sum those factorials, and the result is the same as the original number, 
then that number is called a strong number.

Problem Statement : To Check Given number is Strong Number or not.
EXAMPLE : 
1)
Input:  145
Output: "It is a Strong Number"
"""
n=int(input("Enter Number"))
factorial=1
sum=0
n1= n
while (n>0):
    rem = int(n%10)
    n=n//10
    for i in range(1,rem+1):
        factorial*=i 
    sum+=factorial
    factorial=1      
if (n1 == sum):
    print("It is Strong Number")
else:
    print("It is not a Strong Number")

