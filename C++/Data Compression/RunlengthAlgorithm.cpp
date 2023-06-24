#include <iostream>
#include <string>

// Function to perform Run-Length Encoding
std::string runLengthEncoding(const std::string& input) {
    std::string encoded; // Output sequence to store the compressed data

    // Iterate through the input sequence
    for (int i = 0; i < input.length(); i++) {
        char current = input[i]; // Current character
        int count = 1; // Counter for the current character

        // Check if the current character is the same as the next character
        while (i + 1 < input.length() && input[i + 1] == current) {
            count++; // Increment the counter
            i++; // Move to the next character
        }

        // Append the current character and its count to the encoded sequence
        encoded += current;
        encoded += std::to_string(count);
    }

    return encoded;
}

int main() {
    std::string input = "AAAABBBCCDAA";
    std::string encoded = runLengthEncoding(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Encoded: " << encoded << std::endl;

    return 0;
}
