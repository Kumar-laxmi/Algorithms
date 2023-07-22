morse_code_map = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
    '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.',
    ' ': '/'
}

def convert_to_morse_code(text):
    morse_code = []
    text = text.upper()
    
    for char in text:
        if char in morse_code_map:
            morse_code.append(morse_code_map[char])
            morse_code.append(' ')  # Add space between characters
    
    return ''.join(morse_code)

def main():
    text = input("Enter a text string: ")
    morse_code = convert_to_morse_code(text)
    
    print("Text:", text)
    print("Morse Code:", morse_code)

if __name__ == "__main__":
    main()
