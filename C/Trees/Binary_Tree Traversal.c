/* 
Modified by : Anubha Sharma
Github Username: AnubhaSharma2709

The program is to implement Binary Tree Traversal

The Approach that I followed is:

1. The user can dynamically input the binary tree and perform the Traversal

2. I have used linked list for implemetation of the program

3. I have used recursion in the program to perfom Traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
// Function to create a Binary Tree. 
// This is important so that the user can dyanmically create the tree and doesnot have to hard code the elements of the tree

/*
Function to create a new binary tree node
Essential because it builds a binary tree by connecting nodes.
*/
struct node* newNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Construction of Binary Tree
struct node* createTree(){
    int data;
    printf("Enter the Data(-1 to exit the Loop)");
    scanf("%d", &data);
    if(data == -1){
        return NULL;
    }
    struct node* root = newNode(data);
    printf("Left Subtree of %d:\n", data);
    root->left = createTree();
    printf("Right Subtree of %d:\n", data);
    root->right = createTree();
    return root;
}
// Implementation of Traversal 
/*
1. Inorder Traversal:
    Left Data Right
*/
void inorderTraversal(struct node* root){
    if(root==NULL)
       return;
    inorderTraversal(root->left);
    printf("%d", root->data);
    inorderTraversal(root->right);
}
/*
2. Preorder Traversal:
    Data left Right
*/
void preorderTraversal(struct node* root){
    if(root==NULL)
    return;
    printf("%d", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
/*
3. Postorder Traversal:
    Left Right Data
*/
void postorderTraversal(struct node* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d", root->data);
    }
int main(){
    struct node* root = createTree();
    printf("Binary Tree Traversals:\n");
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}