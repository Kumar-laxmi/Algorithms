// convert decimal to binary

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

