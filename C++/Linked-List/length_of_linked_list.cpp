/*
Algorithm:
    1. Initialize a counter variable to 0.
    2. Start at the head of the linked list.
    3. While the current node is not None:
     a. Increment the counter variable by 1.
     b. Set the current node to the next node in the list.
    4. Return the final value of the counter variable as the length of the linked list.
Input:
    An arbitraty number of inputs asking for the data in the nodes of the linked list.
    If nothing is entered in data value for the node, the code will give us output.
Output:
    Output is the number of nodes present in the created linked list.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Define the Node class to represent a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) { // Constructor to create a new node with the given data value
        this->data = data;
        this->next = nullptr;
    }
};

// Define the LinkedList class to represent the entire list
class LinkedList {
public:
    Node* head;

    LinkedList() { // Constructor to initialize the list's head pointer to nullptr
        this->head = nullptr;
    }

    void append(int data) { // Method to append a new node to the end of the list
        Node* new_node = new Node(data); // Create a new node with the given data value
        if (this->head == nullptr) { // If the list is empty, set the head pointer to the new node
            this->head = new_node;
            return;
        }
        Node* current_node = this->head; // Otherwise, traverse the list to find the last node
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = new_node; // Set the last node's next pointer to the new node
    }

    int length() { // Method to find the length of the list
        int count = 0; // Initialize a counter variable to 0
        Node* current_node = this->head; // Start at the head of the list
        while (current_node) { // Traverse the list until the end is reached
            count++; // Increment the counter for each node visited
            current_node = current_node->next;
        }
        return count; // Return the final value of the counter
    }
};

int main() {
    LinkedList my_list; // Create a new linked list
    string input;
    int data;
    while (true) {
        cout << "Enter a data value to add to the list (or enter to stop): ";
        getline(cin, input);
        if (input.empty()) { // If the user hits enter, stop adding nodes
            break;
        }
        stringstream ss(input); // Convert the input string to an integer
        ss >> data;
        my_list.append(data); // Add the data value to the list
    }
    int length = my_list.length(); // Find the length of the list
    cout << "The length of the list is: " << length << endl; // Print the result
    return 0;
}
