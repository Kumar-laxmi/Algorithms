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

#include <iostream>
#include <string>

using namespace std;

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
string homophonic_substitution(string message) {
    string result = ""; // Define a string to hold the substituted message
    int j;
    for (int i = 0; i < message.length(); i++) {
        if (islower(message[i])) { // Check if the character is a lowercase letter
            j = message[i] - 'a'; // Calculate the index of the corresponding row in the substitution table
            result += homophonic[j % 6][i % 4]; // Substitute the character with the corresponding homophonic letter
        }
        else if (isupper(message[i])) { // Check if the character is an uppercase letter
            j = message[i] - 'A'; // Calculate the index of the corresponding row in the substitution table
            result += homophonic[j % 6][i % 4] - 32; // Substitute the character with the corresponding homophonic letter (converted to uppercase)
        }
        else { // If the character is not a letter, just copy it to the result
            result += message[i];
        }
    }
    return result; // Return the substituted message
}

// Define the main function
int main() {
    string message;
    cout << "Enter message: ";
    getline(cin, message); // Read the input message from the user
    cout << "Homophonic substitution: " << homophonic_substitution(message) << endl; // Perform homophonic substitution and print the result
    return 0; // Exit the program with success status
}
