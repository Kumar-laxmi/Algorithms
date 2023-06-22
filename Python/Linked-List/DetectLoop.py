""""
Given a linked list, check if the linked list has loop(cycle) or not.

Example: Head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
Output: True

Solution:
1. Traverse the list one by one and keep putting the node addresses in a Hash Table.
2. At any point, if NULL is reached then return false.
3. If next of current node points to any of the previously stored nodes in Hash then return true.
"""
# Linked List Node
class Node:
    def __init__(self, data):
        self.val = data
        self.next = None

# Display linked list
def display(head):
    temp = head
    while temp:
        print(temp.val, "->", end=" ")
        temp = temp.next
    print()

# Function to detect loop in a linked list
def detect_loop(head):
    visited = set()
    temp = head
    while temp:
        # If node is already present in the set
        if temp in visited:
            return True
        # Insert node into the set
        visited.add(temp)
        temp = temp.next
    return False

# Create an empty linked list
head = None
tail = None

# Insert nodes in the linked list
print("Enter the nodes (Enter -1 to stop): ")
while True:
    data = int(input())
    if data == -1:
        break
    newnode = Node(data)
    if head is None:
        head = newnode
        tail = newnode
    else:
        tail.next = newnode
        tail = newnode

# Create a loop in the linked list
tail.next = head.next.next

if detect_loop(head):
    print("Loop detected")
else:
    print("No loop detected")

