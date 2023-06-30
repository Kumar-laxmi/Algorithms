#include <stdio.h>
#define SIZE 10

//function to get the sum of all elements in the given range
int getSum(int BITree[], int index) {
    int sum = 0;
    index = index + 1;  // convert 0-based index to 1-based index by adding 1

    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);  // move index to the parent node
    }
    return sum;
}

// function to update the Fenwick tree
void updateBIT(int BITree[], int index, int value, int n) {
    index = index + 1;  // Convert 0-based index to 1-based index

    while (index <= n) {
        BITree[index] += value;
        index += index & (-index);  // Move index to the next node
    }
}

// Building the Fenwick tree
void constructBIT(int arr[], int BITree[], int n) {
    for (int i = 0; i < n; i++)
        BITree[i] = 0;

    for (int i = 0; i < n; i++)
        updateBIT(BITree, i, arr[i], n);
}

// Test the Fenwick tree implementation
int main() {
    int arr[SIZE] = {2, 7, -4, 6, 9, 8, -3, 3, 3, 5};
    int BITree[SIZE + 1];

    constructBIT(arr, BITree, SIZE);

    // to get the sum of elements in the range [0, 6]
    int sum = getSum(BITree, 6);
    printf("Sum of elements in range [0, 6]: %d\n", sum);

    // update the value at index 2 to 10
    int index = 2;
    int value = 10;
    int diff = value - arr[index];
    arr[index] = value;
    updateBIT(BITree, index, diff, SIZE);

    // to get the sum of elements in the range [0, 6] after the update
    sum = getSum(BITree, 6);
    printf("Sum of elements in range [0, 6] after update: %d\n", sum);

    return 0;
}
