"""
Python program to detect a loop in a linked list.
A loop is detected if there is a cycle in the linked list.

Algorithm:
1. Create two pointers, slow and fast. Both initially point to the head of the linked list.
2. Move slow pointer by one step and fast pointer by two steps.
3. If there is a loop, slow and fast pointers will meet at some point.
   This is because if there is a cycle, the fast pointer will eventually catch up with the slow pointer.
4. If slow and fast pointers meet, it means there is a loop in the linked list.
5. If fast pointer reaches the end of the list (NULL), it means there is no loop.

Time complexity: O(N)
Space complexity: O(1)
"""

class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

def detectLoop(head):
    # Create two pointers, slow and fast
    slow = head
    fast = head

    while fast and fast.next:
        # Move slow pointer by one step
        slow = slow.next
        # Move fast pointer by two steps
        fast = fast.next.next

        # If slow and fast pointers meet, there is a loop
        if slow == fast:
            return True

    # No loop found
    return False

# Create linked list
head = None
tail = None

while True:
    data = int(input("Enter data (enter -1 to end): "))

    if data == -1:
        break
    else:
        # Create a new node
        new_node = Node(data)

        if head is None:
            # First node in the list
            head = tail = new_node
        else:
            # Append new node to the list
            tail.next = new_node
            tail = new_node

# Create a loop for testing
tail.next = head

if detectLoop(head):
    print("Loop found")
else:
    print("No loop found")
