import random

class Node:
   #Function to create a new node with the given key
# and a randomly generated priority value
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None
# Function to perform a right rotation on the given root node
def right_rotate(root):
    new_root = root.left
    temp = new_root.right
    new_root.right = root
    root.left = temp
    return new_root
# Function to perform a left rotation on the given root node
def left_rotate(root):
    new_root = root.right
    temp = new_root.left
    new_root.left = root
    root.right = temp
    return new_root
#Function to insert a new node with the given key into the tree
def insert(root, key, priority):
    if root is None:
        return Node(key, priority)

    if key < root.key:
        root.left = insert(root.left, key, priority)
        if root.left.priority > root.priority:
            root = right_rotate(root)
    else:
        root.right = insert(root.right, key, priority)
        if root.right.priority > root.priority:
            root = left_rotate(root)
    return root
# Function to delete the node with the given key from the tree
def delete_node(root, key):
    if root is None:
        return root

    if key < root.key:
        root.left = delete_node(root.left, key)
    elif key > root.key:
        root.right = delete_node(root.right, key)
    else:
        if root.left is None:
            temp = root.right
            root = None
            return temp
        elif root.right is None:
            temp = root.left
            root = None
            return temp

        if root.left.priority > root.right.priority:
            root = right_rotate(root)
            root.right = delete_node(root.right, key)
        else:
            root = left_rotate(root)
            root.left = delete_node(root.left, key)
    return root
# Function to perform an inorder traversal of the tree
def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print("Key:", root.key, "Priority:", root.priority)
        inorder_traversal(root.right)

root = None
# Main loop to interact with the user and perform operations
while True:
    print("1. Insert  2. Delete  3. Print Inorder  4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        key = int(input("Enter the key to insert: "))
        priority = int(input("Enter the priority: "))
        root = insert(root, key, priority)
    elif choice == 2:
        key = int(input("Enter the key to delete: "))
        root = delete_node(root, key)
    elif choice == 3:
        print("Inorder Traversal:")
        inorder_traversal(root)
    elif choice == 4:
        break
    else:
        print("Invalid choice. Please try again.")
    
    print()

