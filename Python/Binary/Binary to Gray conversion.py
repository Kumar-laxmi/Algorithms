'''
Author: Abdul Kadir
Github username: AK3847
Topic: Binary to gray conversion and vice-versa:

--------------LOGIC----------------
1.Binary to Gray:
--> Here the most significant bit of the gray code is same as the given binary code
    so we don't need to make any changes
--> Further traversing the binary from 1st index(i.e 2nd position) we take the xor of current
    index character  of binary code with the previous index character of binary code 
    and add it to our converted gray code

2. Gray to Binary:
--> Here the most significant bit of the Binary code is same as the given Gray code, so we direclty copy it.
--> Further traversing the Gray code we check if the current character of Gray code is '0', if it is '0'
    we copy the value of previous index of converted Binary code,else we copy the flipped value of current Gray character
    to our binary code.
'''
#User-defined function to convert given binary code into gray code and display it
def binarytoGray(binary):
    #Initializing matrice
    rows,cols=(len(binary),2)
    matrice=[[0 for i in range(cols)] for j in range(rows)] 

    #Assigning the initial values
    matrice[0][0]=binary[0]
    matrice[0][1]=binary[0] #MSB of Gray code is same as that of given Binary code

    for i in range(1, len(binary)):
        matrice[i][0]=binary[i]
        #Taking XOR of the current index character with the previous index character of Binary code
        #and copying that value in the 2nd column of the matrice
        matrice[i][1]='0' if binary[i] is binary[i-1] else '1'

    #Printing the Answer
    print("Binary  Gray")
    for i in matrice:
	    print('\t'.join(map(str,i)))

#User-Defined function to convert given Gray code into Binary code and display it
def graytoBinary(gray):
    #Initializing matrice
    rows,cols=(len(gray),2)
    matrice=[[0 for i in range(cols)] for j in range(rows)]

    #Assigning the initial values
    matrice[0][0]=gray[0]
    matrice[0][1]=gray[0]#MSB of Binary code is same as that of given Gray code

    for i in range(1,len(gray)):
        matrice[i][0]=gray[i]
        # if the current character is '0' 
        # we copy the previous character of the binary code
        if(gray[i] == '0'):
             matrice[i][1]=matrice[i-1][1]
        # else we copy the flipped value of the previous binary code character
        # i.e if its '0' we take '1' and vice-versa
        else:
            matrice[i][1]='1' if matrice[i-1][1] == '0' else '0'
    
    #Printing the Answer
    print("Gray Binary")
    for i in matrice:
            print('\t'.join(map(str,i)))

  
binary = "11001" #Given Binary code
gray = "10101" #Given Gray code
binarytoGray(binary) #Calling user-defined function 
graytoBinary(gray) #Calling user-defined function