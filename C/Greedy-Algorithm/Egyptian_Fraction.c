/* C program to print a fraction in Egyptian Form using Greedy Algorithm*/

#include <stdio.h>

void egyptian_Fraction(int n, int d)
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
        egyptian_Fraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    printf("1/%d + ", x);
    egyptian_Fraction(n * x - d, d * x);
}

int main()
{
    int num, den;
    printf("Enter Numerator: ");
    scanf("%d", &num);
    printf("Enter Denominator:");
    scanf("%d", &den);
    printf("Egyptian Fraction representation of %d/%d is\n", num, den);
    egyptian_Fraction(num, den);
    return 0;
}