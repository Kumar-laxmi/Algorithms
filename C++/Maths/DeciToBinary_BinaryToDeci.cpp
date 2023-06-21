//Decimal to Binary Converter and vice-versa in C++
#include <iostream>
#include <cmath>
using namespace std;

//function for decimal to binary converter
string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0"; // Special case for decimal number 0
    }

    string binary = "";
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary = to_string(remainder) + binary; // Append the remainder at the beginning of the string
        decimal /= 2;
    }

    return binary;
}


//function for binary to decimal converter
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        int digit = binary[i] - '0';
        decimal += digit * pow(2, power);
        power++;
    }

    return decimal;
}

int main() {
  //Function for input
    cout << "Please enter 1 for Decimal to Binary converter." << endl;
    cout << "Please enter 2 for Binary to Decimal converter." << endl;
    int c;
    cin >> c;

    switch (c) {
      //when entered 1
        //Decimal to Binary
        case 1: {
            cout << "Enter the Decimal Number: ";
            int decimalNumber;
            cin >> decimalNumber;
            string binaryNumber = decimalToBinary(decimalNumber);
            cout << "Binary representation of " << decimalNumber << " is: " << binaryNumber << endl;
            break;
        }

        //when entered 2
        //Binary to decimal
        case 2: {
            cout << "Enter the Binary Number: ";
            string binary;
            cin >> binary;
            int decimalNumber = binaryToDecimal(binary);
            cout << "Decimal representation of " << binary << " is: " << decimalNumber << endl;
            break;
        }

        //when entered invalid input
        default:
            cout << "You did not enter either 1 or 2." << endl;
    }

    return 0;
}
/*******************************************************
 Case 1:
 Enter the Decimal Number
 42
 Binary representation of 42 is: 101010
 Case 2:
 Enter the Binary Number
 100
 Decimal representation of 100 is: 4
 default:
 You did not enter either 1 or 2.
 *******************************************************/