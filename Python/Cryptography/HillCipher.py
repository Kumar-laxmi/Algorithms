#
# 👉 In classical cryptography, the Hill cipher is a polygraphic substitution cipher based on linear algebra.

# 👉 Invented by Lester S. Hill in 1929, it was the first polygraphic cipher in which it was practical to operate on more than three symbols at once.

# Steps
# =====
# ⇒ Generate a cipher key 2x2 matrix by replacing characters with numerical values.
# ⇒ Generate a vector of 2x1 matrices with numeric codes of plain text characters.
# ⇒ Multiply the key mtx. with each 2x1 matrix in plain text matrix vector & mod the result with 26, to obtain the cipher text numeric values.
# ⇒ Convert these numeric values back to alphabetic characters to obtain the cipher text.
#

temp = [] # dummy array to store 2x1 mtx.

keyMtx = [[0] * 2 for i in range(2)] # 2x2 mtx for cipher key

plainTxtMtxArr = [] # for array of plain text mtx.

cipherTxtMtxArr = [] # for array of cipher text mtx.


# function to generate key matrix
def generateKeyMtx(key):
    k = 0
    for i in range(2):
        for j in range(2):
            keyMtx[i][j] = ord(key[k]) % 65
            k += 1


# function to generate cipher text matrix
def hillCipherEncryption():
    for i in range(len(plainTxtMtxArr)):
        # cipher text mtx. = key mtx. * plain text mtx.
        for j in range(2):
            for k in range(1):
                temp[i] = 0
                for x in range(2):
                    temp[j] = (keyMtx[j][x] * plainTxtMtxArr[x][k]) % 26

                cipherTxtMtxArr.append(temp)
                temp.clear()


# main function
def main():
    cipherTxt = "" # for cipher text

    print("\tHILL CIPHER")

    # input plain text and cipher key
    plainTxt = input("Enter Plain Text : ")
    key = input("Enter Key (LENGTH 4) : ")

    # check if key length is not 4
    if len(key) > 4:
        key = key[0:4] # trim key
    elif len(key) < 4:
        print("INVALID KEY")
        exit(0) # terminate program
    
    generateKeyMtx(key) # function call for key mtx. generation

    # generate plain text vector (2x1 mtx.)
    for i in range(0, len(plainTxt), 2):
        if i != len(plainTxt) - 1:
            if plainTxt[i] != ' ' and plainTxt[i + 1] != ' ':
                temp.append(ord(plainTxt[i]) % 65)
                temp.append(ord(plainTxt[i + 1]) % 65)
        
        elif plainTxt[i] != ' ':
            temp.append(ord(plainTxt[i]) % 65)
        
        plainTxtMtxArr.append(temp)
        temp.clear()

    hillCipherEncryption() # function call for cipher mtx. generation

    # convert cipher text values to characters
    for i in range(len(cipherTxtMtx)):
        for j in range(len(cipherTxtMtx)):
            cipherTxt += chr(cipherTxtMtxArr[i][j]) + 65

    # display output
    print("PLAIN TEXT :", plainTxt)
    print("CIPHER TEXT :", cipherTxt)


main()
