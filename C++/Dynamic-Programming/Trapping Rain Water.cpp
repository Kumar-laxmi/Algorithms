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
int trap(vector<int> &h)

{
    if (!h.size())
        return 0;
    int i = 0, j = h.size() - 1, maxLeft = h[i], maxRight = h[j], res = 0, e;
    while (i <= j)
    {
        if (h[i] > h[j])
        {
            e = h[j];
            if (e > maxRight)
                maxRight = e;
            else
                res += maxRight - e;
            j--;
        }
        else
        {
            e = h[i];
            if (e > maxLeft)
                maxLeft = e;
            else
                res += maxLeft - e;
            i++;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        cout << trap(v);
    }
    return 0;
}