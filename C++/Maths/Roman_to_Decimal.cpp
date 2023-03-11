/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/* Problem Statement : Given a Roman numeral, the task is to convert it into its decimal equivalent.
EXAMPLES : 
1)
Input:  "XXI"
Output: 21
2)
Input:  "MCMXCIV"
Output: 1994 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
// Function to return the decimal equivalent of a Roman numeral
int value(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    // If the character is not a valid Roman numeral
    return -1;
}
// Function to convert Roman numeral to decimal
int romanToDecimal(string str)
{
    int result = 0;
    int prev = 0;
    // Iterating over each character in the input string in reverse order
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int curr = value(str[i]);
        if (curr >= prev)
        {
            // If the value of the current symbol is greater than or equal to the value of the previous symbol, add it to the result
            result += curr;
        }
        else
        {
            // If the value of the current symbol is less than the value of the previous symbol, subtract it from the result
            result -= curr;
        }
        prev = curr;
    }

    return result;
}
int main()
{
    string str;
    cout << "Enter a Roman numeral: ";
    cin >> str;
    cout << "Decimal equivalent: " << romanToDecimal(str) << endl;
    return 0;
}