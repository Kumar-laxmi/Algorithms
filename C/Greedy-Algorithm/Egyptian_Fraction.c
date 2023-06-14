/* C program to print a fraction in Egyptian Form using Greedy Algorithm*/

#include <stdio.h>

void egyptianFraction(int n, int d)
{
    // When Both Numerator and denominator becomes zero then we simply return;
    if (d == 0 || n == 0)
        return;
    if (d % n == 0)
    {
        printf("1/%d", d / n);
        return;
    }
    if (n % d == 0)
    {
        printf("%d", n / d);
        return;
    }
    if (n > d)
    {
        printf("%d + ", n / d);
        egyptianFraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    printf("1/%d + ", x);
    egyptianFraction(n * x - d, d * x);
}

int main()
{
    int numerator, denominator;
    printf("Enter Numerator: ");
    scanf("%d", &numerator);
    printf("Enter Denominator:");
    scanf("%d", &denominator);
    printf("Egyptian Fraction representation of %d/%d is\n", numerator, denominator);
    egyptianFraction(numerator, denominator);
    return 0;
}