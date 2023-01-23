#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007ll // 998244353ll
#define mii map<int, int>
#define pii pair<int, int>
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}
using namespace std;

int f(vector<vector<int>> &temp, int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }

    if (temp[m][n] != -1)
        return temp[m][n];

    int left = f(temp, m - 1, n);
    int up = f(temp, m, n - 1);

    return temp[m][n] = left + up;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> temp(m, vector<int>(n, -1));
    int total = f(temp, m - 1, n - 1);
    return total;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);

    return 0;
}
