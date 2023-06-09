// Addition of 2 Linked List in Java.
/*
    * Problem:-
    * Given two non-empty linked lists representing two non-negative integers.
    * The digits are stored in reverse order, and each of their nodes contains a
    * single digit.
    * Add the two numbers and return the sum as a linked list.The two numbers do
    * not contain any leading zero, except the number 0 itself.
    * 
    * Problem Link :- https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
    * Time complexity
    * O(n+m)-> Where, n is length of l1 and m is length of l2. Thus, it is equal to
    * max of n and m
    * 
    * Space complexity
    * O(n)--> In creating another linked list where answer is stored
    * 
    * Ex:-
    * Input: l1 = [2,4,3], l2 = [5,6,4]
    * Output: [7,0,8]
    * Explanation: 342 + 465 = 807.
 */
import java.util.*;
public class Add2LinkedList
{
    static class Node 
   {
       int data;
       Node next;
       Node(int d)
       {
           data = d;
           next = null;
       }
   }
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the size of the first list : ");
            int n = sc.nextInt();
            System.out.println("Enter the list 1 values : ");
            int val = sc.nextInt();
            Node first = new Node(val);
            Node tail = first;
            for(int i=0;i<n-1;i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            System.out.print("Enter the size of the second list : ");
            int m = sc.nextInt();
            System.out.println("Enter the list 2 values : ");
            val = sc.nextInt();
            Node second = new Node(val);
            tail = second;
            for(int i=0;i<m-1;i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            Node res = addTwoLists(first, second);
            printList(res);
    }
    static void printList(Node n)
    {
        System.out.print("Sum = ");
        while(n!=null)
        {
            System.out.print(n.data);
            n = n.next;
        }
        System.out.println();
    }
    //Function to add two numbers represented by linked list.
    static Node addTwoLists(Node first, Node second){
        // code here
        // return head of sum list
        // Step 1 reverse Linked List 1 
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        Node result = null;
        Node start = null;
        while(first!=null && second!=null)
        {
            
            int sum = first.data + second.data + carry;
            Node newnode = new Node(sum%10);
            carry = sum/10;
            if(result == null){
                start = newnode;
                result = newnode;
            }
            else 
            {
                result.next = newnode;
                result = newnode;
            }
            first = first.next;
            second = second.next;
        }
        while(first!=null)
        {
            int sum = first.data + carry;
            Node newnode = new Node(sum%10);
            carry = sum/10;
            if(result == null){
                result = newnode;
                start = newnode;
            }
            else 
            {
                result.next = newnode;
                result = newnode;
            }
            first = first.next;
        }
        while(second!=null)
        {
            int sum = second.data + carry;
            Node newnode = new Node(sum%10);
            carry = sum/10;
            if(result == null){
                result = newnode;
                start = newnode;
            }
            else 
            {
                result.next = newnode;
                result = newnode;
            }
            second = second.next;
        }
        if(carry == 1)
        {
            Node newnode = new Node(1);
            result.next = newnode;
            result = newnode;
        }
        result = reverse(start);
        return result;
    }
    static Node reverse(Node first)
    {
        // This function is used to reverse the linked list it takes around T.C = O(N)
        Node prev = null;
        Node curr = first;
        Node next1 = first;
        while(curr!=null)
        {
            next1 = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
}
