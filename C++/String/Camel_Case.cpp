/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/*Problem Description
Program to convert  text sentence in CamelCase format .
Examples:
 1] INPUT: "this is camel case"
    OUTPUT "thisIsCamelCase"
 2] INPUT: "Hi Atul here"
   OUTPUT: "hiAtulHere"
Example Explanation */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int Testcase;
    cout << "Enter no of Testcases: ";
    cin >> Testcase;
    cout << endl;
    cin.ignore(); // Clear the input buffer
    while (Testcase--) {
        string str;
        cout << "Enter a sentence: ";
        getline(cin, str);
        bool flag = false;
        string camelCaseString = "";
        for (int i = 0; i < str.length(); i++) {
            if (i == 0) camelCaseString += tolower(str[i]);   //Converts to lowercase
            else if (str[i] == ' ') flag = true; // Check for spaces in the sentence
            else if (flag && str[i] != ' ') {
                camelCaseString += toupper(str[i]);   //Converts to uppercase
                flag = false;
            }
            else camelCaseString += tolower(str[i]);   //Converts to lowercase
        }
        cout << "Original: " << str << endl;
        cout << "Camel Case: " << camelCaseString << endl;
    }
    return 0;
}