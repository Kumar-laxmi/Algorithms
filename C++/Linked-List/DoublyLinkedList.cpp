#include <iostream>
#include <stdio.h>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() { head = NULL; }
    void insertEnd(int);
    void insertBeg(int);
    void insertAtPos(int, int);
    void deleteNode(int);
    void searchNode(int);
    void printList();
};

void insertionChoice(LinkedList *list) {
    int c, ele, pos;
    cout << "\nChoose Insertion Position :\n1. Front\n2. After Nth Node\n3. End\n\tMAKE YOUR CHOICE : ";
    cin >> c;
    
    switch(c) {
    case 1: // Front
        cout << "Enter element to be inserted : ";
        cin >> ele;
        list->insertBeg(ele);
        break;

    case 2: // After Nth Position
        cout << "Enter nth position : ";
        cin >> pos;
        cout << "Enter element to be inserted : ";
        cin >> ele;
        list->insertAtPos(pos, ele);
        break;

    case 3: // End
        cout << "Enter element to be inserted : ";
        cin >> ele;
        list->insertEnd(ele);

    default:
        cout << "\n\t*** INVALID INPUT ***";
        break;
    }
}

// insertion method
void LinkedList::insertBeg(int ele) {
    Node *newNode = new Node(ele);
    newNode->next = head; // point newNode's next to list's head
    newNode->prev = NULL; // point newNode's previous to NULL
    if(!head) head->prev = newNode; // point list's head to newNode
    head = newNode; // make newNode as new head
    cout << "\n\tElement inserted successfully at front";
}

void LinkedList::insertAtPos(int pos, int ele) {
    Node *p = head;
    int len = 0;
    while(p) { ++len; p = p->next; } // length of list
    
    // check if position is more than list length
    if(len < pos) { cout << "Index Out Of Range" << endl; return; }

    p = head;
    Node *newNode = new Node(ele);
    while(pos--) p = p->next; // traverse to nth node
    newNode->next = p->next; // point newNode's next to nth node's next
    p->next = newNode; // point nth node's next to newNode
    newNode->prev = p; // point newNode's previous to nth node
    if(newNode->next) newNode->next->prev = newNode; // point newNode's next node's prev back to newNode, if newNode doesn't points to NULL
    
    cout << "\n\tElement inserted successfully";
}

void LinkedList::insertEnd(int ele) {
    Node *newNode = new Node(ele), *p = head;

    // empty list
    if(!head) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(p) p = p->next; // traverse to list end
    p->next = newNode; // point last node's next to newNode
    newNode->prev = p; // point newNode's prev to last node
    
    cout << "\n\tElement inserted successfully at the end";
}

// deletion method
void LinkedList::deleteNode(int pos) {
    Node *p1 = head, *p2 = NULL;
    int length = 0;
    if (!head) { cout << "EMPTY LIST" << endl; return; }
    // list length
    while (p1) { p1 = p1->next; ++length; }

    // check if position is more than list length
    if(length < pos) { cout << "Index Out Of Range" << endl; return; }

    p1 = head;
    // if head node to be deleted
    if(pos == 1) {
        head = head->next;
        delete p1;
        cout << "\n\t!!! ELEMENT DELETED !!!";
        return;
    }
    // delete nth node
    while (pos--) { p2 = p1; p1 = p1->next; }
    p2->next = p1->next;
    delete p1;
    cout << "\n\t!!! ELEMENT DELETED !!!";
    if(p2->next == NULL) p2->next = head; // point back to head
}

// search method
void LinkedList::searchNode(int x) {
    Node *p = head;
    while(p) {
        if(p->data == x) {
            cout << "\n!!! ELEMENT FOUND !!!";
            return;
        }
        p = p->next;
    }
    cout << "\n*** ELEMENT NOT FOUND ***";
}

// print method
void LinkedList::printList() {
    Node *p = head;
    if (head == NULL) { cout << "Empty List" << endl; return; }
    while (p) { cout << p->data << " "; p = p->next; }
}

int main() {
    LinkedList list;
    int n, ele, c;
    char ch = 'y';

    cout << "======= DOUBLY LINKED LIST =======";

    // Input code
    while (ch == 'y') {
        cout << "\nChoose an operation :\n1. Insertion\n2. Deletion\n3. Search\n4. Print";
        cout << "\n\tMAKE YOUR CHOICE : ";
        cin >> c;
        switch(c) {
        case 1: // Insertion
            insertionChoice(&list);
            break;

        case 2: // Deletion
            cout << "\nDELETION\nEnter the position for deletion : ";
            cin >> ele;
            list.deleteNode(ele);
            break;

        case 3: // Searching
            cout << "\nSEARCHING\nEnter the element to be searched : ";
            cin >> ele;
            list.searchNode(ele);
            break;

        case 4: // Print
            cout << "\nList Elements : ";
            list.printList();
            break;

        default:
            cout << "\n\t*** INVALID INPUT ***";
            break;
        }
        cout << "\n\tTry Again ? (y/n) : ";
        cin >> ch;
    }
    return 0;
}