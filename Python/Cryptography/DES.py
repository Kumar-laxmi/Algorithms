"""
Algorithm:
    Key generation: The 64-bit encryption key is provided as input to the algorithm. 
    The key is first passed through a permutation function to obtain a 56-bit key, 
    and then it is divided into two halves, each containing 28 bits. Each half is 
    separately subjected to a series of shifts and permutations, generating 16 subkeys, each 48 bits long.

    Initial permutation: The 64-bit plaintext is permuted according to a fixed permutation 
    table. This step is designed to add confusion to the plaintext.

    Feistel rounds: The permuted plaintext is divided into two halves, each containing 
    32 bits. These halves are then subjected to a series of 16 rounds, each consisting 
    of the following operations:

    a. Expansion: The 32-bit right half is expanded to 48 bits using a fixed permutation table.

    b. XOR: The expanded right half is XORed with the 48-bit subkey generated during the key generation step.

    c. Substitution: The XOR output is divided into eight 6-bit blocks, which are then substituted 
    using eight different S-boxes, each of which maps a 6-bit input to a 4-bit output.

    d. Permutation: The output of the S-boxes is then permuted using another fixed permutation table.

    e. XOR: The permuted output of the S-boxes is XORed with the left half of the plaintext.

    f. Swap: The left and right halves of the plaintext are swapped before the next round.

    Final permutation: The output of the 16th Feistel round is permuted according to a fixed 
    permutation table to produce the final ciphertext.

Input:
    1. Asks the user if they want to encrypt or decrypt.
    2. If user chooses to encrypt the code asks the user to input a string to encrypt.
    3. If the user chooses to decrypt, the code asks the user for the key in hexadecimal format. 
       Then it asks the user to enter the key(IV) in hexadecimal format. 
       Then it finally asks the user to enter the ciphertext.

Output:
    1. In case the user chooses to encrypt, the code outputs a key, key(IV) and cipher text in hexadecimal format.
    2. In case the user chosses to decrypt, the code outputs the plaintext that was encrypted with the keys.
"""

# Import necessary modules
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.backends import default_backend
import os

# Define a function to generate a random key
def generate_key():
    key = os.urandom(8)
    return key

# Define a function to encrypt plaintext using 3DES
def encrypt(key, iv, plaintext):
    # Create a cipher object using the 3DES algorithm in CBC mode
    cipher = Cipher(algorithms.TripleDES(key), modes.CBC(iv), backend=default_backend())
    # Create an encryptor object using the cipher object
    encryptor = cipher.encryptor()
    # Create a padder object using PKCS7 padding with a block size of 64 bytes
    padder = padding.PKCS7(64).padder()
    # Pad the plaintext using the padder object
    padded_plaintext = padder.update(plaintext) + padder.finalize()
    # Encrypt the padded plaintext using the encryptor object
    ciphertext = encryptor.update(padded_plaintext) + encryptor.finalize()
    return ciphertext

# Define a function to decrypt ciphertext using 3DES
def decrypt(key, iv, ciphertext):
    # Create a cipher object using the 3DES algorithm in CBC mode
    cipher = Cipher(algorithms.TripleDES(key), modes.CBC(iv), backend=default_backend())
    # Create a decryptor object using the cipher object
    decryptor = cipher.decryptor()
    # Decrypt the ciphertext using the decryptor object
    decrypted_padded_text = decryptor.update(ciphertext) + decryptor.finalize()
    # Create an unpadder object using PKCS7 padding with a block size of 64 bytes
    unpadder = padding.PKCS7(64).unpadder()
    # Unpad the decrypted padded text using the unpadder object
    unpadded_text = unpadder.update(decrypted_padded_text) + unpadder.finalize()
    return unpadded_text

# Get the user's choice of whether to encrypt or decrypt
choice = input("Enter 'e' to encrypt or 'd' to decrypt: ")

if choice == 'e':
    # Generate a random key and IV
    key = generate_key()
    iv = os.urandom(8)
    # Get the plaintext from the user
    plaintext = input("Enter a plaintext to encrypt: ").encode()
    # Encrypt the plaintext using 3DES
    ciphertext = encrypt(key, iv, plaintext)
    # Print the key, IV, and ciphertext in hexadecimal format
    print("Key (hexadecimal):", key.hex())
    print("IV (hexadecimal):", iv.hex())
    print("Ciphertext (hexadecimal):", ciphertext.hex())

elif choice == 'd':
    # Get the key, IV, and ciphertext from the user in hexadecimal format
    key = bytes.fromhex(input("Enter the key in hexadecimal format: "))
    iv = bytes.fromhex(input("Enter the IV in hexadecimal format: "))
    ciphertext = bytes.fromhex(input("Enter a ciphertext to decrypt: "))
    # Decrypt the ciphertext using 3DES
    plaintext = decrypt(key, iv, ciphertext)
    # Print the decrypted plaintext
    print("Plaintext:", plaintext.decode())

else:
    # If the user enters an invalid choice, print an error message
    print("Invalid choice.")