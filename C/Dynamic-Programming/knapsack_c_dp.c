#include <stdio.h>
#include <string.h>

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n)
{
    // table[i] will store the maximum value that can be achieved with a capacity of i
    int table[W+1];

    // initialize all values of table[] as 0
    memset(table, 0, sizeof(table));

    // iterate through all items
    for (int i = 0; i < n; i++)
    {
        // consider all capacities from 0 to W
        for (int j = 0; j <= W; j++)
        {
            // if the weight of the item is more than the current capacity j, then skip the item
            if (wt[i] > j)
                continue;

            // table[j] is the maximum value that can be achieved with a capacity of j
            // val[i] is the value of the current item
            // table[j-wt[i]] is the maximum value that can be achieved with a capacity of j-wt[i]
            // (which will be filled by the next iteration)
            table[j] = table[j] > val[i] + table[j-wt[i]] ? table[j] : val[i] + table[j-wt[i]];
        }
    }

    // return the maximum value that can be achieved with a capacity of W
    return table[W];
}

int main()
{
    int val[] = {100, 180, 260, 310, 40, 535, 695, 860, 920, 220};
    int wt[] = {20, 30, 10, 5, 25, 15, 30, 45, 50, 10};
    int W = 200;
    int n = sizeof(val)/sizeof(val[0]);

    printf("%d\n", knapsack(W, wt, val, n));

    return 0;
}
