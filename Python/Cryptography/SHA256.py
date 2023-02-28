"""
Definition:
    SHA-256 (Secure Hash Algorithm 256) is a widely-used cryptographic hashing 
    algorithm that produces a fixed-size 256-bit (32-byte) hash value. The 
    SHA-256 algorithm takes an input message of any length and processes it in 
    512-bit (64-byte) blocks. The message is first padded with a 1-bit followed 
    by zeros to make it a multiple of 512 bits. The last 64 bits of the padded 
    message are used to store the length of the original message in bits. The 
    output of the SHA-256 algorithm is a 256-bit hash value that is typically 
    represented as a sequence of 64 hexadecimal digits. The hash value is unique 
    to the input message, and even a small change to the message will result 
    in a completely different hash value. This makes the SHA-256 algorithm useful 
    for verifying the integrity of data, as well as for password hashing and 
    digital signatures.
Input:
    Option: the code asks the user if they want to encrypt or verify a hash
    Message: in case the user wants to encrypt, the code asks the user for a message to encrypt.
    Hash: if the user wants to verify a hash, then the code asks the user for the original 
    hash and the original message.
Output:
    Hash: If the user wants to encrypt a message, the code gives a hash as the output.
    Verification: If the user wanted to verify a hash and has given the necessary inputs, the code 
    will either say the hash is verified in case of successful verification or it will say that 
    the hash does not match, indicating the hash or message for this hash is invalid.
"""

import hashlib

"""Ask the user whether to encrypt a message or verify a hash"""
while True:
    action = input("Do you want to encrypt or verify a hash? (e/v): ")
    if action == 'e':
        """Here the Encryption of a string is being done."""
        input_str = input("Enter a string to hash: ")
        input_bytes = input_str.encode('utf-8')
        hash_obj = hashlib.sha256()
        hash_obj.update(input_bytes)
        hash_result = hash_obj.hexdigest()
        print("The SHA-256 hash of the input string is:", hash_result)
        break
    elif action == 'v':
        """Here a hash is being Verified"""
        input_str = input("Enter the original string: ")
        input_bytes = input_str.encode('utf-8')
        original_hash = input("Enter the original hash: ")
        verify_obj = hashlib.sha256()
        verify_obj.update(input_bytes)
        verify_result = verify_obj.hexdigest()
        if verify_result == original_hash:
            """Hash verification successful"""
            print("The hash is verified.")
        else:
            """Hash verification is unsuccessful"""
            print("The hash does not match.")
        break
    else:
        print("Invalid input. Please enter 'e' or 'v'.")
