/*
Binary Search Tree: 
i)Bst is a type of bt where in value of lst is lower than value of temp(root).
value of Rst is higher than temp value.
ii)Operations to be performed on bst are:
   a)create
   b)insert
   c)delete
   d)search
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left_child;
    struct node* right_child;
};

typedef struct node NODE;

void inorder(NODE*);
NODE* search(NODE*, int);
NODE* delete(NODE*, int);
NODE* min(NODE*);
NODE* insert(NODE*, int);

int main(){

    NODE* root = NULL;
    int n; // number of nodes
    int value; // the value to be inserted
    int del; // the node to be deleted
    printf("\nEnter the number to be inserted : ");
    scanf("%d", &n);
    printf("\nEnter the inputs to BST : ");
    if(n > 0){
        scanf("%d", &value);
        root = insert(root, value);
    }
    for(int i = 1; i < n; i++){
        scanf("%d", &value);
        insert(root, value);
    }
    int searchelement;
    printf("\nInorder traversal is :");
    inorder(root);
    printf("Enter the element to be searched : ");
    scanf("%d", &searchelement);
    search(root, searchelement);
    printf("\nDelete the node : ");
    scanf("%d", &del);
    delete(root, del);
    printf("\n Inorder traversal after deletion is : ");
    inorder(root);
    printf("\n");
    return 0;
}

NODE* insert(NODE* temp, int value){

    if(temp == NULL){

        // There is no ROOT node in the tree.
        temp = (NODE*)malloc(sizeof(NODE));

        temp -> value = value;
        temp -> left_child = NULL;
        temp -> right_child = NULL;
    }

    else if(value < temp -> value){
        temp -> left_child = insert(temp -> left_child, value);
    }

    else if(value > temp -> value){
        temp -> right_child = insert(temp -> right_child, value);
    }

    return temp;
}

/**
 * If the node is empty, return NULL. If the node has no left child, return the node. Otherwise, return
 * the minimum of the left child
 */

NODE* min(NODE* temp){

    if(temp == NULL){
        return NULL;
    }
    else if(temp -> left_child == NULL)
        return temp;
    
    else{
        return min(temp -> left_child);
    }
}

void inorder(NODE* temp){
    if(temp == NULL)
        return;
    
    inorder(temp -> left_child);
    printf("%d ", temp -> value);
    inorder(temp -> right_child);
}

NODE* delete(NODE* root, int value){

    //base case
    if(root == NULL){
        return root;
    }

    if(value < root -> value){
        root -> left_child = delete(root -> left_child, value);
    }
    else if(value > root -> value){
        root -> right_child = delete(root -> right_child, value);
    }

    else{
        if(root -> left_child == NULL){
            struct node* temp = root -> right_child;
            free(root);
            return temp;
        }

        else if(root -> right_child == NULL){
            struct node* temp = root -> left_child;
            free(root);
            return temp;
        }
        else{
            /* Finding the minimum value in the right subtree of the node to be deleted. */
            struct node* temp = min(root -> right_child);
            root -> value = temp -> value;
            root -> right_child = delete(root -> right_child, temp -> value);
        }
    }
    return root;
}

NODE* search(NODE* root, int key){
    
    int flag = 0;
    NODE* temp = root;
    while(temp != NULL){

        if(key == temp -> value){
            flag = 1;
            return temp;
        }

        if(key > temp -> value){
            return search(temp -> right_child, key);
        }

        if(key < temp -> value){
            return search(temp -> left_child, key);
        }
    }
    return NULL;
}