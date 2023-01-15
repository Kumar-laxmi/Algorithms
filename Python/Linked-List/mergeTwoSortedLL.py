class Node:
  def __init__(self, data = None, next=None): 
    self.data = data
    self.next = next

class LinkedList:
  def __init__(self):  
    self.head = None
  
  def insert(self, data):
    # create a new node with the data 
    newNode = Node(data)
    # if there is already a head node, traverse the list until the last node 
    if(self.head):
      current = self.head
      while(current.next):
        current = current.next
      # insert the new node as the next node of the last node 
      current.next = newNode
    else:
      # if there is no head node, insert the new node as the head node
      self.head = newNode
  
  def printLL(self):
    # traverse the list and print the data of each node
    current = self.head
    while(current):
      print(current.data)
      current = current.next

# Create a function to merge two linked lists
def merge(List_1, List_2):
    # create a dummy node as the head of the output list 
    head_ptr = temp_ptr = Node() 
    # while there are still nodes in both linked lists
    while List_1 or List_2:
        # if there is a node in List_1 and (either there is no node in List_2 or the node in List_1 is smaller)
        if List_1 and (not List_2 or List_1.data <= List_2.data):
            # insert the node from List_1 into the output list
            temp_ptr.next = Node(List_1.data)
            # move to the next node in List_1
            List_1 = List_1.next
        else:
            # insert the node from List_2 into the output list
            temp_ptr.next = Node(List_2.data)
            # move to the next node in List_2
            List_2 = List_2.next
        # move to the next node in the output list
        temp_ptr = temp_ptr.next
    # return the head of the output list
    return head_ptr.next

# create two linked lists and insert some values
LL1 = LinkedList()
LL1.insert(2)
LL1.insert(4)
LL1.insert(6)
LL1.insert(8)
LL2 = LinkedList()
LL2.insert(1)
LL2.insert(3)
LL2.insert(5)
LL2.insert(7)

# merge the two linked lists
LL3 = LinkedList()
LL3.head = merge(LL1.head, LL2.head)

# print the merged list
LL3.printLL()
