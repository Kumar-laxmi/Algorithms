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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Construct a Binary Tree Node
typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;
// function to create a new Node
Node* newNode(int key)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}
// Returns true if trees with roots as childL and childR are mirror image of each other
bool isSymmertic(Node* root1, Node* root2)
{
	// If both trees are empty, then they are mirror images
	if (root1 == NULL && root2 == NULL)
		return true;
	// For two trees to be mirror images, the following 3 conditions must be true
	// a) Their root node's key must be same
	// b) left subtree of left tree and right subtree of right tree have to be mirror images
	// c) right subtree of left tree and left subtree of right tree have to be mirror images
	if (root1 && root2 && root1->key == root2->key)
		return isSymmertic(root1->left, root2->right)
			&& isSymmertic(root1->right, root2->left);
	// Returns true if a tree is symmetric.
	return false;
}
// Check if tree is mirror of itself
bool isSimilar(Node* root)
{
	return isSymmertic(root, root);
}
// Main function
int main()
{
	//Construct the given Tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);
	if (isSimilar(root))
		printf("Is Symmetric");
	else
		printf("Is Not symmetric");
	return 0;
}