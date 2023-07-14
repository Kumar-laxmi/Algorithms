#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *mergeSortedLists(Node *&head1, Node *&head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *dummyNode = new Node(-1);
    Node *p3 = dummyNode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    // Remaining nodes of first list
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    // Remaining nodes of first list
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}

void displayLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int lenA, lenB;
    cout << "Enter the length of first linked list: ";
    cin >> lenA;

    cout << "Enter the length of second linked list: ";
    cin >> lenB;

    // First Linked List

    int data;
    cout << "Enter the data for the head node of first list: ";
    cin >> data;
    Node *head1 = new Node(data);
    Node *tail1 = head1;

    // Inputting the data for the nodes other than head;
    cout << "Enter data for the other nodes of the first list: ";
    for (int i = 1; i < lenA; i++)
    {
        cin >> data;
        tail1->next = new Node(data);
        tail1 = tail1->next;
    }

    // Second Linked List
    cout << "Enter the data for the head node of second list: ";
    cin >> data;
    Node *head2 = new Node(data);
    Node *tail2 = head2;

    // Inputting the data for the nodes other than head;
    cout << "Enter data for the other nodes of the second list: ";
    for (int i = 1; i < lenB; i++)
    {
        cin >> data;
        tail2->next = new Node(data);
        tail2 = tail2->next;
    }

    Node *head = mergeSortedLists(head1, head2);
    displayLinkedList(head);
}
