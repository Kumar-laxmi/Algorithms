class Node:
    def __init__(self, x):
        self.data = x
        self.next = None

def insert(head, val):
    temp = Node(val)
    if head is None:
        temp.next = head
        return temp

    curr = head
    while curr.next is not None:
        curr = curr.next

    curr.next = temp
    temp.next = None
    return head

def reverse(head, k):
    curr = head
    prevFirst = None
    isFirstPass = True

    while curr is not None:
        first = curr
        prev = None
        count = 0

        while curr is not None and count < k:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
            count += 1

        if isFirstPass:
            head = prev
            isFirstPass = False
        else:
            prevFirst.next = prev
        prevFirst = first

    return head

def printList(head):
    curr = head
    print("\n\n")
    while curr is not None:
        print(curr.data, "->", end=" ")
        curr = curr.next
    print("NULL\n\n")

if __name__ == "__main__":
    head = None
    n = int(input("Enter n: "))
    k = int(input("Enter k: "))
    print("Enter nodes:")
    for i in range(n):
        val = int(input())
        head = insert(head, val)
    
    printList(head)
    head = reverse(head, k)
    printList(head)
