#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int gen_key(int q) {
    int key = rand() % q + pow(10, 20);
    while (gcd(q, key) != 1) {
        key = rand() % q + pow(10, 20);
    }
    return key;
}

int power(int a, int b, int c) {
    int x = 1;
    int y = a;
    while (b > 0) {
        if (b % 2 != 0) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b = b / 2;
    }
    return x % c;
}

void encrypt(char* msg, int q, int h, int g, int* en_msg, int size) {
    int k = gen_key(q);
    int s = power(h, k, q);
    int p = power(g, k, q);

    printf("g^k used: %d\n", p);
    printf("g^ak used: %d\n", s);

    for (int i = 0; i < size; i++) {
        en_msg[i] = s * msg[i];
    }
}

void decrypt(int* en_msg, int p, int key, int q, char* dr_msg, int size) {
    int h = power(p, key, q);
    for (int i = 0; i < size; i++) {
        dr_msg[i] = en_msg[i] / h;
    }
}

int main() {
    srand(time(0));
    char msg[100];
    printf("Enter the message: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Original Message: %s\n", msg);
    int q = rand() % (int) pow(10, 50) + pow(10, 20);
    int g = rand() % (q - 2) + 2;
    int key = gen_key(q);
    int h = power(g, key, q);
    printf("g used: %d\n", g);
    printf("g^a used: %d\n", h);
    int size = sizeof(msg) / sizeof(msg[0]);
    int en_msg[size];
    encrypt(msg, q, h, g, en_msg, size);
    char dr_msg[size];
    decrypt(en_msg, en_msg[0], key, q, dr_msg, size);
    printf("Decrypted Message: %s\n", dr_msg);
    return 0;
}
