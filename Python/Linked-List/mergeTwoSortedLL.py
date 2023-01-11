class Node:
  def __init__(self, data = None, next=None): 
    self.data = data
    self.next = next

class LinkedList:
  def __init__(self):  
    self.head = None
  
  def insert(self, data):
    newNode = Node(data)
    if(self.head):
      current = self.head
      while(current.next):
        current = current.next
      current.next = newNode
    else:
      self.head = newNode
  
  def printLL(self):
    current = self.head
    while(current):
      print(current.data)
      current = current.next
#-----------------------Merge function---------------------#
def merge(List_1, List_2):
    head_ptr = temp_ptr = Node() # head_ptr will be the head node of the output list 
    
    while List_1 or List_2:
        if List_1 and (not List_2 or List_1.data <= List_2.data):
            temp_ptr.next = Node(List_1.data)
            List_1 = List_1.next
        else:
            temp_ptr.next = Node(List_2.data)
            List_2 = List_2.next
        temp_ptr = temp_ptr.next
    return head_ptr.next
#----------------------------------------------------------#
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
LL3 = LinkedList()
LL3.head=merge(LL1.head, LL2.head)
LL3.printLL()