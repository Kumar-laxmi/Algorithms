
'''
 Approach:
Using List in python to sort and store values of given Binary Tree and then iterating through that list to get the BST.
All traversal in the following code has been done inorder.
'''
  
# Class for defining structure of Nodes of Tree
class Node: 
      
    def __init__(self, data): 
        self.data = data  
        self.left = None
        self.right = None
  
# Function to store the inroder traversal of a tree 
def storeInorder(root, inorder): 
    if root is None: 
        return 
      
    storeInorder(root.left, inorder) 
      
    inorder.append(root.data) 
  
    storeInorder(root.right, inorder) 
  
# Function to conver the sorted array into BST
# Note that this sorted array has been generated from the function storeInorder()
def arrayToBST(arr, root): 
  
    if root is None: 
        return 
      
    arrayToBST(arr, root.left) 
    root.data = arr[0] 
    arr.pop(0) 
    arrayToBST(arr, root.right) 
  
# This function converts a given binary tree to BST 
def binaryToBST(root): 
      

    if root is None: 
        return 
      
    # Create the temp array and store the inorder traveral of tree  
    arr = [] 
    storeInorder(root, arr) 
    # Sort the array 
    arr.sort() 
  
    # copy array elements back to binary tree 
    arrayToBST(arr, root) 
  
# Function to binaryToBST the tree (Inorder)
def traverse(root): 
    if root is None: 
        return
    traverse(root.left) 
    print(root.data, end=" ") 
    traverse(root.right) 

# Driver program
root = Node(9) 
root.left = Node(4) 
root.right = Node(5) 
root.left.left = Node(15) 
root.right.right= Node(1)
root.right.left = Node(3)
root.right.right = Node(7)
  

print("Following is the inorder traversal of the Given Binary Tree")
traverse(root)
print()
binaryToBST(root) 
print()
print("Following is the inorder traversal of the converted BST")
traverse(root) 
