#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int low, high;
};

struct Node {
    struct Interval interval;
    int max_high;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(struct Interval i) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->interval = i;
    node->max_high = i.high;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, struct Interval i) {
    if (root == NULL)
        return newNode(i);

    int low = root->interval.low;

    if (i.low < low)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    if (root->max_high < i.high)
        root->max_high = i.high;

    return root;
}

int overlap(struct Interval i1, struct Interval i2) {
    return (i1.low <= i2.high && i2.low <= i1.high);
}

struct Interval* search(struct Node* root, struct Interval i) {
    if (root == NULL)
        return NULL;

    if (overlap(root->interval, i))
        return &(root->interval);

    if (root->left != NULL && root->left->max_high >= i.low)
        return search(root->left, i);

    return search(root->right, i);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("[%d, %d] max = %d\n", root->interval.low, root->interval.high, root->max_high);
    inorder(root->right);
}

int main() {
    struct Interval intervals[] = { {15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40} };
    int numIntervals = sizeof(intervals) / sizeof(intervals[0]);

    struct Node* root = NULL;
    for (int i = 0; i < numIntervals; i++)
        root = insert(root, intervals[i]);

    printf("Inorder traversal of constructed Interval Tree is:\n");
    inorder(root);

    struct Interval searchInterval = {6, 7};
    printf("\nSearching for interval [%d, %d]\n", searchInterval.low, searchInterval.high);
    struct Interval* result = search(root, searchInterval);
    if (result != NULL)
        printf("Overlaps with [%d, %d]\n", result->low, result->high);

    return 0;
}
