#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846264338327

void fft(double complex* x, int n) {
    if (n <= 1) {
        return;
    }

    double complex even[n / 2];
    double complex odd[n / 2];

    for (int i = 0; i < n / 2; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    fft(even, n / 2);
    fft(odd, n / 2);

    for (int k = 0; k < n / 2; k++) {
        double complex t = cexp(-2 * PI * I * k / n) * odd[k];
        x[k] = even[k] + t;
        x[k + n / 2] = even[k] - t;
    }
}

int main() {
    // Input sequence
    double complex x[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(x) / sizeof(x[0]);

    // Compute FFT
    fft(x, n);

    // Print the results
    printf("FFT: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f + %.2fi ", creal(x[i]), cimag(x[i]));
    }
    printf("\n");

    return 0;
}
