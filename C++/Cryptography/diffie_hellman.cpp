#include <iostream>
#include <cmath>

using namespace std;

long long int power(long long int a, long long int b, long long int p)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % p);
}

int main() {
    long long int p, g, a, b, A, B, sA, sB;
    cout << "Enter the value of p: ";
    cin >> p;
    cout << "Enter the value of g: ";
    cin >> g;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    A = power(g, a, p);
    B = power(g, b, p);
    sA = power(B, a, p);
    sB = power(A, b, p);
    cout << "Private key for A is : " << A << endl;
    cout << "Public shared key for A is : " << sA << endl;
    cout << "Private Key for B is : " << B << endl;
    cout << "Public shared Key for B is : " << sB << endl;	
    return 0;
}
