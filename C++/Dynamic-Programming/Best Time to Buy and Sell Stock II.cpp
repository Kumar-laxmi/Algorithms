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

long getAns(vector<int> &Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0; // base case
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    long profit;
    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }
    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return getAns(prices, 0, 0, n, dp);
}

int main()
{

    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << maxProfit(prices);
    return 0;
}