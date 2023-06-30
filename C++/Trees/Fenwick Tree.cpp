#include <vector>
#include <iostream>
using namespace std;

// Fenwick tree class
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) {
        tree.resize(size + 1, 0);
    }

    // it updates the value at index with a given toAdd
    void next(int index, int toAdd) {
        while (index < tree.size()) {
            tree[index] += toAdd;
            index += index & (-index);
        }
    }

    // it returns the prefix sum up to a given index
    int getPrefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    // it returns the sum in a given range [left, right]
    int getRangeSum(int left, int right) {
        return getPrefixSum(right) - getPrefixSum(left - 1);
    }
};

int main() {
    vector<int> values = {2, 7, -4, 6, 9, 8, -3, 3, 3, 5};
    int n = values.size();

    FenwickTree fenwickTree(n);

    // building the Fenwick tree
    for (int i = 0; i < n; i++) {
        fenwickTree.next(i + 1, values[i]);
    }

    // to get prefix sum at index 4
    int prefixSum = fenwickTree.getPrefixSum(4);
    cout << "Prefix Sum at index 5: " << prefixSum << endl;

    // to get range sum from index 1 to 5
    int rangeSum = fenwickTree.getRangeSum(1, 5);
    cout << "Range Sum from index 2 to 6: " << rangeSum << endl;

    return 0;
}
