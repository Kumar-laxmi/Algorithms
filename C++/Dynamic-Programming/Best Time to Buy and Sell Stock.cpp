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

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int maxi = 0;

    if (prices.size() == 1)
    {
        return 0;
    }

    for (int i = 1; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxProfit(v);
    return 0;
}