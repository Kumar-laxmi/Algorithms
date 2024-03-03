'''
------------------------------------- Number To Words Convertor -------------------------------------

Approach

1. Initialize global vectors containing the words for digits, denominations (thousand, million, etc.), tens, and ties.

2. Read an input number as a string from the user.

3. Pad the input number with leading zeros if its size is not a multiple of 3.

4. Reverse the input number for easier processing.

5. Recursively convert the input number to words by processing it in groups of three digits.

6. Extract the one's, ten's, and hundred's digits from the current group.

7. Build the word representation by appending the corresponding words for the digits, tens, and hundreds.

8. Append the appropriate denomination (thousand, million, etc.) based on the current level.

9. Recursively process the remaining digits.

10. Print the resulting word representation of the input number.

Below is the implementation of Number-to-Words Conversion in PYTHON Language.
'''

# Program starts

# Initializing global variables for word representations
digit = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]

denominations = ["", "Thousand", "Million", "Billion", "Trillion"]

tens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]

ties = ["Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]

# Function to concatenate two strings with a space between them
def add(s1, s2):
    if s1 and s2:
        return s1 + " " + s2
    return s1 + s2

# Function to convert any number into words recursively
def convert(idx, level):
    # Base condition to check whether the current index is greater than or equal to the size of the input number
    if idx >= len(input):
        return ""
    cur = ""
    od = int(input[idx])  # One's digit
    td = int(input[idx + 1])  # Ten's digit
    hd = int(input[idx + 2])  # Hundred's digit

    if hd:
        cur = add(cur, add(digit[hd], "Hundred"))  # Add the hundred's digit to the current string

    if td:
        if td == 1:
            cur = add(cur, tens[od])  # If the ten's digit is 1, use the corresponding value from the 'tens' list
        else:
            cur = add(cur, ties[td - 1])  # If the ten's digit is not 1, use the corresponding value from the 'ties' list
            if od:
                cur = add(cur, digit[od])  # Add the one's digit if it's not zero
    elif od:
        cur = add(cur, digit[od])  # If the ten's digit is zero, only add the one's digit

    if cur:
        cur = add(cur, denominations[level])  # Add the current level's denomination (thousand, million, billion, etc.) to the string

    return add(convert(idx + 3, level + 1), cur)  # Recursively convert the remaining digits and concatenate with the current string

# Driver function
if __name__ == '__main__':
    # Taking input from the user
    input = input("\nEnter Number: ")
    
    print(f"\n{input} in Words: ", end="")

    while len(input) % 3 != 0:
        input = "0" + input  # Pad the input number with leading zeros to make its size a multiple of 3
    
    input = input[::-1]  # Reverse the input number for easier processing
    
    if input == "000":
        print("Zero")  # If the input number is all zeros
    elif len(input) > 15:
        print("This is a very large number !")  # If the input number exceeds the supported range
    else:
        print(convert(0, 0))  # Convert the input number to words and print the result

    print('\n')
