#include <stdio.h>

void factors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    factors(24);
    return 0;
}
