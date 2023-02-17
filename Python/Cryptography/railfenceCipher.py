'''
The rail fence cipher (sometimes called zigzag cipher) is a transposition cipher that jumbles up the order of the letters of a message
using a basic algorithm.

The rail fence cipher works by writing your message on alternate lines across the page, and then reading off each line in turn.

Encrytion:
-> The plain-text is written downwards and diagonally on successive rails of an imaginary fence.
-> When we reach the bottom rail, we traverse upwards moving diagonally, after reaching the top rail, the direction is changed again.
    Thus the alphabets of the message are written in a zig-zag manner.
-> After each alphabet has been written, the individual rows are combined to obtain the cipher-text.

Text: ALGORITHMS , Key=3

A * * * R * * * M *
* L * O * I * H * S
* * G * * * T * * *

Encryted Text : ARMLOIHSGT

Decryption:
-> Construct the matrix with the given key
-> Fill the letters accordingly and then traverse the matrix in a zigzag manner.

'''

#Function to encypt a sentence
def encrypt(clearText,key):
    #Creating a matrix to store the text in a zigzag manner
    matrix=[["" for x in range(len(clearText))] for y in range(key)]

    increment=1# To find the direction
    row,col=0,0

    for c in clearText:
        #Check the direction of the flow
        #Reverse the direction if we've just filled thhe top or bottom rail
        if row+ increment<0 or row+increment>=len(matrix):
            increment*=-1
        #Fill the corresponding character
        matrix[row][col]=c
        #Find the next row using increment flag
        row+=increment
        col+=1

    #Traverse the matrix and store the characters in result
    result=[]
    for i in range(key):
        for j in range(len(clearText)):
            if matrix[i][j]!='\n':
                result.append(matrix[i][j])
    
    return ("".join(result))

#Function to decrypt a sentence
def decrypt(encryptText,key):
    # create the matrix to cipher
    matrix=[["" for x in range(len(encryptText))] for y in range(key)]

    index=0
    increment=1 #Flag to check the direction

    for selectedRow in range(0,len(matrix)):
        row =0

        for col in range(0,len(matrix[row])):
            #Check the direction , if at the edges change the direction by using the increment flag
            if row+increment<0 or row+increment>=len(matrix):
                increment*=-1
            #If desired positions match fill the character in the correct place  
            if row == selectedRow:
                matrix[row][col]+=encryptText[index]
                index+=1
            #Increment the row to traverse to the next line
            row+=increment

    #Transpose the matrix to read the characters line by line
    matrix=transpose(matrix)
    
    #Traverse line by line and append the characters found in each line
    #to result variable
    result=[]
    for i in range(len(encryptText)):
        for j in range(key):
            if matrix[i][j]!='\n':
                result.append(matrix[i][j])
    
    return ("".join(result))


#Function to transpose the matrix and return the new matrix
def transpose( m ):
	#This will store the transposed matrix
	result = [ [ 0 for y in range( len(m) ) ] for x in range( len(m[0]) ) ]
	
	for i in range( len(m) ):
		for j in range( len(m[0]) ):
			result[ j ][ i ] = m[ i ][ j ]
	
	return result

#Main function to encrypt or decrypt a text
if __name__ == "__main__":
    #Menu driven program 
    print("Railfence Cipher: ")
    print("1. Encrypt a text")
    print("2. Decrypt a text")
    print("3. Exit")
    n=int(input())

    while n<3:
        if n==1:#If choice is 1 then proceed with encryption
            print("Encryption")
            print("Enter the text and the key: ")
            text=input()
            key=int(input())
            print("Encrpyted text using Railfence Cypher Algorithm is: ")
            print(encrypt(text,key))
        
        elif n==2:#If choice is 2 then proceed with decryption
            print("Decryption")
            print("Enter the text and the key: ")
            text=input()
            key=int(input())
            print("Decrpyted text using Railfence Cypher Algorithm is: ")
            print(decrypt(text,key))

        print("1. Encrypt a text")
        print("2. Decrypt a text")
        print("3. Exit")
        n=int(input())
        
    #End of the program
    print("End of the program")