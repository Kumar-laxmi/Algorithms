#
# 👉 In cryptography, the Vernam Cipher encypts the alphabetic text. It's a substitution technique to convert the plain text into cipher text.

# 👉 It's also called ONE TIME PAD Cipher Algorithm.

# Steps
# =====
# ⇒ Generate a random key from 26 alphabetic characters.
# ⇒ Assign a number to each character of the plain-text and the key according to alphabetical order.
# ⇒ Add the assigned numbers and store the same in a new array/vector.
# ⇒ Subtract 26 from the added values, if they are greater than 26.
# ⇒ Assign the characters associated to the final subtracted values to obtain the cipher text.

import random  # for randint() -> generates random numbers
import itertools # for filterfalse() -> lambda function

# array for characters of random key
alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g',
         'h', 'i', 'j', 'k', 'l', 'm', 'n',
         'o', 'p', 'q', 'r', 's', 't', 'u',
         'v', 'w', 'x', 'y', 'z']

# random key generation function
def generateKey(n):
    key = ""
    # generate random key
    for i in range(n):
        key += alpha[random.randint(0, 1000) % 26]
    return key

# main function definition
def main():
    # alphabet codes
    alphaCode = {
        'a': 1,
        'b': 2,
        'c': 3,
        'd': 4,
        'e': 5,
        'f': 6,
        'g': 7,
        'h': 8,
        'i': 9,
        'j': 10,
        'k': 11,
        'l': 12,
        'm': 13,
        'n': 14,
        'o': 15,
        'p': 16,
        'q': 17,
        'r': 18,
        's': 19,
        't': 20,
        'u': 21,
        'v': 22,
        'w': 23,
        'x': 24,
        'y': 25,
        'z': 26,
    }

    cipherTxt = ""  # for cipher text
    addedCode = []  # for added alphabetic codes

    # input plain text
    plainTxt = input("Enter Plain Text : ")

    # remove spaces from plain text
    tempTxt = list(itertools.filterfalse(lambda x : x == ' ', plainTxt))
    ''.join(tempTxt)

    key = generateKey(len(tempTxt))

    print("Generated Key :", key)

    # create added alphabetic code vector/array
    for i in range(len(tempTxt)):
        addedCode.append(alphaCode[tempTxt[i]] + alphaCode[key[i]])

    # create subtraced alphabetic code vector/array
    for i in addedCode:
        if i > 26:
            i = i - 26

    for i in addedCode:
        # find alphabetic character associated with respective value
        for k, val in alphaCode.items():
            if val == i:
                cipherTxt += k  # append cipher text character
                break

    # print results
    print("Plain Text :", plainTxt)
    print("Cipher Text :", cipherTxt)


main()
