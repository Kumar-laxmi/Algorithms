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
class Node:
	#  Construct a Binary Tree Node
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None
#Returns true if trees with roots as childL and childR are mirror image of each other
def isSymmetric(root1, root2):
	# If both trees are empty, then they are mirror images
	if root1 is None and root2 is None:
		return True
	""" For two trees to be mirror images,
		the following three conditions must be true
		1 - Their root node's key must be same
		2 - left subtree of left tree and right subtree
		of the right tree have to be mirror images
		3 - right subtree of left tree and left subtree
		of right tree have to be mirror images
	"""
	if (root1 is not None and root2 is not None):
		if root1.key == root2.key:
			return (isSymmetric(root1.left, root2.right)and
					isSymmetric(root1.right, root2.left))
	# For two trees to be mirror images, the following 3 conditions must be true
	# a) Their root node's key must be same
	# b) left subtree of left tree and right subtree of right tree have to be mirror images
	# c) right subtree of left tree and left subtree of right tree have to be mirror images
	return False
def isSimilar(root):
	# Check if tree is mirror of itself
	return isSymmetric(root, root)
# Main function
# Let's construct the tree show in the above figure
root = Node(1)
root.left = Node(2)
root.right = Node(2)
root.left.left = Node(3)
root.left.right = Node(4)
root.right.left = Node(4)
root.right.right = Node(3)
print ("Is Symmetric" if isSimilar(root) == True else "Is Not symmetric")