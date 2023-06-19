#Addition of two Linked-List Number Python #1317

# The code defines a class named ListNode, representing a node of the linked list. Each node has an integer value (val) and a reference to the next node (next)
# The addTwoNumbers function is responsible for adding two numbers represented as linked lists. However, the logic for addition is not implemented and needs to be completed based on the requirements.
# The printList function is used to print the values of the nodes in a linked list.
# The makeList function is used to create a linked list with a given number of nodes. It takes input from the user and constructs the linked list accordingly.
# The user is prompted to enter the number of digits in the first and second linked lists.
# The makeList function is called to create the respective linked lists based on the user input.
# The addTwoNumbers function is called with the two linked lists as parameters to perform the addition.
# Finally, the result is printed using the printList function.
#Sample Input:
# 5
# 1 0 3 2 5
# 3
# 1 2 4
# Sample Output:
# 1 0 3 5 8
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def addTwoNumbers(l1, l2):
    l1 = reverseList(l1)
    l2 = reverseList(l2)

    dummy = ListNode(0)
    current = dummy
    carry = 0

    while l1 or l2:
        sum = carry

        if l1:
            sum += l1.val
            l1 = l1.next

        if l2:
            sum += l2.val
            l2 = l2.next

        digit = sum % 10
        carry = sum // 10

        current.next = ListNode(digit)
        current = current.next

    if carry > 0:
        current.next = ListNode(carry)

    return reverseList(dummy.next)


def reverseList(head):
    prev = None
    current = head

    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    return prev


def makeList(n):
    dummy = ListNode(-1)
    prev = dummy

    values = input("Enter the values of the nodes (separated by spaces): ").split()
    for i in range(n):
        val = int(values[i])
        prev.next = ListNode(val)
        prev = prev.next

    return dummy.next


def printList(node):
    while node:
        print(node.val, end=" ")
        node = node.next
    print()


def main():
    exit = False

    while not exit:
        print("Menu:")
        print("1. Add two numbers represented as linked lists")
        print("2. Exit")

        choice = int(input("Enter your choice: "))
        print()

        if choice == 1:
            n1 = int(input("Enter the number of digits in the first linked list: "))
            head1 = makeList(n1)

            n2 = int(input("Enter the number of digits in the second linked list: "))
            head2 = makeList(n2)

            result = addTwoNumbers(head1, head2)

            print("Result: ", end="")
            printList(result)
            print()

        elif choice == 2:
            exit = True

        else:
            print("Invalid choice! Please try again.\n")


if __name__ == "__main__":
    main()
