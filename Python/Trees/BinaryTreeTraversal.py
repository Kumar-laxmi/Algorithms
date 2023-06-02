# Modified by : Anubha Sharma
#Github Username: AnubhaSharma2709

#The program is to implement Binary Tree Traversal

#The Approach that I followed is:

#1. The user can dynamically input the binary tree and perform the Traversal

#2. I have used linked list for implemetation of the program

#3. I have used recursion in the program to perfom Traversal


#Code Implemetation
class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
#Function to create a Binary Tree. 

def createTree():
    data= int(input("Enter the data(-1 to exit)"))
    if(data==-1):
        return None
    root = node(data)
    print("Left SubTree of", data)
    root.left = createTree()
    print("Right Subtree of", data)
    root.right = createTree()
    return root
#1. Inorder Traversal: Left Data Right
def inorderTraversal(root):
    if root is None:
        return
    
    inorderTraversal(root.left)
    print(root.data, end=" ")
    inorderTraversal(root.right)
#2. Preorder Traversal: Data Left Right
def preorderTraversal(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorderTraversal(root.left)
    preorderTraversal(root.right)
#3. Postorder Traversal: Left Right Data
def postorderTraversal(root):
    if root is None:
        return

    postorderTraversal(root.left)
    postorderTraversal(root.right)
    print(root.data, end=" ")


#main program
root = createTree()
print("Binary Tree Traversal :")

print("Inorder Traversal: ", end="")
inorderTraversal(root)
print()

print("Preorder Traversal: ", end="")
preorderTraversal(root)
print()

print("Postorder Traversal: ", end="")
postorderTraversal(root)
print()



