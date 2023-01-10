#include <stdio.h>
#include <stdlib.h>
 
 
/*
Approach:
Using array in C to store and sort values of given Binary Tree and then iterating through that array to get the BST.
All traversal in the following code has been done inorder.
*/

 
/* Structure for the Node */
struct node
{
    int info;
    struct node* left, *right;
};
 
int data[100];
int i = 0;
 
/*creates a new node */
 
struct node* genNode(int key)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->info = key;
    root->left = NULL;
    root->right = NULL;
 
    return(root);
}
 
/* counts the number of nodes in a tree */
 
int count(struct node *n)
{
    int c = 1;
 
    if (n == NULL)
        return 0;
    else
    {
        c += count(n->left);
        c += count(n->right);
        return c;
    }
}
 
/*
 * Copies the nodes of Binary Tree in an array
 */
void binarytoarray(struct node * root, int data[], int *ptr)
{
    if(root != NULL)
    {
    binarytoarray(root->left, data, ptr);
    data[*ptr] = root->info;
    (*ptr)++;
    binarytoarray(root->right, data, ptr);
    }
}
 
/*
 * Copies the element of array to bst
 */
void arraytobst(int *arr, struct node *root, int *index)
{
    if(root != NULL)
    {
        arraytobst(arr, root->left, index);
        root->info = arr[i++];  // This i is a global variable initialized in line 20
        arraytobst(arr, root->right, index);
    }
}
 
int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
 
/*
 * Function to traverse the tree (Inorder)
 */
 
void traverse(struct node *root)
{
    if(root !=NULL)
    {
        traverse(root->left);
        printf("%d\t",root->info);
        traverse(root->right);
    }
}
 
/*
 * Function to converts binary tree to bst
 */
void binaryToBST(struct node *root)
{
    int n, i;
 
    if (root == NULL)
        return;
    n = count(root);
    i = 0;
    binarytoarray(root, data, &i);
    qsort(&data, n, sizeof(data[0]), compare);
    i = 0;
    arraytobst(data, root, &i);
}
 

int main()
{
    struct node *root = genNode(9);
    root->left = genNode(4);
    root->right = genNode(5);
    root->left->left = genNode(15);
    root->right->right= genNode(1);
    root->right->left = genNode(3);
    root->right->right = genNode(7);
 
 
    printf("Inorder Traversal of Input Binary Tree is\n");
    traverse(root);
    binaryToBST(root);
    printf("\nInorder Traversal of the converted Binary Search Tree is\n");
    traverse(root);
    return 0;
}
