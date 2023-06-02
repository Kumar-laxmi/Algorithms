from collections import deque

class Node:
    def __init__(self, k):
        self.key = k
        self.left = None
        self.right = None

def insert(root):
    print("Enter value to be entered: ", end="")
    val = int(input())
    root = Node(val)

    if val == -1:
        return None

    print("Enter value to the left of", val, ": ", end="")
    root.left = insert(root.left)
    print("Enter value to the right of", val, ": ", end="")
    root.right = insert(root.right)

    return root

def display(V):
    for i in V:
        print(i, end=" ")

def left_view(root, level, res):
    if not root:
        return
    if len(res) == level:
        res.append(root.key)

    left_view(root.left, level + 1, res)
    left_view(root.right, level + 1, res)

def right_view(root, level, res):
    if not root:
        return
    if len(res) == level:
        res.append(root.key)

    right_view(root.right, level + 1, res)
    right_view(root.left, level + 1, res)

def top_view(root):
    res = []
    if not root:
        return res

    mp = {}
    q = deque([(root, 0)])
    while q:
        f = q.popleft()
        node, line = f[0], f[1]

        if line not in mp:
            mp[line] = node.key

        if node.left:
            q.append((node.left, line - 1))
        if node.right:
            q.append((node.right, line + 1))

    for i in sorted(mp.keys()):
        res.append(mp[i])

    return res

def bottom_view(root):
    res = []
    if not root:
        return res

    mp = {}
    q = deque([(root, 0)])
    while q:
        f = q.popleft()
        node, line = f[0], f[1]

        mp[line] = node.key

        if node.left:
            q.append((node.left, line - 1))
        if node.right:
            q.append((node.right, line + 1))

    for i in sorted(mp.keys()):
        res.append(mp[i])

    return res

if __name__ == "__main__":
    root = None
    print("Enter binary tree nodes, and for no node, enter -1\n")
    root = insert(root)
    L, R, T, B = [], [], [], []
    usrchoice = 0

    while True:
        print("\n\n1. Left View")
        print("2. Right View")
        print("3. Top View")
        print("4. Bottom View")
        print("5. Exit")
        print("Enter the choice of operation to be implemented: ", end="")
        usrchoice = int(input())

        if usrchoice == 1:
            left_view(root, 0, L)
            display(L)
        elif usrchoice == 2:
            right_view(root, 0, R)
            display(R)
        elif usrchoice == 3:
            T = top_view(root)
            display(T)
        elif usrchoice == 4:
            B = bottom_view(root)
            display(B)
        elif usrchoice == 5:
            break
        else:
            print("Enter a valid choice")
