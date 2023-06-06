# ====================== Problem Statement ==========================
'''
Here we will take the numbers input from user and with the help of priority queue we need to implement stack.
Priority queue is a special type of queue in which the numbers are dequeue based on their priority. Every no has some priority along with its data.
The data having the highest priority is popped first.
In priority queue, we assign priority to the elements that are being pushed. A stack requires elements to be processed in Last in First Out manner.
The idea is to associate a count that determines when it was pushed. This count works as a key for the priority queue. So the implementation of 
stack uses a priority queue of pairs, with the first element serving as the key.
For ex:
User enters input : 4 1 2
so in queue -> [(2,3) (1,2) (4,1)]

====================== Code with Python ==========================
'''
import heapq
class Stack:
    def __init__(self):
        self.cnt=0 #storing the count of no of elements in queue and act as a key for priority
        self.pq=[]

    def push(self,data):#function to insert element in queue
        self.cnt+=1
        heapq.heappush(self.pq,(self.cnt,data))

    def pop(self):#function to delete element from queue
        if not self.pq:
            print("Empty Stack!!")
        self.pq.pop(self.cnt-1)
        self.cnt-=1

    def top(self):#function to find top element
        if not self.pq:
            print("Empty Stack!!")
            return -1
        else:
            return self.pq[self.cnt-1][1]

print("Enter choice :")
print("1-push 2-pop 3-peek")
choice=int(input())#choice is used to store the value of next function to pe performed
s=Stack()
while(choice!=0):
    if(choice==1):#insert element
        element=input("Enter element : ")
        s.push(element)
    elif(choice==2):#delete element
        s.pop()
    elif(choice==3):#find topmost element
        if s.top()!=-1:
            print(s.top())
    elif(choice==0):#terminate the loop
        break
    else:
        print("Invalid choice")
    print("Enter choice :")
    print("0-To Exit 1-push 2-pop 3-peek")
    choice=int(input())