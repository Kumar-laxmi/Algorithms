"""
The Diffie-Hellman algorithm is being used to establish a shared secret that 
can be used for secret communications while exchanging data over a public network 
using the elliptic curve to generate points and get the secret key using the parameters.
I took same example of Alice and Bob which is mentioned in the issue . 
Time complexity using single key exchange - O (n^3).
Space Complexity - O (n)
"""

def power(base, exponent, modulus):
    result = 1
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent = exponent // 2
        base = (base * base) % modulus
    return result

def diffie_hellman():
    P = int(input("Enter a prime number P: "))
    G = int(input("Enter a G (G is a primitive root of P): "))

    # The below code generate private keys for Alice and Bob
    Private_Alice = int(input("Enter Alice's private key: "))
    Private_Bob = int(input("Enter Bob's private key: "))

    # To compute public values
    # Public_Alice = "G^Private_Alice mod P"
    # Public_Bob = "G^Private_Bob mod P"
    Public_Alice = power(G, Private_Alice, P)
    Public_Bob = power(G, Private_Bob, P)

    print("\nPublic keys of Alice and Bob : " , Public_Alice ,"&", Public_Bob)

    # Generate secret key
    alice_shared_secret = power(Public_Bob, Private_Alice, P)
    bob_shared_secret = power(Public_Alice, Private_Bob, P)

    print("Generated Secret Key are" ,alice_shared_secret , "&" ,bob_shared_secret)

    if alice_shared_secret == bob_shared_secret:
        print("Shared secret:", bob_shared_secret)

        # Encryption using XOR encrpytion algorithm
        message = input("Enter a message to encrypt: ")
        encryption = message.encode()
        encrypted_message = bytes([encryption[i] ^ (alice_shared_secret >> (i % 16) * 8) % 256 for i in range(len(encryption))])
        print("Encrypted message is:", encrypted_message.hex())

        decrypted_message = bytes([encrypted_message[i] ^ (alice_shared_secret >> (i % 16) * 8) % 256 for i in range(len(encrypted_message))])
        decoded_message = decrypted_message.decode()
        print("Decrypted message is:", decoded_message)
    else:
        print("Shared secrets do not match.")

diffie_hellman()



