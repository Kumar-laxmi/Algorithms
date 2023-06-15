// Luhn Algorithm
// The Luhn algorithm, also known as the mod 10 algorithm, is a simple checksum formula used to validate various identification numbers,
//  such as credit card numbers, IMEI numbers etc. It is mostly used as a simple method to distinguish valid numbers from mistyped or 
// otherwise incorrect numbers. 


// Approach and Explanation

// 1. Start from the rightmost digit (excluding any check digit), double the value of every second digit. 

// 2. If doubling of a number results in a two digit number , greater than 9 then add the digits of the product.

// 3. Sum up all the digits, including the modified ones from the previous step, and calculate the total.

// 4. If the total is divisible by 10 (i.e., the modulo 10 operation results in 0), the number is considered valid according to the Luhn algorithm.

// Time Complexity->	O(n)
// Space Complexity->	O(1)

// Implementation
#include <iostream>
using namespace std;
// function to check validity of a number
bool luhnAlgorithm(string number) {
    int n = number.length();
    int sum = 0;
    bool isSecondDigit = false;

    // Traverse the number from right to left
    for (int i = n - 1; i >= 0; i--) {
        int digit = number[i] - '0';

        // Double every second digit, starting from the rightmost
        if (isSecondDigit) {
            digit *= 2;
        }

        // Adding the 2 digit to sum if the digits produced is double digit
        sum += digit / 10; // If the no. is <9 then this step will produce 0
        sum += digit % 10;

        // Toggle the flag for the next iteration
        isSecondDigit = !isSecondDigit;
    }

    // If the sum is divisible by 10, the number is valid
    return (sum % 10 == 0);
}

int main() {
    string number;

    // Read the number as a string
    cout << "Enter the number: ";
    cin >> number;

    // Check if the number is valid using the Luhn algorithm
    if (luhnAlgorithm(number)) {
        cout << "Valid number." << endl;
    } else {
        cout << "Invalid number." << endl;
    }

    return 0;
}
