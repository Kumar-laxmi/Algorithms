// convert decimal to binary
//Approach to solve
//This code is a simple program that converts a decimal (base 10) number to binary (base 2) using recursion.
//The main function of the code is the "convert" function, which takes an integer "n" as its input.
//This function first checks if the input number is 0. If it is, the function returns without doing anything. 
//If the input number is not 0, the function makes a recursive call to itself, passing in the value of "n" divided by 2 as the new input.
//This effectively "shifts" the binary digits of the number one place to the right, discarding the rightmost digit.
//The function then prints the value of "n" modulo 2, which is the rightmost digit of the binary representation of the number. This digit is stored in the output.

//In the main function, the code first prompts the user to enter a decimal number, and stores the value in the variable "n". 
//The code then calls the "convert" function, passing in "n" as the input.
//This causes the "convert" function to print the binary representation of "n" by making recursive calls and printing the rightmost digit each time.
//The outputs then printed in the main function is the decimal number entered followed by its binary representation.
#include <iostream>
using namespace std;

void convert(int n) {
    if (n == 0) {
        return;
    }
    convert(n/2);
    cout << n % 2;
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << n << " in decimal = ";
    convert(n);
    cout << " in binary" << endl;
    return 0;
}

