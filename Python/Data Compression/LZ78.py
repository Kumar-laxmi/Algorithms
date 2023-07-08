'''
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
'''

def compress(data):
    storage = {"": 0}
    compressed_data = []
    current_symbol = ""
    index = 1
    for character in data:
        current_symbol += character
        if current_symbol not in storage:
            storage[current_symbol] = index
            compressed_data.append((storage[current_symbol[:-1]], character))
            index += 1
            current_symbol = ""
    return compressed_data

def decompress(data):
    storage = {0: ""}
    decompressed_data = ""
    index = 1
    for character in data:
        storage[index] = storage[character[0]] + character[1]
        decompressed_data += storage[index]
        index += 1
    return decompressed_data


message = "ABBCBCABABCAABCAAB"
compressed_message = compress(message)
    #[(0, 'A'), (0, 'B'), (2, 'C'), (3, 'A'), (2, 'A'), (4, 'A'), (6, 'B')]
decompressed_message = decompress(compressed_message)

print(f"Original Message: {message}")
print(f"Compressed Message: {compressed_message}") 
print(f"Decompressed Message: {decompressed_message}") 

