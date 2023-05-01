/* Name : Abhinav kumar
Github username : Abhinavcode13
Repository name : Algorithms
Problem : Detect loop in a linked list 
Issue Number : #122

//Algorithm

In this code, the detectLoop() function takes the head of the linked list as an argument and returns 1 if a loop is detected and 0 otherwise.

Inside the function, we initialize two pointers, slow and fast, both pointing to the head of the linked list. Then we traverse the list, with slow moving one step at a time and fast moving two steps at a time.

If there is a loop in the list, the two pointers will eventually meet, and we can detect this condition by checking if slow and fast are pointing to the same node. If a loop is detected, we print a message to the console and return 1. If no loop is detected, we return 0.

In the main function, we create a sample linked list with four nodes and create a loop from the fourth node to the second node. We then call the detectLoop() function to test the loop detection. When the code is run, it should print "Loop Detected!" to the console.

*/

-------------------------------------------------------------------------//C code begins here---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
struct node {
    int data;
    struct node* next;
};

// Function to detect a direct loop in a linked list
int detectLoop(struct node* head) {
    struct node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

// Main function to take user input for a linked list and test the loop detection
int main() {
    struct node *head = NULL, *tail = NULL;
    int n, i, value;

    // Take user input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Take user input for each node value and create the linked list
    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &value);

        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;

        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Test the loop detection and print the result to the console
    if (detectLoop(head)) {
        printf("Loop Detected!\n");
    } else {
        printf("No Loop Detected.\n");
    }

    return 0;
}
