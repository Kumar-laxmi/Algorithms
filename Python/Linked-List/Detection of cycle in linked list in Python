
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detectCycle(head):
    visited = set()
    while head:
        if head in visited:
            return True
        visited.add(head)
        head = head.next
    return False

def createLinkedList():
    head = None
    tail = None
    while True:
        data = input("Enter data for the next node (press enter to stop): ")
        if not data:
            break
        node = Node(data)
        if head is None:
            head = node
            tail = node
        else:
            tail.next = node
            tail = node
    return head

# Create a linked list
head = createLinkedList()

# Check if there is a cycle in the linked list
if detectCycle(head):
    print("There is a cycle in the linked list.")
else:
    print("There is no cycle in the linked list.")
