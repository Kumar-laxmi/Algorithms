#!/bin/env python

"""
##################################Definition######################################

RSA (Rivest-Shamir-Adleman) is a widely used public-key encryption algorithm that
is based on the mathematical properties of large prime numbers. It is used to s
ecure sensitive information such as financial transactions, electronic communications,
and data storage. The RSA algorithm is used in a wide variety of software and hardware,
including web browsers, email systems, and secure telephones. The security of the 
RSA algorithm is based on the fact that it is very difficult to factorize large prime
numbers, making it computationally infeasible for an attacker to determine the private 
key from the public key.

###################################Algorithm######################################

Key generation: This step involves the generation of two prime numbers(preferrably large), 
                p and q, and the computation of their product n = pq, which 
                is used as the modulus for both the public and private keys.
Public key computation: The public key, e, is computed as a number relatively prime to 
                        (p-1)(q-1), and is then used to encrypt the plaintext.
Private key computation: The private key, d, is computed as the modular 
                        multiplicative inverse of e modulo (p-1)(q-1)
Encryption: The plaintext is encrypted by raising it to the power of e modulo n
Decryption: The ciphertext is decrypted by raising it to the power of d modulo n,
             which results in the original plaintext
"""
import random
import math

#Checking if two numbers are co prime using greatest common divisor
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

#Finding the modular inverse "x" of a number "a"
def mod_inv(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

#Checking if a number is Prime
def is_prime(n):
    flag = 0
    if(n > 1):
	    for k in range(2, int(math.sqrt(n)) + 1):
		    if (n % k == 0):
			    flag = 1
		    break
	    if (flag == 0):
		    return True
	    else:
		    return False
    else:
	    return False

#generating public key and private key pair
def generate_keypair(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Both numbers must be prime.')
    elif p == q:
        raise ValueError('p and q cannot be equal')

    #calculating phi using euler totient function
    n = p * q
    phi = (p-1) * (q-1)
    # "e" is the public key
    e = random.randrange(1, phi)
    g = gcd(e, phi)
    while g != 1:
        e = random.randrange(1, phi)
        g = gcd(e, phi)

    # "d" is the private key
    d = mod_inv(e, phi)
    return ((e, n), (d, n))

#code for encryption
def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext]
    return cipher

#code for decryption
def decrypt(pk, ciphertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in ciphertext]
    return ''.join(plain)

#main function
if __name__ == '__main__':
    p = int(input("enter a prime: "))
    q = int(input("enter a different prime: "))
    public, private = generate_keypair(p, q)
    print(f"Public key: {public}")
    print(f"Private key: {private}")
    message = input("Enter a message: " )
    encrypted_msg = encrypt(public, message)
    print(f"Encrypted message: {encrypted_msg}")
    decrypted_msg = decrypt(private, encrypted_msg)
    print(f"Decrypted message: {decrypted_msg}")

