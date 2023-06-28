/*
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

Below is the implementation of Number-to-Words Conversion in C++ Language.
*/

// Program starts
#include <bits/stdc++.h>
using namespace std;

// Initialising global variables of name of words
vector<string> digit = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

vector<string> denominations = {"", "Thousand", "Million", "Billion", "Trillion"};

vector<string> tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

vector<string> ties = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

// Declaring input value globally
string input;

// Function to concatenate two strings with a space between them
string add(const string &s1, const string &s2)
{
    if (s1.size() && s2.size())
        return s1 + " " + s2;
    return s1 + s2;
}

// Function to convert any number into words recursively
string convert(int idx, int level)
{
    // Base condition to check whether the current index is greater than or equal to the size of the input number
    if (idx >= (int)input.size())
        return "";
    string cur = "";
    int od, td, hd;
    od = int(input[idx] - '0');  // One's digit
    td = int(input[idx + 1] - '0');  // Ten's digit
    hd = int(input[idx + 2] - '0');  // Hundred's digit
    
    if (hd)
        cur = add(cur, add(digit[hd], "Hundred"));  // Add the hundred's digit to the current string
    
    if (td)
    {
        if (td == 1)
            cur = add(cur, tens[od]);  // If the ten's digit is 1, use the corresponding value from the 'tens' vector
        else
        {
            cur = add(cur, ties[td - 1]);  // If the ten's digit is not 1, use the corresponding value from the 'ties' vector
            if (od)
                cur = add(cur, digit[od]);  // Add the one's digit if it's not zero
        }
    }
    else if (od)
        cur = add(cur, digit[od]);  // If the ten's digit is zero, only add the one's digit
    
    if (cur != "")
        cur = add(cur, denominations[level]);  // Add the current level's denomination (thousand, million, billion, etc.) to the string
    
    return add(convert(idx + 3, level + 1), cur);  // Recursively convert the remaining digits and concatenate with the current string
}

// Driver function
int main()
{
    // Taking input from the user
    cout << "\nEnter Number : ";
    cin >> input;
    
    while ((int)input.size() % 3 != 0)
        input = "0" + input;  // Pad the input number with leading zeros to make its size a multiple of 3
    
    cout << endl << input << " in Words : ";
    
    reverse(input.begin(), input.end());  // Reverse the input number for easier processing

    if (input == "000")
        cout << "Zero" << endl; // If user enter only zero
    else if(input.size() > 15)
        cout << "This is a very large number !" << endl;
    else
        cout << convert(0, 0) << endl;  // Convert the input number to words and print the result

    cout << endl;

    return 0;
}
