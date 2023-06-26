class Node:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data
 

# Insert data into the tree
    def insert(self,data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data 

# Print the tree
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()


#Use the insert method to add nodes
n=int(input("Enter the number of nodes you want to enter:"))
num=int(input("Enter a node:"))
root=Node(num)
for i in range(1,n):
    num=input("Enter a node:")
    numint=int(num)
    root.insert(numint)
root.PrintTree()
