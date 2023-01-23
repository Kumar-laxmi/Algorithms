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
vector<vector<int>> generate(int num)
{
    vector<vector<int>> ans;
    for (int i = 0; i < num; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                temp.push_back(1);
            else
                temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        ans.push_back(temp);
    }

    return ans;
}
int main()
{
    int num;
    cin >> num;
    vector<vector<int>> ans = generate(num);
    return 0;
}