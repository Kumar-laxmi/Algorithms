'''
          XOR TABLE
            X Y Z
            0 0 0
            0 1 1
            1 0 1
            1 1 0
'''
x = input("Enter the value of X: ") #taking inputs
y = input("Enter the value of Y: ")

count= 0
res = int(x) ^ int(y)  #taking xor of the two values to get different bits

    #counting number of 1 present in the res
while res>0:
    count += res & 1
    res >>= 1

print("THe result is: ", count)
    #printing the value of bits