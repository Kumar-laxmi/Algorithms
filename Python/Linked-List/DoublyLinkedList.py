class Node:
  def __init__(self, data=None, next=None, prev=None):
    self.data = data
    self.next = next
    self.prev = prev
    
class Linkedlist:
  def __init__(self):
    self.head = None
    
if __name__ == "__main__":
  list = Linkedlist()
  list.head = Node(1)
  list.second = Node(2)
  list.third = Node(3)
  
  list.head.next = list.second
  list.head.prev = None
  
  list.second.next = list.third
  list.second.prev = list.head
  
  list.third.next = None
  list.third.prev = list.second
