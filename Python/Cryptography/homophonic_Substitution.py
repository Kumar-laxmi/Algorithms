"""
Algorithm:
    1. Define a substitution dictionary: In this step, the algorithm defines a dictionary 
    that maps each letter in the plaintext message to one or more substitute characters 
    in the ciphertext message.

    2. Prompt for plaintext input: The algorithm prompts the user to enter the plaintext 
    message that they want to encrypt.

    3. Apply the substitution: The algorithm applies the substitution rules defined in 
    the dictionary to each letter in the plaintext message. If a letter has multiple 
    possible substitutes, one is chosen at random.

    4. Generate the ciphertext: The resulting substitute characters are concatenated to 
    form the ciphertext message.

    5. Output the ciphertext: The algorithm outputs the resulting ciphertext to the user.

Input:
    A string which is also called a plain text.
Output:
    A string called cipher text which changes everytime the same plaintext is entered.
    It substitutes the value of letters randomly to make the cipher text.
"""


import random

"""Define a dictionary of homophonic substitutions for the letters a, e, i, o, u, s"""
substitutions = {
    'a': ['@', '4', '8', '∂', 'æ'],
    'e': ['3', '€', 'ë', 'ê'],
    'i': ['1', '!', '|', 'ï', 'î'],
    'o': ['0', 'ø', 'ô', 'Ω'],
    'u': ['_', 'µ', 'ü', 'û'],
    's': ['5', '$', '§', 'ß'],
}

"""Define a function to apply the homophonic substitution for any string input"""
def homophonic_substitution(text):
    result = ''
    for char in text:
        if char.lower() in substitutions:
            choices = substitutions[char.lower()]
            result += random.choice(choices)
        else:
            result += char
    return result

"""Ask the user to enter any string as input"""
plaintext = input('Enter the plaintext message: ')

# Apply the homophonic substitution to the input
ciphertext = homophonic_substitution(plaintext)

# Print the results
print('Plaintext:', plaintext)
print('Ciphertext:', ciphertext)
