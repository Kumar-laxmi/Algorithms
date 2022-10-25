# tree node
class Node(object):
    def __init__(self, ele):
        self.data = ele
        self.left = None
        self.right = None
        self.height = 1

class AvlTree(object):
    # insert method
    def insertNode(self, node, ele):
        if not node:
            return Node(ele)
        elif ele < node.val:
            node.left = self.insertNode(node.left, ele)
        else:
            node.right = self.insertNode(node.right, ele)

        # height updation
        node.height = 1 + max(self.getHeight(node.left), self.getHeight(node.right))

        balance = self.getBalance(node)

        # ll rotation
        if balance > 1 and ele < node.left.val:
            return self.rightRotate(node)

        # rr rotation
        if balance < -1 and ele > node.right.val:
            return self.leftRotate(node)

        # lr rotation
        if balance > 1 and ele > node.left.val:
            node.left = self.leftRotate(node.left)
            return self.rightRotate(node)

        # rl rotation
        if balance < -1 and ele < node.right.val:
            node.right = self.rightRotate(node.right)
            return self.leftRotate(node)

        return node

    # deletion method
    def delete(self, node, ele):
        if not node:
            return node

        elif ele < node.val:
            node.left = self.delete(node.left, ele)

        elif ele > node.val:
            node.right = self.delete(node.right, ele)

        else:
            if node.left is None:
                temp = node.right
                node = None
                return temp

            elif node.right is None:
                temp = node.left
                node = None
                return temp

            temp = self.getMinValueNode(node.right)
            node.val = temp.val
            node.right = self.delete(node.right, temp.val)

        # one node case
        if node is None:
            return node

        # height updation
        node.height = 1 + max(self.getHeight(node.left), self.getHeight(node.right))

        balance = self.getBalance(node)

        # ll rotation
        if balance > 1 and self.getBalance(node.left) >= 0:
            return self.rightRotate(node)

        # rr rotation
        if balance < -1 and self.getBalance(node.right) <= 0:
            return self.leftRotate(node)

        # lr rotation
        if balance > 1 and self.getBalance(node.left) < 0:
            node.left = self.leftRotate(node.left)
            return self.rightRotate(node)

        # rl rotation
        if balance < -1 and self.getBalance(node.right) > 0:
            node.right = self.rightRotate(node.right)
            return self.leftRotate(node)

        return node

    def leftRotate(self, n):

        x = n.right
        y = x.left

        # rotation
        x.left = n
        n.right = y

        n.height = 1 + max(self.getHeight(n.left), self.getHeight(n.right))
        x.height = 1 + max(self.getHeight(x.left), self.getHeight(x.right))
        return x

    def rightRotate(self, n):

        x = n.left
        y = x.right

        # rotation
        x.right = n
        n.left = y

        n.height = 1 + max(self.getHeight(n.left), self.getHeight(n.right))
        x.height = 1 + max(self.getHeight(x.left), self.getHeight(x.right))
        return x

    def height(self, node):
        if not node:
            return 0
        return node.height

    def balFact(self, node):
        if not node:
            return 0
        return self.getHeight(node.left) - self.getHeight(node.right)

    def getMinValueNode(self, node):
        if node is None or node.left is None:
            return node
        return self.getMinValueNode(node.left)

    def preOrderTraversal(self, node):
        if not node:
            return
        print("{0} ".format(node.val), end="")
        self.preOrder(node.left)
        self.preOrder(node.right)

def main():
    tree = AvlTree()
    root = None
    while True:
        print("Choose an operation :\n1. INSERTION\n2. DELETION\n3. PREORDER TRAVERSAL\n4. Exit Program")
        ch = int(input("\tMAKE YOUR CHOICE : "))
        if ch == 1:
            ele = int(input("\nEnter the element for insertion : "))
            tree.insertNode(root, ele)
        
        elif ch == 2:
            ele = int(input("\nEnter the element for deletion : "))
            tree.delete(root, ele)

        elif ch == 3:
            print("\nPREORDER TRAVERSAL :", end=" ")
            tree.preOrderTraversal(root)

        elif ch == 4:
            exit(1)

main()