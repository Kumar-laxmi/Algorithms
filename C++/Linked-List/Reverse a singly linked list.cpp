Reversing a linked list using iterative approach

#include <iostream>
using namespace std;

// linkedlist node creation
struct Node
{
    int value;
    struct Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

struct linkedlist
{
    Node *head;

    linkedlist()
    {
        head = NULL;
    }

    // reverse function---to reverse the given linked list
    void reverse_llist()
    {
// initializing current, previous and next node
        Node *c = head;
        Node *p = NULL;
        Node *next = NULL;

        while (c != NULL)
        {
            //stroring the next address of current node
            next = c->next;
            //reversing the current node's pointer
            c->next = p;
             //moving the pointer on position ahead
            p = c;
            c = next;
        }
        head = p;
    }
    //Function to print the linkedlist
    void print()
    {
        struct Node *t = head;
        while (t != NULL)
        {
            cout << t->value << " ";
            t = t->next;
        }
    }
//push data into the linked list
    void push(int value)
    {
        Node *t = new Node(value);
        t->next = head;
        head = t;
    }
};

int main(){
    //empty linked list
    linkedlist l;
    l.push(22);
    l.push(88);
    l.push(45);
    l.push(30);
    l.push(14);

    cout<<"The original list is: \n";
    l.print();

    l.reverse_llist();
    cout<<"Linked list after reversal: \n";
    l.print();
    return 0;
}

Time Complexity of reversing a linked list is O(n) 
