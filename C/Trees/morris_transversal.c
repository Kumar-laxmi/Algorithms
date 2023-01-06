// =============================PROBLEM STATEMENT================================

/* The problem that the above code solves is to traverse a binary tree in inorder 
and print out the values of the nodes in the tree.

Inorder traversal of a binary tree involves visiting the left subtree, the root, 
and then the right subtree. The tree is traversed recursively, with the inorder 
traversal of the left subtree being performed before the root and the inorder 
traversal of the right subtree being performed after the root.

The above code uses Morris traversal, which is a technique for performing inorder 
traversal of a binary tree without using recursion or a stack. It works by using 
the right pointers of the nodes in the tree to store the inorder successor of each 
node, and then traversing the tree using these pointers.

==============================INTUITION============================================
The function morris_traversal takes a pointer to the root node of the tree as an 
argument and performs Morris traversal on the tree, printing out the values of the 
nodes as it goes. The function initializes the current pointer to the root of the 
tree and enters a loop, which continues until current becomes NULL. Inside the loop, 
if the left child of current is NULL, the value of current is printed and current is
updated to its right child. If the left child is not NULL, the algorithm finds the 
inorder predecessor of current, which is the rightmost node in the left subtree of current. 
The algorithm then makes current the right child of its inorder predecessor. 
If the inorder predecessor's right child is already current, it means that current 
has already been visited, so the algorithm sets the right child of the inorder predecessor 
back to NULL and prints the value of current. current is then updated to its right child. 
This process is repeated until current becomes NULL, at which point the function terminates
*/

// ===================================CODE==================================================
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void morris_traversal(struct TreeNode *root) {
  struct TreeNode *current, *pre;

  if (root == NULL) {
    return;
  }

  current = root;
  while (current != NULL) {
    if (current->left == NULL) {
      printf("%d ", current->val);
      current = current->right;
    } else {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while (pre->right != NULL && pre->right != current) {
        pre = pre->right;
      }

      /* Make current as right child of its inorder predecessor */
      if (pre->right == NULL) {
        pre->right = current;
        current = current->left;
      }

      /* Revert the changes made in if part to restore the original
         tree i.e., fix the right child of predecssor */
      else {
        pre->right = NULL;
        printf("%d ", current->val);
        current = current->right;
      }
    }
  }
}

int main() {
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct TreeNode root;
  root.val = 1;
  root.left = &(struct TreeNode){2, &(struct TreeNode){4, NULL, NULL}, &(struct TreeNode){5, NULL, NULL}};
  root.right = &(struct TreeNode){3, NULL, NULL};

  morris_traversal(&root);

  return 0;
}
