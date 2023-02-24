#
# In cryptography, the Caesar cipher is one of the simplest and best known encryption techniques. 

# It is a type of substitution cipher where each letter in the plaintext is replaced with a letter representing a certain number of digits in the alphabet. 

# Steps
# =====
# ⇒ Convert all uppercase character into lowercase in the plain text.
# ⇒ Check if plain text has no intergral characters.
# ⇒ No. all characters from a - z as 0 - 25.
# ⇒ Find encripted value by : (characterNum + key) mod 26.
# ⇒ Convert the encripted value to equivalent alphabetic character (Cipher Text).


# main function definition
def main():
    dig = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] # for integral values in plain text
    # alphabet codes
    alphaCode = {
        'a' : 1,
        'b' : 2,
        'c' : 3,
        'd' : 4,
        'e' : 5,
        'f' : 6,
        'g' : 7,
        'h' : 8,
        'i' : 9,
        'j' : 10,
        'k' : 11,
        'l' : 12,
        'm' : 13,
        'n' : 14,
        'o' : 15,
        'p' : 16,
        'q' : 17,
        'r' : 18,
        's' : 19,
        't' : 20,
        'u' : 21,
        'v' : 22,
        'w' : 23,
        'x' : 24,
        'y' : 25,
        'z' : 26,
    }

    cipherTxt = "" # for cipher text

    # input plain text
    plainTxt = input("Enter Plain Text : ")
    key = int(input("Enter Key : "))
    
    plainTxt = plainTxt.lower() # convert plain text to lower case
    
    for i in plainTxt:
        # check if :
        #     -> ith character in plain text is space
        #     -> ith character in plain text is integer
        if i not in dig and i != ' ':
            # find encripted value
            encriptVal = (alphaCode[i] + key) % 26

            # find alphabetic character associated with respective encripted value
            for k, val in alphaCode.items():
                if val == encriptVal:
                    cipherTxt += k # append cipher text
                    break

    # print results
    print("Plain Text :", plainTxt)
    print("Cipher Text :", cipherTxt)

main() # main function call