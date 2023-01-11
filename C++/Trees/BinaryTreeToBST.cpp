#include <bits/stdc++.h>
using namespace std;

/*
Approach: 
-> Using Set from C++ STL to store values of Nodes of given Binary Tree in sorted way and then iterating through that set and 
   generating the Nodes of BST with each iteration.
-> All traversal in the following code has been done inorder.
*/

// Structure of Node 
struct Node1 {
   int data;
   struct Node1 *left, *right;
};

// Function for storing the nodes in set while performing traverse traversal.
void storetraverseInSet(Node1* root1, set<int>& s){
   if (!root1)
   	return;
   storetraverseInSet(root1->left, s);
   s.insert(root1->data);
   storetraverseInSet(root1->right, s);
}
// Function for copying elements of set one by one to the tree while performing traverse traversal
void setToBST(set<int>& s, Node1* root1){
   if (!root1) return;
   
   setToBST(s, root1->left);
   auto it = s.begin();
   root1->data = *it;
   s.erase(it);
   setToBST(s, root1->right);
}

// Function to convert Binary tree to BST.
void binaryTreeToBST(Node1* root1){
   set<int> s;
   storetraverseInSet(root1, s);
   setToBST(s, root1);
}

Node1* newNode(int data){
   Node1* temp = new Node1();
   temp->data = data;
   temp->left = temp->right = NULL;
   return temp;
}

// function for doing inorder traversal
void traverse(Node1* root1){
   if (!root1)
   return;
   traverse(root1->left);
   cout<< root1->data << " ";
   traverse(root1->right);
}
int main(){
   Node1* root1 = newNode(9);
   root1->left = newNode(4);
   root1->right = newNode(5);
   root1->right->left = newNode(15);
   root1->left->left = newNode(1);
   root1->left->right = newNode(3);
   root1->right->right = newNode(7);
   
   cout<< "Inorder traversal of given Binary Tree is: " << endl;
   traverse(root1);
   
   binaryTreeToBST(root1);
   cout<< "\nInorder traversal of BST is: " << endl;
   traverse(root1);
   return 0;
}
