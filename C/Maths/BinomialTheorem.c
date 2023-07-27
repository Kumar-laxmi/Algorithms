#include <stdio.h>
#include <math.h>

int fact(int n) {
    int factn = 1;
    for (int i = 1; i < n + 1; i++) {
        factn = factn * i;
    }
    return factn;
}

int main() {
    printf("Enter in (1+x)^n the values of x and n respectively\n");
    int x, n;
    scanf("%d %d", &x, &n);
    int nf = fact(n);
    int arr[n + 1];

    for (int i = 0; i <= n; i++) {
        int ncr = nf / (fact(i) * fact(n - i));
        arr[i] = ncr * pow(x, i);
        arr[n - i] = ncr * pow(x, n - i);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

