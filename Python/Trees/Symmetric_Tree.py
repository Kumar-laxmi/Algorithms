#Name :  Atul Kumar
#Github username : atul1510
#Repositary name : Algorithms
#Problem Description:
#Given a binary tree, check whether it is a mirror of itself.
#Examples:
#1] INPUT:
#1
#/
#2 2
#/ \ /
#3 4 4 3
#OUTPUT: Symmetric
#2] INPUT:
#1
#/
#2 2
#\
#3 3
#OUTPUT: Not symmetric */
# Python program to check if a given Binary Tree is symmetric or not
# Construct a Binary Tree Node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
# Returns true if trees with roots as childL and childR are mirror image of each other
def isSymmetric(root1, root2):
    # If both trees are empty, then they are mirror images
    if root1 is None and root2 is None:
        return True
    # For two trees to be mirror images, the following 3 conditions must be true
    # a) Their root node's key must be same
    # b) left subtree of left tree and right subtree of right tree have to be mirror images
    # c) right subtree of left tree and left subtree of right tree have to be mirror images
    if root1 and root2 and root1.key == root2.key:
        return isSymmetric(root1.left, root2.right) and isSymmetric(root1.right, root2.left)
    # if none of above conditions is true then childL and childR are not mirror images
    return False
# Returns true if a tree is symmetric.
def isSimilar(root):
    # Check if tree is mirror of itself
    return isSymmetric(root, root)
# Function to take input from user
def takeInput():
    val = int(input("Enter root value (-1 for no node): "))
    if val == -1:
        return None
    root = Node(val)
    root.left = takeInput()
    root.right = takeInput()
    return root
# Main function
if __name__ == '__main__':
    # Take input for the binary tree
    print("Enter elements of the binary tree:")
    root = takeInput()
    if isSimilar(root):
        print("The tree is symmetric")
    else:
        print("The tree is not symmetric")