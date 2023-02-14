#include <iostream>
#include <algorithm>
#include<cstring>

using namespace std;

// ========================== Problem Statement ===========================

/*
You are given a set of items, each with a weight and a value. 
You are also given a knapsack with a certain capacity. Your goal 
is to maximize the total value of items that you can put in the 
knapsack, subject to the constraint that the total weight of the 
items must not exceed the capacity of the knapsack.

For example, suppose you have the following set of items:

Item	Value	Weight
1	100	20
2	180	30
3	260	10
4	310	5
5	40	25
6	535	15
7	695	30
8	860	45
9	920	50
10	220	10
The capacity of the knapsack is 200. Your goal is to choose a subset 
of these items such that the total value is maximized, and the total 
weight is less than or equal to 200.

The 0/1 in the name refers to the fact that each item must either be 
included or excluded (as opposed to a fractional knapsack problem, 
where you can include a fraction of an item).
*/

//===========================C++ Implementation================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Struct to represent an item
struct Item
{
    int value;
    int weight;
};

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<Item> items)
{
    int n = items.size();

    // dp[i][j] will store the maximum value that can be achieved with a capacity of i using the first j items
    vector<vector<int>> dp(W+1, vector<int>(n+1));

    // iterate through all items
    for (int i = 1; i <= n; i++)
    {
        // consider all capacities from 0 to W
        for (int j = 0; j <= W; j++)
        {
            // if the weight of the current item is more than the current capacity j, then skip the item
            if (items[i-1].weight > j)
            {
                // copy the value from the previous iteration (i.e., the item is not included)
                dp[j][i] = dp[j][i-1];
            }
            else
            {
                // dp[j][i-1] is the maximum value that can be achieved with a capacity of j using the first i-1 items
                // items[i-1].value is the value of the current item
                // dp[j-items[i-1].weight][i-1] is the maximum value that can be achieved with a capacity of j-items[i-1].weight using the first i-1 items
                dp[j][i] = max(dp[j][i-1], items[i-1].value + dp[j-items[i-1].weight][i-1]);
            }
        }
    }

    // return the maximum value that can be achieved with a capacity of W and using all n items
    return dp[W][n];
}

int main()
{
    vector<Item> items = {{100, 20}, {180, 30}, {260, 10}, {310, 5}, {40, 25}, {535, 15}, {695, 30}, {860, 45}, {920, 50}, {220, 10}};
    int W = 200;

    cout << knapsack(W, items);

    return 0;
}
