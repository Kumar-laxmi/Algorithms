#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, string> morseCodeMap = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."},
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "/"}
};

string convertToMorseCode(const string& text) {
    string morseCode;
    for (char ch : text) {
        char upperChar = toupper(ch);
        if (morseCodeMap.count(upperChar) > 0) {
            morseCode += morseCodeMap[upperChar];
            morseCode += ' '; // Add space between characters
        }
    }
    return morseCode;
}

int main() {
    string text;
    cout << "Enter a text string: ";
    getline(cin, text);

    string morseCode = convertToMorseCode(text);
    cout << "Text: " << text << endl;
    cout << "Morse Code: " << morseCode << endl;

    return 0;
}
