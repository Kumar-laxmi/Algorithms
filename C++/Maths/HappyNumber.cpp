#include <iostream>
#include <unordered_set>

bool isHappy(int n) {
    std::unordered_set<int> seen;

    while (n != 1) {
        int current = n;
        int sum_of_squares = 0;

        while (current != 0) {
            int digit = current % 10;
            sum_of_squares += digit * digit;
            current /= 10;
        }

        if (seen.count(sum_of_squares)) {
            return false; // Entered a cycle containing 4, so it's an unhappy number
        }

        seen.insert(sum_of_squares);
        n = sum_of_squares;
    }

    return true; // Reached 1, so it's a happy number
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    bool isHappyNumber = isHappy(number);
    std::cout << number << " is a happy number: " << (isHappyNumber ? "true" : "false") << std::endl;
    return 0;
}
