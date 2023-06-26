#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

template <typename T>
vector<vector<T>> generatePowerSet(vector<T> &originalSet)
{
    int n = originalSet.size();
    int numSubsets = pow(2, n); // Total number of subsets

    vector<vector<T>> powerSet;

    for (int i = 0; i < numSubsets; i++)
    {
        vector<T> subset;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(originalSet[j]);
            }
        }
        powerSet.push_back(subset);
    }

    return powerSet;
}

template <typename T>
void printPowerSet(const vector<vector<T>> &powerSet)
{
    for (const auto &subset : powerSet)
    {
        cout << "{ ";
        for (const auto &element : subset)
        {
            cout << element << " ";
        }
        cout << "}" << endl;
    }
}

template <typename T>
void removeDuplicates(vector<T> &originalSet)
{
    unordered_set<T> uniqueSet(originalSet.begin(), originalSet.end());
    originalSet.assign(uniqueSet.begin(), uniqueSet.end());
}

int main()
{
    int numElements;
    cout << "Enter the number of elements in the original set: ";
    cin >> numElements;

    vector<char> originalSet(numElements);
    cout << "Enter the elements of the original set: ";
    cout << endl;
    for (int i = 0; i < numElements; i++)
    {
        cin >> originalSet[i];
    }

    // Remove duplicates from the original set
    removeDuplicates(originalSet);

    // Generate the power set
    vector<vector<char>> powerSet = generatePowerSet(originalSet);

    // Print the power set
    cout << "Power Set:" << endl;
    printPowerSet(powerSet);

    return 0;
}