// Path: C\Searching\sublist_search.c
// C program to check whether the first list is present in 2nd list or not, when two linked lists are given.
// Time-Complexity: O(M*N), where M is the number of nodes in the second list and N in the first.
// Auxiliary-Space: O(1).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node **head, int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
}

// Function to display a linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
        printf("NULL");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Returns true if first list is present in second list else false
bool isSublist(struct Node *list1, struct Node *list2)
{
    // If list1 and list2 are null (Empty), list1 is sublist of list2
    if (list1 == NULL && list2 == NULL)
    {
        return true;
    }

    // Else, if list1 is null and list2 is not, return false
    if (list1 == NULL)
    {
        return false;
    }

    // current1 is to traverse in list1 and current2 in list2
    struct Node *current1 = list1;
    struct Node *current2 = list2;

    // Traverse the second list by picking nodes one by one
    while (list2 != NULL)
    {
        // Initialize current2 pointer with the current node of the second list
        current2 = list2;

        // Start matching the first list with the second list
        while (current1 != NULL)
        {
            // If the second list becomes empty and the first list does not, return false
            if (current2 == NULL)
            {
                return false;
            }

            // If the data part is the same, go to the next nodes of both lists
            else if (current1->data == current2->data)
            {
                current1 = current1->next;
                current2 = current2->next;
            }

            // If they are not equal, break the loop
            else
            {
                break;
            }
        }

        // Returns True, If list1 is traversed completely (till the end)
        // Indicating that list1 is found
        if (current1 == NULL)
        {
            return true;
        }

        // Initialize cuurent1 pointer with first again
        current1 = list1;

        // Move to the next node of the second list
        list2 = list2->next;
    }

    return false;
}

// program starts here
int main(void)
{
    // Create the first linked list
    struct Node *list1 = NULL;

    // size of list1
    int N;
    printf("No of Nodes in the first list: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int data;
        printf("data %d: ", i + 1);
        scanf("%d", &data);

        insertAtEnd(&list1, data);
    }
    printf("\n");
    // insertAtEnd(&list1, 1);
    // insertAtEnd(&list1, 2);
    // insertAtEnd(&list1, 4);

    // for (int i = 1; i <= 10; i++) {
    // insertAtEnd(&list2, i);
    // }

    // Create the second linked list
    struct Node *list2 = NULL;

    // size of list2
    int M;
    printf("No of Nodes in the second list: ");
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int data;
        printf("data %d: ", i + 1);
        scanf("%d", &data);

        insertAtEnd(&list2, data);
    }
    printf("\n");

    // Display the first linked list
    printf("List 1: ");
    displayList(list1);

    // Display the second linked list
    printf("List 2: ");
    displayList(list2);
    printf("\n");

    // Check if the first list is a sublist of the second list
    bool result = isSublist(list1, list2);
    printf("Is the first list a sublist of the second list? ");

    if (result)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}