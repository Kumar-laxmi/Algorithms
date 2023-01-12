// convert binary to decimal
//Approach 
//    This code is a simple program that converts a binary (base 2) number to decimal (base 10) representation.
//
//    The main function of the code is the "convert" function, which takes a long long integer "n" as its input (representing the binary number). 
//    The function first initializes a variable "dec" to store the decimal representation of the binary number, and two more variables "i" and "rem".
//
//    Then the function enters a while loop that iterates as long as the input number is not 0. 
//    In each iteration, it takes the remainder of the input number divided by 10 (using the modulo operator %), and assigns it to the "rem" variable. 
//    It then divides the input number by 10 (using the division operator /=) to discard the rightmost digit. 
//    Then the function add rem * pow(2, i) where i is incremented each time to the dec variable.
//
//    At the end of the loop, the function returns the decimal representation of the binary number.
//
//    The main function prompts the user to enter a binary number and reads the input,
//    then calls the "convert" function, passing in the input binary number as the argument,
//    and finally print the binary number followed by its decimal representation.

#include <iostream>
#include <cmath>

using namespace std;

int convert(long long);

int main() {
  long long n;
  cout << "Enter a binary number: ";
  cin >> n;
  cout << n << " in binary = " << convert(n) << " in decimal";
  return 0;
}

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
