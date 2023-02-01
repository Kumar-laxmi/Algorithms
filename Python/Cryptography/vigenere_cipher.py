"""
Vigenère cipher uses a keyword to encrypt a message by replacing each letter of the message with a 
letter that is shifted a certain number of places down the alphabet based on the corresponding letter 
of the keyword. The same keyword is used for each letter of the message but shifted to a different 
position for each letter of the message. This makes the Vigenère cipher much more secure than simple 
substitution ciphers, such as the Caesar cipher.

Input:
 Message: Takes input the message you want to encrypt or decrypt.
 key: Takes an alphabetic key as input
 option: asks if you want to encrypt or decrypt the message

Output:
 Cipher text: if you choose to encrypt then the output is a cipher text.
 plain text: if you gave the cipher text as input and the correct key then it gives back the correct plaintext/message
 wrong message: if you mistake the key or plain text then it gives some gibberish.
"""

"""Function to encrypt and decrypt"""
def vigenere_cipher(plaintext, key, encrypt=True):
    key = key.upper()
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    result = ''

    for i, char in enumerate(plaintext.upper()):
        if char in alphabet:
            char_index = alphabet.index(char)
            key_index = alphabet.index(key[i % len(key)])
            if encrypt:
                result += alphabet[(char_index + key_index) % 26]
            else:
                result += alphabet[(char_index - key_index + 26) % 26]
        else:
            result += char

    return result

"""Taking input from user"""
plaintext = input("Enter the message to be encrypted/decrypted: ")
key = input("Enter the key: ")
mode = input("Enter 'e' to encrypt, 'd' to decrypt: ")

"""Encryption or decryption phase"""
if mode == 'e':
    ciphertext = vigenere_cipher(plaintext, key)
    print(f"Encrypted message: {ciphertext}")
elif mode == 'd':
    ciphertext = vigenere_cipher(plaintext, key, encrypt=False)
    print(f"Decrypted message: {ciphertext}")
else:
    print("Invalid mode. Enter 'e' to encrypt, 'd' to decrypt.")
