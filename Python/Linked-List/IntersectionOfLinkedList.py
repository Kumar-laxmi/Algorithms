# Linked List Node
class Node:
    def __init__(self, data):
        self.val = data
        self.next = None

# Display linked list
def display(head):
    temp = head
    while temp is not None:
        print(temp.val, "->", end=" ")
        temp = temp.next
    print()

# Insert node at the end of linked list
def insertattail(head, tail, data):
    temp = Node(data)
    if head is None:
        head = temp
        tail = temp
        return head, tail
    tail.next = temp
    tail = temp
    return head, tail

# Function to find intersection point of two linked lists
# Method 1: Using Hashing -> O(n) time and O(n) space
def getIntersectionNode(headA, headB):
    ptr1 = headA
    ptr2 = headB

    hash_set = set()

    while ptr1:
        hash_set.add(ptr1)
        ptr1 = ptr1.next

    while ptr2:
        if ptr2 in hash_set:
            return ptr2
        ptr2 = ptr2.next

    return None

# Method 2: Using 2 pointers -> O(n) time and O(1) space
def IntersectionNode(headA, headB):
    ptr1 = headA
    ptr2 = headB

    while ptr1 != ptr2:
        ptr1 = headB if ptr1 is None else ptr1.next
        ptr2 = headA if ptr2 is None else ptr2.next

    return ptr1

# Create an empty linked list
head1 = None
tail1 = None

# Insert nodes in linked list
n1 = int(input("Enter the number of nodes in linked list 1: "))
print("Enter the nodes of linked list 1: ")
for _ in range(n1):
    data = int(input())
    head1, tail1 = insertattail(head1, tail1, data)

# Create an empty linked list
head2 = None
tail2 = None

# Insert nodes in linked list
n2 = int(input("Enter the number of nodes in linked list 2: "))
print("Enter the nodes of linked list 2: ")
for _ in range(n2):
    data = int(input())
    head2, tail2 = insertattail(head2, tail2, data)

# Create a random intersection point
import random
pos = random.randint(1, n1)
temp = head1
for _ in range(pos-1):
    temp = temp.next
tail2.next = temp

# Display linked lists
print("Linked list 1: ", end="")
display(head1)
print("Linked list 2: ", end="")
display(head2)

# Find intersection point
intersection = IntersectionNode(head1, head2)
if intersection:
    print("Intersection point is: ", intersection.val)
    print("Linked list after intersection: ")
    display(intersection)
else:
    print("No intersection point")
