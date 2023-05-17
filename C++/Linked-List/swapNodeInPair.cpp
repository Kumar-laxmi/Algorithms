/*     problem Statement:-

                -----------Swapping Nodes in a Linked List------
            You are given the head of a linked list, and an integer k.

   Return the head of the linked list after swapping the values of the kth node 
   from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        cout << "deleted Node data: " << this->data << "\n";
        delete this;
    }
};

void insertNode(Node *&head, int d)
{// insert at beginning of the node----
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

int getLength(Node *head)
{       //this finds total no of nodes in given list----
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *swapNodeInPair(Node *head, int k)
{
    // naive approach---
/*
    create two node type pointers pointing toward head. Now traverse through each 
    node. If we reach kth node from beginning then make ptr1 update to that node. Similarly
    if we reach kth node from end then update the ptr2 to that node. Now simply swap the
    value of reached nodes.
*/
    // t.c:- O(n) & auxilary-space:- O(1)
    //As we are traversing complete list without using any extra space
    int n = getLength(head);
    int i = 0;
    Node *ptr1 = head;
    Node *ptr2 = head;
    Node *temp = head;
    while (i < n)
    {
        if (i == k - 1)
        {
            ptr1 = temp;
        }
        if (i == n - k)
        {
            ptr2 = temp;
        }
        temp = temp->next;
        i++;
    }
    swap(ptr1->data, ptr2->data);
    return head;
}

void print(Node *head)
{       //printing the given list---
    
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main()
{

    int n;
    cout << "Enter the length of list  : ";
    cin >> n;
    Node *head = new Node();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(head, x);
    }

    int k;
    cout << "\nEnter the value of k (value after which swapping needs to be done):  ";
     cin >> k;

    cout<<"\ngiven List: ";
     print(head);

    Node *ans = swapNodeInPair(head, k);
    cout<<"\nList after reversing the Kth Node from beginning and kth Node from end :\n";

    print(ans);
    cout<<endl;
    return 0;
}