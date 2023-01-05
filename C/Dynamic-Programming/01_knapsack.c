#include <stdio.h>
#include <string.h>
#include <math.h>

// Struct to represent an item
struct Item
{
    int value;
    int weight;
};

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, struct Item items[], int n)
{
    // dp[i][j] will store the maximum value that can be achieved with a capacity of i using the first j items
    int dp[W+1][n+1];

    // initialize all values of dp[][] as 0
    memset(dp, 0, sizeof(dp));

    // iterate through all items
    for (int i = 1; i <= n; i++)
    {
        // consider all capacities from 0 to W
        for (int j = 0; j <= W; j++)
        {
            // if the weight of the current item is more than the current capacity j, 
            //then skip the item
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
                dp[j][i] = fmax(dp[j][i-1], items[i-1].value + dp[j-items[i-1].weight][i-1]);
            }
        }
    }

    // return the maximum value that can be achieved with a capacity of W and using all n items
    return dp[W][n];
}

int main()
{
    struct Item items[] = {{100, 20}, {180, 30}, {260, 10}, {310, 5}, {40, 25}, {535, 15}, {695, 30}, {860, 45}, {920, 50}, {220, 10}};
    int W = 200;
    int n = sizeof(items)/sizeof(items[0]);

    printf("%d\n", knapsack(W, items, n));

    return 0;
}


           
