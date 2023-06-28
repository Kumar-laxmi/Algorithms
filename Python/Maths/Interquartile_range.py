#Problem statement :- Calculate Interquartile range from given number series 

n = int(input("Enter the size"))

arr = []
for i in range (0 , n):
    element = int(input())
    arr.append(element)

arr.sort()

start = 0  
last = n-1 

n = last - start + 1
n = (n + 1) // 2 - 1

mid=n

print("Median of series as Quartile2 : ", arr[mid])

q1=int(mid/2)

Quartile1 = arr[q1]  

print("The Median of first half as Quartile1",Quartile1)

q2 = int(mid+1+(last-mid)/2)
Quartile3 = arr[q2]

print("The Median of Second half as Quartile3 : ",Quartile3)
   
print("The IQR value is ",Quartile3 - Quartile1)

#  Case 1: INPUt :- 1  3  5  2  4  6

#        OUTPUT:- Median of series as Quartile2 : 3
#                 The Median of first half as Quartile1 : 2
#                The Median of second half as Quartile2 : 5
#                The IQR value is : 3

