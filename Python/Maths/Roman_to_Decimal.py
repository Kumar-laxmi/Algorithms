#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
# Problem Statement : Given a Roman numeral, the task is to convert it into its decimal equivalent.
#EXAMPLES : 
#1)
#Input:  "XXI"
#Output: 21
#2)
#Input:  "MCMXCIV"
#Output: 1994 */
# Function to convert Roman numerals to decimal
def romanToInt(s):
    # Create a list to store the values of each Roman numeral
    values = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
    decimals = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    # Initialize the result to 0
    result = 0
    # Iterate over each symbol and its corresponding decimal value
    for i in range(len(values)):
        # Keep removing the symbol from the input string as long as it can be found in the string
        while s.startswith(values[i]):
            # Add the corresponding decimal value to the result
            result += decimals[i]
            # Remove the symbol from the input string
            s = s[len(values[i]):]
    # Return the result
    return result
# Take input from the user
s = input("Enter a Roman numeral: ")
# Convert the Roman numeral to decimal and print the result
result = romanToInt(s)
print("The decimal equivalent of the Roman numeral is:", result)