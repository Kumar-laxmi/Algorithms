/*
Algorithm:
    1. Initialize a counter variable to 0.
    2. Start at the head of the linked list.
    3. While the current node is not None:
     a. Increment the counter variable by 1.
     b. Set the current node of the linked list to the next node in the linked list.
    4. Return the final value of the counter variable as the length of the linked list.
Input:
    An arbitraty number of inputs asking for the data in the nodes of the linked list.
    If nothing is entered in data value for the node, the code will give us output.
Output:
    Output is the number of nodes present in the created linked list.
*/

#include <stdio.h>
#include <stdlib.h>

/* Define the Node struct to represent a single node in the linked list */
struct Node {
    int data;          // Set the data value in the node
    struct Node* next; // Initialize the node's next pointer to NULL
};

/* Define the LinkedList struct to represent the entire linked list */
struct LinkedList {
    struct Node* head; // Initialize the list's head pointer to NULL
};

/* Define a function to append a new node to the end of the list */
void append(struct LinkedList* list, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Create a new node with the given data value
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) { // If the list is empty, set the head pointer to the new node
        list->head = new_node;
        return;
    }
    struct Node* current_node = list->head; // Otherwise, traverse the list to find the last node
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node; // Set the last node's next pointer to the new node of the linked list
}

/* Define a function to find the length of the obtained linked list */
int length(struct LinkedList* list) {
    int count = 0; // Initialize the counter variable to 0
    struct Node* current_node = list->head; // Start at the head of the linked list
    while (current_node != NULL) { // Traverse the linked list until the end is reached
        count++; // Increment the counter for each node visited
        current_node = current_node->next;
    }
    return count; // Return the final value of the counter
}

int main() {
    struct LinkedList my_list = {NULL}; // Create a new linked list with a NULL head pointer
    int data;
    while (1) {
        printf("Enter a data value to add to the list (or press enter to stop): ");
        char input[100];
        fgets(input, 100, stdin);
        if (input[0] == '\n') { // If the user presses enter without entering any data, stop adding nodes
            break;
        }
        data = atoi(input); // Convert the user input to an integer and add it to the list
        append(&my_list, data);
    }
    int list_length = length(&my_list); // Find the length of the list
    printf("The length of the list is: %d\n", list_length); // Print the result
    return 0;
}
