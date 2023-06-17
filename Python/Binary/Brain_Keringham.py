#Brian Kerningham's Algorithm in Python
def setBits(n):
    count = 0
    while (n):
        n = n & (n-1)
        count+= 1
     
    return count
 
print(setBits(15))