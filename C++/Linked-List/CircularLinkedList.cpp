#include <iostream>
#include <stdio.h>
using namespace std;
class Node {
public:
    int data;
    Node *next;
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
    void insertNode(int);
    void deleteNode(int);
    void searchNode(int);
    void printList();
};

// insertion method
void LinkedList::insertNode(int x) {
    Node *newNode = new Node(x);
    if(!head) {
        head = newNode;
        return;
    } // if empty list
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode = head;
}

// deletion method
void LinkedList::deleteNode(int pos) {
    Node *p1 = head, *p2 = NULL;
    int length = 0;
    if (!head) { cout << "EMPTY LIST" << endl; return; }
    // list length
    while (p1) { p1 = p1->next; ++length; }

    // check if postion more than list length
    if (length < pos) { cout << "Index Out Of Range" << endl; return; }

    p1 = head;
    // if head node to be deleted
    if (pos == 1) {
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

    cout << "======= CIRCULAR LINKED LIST =======";

    // Input code
    while (ch == 'y') {
        cout << "\nChoose an operation :\n1. Insertion\n2. Deletion\n3. Search\n4. Print";
        cout << "\n\tMAKE YOU CHOICE : ";
        cin >> c;
        switch (c) {
        case 1: // Insertion
            cout << "\nINSERTION\nEnter List Size : ";
            cin >> n;
            cout << "\nEnter List Elements : ";
            for (int i = 0; i < n; i++) { cin >> ele; list.insertNode(ele); }
            cout << "\n\tElements Inserted Successfully";
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