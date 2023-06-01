/* 
Modified by : Anubha Sharma
Github Username: AnubhaSharma2709

The program is to implement Binary Tree Traversal

The Approach that I followed is:

1. The user can dynamically input the binary tree and perform the Traversal

2. I have used linked list for implemetation of the program

3. I have used recursion in the program to perfom Traversal
*/


//Code Implemetation
#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
// Function to create a Binary Tree. 
// This is important so that the user can dyanmically create the tree and doesnot have to hard code the elements of the tree

/*
Function to create a new binary tree node
Essential because it builds a binary tree by connecting nodes.
*/
node* createNode(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};
// Construction of Binary Tree
node* createTree(){
    int data;
    cout<<"Enter the Data(-1 to exit)";
    cin>>data;
    if(data==-1)
    return NULL;
    node* root = createNode(data);
    cout<<"Enter the left subtree of"<<data<<"\n";
    root->left = createTree();
    cout<<"Enter the Right subtree of"<<data<<"\n";
    root->right = createTree();
    return root;
}
// Implementation of Traversal 
/*
1. Inorder Traversal:
    Left Data Right
*/
void inorderTraversal(node* root){
    if(root==NULL)
    return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
/*
2. Preorder Traversal:
    Data left Right
*/
void preorderTraversal(node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
/*
3. Postorder Traversal:
    Left Right Data
*/
void postorderTraversal(node* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" "; 
}
//main program
int main(){
    node* root = createTree();
    cout << "Binary Tree Traversals:\n";

    cout<<"Inorder Traversal of Tree\n";
    inorderTraversal(root);
    cout<<"\n";

    cout<<"Preorder Traversal of Tree\n";
    preorderTraversal(root);
    cout<<"\n";

    cout<<"Postorder Traversal of Tree\n";
    postorderTraversal(root);
    cout<<"\n";
}
