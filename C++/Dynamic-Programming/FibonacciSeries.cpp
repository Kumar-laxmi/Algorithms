#include <iostream>
#include <map>
using namespace std;
int fib(int n, map<int, int> &dp)
{
    int f1 = -1, f2 = -1;
label:
    if (n == 2)
    {
        cout << (n - 2) << " " << (n - 1) << " ";
        dp[n - 2] = (n - 2);
        dp[n - 1] = (n - 1);
        return (n - 1);
    }
    if (n == 1)
    {
        cout << (n - 1) << " ";
        dp[n - 1] = (n - 1);
        return (n - 1);
    }
    if (dp.find(n - 2) != dp.end())
    {
        f1 = (dp.find(n - 2))->second;
    }
    if (dp.find(n - 3) != dp.end())
    {
        f2 = (dp.find(n - 3))->second;
    }
    if (f1 == -1)
    {
        f1 = fib(n - 1, dp);
        dp[n - 2] = f1;
        goto label;
    }
    cout << (f1 + f2) << " ";
    return (f1 + f2);
}
int main()
{
    int n;
    cout << "Enter a Number : ";
    cin >> n;
    map<int, int> dp;
    fib(n, dp);
    return 0;
}