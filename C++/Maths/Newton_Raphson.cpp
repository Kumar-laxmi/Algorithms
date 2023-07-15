// C++ program for implementation of Newton Raphson Method for Solving Equations

#include <iostream>
#include <bits/stdc++.h>
#define EPSILON 0.001
using namespace std;

// Bisection Method.
// We are taking a function whose roots we want to find.
// The function is x^3 - x^2  + 2
double func(double x)
{
    return x * x * x - x * x + 2;
}

// Derivative of the above function which is 3*x*x - 2*x
double derivFunc(double x)
{
    return 3 * x * x - 2 * x;
}

// Function to find the root
// Its an Iterative method thats why this while loop is used.
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x) / derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;
    }

    cout << "The value of the root is : " << x;
}

// Main Function / Main code to implement above function
int main()
{
    double x0;
    cout << "Enter Initial Guess:" << endl;
    cin >> x0; // Enter Initial Guess here
    newtonRaphson(x0);
    return 0;
}
