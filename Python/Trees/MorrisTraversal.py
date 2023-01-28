#   Morris Traversal
#   Time Complexity = O(n)
#   Space Complexity = O(1) (Main advantage of using this traversal. Uses only constant space)
#                              1
#                             / \
#                            /   \
#                           2     3
#                          /  \
#                         /    \
#                        4      5
#                                \
#                                 \
#                                  6
#              
#                 Output --> 4 2 5 6 1 3

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

#Morris Inorder-Traversal
def morrisTraversal(root):
    #     Case 1:- If there is no left node then current i.e. root will be printed and it will be moved towards 
    #              right.
    #     Case 2:- If there exists a left node then we will move one step towards left node then immediately move on 
    #              towards right until right node does not encounter null. Again it will point to current node i.e. root 
    #              and same process continues.

    morris = []
    cur = root
    
    while cur!=None:
        
        if cur.left == None:
            morris.append(cur.val)
            cur = cur.right
        else:
            temp = cur.left
    
            while temp.right!=None and temp.right!=cur:
                temp = temp.right
                
            if temp.right == None:
                temp.right = cur
                cur = cur.left
            else:
                temp.right = None
                morris.append(cur.val)
                cur = cur.right
                
    return morris

def preorder(root):
    if root:
        print(root.val, end=' ')
        preorder(root.left)
        preorder(root.right)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=' ')

# Building the tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.left.right.right = TreeNode(6)

#Menu
print("1. Preorder")
print("2. Inorder")
print("3. Postorder")
print("4. Morris Traverse")
print("Select an option from above: ", end='')
choice = int(input())

if choice==1:
    preorder(root)
elif choice==2:
    inorder(root)
elif choice==3:
    postorder(root)
else:
    morris = morrisTraversal(root)
    print(' '.join([str(i) for i in morris]))