/*Morris Traversal
  
  Time Complexity = O(n)
  Space Complexity = O(1) (This is the main advantage of using this traversal as other traversal methods
                            uses O(n) space)

                             1
                            / \
                           /   \
                          2     3
                         /  \
                        /    \
                       4      5
                               \
                                \
                                 6
                
                Output --> 4 2 5 6 1 3
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

/*------Morris Traversal(Inorder)--------*/
vector<int> inorderTraverse(node *root){
    vector <int> inorder;

    node *current = root;

    /*Case 1:- If their is no left node then current i.e. root will be printed and it will be moved towards 
               right.
      
      Case 2:- If their exists left node then will move one step towards left node then immediately will move on 
               towards right until right node does not encounter null(i.e predecessor form) and again it will point to current node i.e. root 
               and same process continues.
    */
    while(current != NULL){
        if(current -> left == NULL){
            inorder.push_back(current -> data);
            current = current -> right;
        }
        else{
            node *previous = current -> left;
            while(previous -> right != NULL && previous -> right != current){
                previous = previous -> right;
            }

            if(previous -> right == NULL){
                previous -> right = current;
                current = current -> left;
            }
            else{
                previous -> right = NULL;
                inorder.push_back(current -> data);
                current = current -> right;
            }
        }
    }
    return inorder;
}

/*----Creating a structure-----*/
struct node *newNode(int data) {
  struct node * node = (struct node*) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}

int main() {
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > inorder;
  inorder = inorderTraverse(root);

  cout << "The Morris inorder traverse is: ";
  for (int i=0; i<inorder.size(); i++){
    cout << inorder[i] << " ";
  }
  return 0;
}