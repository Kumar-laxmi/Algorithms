#include <iostream>
#include <cmath>

int fact(int n) {
    int factn = 1;
    for (int i = 1; i < n + 1; i++) {
        factn = factn * i;
    }
    return factn;
}

int main() {
    std::cout << "Enter in (1+x)^n the values of x and n respectively" << std::endl;
    int x, n;
    std::cin >> x >> n;
    int nf = fact(n);
    int arr[n + 1];

    for (int i = 0; i <= n; i++) {
        int ncr = nf / (fact(i) * fact(n - i));
        arr[i] = ncr * pow(x, i);
        arr[n - i] = ncr * pow(x, n - i);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
