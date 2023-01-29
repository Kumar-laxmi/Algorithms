import java.util.*;
public class CircularLinkList
{  
        public static void main(String[] args) 
        {  
            CircularLinkList Obj = new CircularLinkList();  //Object is created
            Obj.add(11);  
            Obj.add(22);  // Random input or insertion of four Numbers
            Obj.add(33);  
            Obj.add(44);  
            Obj.print();  
        }  
        public class Node
        {  
            int element;  
            Node next;  
            public Node(int element) 
            {  
                this.element = element;  //Current element is stored
            }  
        }  
          
        public Node head = null;  
        public Node tail = null;  
          
        public void add(int element)
        {  
            Node newEle = new Node(element);  
            if(head == null) 
            {  
                head = newEle;  
                tail = newEle;  
                newEle.next = head;         //Address of first and last node is stored
            }  
            else 
            {  
                tail.next = newEle;  
                tail = newEle;  
                tail.next = head;  
            }  
        }  
          
        public void print() 
        {  //print function
            Node current = head;  
            if(head == null) 
            {  
                System.out.println("List is empty");  
            }  
            else
            {  
                System.out.println("Nodes of the circular linked list: ");  
                 do
                 {  
                    System.out.print(" "+ current.element);  
                    current = current.next;  
                    }while(current != head);  
                System.out.println();  
            }  
        }  
    } 
