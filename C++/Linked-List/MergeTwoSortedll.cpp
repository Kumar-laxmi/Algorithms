#include <bits/stdc++.h>
using namespace std;

// class for Link list node
class Node
{
public:
    int data;
    Node *next;
};

// takes the node from the front of the source and move it to the front of the dest.
void nodemove(Node **dest, Node **source)
{
    Node *newNode = *source;
    assert(newNode != NULL);
    *source = newNode->next;
    newNode->next = *dest;
    *dest = newNode;
}

// merge two sorted linked list in one bigger soted list
Node *SortedMerge(Node *a, Node *b)
{
    Node dummy;

    Node *tail = &dummy;

    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            nodemove(&(tail->next), &a);
        else
            nodemove(&(tail->next), &b);

        tail = tail->next;
    }
    return (dummy.next);
}

// insert a node at the beginning of the linked list
void push(Node **head, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head);

    (*head) = new_node;
}

// to print nodes in a given linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    // empty linked list
    Node *res = NULL;
    Node *a = NULL;
    Node *b = NULL;

    // // create two linked list
    cout << "Enter values for first linked list (press -1 to stop):" << endl;
    cout << "Linked List 1:- ";
    while (true)
    {
        int input;
        cin >> input;
        if (input == -1)
        {
            break;
        }
        push(&a, input);
    }
    cout << "Linked List 2:- ";
    while (true)
    {
        int input;
        cin >> input;
        if (input == -1)
        {
            break;
        }
        push(&b, input);
    }

    // this will remove duplicates from linked list
    res = SortedMerge(a, b);

    cout << "Merged Linked List is: \n";
    printList(res);

    return 0;
}