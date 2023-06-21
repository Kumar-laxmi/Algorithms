#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int low, high;
};

struct Node
{
    Interval interval;
    int max_high;
    Node *left;
    Node *right;
};

Node *newNode(Interval i)
{
    Node *node = new Node;
    node->interval = i;
    node->max_high = i.high;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *insert(Node *root, Interval i)
{
    if (root == nullptr)
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

bool overlap(Interval i1, Interval i2)
{
    return (i1.low <= i2.high && i2.low <= i1.high);
}

Interval *search(Node *root, Interval i)
{
    if (root == nullptr)
        return nullptr;

    if (overlap(root->interval, i))
        return &(root->interval);

    if (root->left != nullptr && root->left->max_high >= i.low)
        return search(root->left, i);

    return search(root->right, i);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << "[" << root->interval.low << ", " << root->interval.high << "] max = " << root->max_high << endl;
    inorder(root->right);
}

int main()
{
    vector<Interval> intervals = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};

    Node *root = nullptr;
    for (const auto &interval : intervals)
        root = insert(root, interval);

    cout << "Inorder traversal of constructed Interval Tree is" << endl;
    inorder(root);

    Interval searchInterval = {6, 7};
    cout << endl
         << "Searching for interval [" << searchInterval.low << ", " << searchInterval.high << "]" << endl;
    Interval *result = search(root, searchInterval);
    if (result != nullptr)
        cout << "Overlaps with [" << result->low << ", " << result->high << "]" << endl;

    return 0;
}
