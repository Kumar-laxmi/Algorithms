''' 
          XOR TABLE
            X Y Z
            0 0 0
            0 1 1
            1 0 1
            1 1 0
'''
x,y, = 9,14  #taking inputs 
count=0
res = x ^ y  #taking xor of the two values to get different bits

    #counting number of 1 present in the res 
while res>0:
    count += res & 1;
    res >>= 1

print(count) 
    #printing the value of bits