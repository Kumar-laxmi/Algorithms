class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def getIntersectionNode(headA, headB):
    ptrA = headA
    ptrB = headB

    while ptrA != ptrB:
        ptrA = headB if ptrA is None else ptrA.next
        ptrB = headA if ptrB is None else ptrB.next

    return ptrA

# Create the first linked list: 1 -> 2 -> 3 -> 4 -> 5
headA = ListNode(1)
nodeA2 = ListNode(2)
nodeA3 = ListNode(3)
nodeA4 = ListNode(4)
nodeA5 = ListNode(5)

headA.next = nodeA2
nodeA2.next = nodeA3
nodeA3.next = nodeA4
nodeA4.next = nodeA5

# Create the second linked list: 6 -> 7 -> 4 -> 5
headB = ListNode(6)
nodeB2 = ListNode(7)

headB.next = nodeB2
nodeB2.next = nodeA4

# Find the intersection node
intersection = getIntersectionNode(headA, headB)

if intersection:
    print("Intersection node value:", intersection.val)
else:
    print("No intersection found.")
