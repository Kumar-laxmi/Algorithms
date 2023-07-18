#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculateParityBits(int m, int low, int high) {
    //Binary algorithm to find required number of bits
    if (high == 0) {
        high = m + 1;
    }
    
    int r = (low + high) / 2;
    
    if (low == high) {
        return low;
    } else if ((1 << r) >= r + m + 1) {     //#r = redundant bit, m = data bit
        return calculateParityBits(m, low, r);
    } else {
        return calculateParityBits(m, r + 1, high);
    }
}

int isPowerOfTwo(int num){
    //Performs a bitwise AND operation between num and num - 1. 
    //This operation turns off the rightmost set bit in num 
    //(i.e., the least significant bit).
    
    //If the result of the bitwise AND operation is zero, it means that num 
    //had only one set bit (power of 2) before the bitwise operation, and 
    //that bit was turned off. In this case, the number is considered a power of 2
    return (num & (num - 1)) == 0;
}

int calculateParityValue(const char* encoded_block, int block_size, int pos) {
    int count = 0;
    for (int i = 0; i < block_size; i++) {
        //If value of bit is '1' and corresponds to current parity
        if (encoded_block[i] == '1' && ((i + 1) & pos) != 0) {
            count++;
        }
    }
    return count % 2;
}

char* hamming_encode(const char* message) {
    int m = strlen(message); // Length of the message
    int r = calculateParityBits(m,0,0); // Calculate number of parity bits
    
    int block_size = m + r; //Total size of the encoded block

    //Allocate memory for the encoded block (+1 for the null terminator)
    char* encoded_block = (char*)malloc((block_size + 1) * sizeof(char));

    int data_bit = 0;
    int numOnes=0;
    //Iterate over block and copy data
    for (int position = 1; position <= block_size; position++) {
        if (isPowerOfTwo(position)) {
            encoded_block[position - 1] = 'P'; //Mark as parity bit
            numOnes++; //Count number of ones
        } else {
            encoded_block[position - 1] = message[data_bit]; //Data bit, copy from the message
            data_bit++;
        }
    }
    for (int position = 1; position <= block_size; position++) {
        if (encoded_block[position - 1] == 'P') {
            // Calculate and assign the required parity value
            int parity = calculateParityValue(encoded_block, block_size, position);
            encoded_block[position - 1] = (parity % 2 == 0) ? '0' : '1';
        }
    }

    encoded_block[block_size] = '\0'; // Null terminator

    return encoded_block;
}

int main(){
    const char* message = "11110010010"; // Example message
    char* encoded_message = hamming_encode(message);

    printf("Message entered: %s\n", message);
    printf("Encoded Message: %s\n", encoded_message);
    free(encoded_message); // Free the dynamically allocated memory
}