/*
Written by nuggetbucket54

========== COMPRESSION LOGIC ==========

1. Start with an empty dictionary and an empty input buffer.
2. Read symbols from the input data one at a time.
3. Initialize a prefix as an empty string.
4. Append the current symbol to the prefix.
5. If the prefix is already in the dictionary, update the prefix by
   appending the current symbol and repeat step 5.
6. If the prefix is not in the dictionary, add the prefix to the dictionary with a unique index
   and output the index of the previous prefix and the current symbol.
7. Clear the prefix and repeat from step 4 until all symbols are processed.

========== DECOMPRESSION LOGIC ==========

During decompression, the algorithm uses the dictionary entries to reconstruct the original data.
It reads the index and symbol pairs, retrieves the corresponding phrases from the dictionary, and
outputs them to reconstruct the original data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct {
    int index;
    char symbol;
} CompressedPair;

CompressedPair* compress(const char* data, int* compressed_size) {
    int data_length = strlen(data);
    int index = 1;
    char current_symbol[MAX_BUFFER_SIZE];
    CompressedPair* compressed_data = (CompressedPair*)malloc(data_length * sizeof(CompressedPair));
    int compressed_index = 0;

    memset(current_symbol, 0, sizeof(current_symbol));

    for (int i = 0; i < data_length; i++) {
        current_symbol[strlen(current_symbol)] = data[i];
        if (strstr(current_symbol, "\0") != NULL) {
            compressed_data[compressed_index].index = index;
            compressed_data[compressed_index].symbol = data[i];
            compressed_index++;
            index++;
            memset(current_symbol, 0, sizeof(current_symbol));
        }
    }

    *compressed_size = compressed_index;
    return compressed_data;
}

char* decompress(const CompressedPair* data, int compressed_size) {
    char** storage = (char**)malloc(MAX_BUFFER_SIZE * sizeof(char*));
    char* decompressed_data = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
    int index = 1;

    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        storage[i] = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
        memset(storage[i], 0, sizeof(storage[i]));
    }

    memset(decompressed_data, 0, sizeof(decompressed_data));

    for (int i = 0; i < compressed_size; i++) {
        strcat(storage[index], storage[data[i].index]);
        storage[index][strlen(storage[index])] = data[i].symbol;
        strcat(decompressed_data, storage[index]);
        index++;
    }

    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        free(storage[i]);
    }
    free(storage);

    return decompressed_data;
}

int main() {
    const char* message = "ABBCBCABABCAABCAAB";
    int compressed_size;
    CompressedPair* compressed_message = compress(message, &compressed_size);
    char* decompressed_message = decompress(compressed_message, compressed_size);

    printf("Original Message: %s\n", message);
    printf("Compressed Message: ");
    for (int i = 0; i < compressed_size; i++) {
        printf("(%d, %c), ", compressed_message[i].index, compressed_message[i].symbol);
    }
    printf("\n");
    printf("Decompressed Message: %s\n", decompressed_message);

    free(compressed_message);
    free(decompressed_message);

    return 0;
}