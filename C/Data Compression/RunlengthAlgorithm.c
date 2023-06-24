#include <stdio.h>
#include <string.h>

void runLengthEncoding(const char *input)
{
    int length = strlen(input);
    
    // Initialize an empty output sequence
    char output[length * 2]; // Assuming worst-case scenario where every character is unique
    int outputIndex = 0;
    
    // Iterate through the input sequence
    int i = 0;
    while (i < length)
    {
        // Start with the current element and compare it with the next element
        char current = input[i];
        int count = 1;
        
        // Check if the next element is the same as the current element
        while (i + 1 < length && input[i + 1] == current)
        {
            count++; // If the elements are the same, increment the counter
            i++; // Move to the next element
        }
        
        // Add the current element and its count to the output sequence
        output[outputIndex++] = current;
        output[outputIndex++] = count + '0'; // Convert count to character
        
        i++; // Move to the next element
    }
    
    // Null-terminate the output sequence
    output[outputIndex] = '\0';
    
    // Print the compressed data
    printf("Compressed data: %s\n", output);
}

int main()
{
    const char *input = "AAAABBBCCDAA";
    
    // Perform Run-Length Encoding on the input sequence
    runLengthEncoding(input);
    
    return 0;
}
