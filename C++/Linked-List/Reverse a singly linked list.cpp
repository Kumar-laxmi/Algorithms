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
            next = c->next;
            c->next = p;
            p = c;
            c = next;
        }
        head = p;
    }
    void print()
    {
        struct Node *t = head;
        while (t != NULL)
        {
            cout << t->value << " ";
            t = t->next;
        }
    }

    void push(int value)
    {
        Node *t = new Node(value);
        t->next = head;
        head = t;
    }
};

int main(){
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
