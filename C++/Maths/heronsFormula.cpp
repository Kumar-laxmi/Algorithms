//This code takes input of three sides of a traingle from the user and returns it's are which is calculated using Heron's Formula. In symbols, if a, b, and c are the lengths of the sides: Area = Square root of√s(s - a)(s - b)(s - c) where s is half the perimeter, or (a + b + c)/2.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double s1, s2, s3, area, S;
    cout << "Enter Three Sides of a Triangle" << endl;
    cin >> s1 >> s2 >> s3;

    S = (s1 + s2 + s3) / 2;
    area = sqrt(S * (S - s1) * (S - s2) * (S - s3));

    cout << "The Area of triangle = " << area << endl;
}
