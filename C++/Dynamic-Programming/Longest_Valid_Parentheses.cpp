//  Question : Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring

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

int longestValidParentheses(string s)
{

    int n = s.length(), longest = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty())
            {
                if (s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
            else
                st.push(i);
        }
    }
    if (st.empty())
        longest = n;
    else
    {
        int a = n, b = 0;
        while (!st.empty())
        {
            b = st.top();
            st.pop();
            longest = max(longest, a - b - 1);
            a = b;
        }
        longest = max(longest, a);
    }
    return longest;
}
int main()
{

    string str;
    cin >> str;
    cout << longestValidParentheses(str);
    return 0;
}