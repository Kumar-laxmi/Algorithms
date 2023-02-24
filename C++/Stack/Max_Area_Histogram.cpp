/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
//Problem Statement : To determine the largest area in a given histogram.
// C++ program to find largest rectangle area in histogram using stack
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
int MaxArea(vector<int> &heights) // The main function to find the maximum rectangular
// area under given histogram with n bars
{
    int x = heights.size();     // Create an empty stack. The stack holds indexes
     // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    vector<int> nsl(x), psl(x);
    stack<int> s;
    for (int i = x - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])   // Initialize max area
        {
            s.pop();
        }
        nsl[i] = s.empty() ? x : s.top();         // To store area with top bar  as the smallest bar
        s.push(i);
    }
    while (!s.empty())        // If this bar is higher than the bar on top
        // stack, push it to stack
    {
        s.pop();
    }
    for (int i = 0; i < x; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])         // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        {
            s.pop();
        }
        psl[i] = s.empty() ? -1 : s.top();
        s.push(i);                                // store the top index
    }
    int ans = INT_MIN;
    for (int i = 0; i < x; i++)
    {
        ans = max(ans, (nsl[i] - psl[i] - 1) * (heights[i]));   // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    }
    return ans;
}
int main()   // Main Function
{
    vector<int> h;   //Function Call
    h.push_back(5);
    h.push_back(4);
    h.push_back(1);
    h.push_back(6);
    h.push_back(3);
    h.push_back(2);
    h.push_back(2);
    cout << MaxArea(h) << endl;
    return 0;
}