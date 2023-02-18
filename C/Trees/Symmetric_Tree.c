/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
Problem Description:
Given a binary tree, check whether it is a mirror of itself.
Examples:
1] INPUT:
1
/
2 2
/ \ /
3 4 4 3
OUTPUT: Symmetric
2] INPUT:
1
/
2 2
\
3 3
OUTPUT: Not symmetric */
// C program to check if a given Binary Tree is symmetric or not
#include <stdio.h>
#include <stdlib.h>
// Construct a Binary Tree Node
struct Node 
{
    int key;
    struct Node* left, *right;
};
// function to create a new Node
struct Node* newNode(int key)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
// Returns true if trees with roots as childL and childR are mirror image of each other
int isSymmetric(struct Node* root1, struct Node* root2)
{
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return 1;
    // For two trees to be mirror images, the following 3 conditions must be true
    // a) Their root node's key must be same
    // b) left subtree of left tree and right subtree of right tree have to be mirror images
    // c) right subtree of left tree and left subtree of right tree have to be mirror images
    if (root1 && root2 && root1->key == root2->key)
        return isSymmetric(root1->left, root2->right)
            && isSymmetric(root1->right, root2->left);
    // if none of above conditions is true then childL and childR are not mirror images
    return 0;
}
// Returns true if a tree is symmetric.
int isSimilar(struct Node* root)
{
    // Check if tree is mirror of itself
    return isSymmetric(root, root);
}
// Function to take input from user
struct Node* takeInput() 
{
    int val;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
    struct Node* root = newNode(val);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}
// Main function
int main()
{
    // Take input for the binary tree
    printf("Enter elements of the binary tree:\n");
    struct Node* root = takeInput();
    if (isSimilar(root)) {
        printf("The tree is symmetric");
    }
    else {
        printf("The tree is not symmetric");
    }
    return 0;
}