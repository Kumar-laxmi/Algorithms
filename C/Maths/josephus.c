#include <stdio.h>
#include <stdlib.h>

// Josephus Problem Algorithm:
// 1. Create a circular linked list to represent the circle of people.
// 2. Initialize the linked list with people numbered from 1 to n.
// 3. Start with a pointer pointing to the first person.
// 4. Repeat the elimination process until only one person remains:
//     a. Move the pointer k-1 steps in a circular manner.
//     b. Remove the person at the current position.
//     c. Update the pointer to the next position after the elimination, wrapping around if necessary.
// 5. Return the position of the last remaining person.

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int josephus(int n, int k) {
    Node* head = NULL;
    Node* prev = NULL;

    // Create the circular linked list with people numbered from 1 to n
    for (int i = 1; i <= n; ++i) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
    }

    // Make the linked list circular
    prev->next = head;

    Node* curr = head;

    // Elimination process
    while (n > 1) {
        // Move the pointer k-1 steps in a circular manner
        for (int count = 1; count < k; ++count) {
            prev = curr;
            curr = curr->next;
        }

        // Remove the person at the current position
        prev->next = curr->next;
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
        --n;
    }

    int lastPerson = curr->data;

    // Free the remaining node
    free(curr);

    return lastPerson;
}

int main() {
    int n, k;
    
    // User input for n and k
    printf("Enter the number of people in the circle: ");
    scanf("%d", &n);
    printf("Enter the elimination step size: ");
    scanf("%d", &k);

    int lastPerson = josephus(n, k);  // Solve the Josephus Problem
    printf("The last remaining person is at position: %d\n", lastPerson);

    return 0;
}
