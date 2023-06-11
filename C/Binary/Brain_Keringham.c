#include <stdio.h>

//Brian Kerningham's Algorithm in C
int setBits(int n)
{
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    printf("%d",setBits(15));
    return 0;
}