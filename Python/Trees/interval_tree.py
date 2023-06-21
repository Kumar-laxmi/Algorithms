class Interval:
    def __init__(self, low, high):
        self.low = low
        self.high = high


class Node:
    def __init__(self, interval):
        self.interval = interval
        self.max_high = interval.high
        self.left = None
        self.right = None


def insert(root, interval):
    if root is None:
        return Node(interval)

    low = root.interval.low

    if interval.low < low:
        root.left = insert(root.left, interval)
    else:
        root.right = insert(root.right, interval)

    if root.max_high < interval.high:
        root.max_high = interval.high

    return root


def do_overlap(i1, i2):
    return i1.low <= i2.high and i2.low <= i1.high


def search(root, interval):
    if root is None:
        return None

    if do_overlap(root.interval, interval):
        return root.interval

    if root.left is not None and root.left.max_high >= interval.low:
        return search(root.left, interval)

    return search(root.right, interval)


def inorder(root):
    if root is None:
        return

    inorder(root.left)
    print(f"[{root.interval.low}, {root.interval.high}] max = {root.max_high}")
    inorder(root.right)


intervals = [
    Interval(15, 20),
    Interval(10, 30),
    Interval(17, 19),
    Interval(5, 20),
    Interval(12, 15),
    Interval(30, 40),
]

root = None
for interval in intervals:
    root = insert(root, interval)

print("Inorder traversal of constructed Interval Tree is")
inorder(root)

search_interval = Interval(6, 7)
print(f"\nSearching for interval [{search_interval.low}, {search_interval.high}]")
result = search(root, search_interval)
if result is not None:
    print(f"Overlaps with [{result.low}, {result.high}]")
