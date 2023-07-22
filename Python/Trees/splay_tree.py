# Path: Python\Trees\splay_tree.py
# Python program to implement Splay Tree.

# A splay tree is a self-adjusting binary search tree
# where recently accessed nodes are moved to the root for

# from colorama import Fore, Style


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


class SplayTree:
    def RR_Rotate(self, k2):
        # Perform right-right rotation
        k1 = k2.left
        k2.left = k1.right
        k1.right = k2
        return k1

    def LL_Rotate(self, k2):
        # Perform left-left rotation
        k1 = k2.right
        k2.right = k1.left
        k1.left = k2
        return k1

    def splay(self, key, root):
        if not root:
            return None

        # Header node for easier manipulation
        header = Node(None)
        header.left = header.right = None
        LeftTreeMax = RightTreeMin = header

        # Splay the key to the root of the tree
        while True:
            if key < root.key:
                if not root.left:
                    break
                if key < root.left.key:
                    # Zig-Zig (Right-Right) rotation
                    root = self.RR_Rotate(root)
                    if not root.left:
                        break
                RightTreeMin.left = root
                RightTreeMin = RightTreeMin.left
                root = root.left
                RightTreeMin.left = None
            elif key > root.key:
                if not root.right:
                    break
                if key > root.right.key:
                    # Zag-Zag (Left-Left) rotation
                    root = self.LL_Rotate(root)
                    if not root.right:
                        break
                LeftTreeMax.right = root
                LeftTreeMax = LeftTreeMax.right
                root = root.right
                LeftTreeMax.right = None
            else:
                # Key found at the root, break the loop
                break

        # Reassemble the tree
        LeftTreeMax.right = root.left
        RightTreeMin.left = root.right
        root.left = header.right
        root.right = header.left
        return root

    def newNode(self, key):
        p_node = Node(key)
        p_node.left = p_node.right = None
        return p_node

    def insert(self, key, root):
        # Perform Insertion
        p_node = self.newNode(key)
        if not root:
            root = p_node
            return root
        root = self.splay(key, root)
        if key < root.key:
            p_node.left = root.left
            p_node.right = root
            root.left = None
            root = p_node
        elif key > root.key:
            p_node.right = root.right
            p_node.left = root
            root.right = None
            root = p_node
        else:
            return root
        return root

    def delete(self, key, root):
        # Perfome Deletion
        temp = None
        if not root:
            return None
        root = self.splay(key, root)
        if key != root.key:
            return root
        else:
            if not root.left:
                temp = root
                root = root.right
            else:
                temp = root
                root = self.splay(key, root.left)
                root.right = temp.right
            del temp
            return root

    def search(self, key, root):
        return self.splay(key, root)

    # Pre-order traversal of the tree
    def preOrder(self, root):
        if root:
            print(root.key, end=" ")
            self.preOrder(root.left)
            self.preOrder(root.right)


if __name__ == '__main__':
    st = SplayTree()
    root = None
    # st.preOrder(root)
    print("1. Insert")
    print("2. Delete")
    print("3. Search")
    print("4. Exit")
    
    while True:
        c = int(input("Enter your choice: "))

        if c == 1:
            i = int(input("Enter value to be inserted: "))
            root = st.insert(i, root)
            print("After Inserting", i, end='')

        elif c == 2:
            i = int(input("Enter value to be deleted: "))
            root = st.delete(i, root)
            print("After Deleting", i, end='')

        elif c == 3:
            i = int(input("Enter value to be searched: "))
            root = st.search(i, root)
            print("After Searching", i, end='')

        elif c == 4:
            break
        else:
            # print(Fore.RED + "\nInvalid type!\n" + Style.RESET_ALL)
            print("\nInvalid typle!\n")
            continue

        # print(", the PreOrder Traversal: ", end='' + Fore.BLUE)
        print(", the PreOrder Traversal: ", end='')
        if not root:
            print("None")
        else:
            st.preOrder(root)
            print()
        # print(Style.RESET_ALL)
        print()
