# Python program to check if a number is Kaprekar number or not
 
import math
 
def kaprekar_num( num):
    if num == 1 :
        return True
     
    #Count number of digits in square
    power = num * num
    digits = 1
    while not power == 0 :
        digits = digits + 1
        power = power // 10
     
    power = num*num  # Recompute square as it was changed
     
    # Split the square at different points and see if sum
    # of any pair of splitted numbers is equal to n.
    i = 0
    while i< digits :
        i = i + 1
        power_10 = (int) (math.pow(10, i))
         
        
        if power_10 == num :
            continue
         
        #sum to check with original number
         
        sum = power//power_10 + power % power_10
        if sum == num :
            return True
     

    return False
     

i=input("Enter the number")
if (kaprekar_num(i)) :
    print ("This number is Kaprekar number")
else :
    print("This number is not kaprekar number")
    

#**********************************

# Case 1 : Enter Number 45

# output: This number is kaprekar number 

# Case 2: Enter Number 129

# output: This number is not kaprekar number

#*********************************