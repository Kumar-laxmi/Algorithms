class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def mergeSortedLists(head1, head2):
    ptr1 = head1
    ptr2 = head2
    dummyNode = Node(-1)
    ptr3 = dummyNode

    while ptr1 is not None and ptr2 is not None:
        if ptr1.data < ptr2.data:
            ptr3.next = ptr1
            ptr1 = ptr1.next
        else:
            ptr3.next = ptr2
            ptr2 = ptr2.next
        ptr3 = ptr3.next

    while ptr2 is not None:
        ptr3.next = ptr2
        ptr2 = ptr2.next
        ptr3 = ptr3.next

    while ptr1 is not None:
        ptr3.next = ptr1
        ptr1 = ptr1.next
        ptr3 = ptr3.next
    return dummyNode.next


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data)
        temp = temp.next
    print("nullptr")


if __name__ == "__main__":
    lenA = int(input("Enter the length of the first linked list: "))
    lenB = int(input("Enter the length of the second linked list: "))

    data = int(input("Enter the data for the head node of the first list: "))
    head1 = Node(data)
    tail1 = head1

    print("Enter data for the other nodes of the first list: ")
    for _ in range(1, lenA):
        data = int(input())
        tail1.next = Node(data)
        tail1 = tail1.next

    data = int(input("Enter the data for the head node of the second list: "))
    head2 = Node(data)
    tail2 = head2

    print("Enter data for the other nodes of the second list: ")
    for _ in range(1, lenB):
        data = int(input())
        tail2.next = Node(data)
        tail2 = tail2.next

    print("Combined Linked List: ")
    head = mergeSortedLists(head1, head2)
    printLinkedList(head)
