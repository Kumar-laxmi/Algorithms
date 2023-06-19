/*----------------------------------------------Introduction---------------------------------------------------------------------------
Morse code is a method used in telecommunication to encode text characters as standardized sequences of two different signal durations, called dots and dashes. 
Morse Code defines a standard encoding where each letter is mapped to a series of  dots and dashes, as follows:
 “a” maps to “.-“, “b” maps to “-…”, “c” maps to “-.-.”, and so on.
----------------------------------------------Algorithm------------------------------------------------------------------------------
Every character in the English language is substituted by a series of 'dots' and 'dashes' or sometimes just singular 'dot' or 'dash' and vice versa.
Every text string is converted into the series of dots and dashes. For this every character is converted into its Morse code and 
appended in encoded message and have considered both numbers and alphabets.*/


#include <bits/stdc++.h>
using namespace std;

// function to encode a alphabet as
// Morse code
string morseEncode(char x)
{

	// refered  to the Morse table
	switch (x) {
	case 'a':
		return ".-";
	case 'b':
		return "-...";
	case 'c':
		return "-.-.";
	case 'd':
		return "-..";
	case 'e':
		return ".";
	case 'f':
		return "..-.";
	case 'g':
		return "--.";
	case 'h':
		return "....";
	case 'i':
		return "..";
	case 'j':
		return ".---";
	case 'k':
		return "-.-";
	case 'l':
		return ".-..";
	case 'm':
		return "--";
	case 'n':
		return "-.";
	case 'o':
		return "---";
	case 'p':
		return ".--.";
	case 'q':
		return "--.-";
	case 'r':
		return ".-.";
	case 's':
		return "...";
	case 't':
		return "-";
	case 'u':
		return "..-";
	case 'v':
		return "...-";
	case 'w':
		return ".--";
	case 'x':
		return "-..-";
	case 'y':
		return "-.--";
	case 'z':
		return "--..";
	case '1':
		return ".----";
	case '2':
		return "..---";
	case '3':
		return "...--";
	case '4':
		return "....-";
	case '5':
		return ".....";
	case '6':
		return "-....";
	case '7':
		return "--...";
	case '8':
		return "---..";
	case '9':
		return "----.";
	case '0':
		return "-----";
	default:
		cout << "Found invalid character: " << x << ' '<< endl;
        exit(0);
		
	}
}

void morseCode(string s)
{

	// character by character print
	// Morse code
	for (int i = 0; s[i]; i++)
		cout << morseEncode(s[i])<<" ";
	cout << endl;
}

int main()
{
	string s;
    cout<<"Enter a string:";
    cin>>s;
	morseCode(s);
	return 0;
}
