#include <iostream>
#include <complex>
#include <cmath>

#define PI 3.14159265358979323846264338327

typedef std::complex<double> Complex;

void fft(Complex* x, int n) {
    if (n <= 1) {
        return;
    }

    Complex even[n / 2];
    Complex odd[n / 2];

    for (int i = 0; i < n / 2; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    fft(even, n / 2);
    fft(odd, n / 2);

    for (int k = 0; k < n / 2; k++) {
        Complex t = std::polar(1.0, -2 * PI * k / n) * odd[k];
        x[k] = even[k] + t;
        x[k + n / 2] = even[k] - t;
    }
}

int main() {
    // Input sequence
    Complex x[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(x) / sizeof(x[0]);

    // Compute FFT
    fft(x, n);

    // Print the results
    std::cout << "FFT: ";
    for (int i = 0; i < n; i++) {
        std::cout << std::real(x[i]) << " + " << std::imag(x[i]) << "i ";
        std::cout << "\n";
    }
    std::cout << std::endl;

    return 0;
}
