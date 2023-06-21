# Algorithm:
# 1. Start with an empty Treap.
# 2. For each element to be inserted:
#    a. Create a new node with the element and a random priority.
#    b. Split the Treap at the position where the new node should be inserted.
#    c. Merge the left split, new node, and right split to form the updated Treap.
# 3. To delete an element, find the node with the target element and remove it.
# 4. To search for an element, traverse the Treap and return the corresponding node if found.
# 5. Perform any other required operations like rotating, merging, or splitting as needed.

import random

# Class for a node in the Treap
class Node:
    def __init__(self, key):
        self.key = key
        self.priority = random.random()  # Assign a random priority
        self.left = None
        self.right = None

# Split the Treap based on the key. Left Treap will have nodes <= key and right Treap will have nodes > key.
def split(root, key):
    if root is None:
        return None, None
    
    if root.key <= key:
        left, root.right = split(root.right, key)
        return root, left
    else:
        root.left, right = split(root.left, key)
        return right, root

# Merge two Treaps into a single Treap.
def merge(left, right):
    if left is None:
        return right
    if right is None:
        return left
    
    if left.priority > right.priority:
        left.right = merge(left.right, right)
        return left
    else:
        right.left = merge(left, right.left)
        return right

# Insert a new node with a key into the Treap.
def insert(root, key):
    new_node = Node(key)
    left, right = split(root, key)
    return merge(merge(left, new_node), right)

# Search for a key in the Treap.
def search(root, key):
    if root is None or root.key == key:
        return root
    
    if root.key < key:
        return search(root.right, key)
    else:
        return search(root.left, key)

# Delete a node with a key from the Treap.
def erase(root, key):
    if root is None:
        return root
    
    if root.key == key:
        return merge(root.left, root.right)
    
    if key < root.key:
        root.left = erase(root.left, key)
    else:
        root.right = erase(root.right, key)
    
    return root

# Inorder traversal of the Treap
def inorder(root):
    if root is None:
        return
    
    inorder(root.left)
    print(root.key, end=" ")
    inorder(root.right)

root = None

# User input to demonstrate Treap operations
choice = 0
while choice != 5:
    print("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        key = int(input("Enter key to insert: "))
        root = insert(root, key)
        print("Key", key, "inserted.")
    elif choice == 2:
        key = int(input("Enter key to delete: "))
        root = erase(root, key)
        print("Key", key, "deleted.")
    elif choice == 3:
        key = int(input("Enter key to search: "))
        result = search(root, key)
        if result is not None:
            print("Key", key, "found.")
        else:
            print("Key", key, "not found.")
    elif choice == 4:
        print("Inorder Traversal:", end=" ")
        inorder(root)
        print()
    elif choice == 5:
        print("Exiting...")
    else:
        print("Invalid choice. Try again.")

# Deallocate memory
# ...
