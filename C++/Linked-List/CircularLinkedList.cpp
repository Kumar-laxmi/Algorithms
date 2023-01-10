/*

Circular Linked List has the last node pointing to the head of the list, thus forming a circle.

Example : Head --> Node1 --> Node2 --> Node3 --> ... --> LastNode
            ↑                                               ↓
            |_______________________________________________|

Functionalities :
1. Insert Node : Insert a new node in the list
2. Search Node : Perform a linear search on the list to find Nth Node.
3. Delete Nth Node : Delete Nth Node from the list.

*/

#include <iostream> // input output services
using namespace std;

// Node Class which will be a blueprint for all the nodes in the list.
class Node {
public:
    int data; // value held by node
    Node *next; // pointer to the next node
    Node(int data) { // parameterized constructor
        this->data = data; // node value set to data inserted by user
        this->next = NULL; // node points to NULL by default
    }
};

// Linked List Class with head of list and all member functions
class LinkedList {
    Node *head; // pointer to head of list

public:
    LinkedList() { head = NULL; } // unparameterized constructor with head pointing to NULL
    void insertNode(int); // Insert new node
    void deleteNode(int); // Delete nth node from list
    void searchNode(int); // Search a node by value
    void printList(); // Print whole list
} list;

void LinkedList::insertNode(int x) {
    Node *newNode = new Node(x); // newNode decleration by passing value to constructor
    if(!head) { // if empty list (head pointing to NULL)
        head = newNode; // point head pointer to newNode
        return;
    }
    Node *p = head; // traversal pointer
    while(p->next) p = p->next; // traverse to end
    p->next = newNode; // point last node to newNode
    newNode = head; // point newNode back to head node
}

// Deletion method
void LinkedList::deleteNode(int pos) {
    Node *p1 = head, *p2 = NULL; // traversal pointers
    int len = 0; // list length counter
    if(!head) { cout << "EMPTY LIST" << endl; return; }

    while(p1) { ++len; p1 = p1->next; } // find list length

    // check if postion more than list length
    if(len < pos) { cout << "Index Out Of Range" << endl; return; }
    
    p1 = head; // point back to head node
    // if head node to be deleted
    if(pos == 1) {
        head = head->next; // point head pointer to head node's next node
        delete p1; // delete head node (pointed by p1)
        cout << "\n\t!!! ELEMENT DELETED !!!";
        return;
    }
    // delete nth node
    while(pos-- > 1) { p2 = p1; p1 = p1->next; } // traverse to nth node / position
    p2->next = p1->next; // point nth node to next node's next
    delete p1; // delete nth node
    if(p2->next == NULL) p2->next = head; // point back to head if last node deleted
    cout << "\n\t!!! ELEMENT DELETED !!!";
}

// Search method
void LinkedList::searchNode(int key) {
    Node *p = head; // traversal pointer
    while(p) {
        if(p->data == key) { // current node's data equals key
            cout << "\n!!! ELEMENT FOUND !!!";
            return;
        }
        p = p->next; // point to next node
    }
    cout << "\n*** ELEMENT NOT FOUND ***";
}

// Print method
void LinkedList::printList() {
    Node *p = head; // traversal pointer
    if(!head) { cout << "Empty List" << endl; return; } // empty list
    while(p) { cout << p->data << " "; p = p->next; } // print node data and point to next node
}

// Main function
int main() {
    // LinkedList list; // object decleration
    int n, ele, c; // n : number of elements, ele : node value, c : menu choice
    char ch = 'y';

    cout << "======= CIRCULAR LINKED LIST =======";

    // Input code
    while (ch == 'y') {
        cout << "\nChoose an operation :\n1. Insertion\n2. Deletion\n3. Search\n4. Print";
        cout << "\n\tMAKE YOU CHOICE : ";
        cin >> c;
        switch(c) {
        case 1: // Insertion
            cout << "\nINSERTION\nEnter no. of elements : ";
            cin >> n; // input no. of elements to be inserted
            cout << "\nEnter list elements : ";
            // input elements and insert into list
            for (int i = 0; i < n; i++) { cin >> ele; list.insertNode(ele); }
            cout << "\n\tElements Inserted Successfully";
            break;

        case 2: // Deletion
            cout << "\nDELETION\nEnter the position for deletion : ";
            cin >> ele; // input element to be deleted
            list.deleteNode(ele); // function call for deletion
            break;

        case 3: // Searching
            cout << "\nSEARCHING\nEnter the element to be searched : ";
            cin >> ele; // input element to be searched
            list.searchNode(ele); // function call for search
            break;

        case 4: // Print
            cout << "\nList Elements : ";
            list.printList(); // function call for printing list
            break;

        default:
            cout << "\n\t*** INVALID INPUT ***";
            break;
        }
        cout << "\n\tTry Again ? (y/n) : ";
        cin >> ch; // input repeat choice
    }
    return 0;
}

/*

Time Complexity Analysis
========================
▶ Insertion : O(n * listLength)
▶ Deletion : O(listLength + pos)
▶ Search : O(listLength)

where,
n ⇒ No. of elements to be inserted
listLength ⇒ Current length of the list

*/