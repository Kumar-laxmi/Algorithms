// =================================== Problem Statement ====================================
/*
Task: Range Queries and Updates in an Array using Segement Tree

Sol: The problem is to implement a data structure for efficient range queries for operations like sum, minimum and maximum value and updates on an array.We will explore three methods to solve this problem: Brute Force, Prefix Sum, and Segment Tree.

Method 1) Brute Force

Algorithm:
    Querying:
        - For each query, iterate over the given range [l, r] and compute the sum, minimum, or maximum value.
        - Time Complexity: O(r - l + 1) per query.
        - For q querying operations: O((r - l + 1) * q)

    Updating:
        - To update a specific element, modify the array directly.
        - Time Complexity: O(1) per update operation.
        - For u update operations: O(u)

Method 2) Optimised Approach

Algorithm:
    Querying:
        - Compute the prefix sum array, where prefixSum[i] represents the sum of elements from index 0 to i.
        - To find the sum within a given range [l, r], compute prefixSum[r] - prefixSum[l-1].
        - To find the minimum and maximum values within the range, utilize a 2D matrix, minMaxMatrix, of size n x log n.
        - For each element minMaxMatrix[i][j], store the minimum and maximum values of the range [i, i + 2^j - 1].
        - To find the minimum and maximum values within the range [l, r], calculate the minimum and maximum of the two overlapping ranges [l, l + length - 1] and [r - length + 1, r], where length = floor(log2(r - l + 1)).
        - Time Complexity: O(1) per query.
        - For q querying operations: O(q)

    Updating:
        - Updating a specific element requires recomputing the prefix sum array and updating the corresponding element in the minMaxMatrix.
        - To update the prefix sum array, the difference between the new value and the old value at the specific index needs to be added to all subsequent prefix sum values.
        - To update the minMaxMatrix, the minimum and maximum values for the affected range need to be recomputed.
        - Time Complexity: O(log n) per update operation.
        - For u update operations: O((log n) * u)

Method 3) Segment Tree

Algorithm:
    - Segment Tree is a binary tree data structure used to efficiently perform range queries and updates.
    - Each node in the segment tree represents a range of indices in the array.
    - The root of the tree represents the entire array, and each leaf node represents a single element.
    - The values in the intermediate nodes represent the result of applying the query operation to the respective range.

    Construction:
        - To build the segment tree from the input array, the array is divided recursively into smaller segments until each segment contains a single element.
        - The values in the leaf nodes are initialized with the corresponding array elements.
        - The values in the intermediate nodes are computed based on the values in their child nodes.
        - Time Complexity: O(n) for construction.

    Querying:
        - To query the sum, minimum, maximum, or any other operation within a given range [l, r], traverse the segment tree starting from the root.
        - At each node, check if the current range overlaps with the target range. If yes, apply the query operation.
        - If the current range is completely within the target range, return the value stored in that node.
        - If the current range does not overlap with the target range, return an appropriate default value.
        - Time Complexity: O(log n) per query.
        - For q querying operations: O((log n) * q)

    Updating:
        - To update a specific element in the array, propagate the changes through the segment tree.
        - Starting from the root, traverse the tree and update the nodes whose ranges include the target index.
        - Recompute the values in the intermediate nodes based on the updated child nodes.
        - Time Complexity: O(log n) per update operation.
        - For u update operations: O((log n) * u)

Conclusion:
    - The Brute Force method is straightforward to implement but can be inefficient for large input sizes.
    - The Prefix Sum method improves the querying efficiency but has a higher time complexity for update operations.
    - The Segment Tree method offers efficient querying and updating, making it suitable for scenarios with a large number of queries and updates.
    - However, the Segment Tree method requires more initial setup and additional space compared to the other methods and to be used when freuent updates are to be made otherwise method 2 is more efficient.

    We have chosen to implement the Segment Tree approach exclusively for (range sum operation) this problem since it offers the highest efficiency, especially when dealing with a large number of queries. The Segment Tree has been widely recognized as the most suitable data structure for range queries and updates on arrays, providing optimal time complexity for these operations.
*/
// ===================================== Code with C ========================================
#include <stdio.h>
#include <stdlib.h>

// Function to build the Segment Tree
void buildSegmentTree(const int *arr, int *tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildSegmentTree(arr, tree, 2 * node, start, mid);
    buildSegmentTree(arr, tree, 2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Function to perform a range query on the Segment Tree
int rangeQuery(const int *tree, int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
        return 0;

    if (left <= start && right >= end)
        return tree[node];

    int mid = (start + end) / 2;
    int leftSum = rangeQuery(tree, 2 * node, start, mid, left, right);
    int rightSum = rangeQuery(tree, 2 * node + 1, mid + 1, end, left, right);

    return leftSum + rightSum;
}

// Function to update an element in the Segment Tree
void updateElement(int *tree, int node, int start, int end, int index, int value)
{
    if (start == end)
    {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    if (index >= start && index <= mid)
        updateElement(tree, 2 * node, start, mid, index, value);
    else
        updateElement(tree, 2 * node + 1, mid + 1, end, index, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int treeSize = 4 * (n + 1);
    int *tree = (int *)malloc(treeSize * sizeof(int));

    buildSegmentTree(arr, tree, 1, 1, n);

    int choice;
    do
    {
        printf("Segment Tree Operations:\n");
        printf("1. Range Query\n");
        printf("2. Update Element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int left, right;
            printf("Enter the range [left, right]: ");
            scanf("%d %d", &left, &right);

            if (left < 1 || left > n || right < 1 || right > n || left > right)
            {
                printf("Invalid range! Please try again.\n");
                break;
            }

            int sum = rangeQuery(tree, 1, 1, n, left, right);
            printf("Sum of the elements in the range [%d, %d] is: %d\n", left, right, sum);
            break;
        }
        case 2:
        {
            int index, value;
            printf("Enter the index and value: ");
            scanf("%d %d", &index, &value);

            if (index < 1 || index > n)
            {
                printf("Invalid index! Please try again.\n");
                break;
            }

            updateElement(tree, 1, 1, n, index, value);
            printf("Updated the element at index %d to %d\n", index, value);
            break;
        }
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }

    } while (choice != 3);

    free(arr);
    free(tree);

    return 0;
}