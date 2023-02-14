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
   OUTPUT: "HiAtulHere"
Example Explanation */
#include <iostream>
#include <string>
using namespace std;
int main()                // Main function
{
    int count;
    cout << "Enter text count: ";  
    cin >> count;                     // Taking input of count from user
    if(cin.fail())
    {
        cout << "Invalid input." << endl;     //If input is in invalid format
        exit(0);
    }
    cin.ignore(10000,'\n');
    for(int i = 0; i < count; i++)
    {
        string film;
        cout << "Enter text : ";     //Taking text sentence from user
        getline(cin, film);
        if(cin.fail())
        {
            cout << "Invalid input." << endl;
            exit(0);
        }
        if(film.size() == 0)            // If user dosen't input 
            break;
        film[0] = tolower(film[0]);
        for(unsigned int i = 1; i < film.size() - 1; i++)
        {
            if(film[i] == ' ')
            {
                film.erase(i,1);
                film[i] = toupper(film[i]);
                i--;
            }
        }
        cout << "Result: " << film << endl;   // Print the text into Camelcase format
     }
    return 0;
}