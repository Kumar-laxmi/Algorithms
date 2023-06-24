def run_length_encoding(data):
    # Initialize an empty output sequence
    encoded_data = []

    # Iterate through the input sequence
    i = 0
    while i < len(data):
        # Start with the current element and compare it with the next element
        current_char = data[i]
        count = 1

        # Check if there are consecutive repeated elements
        while i + 1 < len(data) and data[i] == data[i + 1]:
            count += 1
            i += 1

        # Add the current element and its count to the output sequence
        encoded_data.append(current_char)
        encoded_data.append(str(count))

        # Move to the next element
        i += 1

    # Return the encoded data as a string
    return ''.join(encoded_data)

# Example usage
input_data = "AAAABBBCCDAA"
encoded_data = run_length_encoding(input_data)
print("Encoded data:", encoded_data)
