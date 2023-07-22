#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char character;
    char* code;
} MorseCodeEntry;

MorseCodeEntry morseCodeMap[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
    {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
    {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', "/"}
};

char* convertToMorseCode(const char* text) {
    int textLength = strlen(text);
    char* morseCode = (char*)malloc((4 * textLength + 1) * sizeof(char));
    int morseCodeIndex = 0;

    for (int i = 0; i < textLength; i++) {
        char upperChar = toupper(text[i]);

        for (int j = 0; j < sizeof(morseCodeMap) / sizeof(MorseCodeEntry); j++) {
            if (morseCodeMap[j].character == upperChar) {
                strcpy(&morseCode[morseCodeIndex], morseCodeMap[j].code);
                morseCodeIndex += strlen(morseCodeMap[j].code);
                morseCode[morseCodeIndex++] = ' '; // Add space between characters
                break;
            }
        }
    }

    morseCode[morseCodeIndex] = '\0';
    return morseCode;
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter a text string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    char* morseCode = convertToMorseCode(text);
    printf("Text: %s\n", text);
    printf("Morse Code: %s\n", morseCode);

    free(morseCode);
    return 0;
}
