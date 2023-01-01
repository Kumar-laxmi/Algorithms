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
            table[j] = max(table[j], val[i] + table[j-wt[i]]);
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

    cout << knapsack(W, wt, val, n);

    return 0;
}
