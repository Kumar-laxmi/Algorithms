#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v) {
        valuePerWeight = static_cast<double>(value) / weight;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items;

    for (int i = 0; i < numItems; ++i) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

  
}

/*
Enter the capacity of the knapsack: [user enters capacity]
Enter the number of items: [user enters number of items]
Enter weight and value for item 1: [user enters weight and value for item 1]
Enter weight and value for item 2: [user enters weight and value for item 2]
...
Enter weight and value for item n: [user enters weight and value for item n]
Maximum value that can be obtained: [output: maximum value that can be obtained]
*/

