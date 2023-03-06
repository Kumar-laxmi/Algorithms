// ====================== Problem Statement ==========================
/*
Here we will take the numbers input from user and with the help of priority queue we need to implement stack.
Priority queue is a special type of queue in which the numbers are dequeue based on their priority. Every no has some priority along with its data.
The data having the highest priority is popped first.
In priority queue, we assign priority to the elements that are being pushed. A stack requires elements to be processed in Last in First Out manner.
The idea is to associate a count that determines when it was pushed. This count works as a key for the priority queue. So the implementation of 
stack uses a priority queue of pairs, with the first element serving as the key.
For ex:
User enters input : 4 1 2
so in queue -> [(2,3) (1,2) (4,1)]
*/

// // ====================== Code with Java ==========================

import java.util.PriorityQueue;
import java.util.Scanner;
class Main
{
 
  // count is used as key for the priority queue.
  int count;
  PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0]-a[0]);
 
  public Main() {
    count = 1;
  }
  
  public boolean isEmpty() {
    return pq.isEmpty();
  }
  //function to insert element in queue
  public void push(int n) {
    int[] arr = new int[]{ count++,n }; 
    pq.add(arr);
  }
 
  //function to delete element from queue
  public void pop() {
    if (pq.isEmpty()) {
      System.out.println("Empty Stack");
      return;
    }
    count--;
    pq.poll();
  }
  
  //function to find top element
  public int top(){
    if (pq.isEmpty()) {
      System.out.println("Empty Stack");
      return -1;
    }
    int[] temp = pq.peek();
    return temp[1];
  }
 
  
 
  public static void main(String[] args) {
    Main s = new Main();
    int choice;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter your choice : ");
    System.out.println("1-push 2-pop 3-peek");
    choice = sc.nextInt();//choice is used to store the value of next function to pe performed
    int element;
    while(choice!=0){
        if(choice==1){//insert element
            System.out.println("Enter element : ");
            element=sc.nextInt();
            s.push(element);
        }
        else if(choice==2){//delete element
            s.pop();
        }
        else if(choice==3){//find topmost element
            if(s.top()!=-1)
            System.out.println(s.top());
        }
        else{//terminate the loop
            System.out.println("Invalid choice!");
        }
        System.out.println("Enter your choice : ");
        System.out.println("0-Exit 1-push 2-pop 3-peek");
        choice = sc.nextInt();
    }
  }
}
