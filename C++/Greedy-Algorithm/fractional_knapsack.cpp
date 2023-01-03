
// ====================== Problem Statement ==========================
/*
You are given a set of items, each with a weight and a value. 
You are also given a knapsack with a certain capacity. 
Your goal is to fill the knapsack with items such that the 
total value of the selected items is maximized, but the total 
weight of the selected items must not exceed the capacity of the knapsack. 
You are allowed to take fractional amounts of an item, so you can take an 
item with a weight of 3, for example, and only take 1.5 of its weight.

For example, consider the following set of items:

Item	Value	Weight
1	60	10
2	100	20
3	120	30 
Suppose the capacity of the knapsack is 50. In this case, 
the optimal solution would be to take the items with values 
100 and 60 (for a total value of 160), since these two items have 
the highest value-to-weight ratio and their total weight is less 
than or equal to the capacity of the knapsack.

The greedy approach is often used to solve the Fractional Knapsack problem. 
The idea is to sort the items in descending order of their value-to-weight ratio, 
and then iterate through the items, adding them to the knapsack if they fit, 
or adding a fraction of them if they don't fit.
*/

// // ====================== Code with C++ ==========================
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Item structure to store weight and value of each item
struct Item
{
    int value, weight;

    // Constructor to initialize the values
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort the items in descending order of their value-to-weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    // Sort the items in descending order of their value-to-weight ratio
    sort(items.begin(), items.end(), cmp);

    // Keep track of the current weight and value of the knapsack
    int currentWeight = 0;
    double currentValue = 0.0;

    // Iterate through the items
    for (int i = 0; i < items.size(); i++)
    {
        // If the current item fits in the knapsack, add it completely
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
        }
        // If the current item does not fit in the knapsack, add a fraction of it
        else
        {
            int remainingWeight = W - currentWeight;
            currentValue += items[i].value * ((double) remainingWeight / items[i].weight);
            break;
        }
    }

    // Return the maximum value
    return currentValue;
}

int main()
{
    // Set the capacity of the knapsack
    int W = 50;

    // Set the number of items
    int n = 3;

    vector<Item> items;

    // Add the items to the vector
    items.push_back(Item(60, 10));
    items.push_back(Item(100, 20));
    items.push_back(Item(120, 30));

    // Print the maximum value
    cout << "Maximum value: " << fractionalKnapsack(W, items) << endl;

    return 0;
}
