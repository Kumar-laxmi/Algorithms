
#Function to calculate parity bits needed to encode a message
def calculateParityBits(m,low = 0,high = None):
    #Binary algorithm to find required number of bits
    if high is None:
        high = m + 1
        
    r=(low + high) //2
    
    if low==high:
        return low
    elif (2**r >= r + m + 1):    #r = redundant bit, m = data bit
        return calculateParityBits(m,low,r)
    else:
        return calculateParityBits(m,r+1,high)

def isPowerOfTwo(num):
    #Performs a bitwise AND operation between num and num - 1. 
    #This operation turns off the rightmost set bit in num 
    #(i.e., the least significant bit).
    
    #If the result of the bitwise AND operation is zero, it means that num 
    #had only one set bit (power of 2) before the bitwise operation, and 
    #that bit was turned off. In this case, the number is considered a power of 2
    return (num & (num-1)) == 0

def calculateParityValue(ones,pos):
    #Count num of ones corresponding to parity bit
    count=0
    #ANDing the bit and position to check if parity 
    #corresponds to that bit
    for bit in ones:
        if (bit & pos != 0):
            count+=1
    #Return 0 if number of ones are even,0 otherwise
    return count % 2
    
def hamming_encode(message):
    #Find number of parity bits
    m = len(message)
    r = calculateParityBits(m)
    
    #Initialize array 
    encoded_block=[None]*(m+r)
    
    #Iterate over block
    data_bit=0
    
    for position in range(1, m + r +1):
        
        #Check if position is power of 2
        if isPowerOfTwo(position):     
            encoded_block[position - 1] = None    #Mark as parity bit
        else:
            encoded_block[position - 1] = message[data_bit]   #Data bit, store message
            data_bit+=1
    
    #List of bits where value is 1
    positionsOfOne=[i + 1 for i, bit in enumerate(encoded_block) if bit == '1']
    
    # Iterate over the parity bits in the encoded block
    for position in range(1, m + r + 1):
        if encoded_block[position - 1] is None:
            #Calculate and assign required parity value
            encoded_block[position - 1] = calculateParityValue(positionsOfOne,position)
    
    #Convert list to string
    result = ''.join([str(i) for i in encoded_block])
    return result

#Sample case
data='11110010010'
print("Message entered:",data)
print("Encoded Message:",hamming_encode(data))
