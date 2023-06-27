//This code takes input of three sides of a traingle from the user and returns it's are which is calculated using Heron's Formula. In symbols, if a, b, and c are the lengths of the sides: Area = Square root of√s(s - a)(s - b)(s - c) where s is half the perimeter, or (a + b + c)/2.


#include <stdio.h>
#include <math.h>

int main()
{
    double s1, s2, s3, area, S;

    // Take input from user
    printf("Enter Three Sides of a Triangle\n");
    scanf("%lf %lf %lf", &s1, &s2, &s3);

    S = (s1 + s2 + s3) / 2;
    area = sqrt(S * (S - s1) * (S - s2) * (S - s3));

    printf("The Area of triangle = %.2f\n", area);
    return 0;
}
