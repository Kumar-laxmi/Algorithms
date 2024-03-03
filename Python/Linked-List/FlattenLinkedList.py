# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.bottom = None
#Printing Linked List
def printLinkedList(node):
    while node:
        print(node.data, end=" ")
        node = node.bottom

def FlattenLinkedList(root):
    #  Initialize the head pointers
    head1 = root
    head2 = root.next
    root = root.next
# Initialize head and tail for the new flattened list
    while root:
        head = None
        tail = None

        # Merge the two sorted linked lists
        while head1 and head2:
            if head1.data < head2.data:
                new_node = Node(head1.data)
                if not head and not tail:
                    head = new_node
                    tail = new_node
                else:
                    tail.bottom = new_node
                    tail = tail.bottom
                head1 = head1.bottom
            else:
                new_node = Node(head2.data)
                if not head and not tail:
                    head = new_node
                    tail = new_node
                else:
                    tail.bottom = new_node
                    tail = tail.bottom
                head2 = head2.bottom

        # Append the remaining nodes of the linked lists
        while head1:
            new_node = Node(head1.data)
            if not head and not tail:
                head = new_node
                tail = new_node
            else:
                tail.bottom = new_node
                tail = tail.bottom
            head1 = head1.bottom

        while head2:
            new_node = Node(head2.data)
            if not head and not tail:
                head = new_node
                tail = new_node
            else:
                tail.bottom = new_node
                tail = tail.bottom
            head2 = head2.bottom

        # Move to the next level
        root = root.next
        head1 = head
        head2 = root

    return head1

if __name__ == "__main__":
    t = int(input("Enter No of attempts: "))

    while t > 0:
        n = int(input("Enter size of horizontal Linkedlist: "))
        work = []
        print("Elements in Horizontal Linkedlist: ")
        for _ in range(n):
            work.append(int(input()))

        temp = None
        head = None
        pre = None
        tempB = None
        preB = None
        flag = 1
        flag1 = 1

        # Create the horizontal linked list with bottom linked lists
        for i in range(n):
            m = work[i]
            m -= 1
            print("Enter Head For Bottom LinkedList: ", end="")
            data = int(input())
            temp = Node(data)
            temp.next = None
            temp.bottom = None

            if flag == 1:
                head = temp
                pre = temp
                flag = 0
                flag1 = 1
            else:
                pre.next = temp
                pre = temp
                flag1 = 1

            print("Enter Bottom Linkedlist Elements: ")
            for _ in range(m):
                temp_data = int(input())
                tempB = Node(temp_data)

                if flag1 == 1:
                    temp.bottom = tempB
                    preB = tempB
                    flag1 = 0
                else:
                    preB.bottom = tempB
                    preB = tempB

        root = FlattenLinkedList(head)
        printLinkedList(root)
        print()

        t -= 1
