#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure representing an item with weight and value
struct Item {
    int weight;
    int value;

    Item(int weight, int value) : weight(weight), value(value) {}
};

// Functor to compare items based on their value-to-weight ratio
struct KnapsackComparator {
    bool operator()(const Item& item1, const Item& item2) const {
        // Calculate the value-to-weight ratio for each item
        double ratio1 = static_cast<double>(item1.value) / item1.weight;
        double ratio2 = static_cast<double>(item2.value) / item2.weight;

        // Compare the ratios to determine the order
        if (ratio1 < ratio2) {
            return true;
        }
        return false;
    }
};

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort the items based on their value-to-weight ratio using the KnapsackComparator
    sort(items.begin(), items.end(), KnapsackComparator());

    double totalValue = 0;
    int remainingCapacity = capacity;

    // Iterate through the sorted items
    for (const Item& item : items) {
        // If the item can be fully included
        if (item.weight <= remainingCapacity) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else { // If the item can only be partially included
            // Calculate the fraction of the item that can be included
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += item.value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    for (int i = 0; i < numItems; ++i) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    
}


/*
example output: 
Enter the number of items: 4
Enter weight and value for item 1: 2 10
Enter weight and value for item 2: 3 15
Enter weight and value for item 3: 5 20
Enter weight and value for item 4: 1 5
Enter the knapsack capacity: 7
The maximum value that can be obtained is: 30.7143

*/

