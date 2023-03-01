/*
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
*/


#include <stdio.h>
#include <string.h>

// Define a 6x5 array representing the homophonic substitution table
char homophonic[6][5] = {
    {'a', 'b', 'c', 'd', 'e'}, // Row 1
    {'f', 'g', 'h', 'i', '\0'}, // Row 2 (with a null terminator to indicate end of row)
    {'j', 'k', 'l', 'm', 'n'}, // Row 3
    {'o', 'p', 'q', 'r', '\0'}, // Row 4 (with a null terminator to indicate end of row)
    {'s', 't', 'u', 'v', '\0'}, // Row 5 (with a null terminator to indicate end of row)
    {'w', 'x', 'y', 'z', '\0'} // Row 6 (with a null terminator to indicate end of row)
};

// Define a function to perform homophonic substitution on a message
char *homophonic_substitution(char *message) {
    static char buffer[1024]; // Define a static buffer to hold the substituted message
    int i, j;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') { // Check if the character is a lowercase letter
            j = message[i] - 'a'; // Calculate the index of the corresponding row in the substitution table
            buffer[i] = homophonic[j % 6][i % 4]; // Substitute the character with the corresponding homophonic letter
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') { // Check if the character is an uppercase letter
            j = message[i] - 'A'; // Calculate the index of the corresponding row in the substitution table
            buffer[i] = homophonic[j % 6][i % 4] - 32; // Substitute the character with the corresponding homophonic letter (converted to uppercase)
        }
        else { // If the character is not a letter, just copy it to the buffer
            buffer[i] = message[i];
        }
    }
    buffer[i] = '\0'; // Terminate the buffer with a null character
    return buffer; // Return the substituted message
}

// Define the main function
int main() {
    char message[1024]; // Define an array to hold the input message
    printf("Enter message: ");
    fgets(message, 1024, stdin); // Read the input message from the user
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character from the input message
    printf("Homophonic substitution: %s\n", homophonic_substitution(message)); // Perform homophonic substitution and print the result
    return 0; // Exit the program with success status
}
