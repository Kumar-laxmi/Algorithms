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
// C++ program to check if a given Binary Tree is symmetric or not
#include <bits/stdc++.h>
using namespace std;
// Construct a Binary Tree Node
struct Node {
	int key;
	struct Node *left, *right;
};
// function to create a new Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}
// Returns true if trees with roots as childL and childR are mirror image of each other
bool isSymmetric(struct Node* root1, struct Node* root2)
{
	// If both trees are empty, then they are mirror images
	if (root1 == NULL && root2 == NULL)
		return true;
	// For two trees to be mirror images, the following 3 conditions must be true
	// a) Their root node's key must be same
	// b) left subtree of left tree and right subtree of right tree have to be mirror images
	// c) right subtree of left tree and left subtree of right tree have to be mirror images
	if (root1 && root2 && root1->key == root2->key)
		return isSymmetric(root1->left, root2->right)
			&& isSymmetric(root1->right, root2->left);
	// if none of above conditions is true then childL and childR are not mirror images
	return false;
}
// Returns true if a tree is symmetric.
bool isSimilar(struct Node* root)
{
	// Check if tree is mirror of itself
	return isSymmetric(root, root);
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
		cout << "Is Symmetric";
	else
		cout << "Is Not symmetric";
	return 0;
}