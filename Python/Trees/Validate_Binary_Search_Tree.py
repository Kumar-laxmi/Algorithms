# Python program to check if a binary tree is bst or not

class Node:
 
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
def maxValue(node):
    if node is None:
        return 0
     
    leftMax = maxValue(node.left)
    rightMax = maxValue(node.right)
     
    value = 0
    if leftMax > rightMax:
        value = leftMax
    else:
        value = rightMax
     
    if value < node.data:
        value = node.data
     
    return value
     
def minValue(node):
    if node is None:
        return 1000000000
     
    leftMax = minValue(node.left)
    rightMax = minValue(node.right)
     
    value = 0
    if leftMax < rightMax:
        value = leftMax
    else:
        value = rightMax
     
    if value > node.data:
        value = node.data
     
    return value
 
# Returns true if a binary tree is a binary search tree
def isBST(node):
    if node is None:
        return True
     
    # false if the max of the left is > than us
    if(node.left is not None and maxValue(node.left) > node.data):
        return False
     
    # false if the min of the right is <= than us
    if(node.right is not None and minValue(node.right) < node.data):
        return False
     
    #false if, recursively, the left or right is not a BST
    if(isBST(node.left) is False or isBST(node.right) is False):
        return False
     
    # passing all that, it's a BST
    return True
 
# Driver code
if __name__ == "__main__":
  root = Node(4)
  root.left = Node(2)
  root.right = Node(5)
  # root.right.left = Node(7)
  root.left.left = Node(1)
  root.left.right = Node(3)
 
  # Function call
  if isBST(root) is True:
      print("Is BST")
  else:
      print("Not a BST")
