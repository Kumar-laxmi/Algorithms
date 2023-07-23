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

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <pair <int, char>> compress(string data) {
    map <string, int> storage;
    vector <pair <int, char>> compressed_data;
    string current_symbol = "";
    int index = 1;

    for (char character: data) {
        current_symbol += character;
        if (storage.find(current_symbol) == storage.end()) {
            storage[current_symbol] = index;
            compressed_data.push_back(make_pair(
                storage[current_symbol.substr(0, current_symbol.length() - 1)], character
            ));
            index += 1;
            current_symbol = "";
        }
    }

    return compressed_data;
}

string decompress(vector <pair <int, char>> data) {
    map <int, string> storage;
    string decompressed_data = "";
    int index = 1;
    for (auto character: data) {
        storage[index] = storage[character.first] + character.second;
        decompressed_data += storage[index];
        index += 1;
    }

    return decompressed_data;
}


int main() {
    string message = "ABBCBCABABCAABCAAB";
    vector <pair <int, char>> compressed_message = compress(message);
    string decompressed_message = decompress(compressed_message);

    cout << "Original Message: " << message << endl;
    cout << "Compressed Message: ";
    for (auto element: compressed_message) {
        cout << "(" << element.first << ", " << element.second << "), ";
    }
    cout << endl;
    cout << "Decompresed Message: " << decompressed_message << endl;
}
