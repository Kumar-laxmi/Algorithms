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

# User inputs
plaintext = input("Enter the message to be encrypted/decrypted: ")
key = input("Enter the key: ")
mode = input("Enter 'e' to encrypt, 'd' to decrypt: ")

# Encryption or decryption
if mode == 'e':
    ciphertext = vigenere_cipher(plaintext, key)
    print(f"Encrypted message: {ciphertext}")
elif mode == 'd':
    ciphertext = vigenere_cipher(plaintext, key, encrypt=False)
    print(f"Decrypted message: {ciphertext}")
else:
    print("Invalid mode. Enter 'e' to encrypt, 'd' to decrypt.")
