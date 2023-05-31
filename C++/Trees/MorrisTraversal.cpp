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


/*-----Morris Preorder Traversal-------*/

/*Case 1 : When there is no left node =>remain same like inorder traversal ,first root is printed then move to left

 Case 2 : The approach of preorder is root left right, so before moving to left ,insert root then move left 
 and if thread already exists remove thread , as we have already visited left subtree now move to right  */

vector<int> preorderTraversal(node* root) {

       vector<int>preorder;
       node* current=root;

        while(current != NULL){
          // case 1
            if(current->left == NULL){
                preorder.push_back(current->data);
                current=current->right;
            }
            else{
              // case 2
                node* previous=current->left;
                while(previous->right && previous->right!=current){
                    previous=previous->right;
                }

                 if(previous->right == NULL){
                    previous->right=current; //create thread
                    preorder.push_back(current->data);  //insert root first 
                    current=current->left;
                }
                else{
                    //if previous->right==current--->  if thread already exists
                    previous->right=NULL; //remove thread
                    current=current->right;
                }
            }
        }
          return preorder;
    }









//Preorder Traversal
void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

//Inorder Traversal
void inorderT(node *p)
{
    if(p!=NULL)
    {
        inorderT(p->left);
        printf("%d ",p->data);
        inorderT(p->right);
    }
}

//Postorder Traversal
void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
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
  vector<int>preorder_traversal;
  int choice;
  cout<<"Select the option given below:- "<<endl;
  cout<<"1. Preorder"<<endl;
  cout<<"2. Inorder"<<endl;
  cout<<"3. Postorder"<<endl;
  cout<<"4. Morris Traverse"<<endl;
  cout<<"5. Morris Preorder Traversal"<<endl;
  cin>>choice;

  switch(choice)
  {
    case 1:
      preorder(root);
      break;
    case 2:
      inorderT(root);
      break;
    case 3:
      postorder(root);
      break;
    case 4:
      inorder = inorderTraverse(root);
       cout << "The Morris inorder traverse is: ";
       for (int i=0; i<inorder.size(); i++){
        cout << inorder[i] << " ";
      }
      break;
      case 5:
        preorder_traversal = preorderTraversal(root);
        cout << "The Morris Preorder traverse is: ";
       for (int i=0; i<preorder_traversal.size(); i++){
        cout << preorder_traversal[i] << " ";
      }
      break;
    default:
      cout<<"Wrong Choice"<<endl;
  }
  return 0;
}