/* Name : Abhinav kumar
Github username : Abhinavcode13
Repository name : Algorithms
Problem : Algorithm for converting an Binary number to a Decimal number and Decimal number to Binary number
Issue Number : #270
Algorithm of issue :

1. Binary to decimal

This program takes an input binary number from the user and converts it to its equivalent decimal form. Here are the steps it follows:

-First, it takes the input binary number from the user.
-Then, it initializes a variable decimalNumber to 0 and a variable i to 0. decimalNumber will store the decimal equivalent of the binary number, and i will keep track of the position of the binary digits.
-Inside a while loop, it performs the following steps:
-It calculates the remainder of the binary number when divided by 10 and stores it in the variable remainder.
-It divides the binary number by 10 and updates its value.
-It calculates the decimal equivalent of the binary digit in the current position (based on the value of i) by multiplying the remainder with 2 raised to the power of i.
-It adds this value to decimalNumber.
-It increments the value of i by 1 to move to the next binary digit position.
 Once the while loop has finished, it outputs the final value of decimalNumber

2. Decimal to binary

-First, it takes the input decimal number from the user.
-Then, it initializes a variable binaryNumber to 0, a variable i to 1, and a variable quotient to the value of the decimal number. binaryNumber will store the binary equivalent of the decimal number, i will keep track of the position of the binary digits, and quotient will be used to calculate the binary digits.
-Inside a while loop, it performs the following steps:
-It calculates the remainder of the quotient when divided by 2 and stores it in the variable remainder.
-It divides the quotient by 2 and updates its value.
-It calculates the binary equivalent of the decimal digit in the current position (based on the value of i) by multiplying the remainder with i.
-It adds this value to binaryNumber.
-It updates the value of i by multiplying it with 10 to move to the next binary digit position.
 Once the while loop has finished, it outputs the final value of binaryNumber.

*/


-------------------------------------------------------------------------//C++ code begins here--------------------------------------------------------------------------
  
//Binary to decimal

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long binaryNumber, decimalNumber = 0, i = 0, remainder;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    cout << "Decimal number is: " << decimalNumber;
    return 0;
}


//Binary to decimal

#include <iostream>

using namespace std;

int main()
{
    int decimalNumber, remainder, quotient, i = 1, binaryNumber = 0;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    quotient = decimalNumber;

    while (quotient != 0)
    {
        remainder = quotient % 2;
        quotient /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    cout << "Binary number is: " << binaryNumber;
    return 0;
}
