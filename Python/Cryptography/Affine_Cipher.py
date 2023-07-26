#AFFINE CIPHER
#The Affine cipher is a standard substitution cipher.
#Encryption:
#        Cipher Text, C=(aX+b) mod 26
#        where a, b are key values and X is letter to be encrypted.
#Decryption:
#        Plain Text, X=[a^-1(C-b)] mod 26
#        where alphabets from (a-z) are numbered sequentially from (0-25).

def is_coprime(a, b):
    while b != 0:
        temp = b
        b = a % b
        a = temp
    gcd = a
    return gcd == 1

def mod_inverse(a, m):
    a = a % m
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return -1

def cipher(plain_text, a, b):
    ciphertext = ""
    for t in plain_text:
        alpha_val = ord(t) - 97
        c = (a * alpha_val + b) % 26
        changed_char = chr(c + 97)
        ciphertext += changed_char
    return ciphertext

def decipher(ciphertext, a, b):
    plaintext = ""
    inverse_a = mod_inverse(a, 26)
    for c in ciphertext:
        alpha_val = ord(c) - 97
        decipher_t = (inverse_a * (alpha_val - b + 26)) % 26
        changed_char = chr(decipher_t + 97)
        plaintext += changed_char
    return plaintext

def main():
    plain_text = input("Enter plain text: ")
    a, b = map(int, input("Enter keys a and b: ").split())

    if not is_coprime(a, 26):
        print("Key 'a' and modulus 'm' are not coprime. Choose different keys.")
        return

    ciphertext = cipher(plain_text, a, b)
    print("Cipher Text after Encryption:")
    print(ciphertext)

    decrypted_text = decipher(ciphertext, a, b)
    print("Decrypted Text/Plain Text after Decryption:")
    print(decrypted_text)

if __name__ == "__main__":
    main()
