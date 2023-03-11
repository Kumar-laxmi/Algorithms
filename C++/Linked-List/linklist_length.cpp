/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms*/
#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* next;
};
// Function to find the length of a singly linked list
int findLength(Node* head) 
{
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int main()
{
    // Creating an empty linked list
    Node* head = NULL;
    // Reading input from the user to create the linked list
    cout << "Enter the number of nodes in the linked list: ";
    int n;
    cin >> n;
    if (n > 0) 
    {
        cout << "Enter the data for each node: ";
        Node* prev = NULL;
        for (int i = 0; i < n; i++) {
            Node* current = new Node;
            cin >> current->data;
            current->next = NULL;
            if (prev == NULL) {
                head = current;
            } else {
                prev->next = current;
            }
            prev = current;
        }
    }
    // Finding the length of the linked list
    int length = findLength(head);
    // Printing the length of the linked list
    cout << "Length of the linked list is: " << length << endl;
    return 0;
}