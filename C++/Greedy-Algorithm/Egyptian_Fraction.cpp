/* C++ program to print a fraction in Egyptian Form using Greedy Algorithm*/
#include <bits/stdc++.h>
using namespace std;
void egyptian_Fraction(int n, int d)
{
    // When Both Numerator and denominator becomes zero then we simply return;
    if (d == 0 || n == 0)
        return;
    if (d % n == 0)
    {
        cout << "1/" << d / n;
        return;
    }
    if (n % d == 0)
    {
        cout << n / d;
        return;
    }
    if (n > d)
    {
        cout << n / d << " + ";
        egyptian_Fraction(n % d, d);
        return;
    }
    int x = d / n + 1;
    cout << "1/" << x << " + ";
    egyptian_Fraction(n * x - d, d * x);
}
int main()
{
    int num, den;
    cout << "Enter Numerator:";
    cin >> num;
    cout << "\nEnter Denominator:";
    cin >> den;
    cout << "Egyptian Fraction : " << num << "/" << den << " is" << endl;
    egyptian_Fraction(num, den);
    return 0;
}
