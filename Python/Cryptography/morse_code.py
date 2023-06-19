"""----------------------------------------------Introduction---------------------------------------------------------------------------
Morse code is a method used in telecommunication to encode text characters as standardized sequences of two different signal durations, called dots and dashes. 
Morse Code defines a standard encoding where each letter is mapped to a series of  dots and dashes, as follows:
 “a” maps to “.-“, “b” maps to “-…”, “c” maps to “-.-.”, and so on.
----------------------------------------------Algorithm------------------------------------------------------------------------------
Every character in the English language is substituted by a series of 'dots' and 'dashes' or sometimes just singular 'dot' or 'dash' and vice versa.
Every text string is converted into the series of dots and dashes. For this every character is converted into its Morse code and 
appended in encoded message and have considered both numbers and alphabets."""


# function to encode a alphabet as
# Morse code
def morseEncode(x):
	
	# refered to the Morse table
	
	if x == 'a':
		return ".-"
	elif x == 'b':
		return "-..."
	elif x == 'c':
		return "-.-."
	elif x == 'd':
		return "-.."
	elif x == 'e':
		return "."
	elif x == 'f':
		return "..-."
	elif x == 'g':
		return "--."
	elif x == 'h':
		return "...."
	elif x == 'i':
		return ".."
	elif x == 'j':
		return ".---"
	elif x == 'k':
		return "-.-"
	elif x == 'l':
		return ".-.."
	elif x == 'm':
		return "--"
	elif x == 'n':
		return "-."
	elif x == 'o':
		return "---"
	elif x == 'p':
		return ".--."
	elif x == 'q':
		return "--.-"
	elif x == 'r':
		return ".-."
	elif x == 's':
		return "..."
	elif x == 't':
		return "-"
	elif x == 'u':
		return "..-"
	elif x == 'v':
		return "...-"
	elif x == 'w':
		return ".--"
	elif x == 'x':
		return "-..-"
	elif x == 'y':
		return "-.--"
	elif x == 'z':
		return "--.."
	elif x == '1':
		return ".----"
	elif x == '2':
		return "..---"
	elif x == '3':
		return "...--"
	elif x == '4':
		return "....-"
	elif x == '5':
		return "....."
	elif x == '6':
		return "-...."
	elif x == '7':
		return "--..."
	elif x == '8':
		return "---.."
	elif x == '9':
		return "----."
	elif x == '0':
		return "-----"

# character by character print
# Morse code
def morseCode(s):
	for character in s:
		print(morseEncode(character), end = "")


s = input("Enter a string:")
morseCode(s)
