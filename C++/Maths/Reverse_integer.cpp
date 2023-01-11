/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/* Problem Description
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer
Look at the example for clarification.
Problem Constraints
N belongs to the Integer limits.
Input Format
Input an Integer.
Output Format
Return a single integer denoting the reverse of the given integer.
Example Input
Input 1:
x = 123
Input 2:
x = -123
Example Output
Output 1:
321
Ouput 2:
-321
 Example Explanation
If the given integer is negative like -123 the output is also negative -321.*/
// C++ program to reverse digits
// of a number
#include <bits/stdc++.h>
using namespace std; 
/* Iterative function to reverse
digits of num*/
int reverseInt(int n)
{
    // Handling negative numbers
    bool negativeF = false;
    if (n < 0)
    {
        negativeF = true;
        n = -n ;
    }
    int prev_rev_Int = 0, rev_Int = 0;
    while (n != 0)
    {
        int curr_digit = n % 10;
        rev_Int = (rev_Int * 10) + curr_digit;
        // checking if the reverse overflowed or not.
        // The values of (rev_num - curr_digit)/10 and
        // prev_rev_num must be same if there was no
        // problem.
        if ((rev_Int - curr_digit) /
               10 != prev_rev_Int)
        {
            return 0;
        }
        prev_rev_Int = rev_Int;
        n = n / 10;
    }
    return (negativeF == true) ?
   -rev_Int : rev_Int;
} 
// Main function
int main()
{
    int n;
    cout << "Enter the integer value" << endl;
    cin >> n;
    cout << "Reverse of Given Integer is " << reverseInt(n) << endl;
    return 0;
}