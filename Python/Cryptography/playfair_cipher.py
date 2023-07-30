# Path: Python\Cryptography\playfair_cipher.py
# Python program to implement playfair cipher algorithm.

# The Playfair cipher algorithm is a symmetric encryption technique that uses a 5x5 grid of letters to encrypt plaintext.
# It employs the rules of letter substitution and rearrangement based on pairs of letters to generate ciphertext.

# Rules for Encryption using playfair cipher Algorithm
# 1). 5 X 5 matrix -> Table
# 2). Digraphs (3 conditions):
# i). same row
# ii). same column
# iii). different row and column


# pre processing the key and plain text
# J is considered as I
def prepareString(line):
    return line.upper().replace('J', 'I').replace(' ', '')


# construct the table based on key word
def constructTable(key):
    # visited array for all alphabets
    visited = [0]*26
    # table declaration
    table = [['X' for _ in range(5)] for _ in range(5)]
    row = col = 0
    # first key to be filled
    # and then A to Z absent characters
    key = key + "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    for ch in key:
        # if absent
        if visited[ord(ch)-ord('A')] == 0:
            table[row][col] = ch
            visited[ord(ch)-ord('A')] = 1
            # from left to right
            # and then top to bottom
            if col == 4:
                row += 1
            col = (col+1) % 5

    return table


# spliting into 2 and adding X in between if 2 chars in same diagraph are equal
def digraphPlainText(plainText):
    res = ""
    i = 0
    length = len(plainText)
    while i < length:
        if i == length-1 or plainText[i] == plainText[i+1]:
            res += plainText[i]
            res += 'X'
            i += 1
        else:
            res += plainText[i]
            res += plainText[i+1]
            i += 2
    return res


# returns the position of ch in the table
def getCoordinates(table, ch):
    for row in range(5):
        for col in range(5):
            if table[row][col] == ch:
                return [row, col]
    return [-1, -1]


# encrypts the plain text
def encrypt(plainText, table):
    cipherText = ""
    i = 0
    while i < len(plainText)-1:
        row1, col1 = getCoordinates(table, plainText[i])
        row2, col2 = getCoordinates(table, plainText[i+1])
        # case 1: same row
        if row1 == row2:
            col1 = (col1 + 1) % 5
            col2 = (col2 + 1) % 5
        # case 2: same column
        elif col1 == col2:
            row1 = (row1 + 1) % 5
            row2 = (row2 + 1) % 5
        # case 3: rectangle
        else:
            temp = col1
            col1 = col2
            col2 = temp
        cipherText += table[row1][col1] + table[row2][col2]
        # +2 since it is a diagraph
        i += 2
    return cipherText


# key for the encrytion
key = input("Enter Key: ")
key = prepareString(key)

# create table 
table = constructTable(key)


plainText = input("Enter Plain Text: ")
plainText = prepareString(plainText)
# split the plain text 
plainText = digraphPlainText(plainText)
print()
encryptedMessage = encrypt(plainText, table)
print("Cipher text:", encryptedMessage)
print()
# Deciphered text is the diagraphed plain text
print("Deciphered text:", plainText)
print()