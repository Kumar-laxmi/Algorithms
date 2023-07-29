#include <iostream>
using namespace std;
// Function to multiply two numbers using Russian Peasant method
int russianPeasant(int a, int b) {
    // initialize result
    int res = 0;

    // While second number doesn't become 1
    while (b > 0) {
        // If second number becomes odd,
        // add the first number to result
        if ((b & 1) != 0)
            res = res + a;

        // Double the first number and halve the second number
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
// Driver program
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << russianPeasant(a, b) << endl;
    return 0;
}
