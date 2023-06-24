#include <iostream>

// Function to perform Russian Peasant multiplication
int russianPeasantMultiply(int a, int b) {
    int result = 0;

    // Keep halving 'a' and doubling 'b' until 'a' becomes 1
    while (a > 0) {
        if (a % 2 == 1) {
            result += b;
        }

        a = a / 2;
        b = b * 2;
    }

    return result;
}

// Main function
int main() {
    int a, b;

    std::cout << "Enter two numbers to multiply: ";
    std::cin >> a >> b;

    int product = russianPeasantMultiply(a, b);

    std::cout << "Product: " << product << std::endl;

    return 0;
}
