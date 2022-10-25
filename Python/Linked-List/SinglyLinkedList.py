class Node:
    # constructor
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    # insertion method
    def insertNode(self, ele):
        newNode = Node(ele)
        if(self.head):
            current = self.head
            while(current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode

    # deletion method
    def deleteNode(self, ele):
        p1 = self.head
        # if head node is the element to be deleted
        if p1 is not None:
            if p1.data == ele:
                self.head = p1.next
                p1 = None
                print("!!! ELEMENT DELETED !!!")
                return
        
        # search ele in list
        while p1 is not None:
            if p1.data == ele:
                break
            p2 = p1
            p1 = p1.next
        
        # if element not present in list
        if p1 == None:
            print("*** ELEMENT NOT FOUND ***")
            return
        
        # delete the node
        p2.next = p1.next
        p1 = None

    # search method
    def searchNode(self, ele):
        p1 = self.head
        # head element to be searched
        if p1.data == ele:
            print("!!! ELEMENT FOUND !!!")
            return

        while p1 is not None:
            if p1.data == ele:
                print("!!! ELEMENT FOUND !!!")
                return
            p1 = p1.next
            
        print("*** ELEMENT NOT FOUND ***")
        return

    # print method
    def printList(self):
        current = self.head
        while(current):
            print(current.data, end=" ")
            current = current.next


def main():
    List = LinkedList()
    ch = 'y'
    # input code
    while ch == 'y':
        print("Choose an operation :\n1. Insertion\n2. Deletion\n3. Search\n4. Print\n\tMAKE YOUR CHOICE : ", end="")
        c = int(input())
        # insertion
        if c == 1:
            print("\nINSERTION\nEnter List Size : ", end="")
            n = int(input())
            print("\nEnter List Elements : ", end="")
            eleList = [int(i) for i in input().split()][:n]
            for i in eleList:
                List.insertNode(i)

        # deletion
        elif c == 2:
            print("DELETION\nEnter element for deletion : ", end="")
            ele = int(input())
            List.deleteNode(ele)
        
        # search
        elif c == 3:
            print("SEARCHING\nEnter element to be searched : ", end="")
            ele = int(input())
            List.searchNode(ele)

        # print
        elif c == 4:
            print("List Elements : ", end="")
            List.printList()
        
        else:
            print("\n\t*** INVALID INPUT ***")
        
        ch = input("\n\tTry Again ? (y/n) : ")

main()