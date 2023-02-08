#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

void MoveNode(struct Node **destRef,
              struct Node **sourceRef);

// takes two sorted linked list in increasing order and make new linked list by merging
struct Node *SortedMerge(struct Node *a, struct Node *b)
{
    struct Node dummy;

    struct Node *tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return (dummy.next);
}

// pull of the front node of the source and put it in dest
void MoveNode(struct Node **destRef,
              struct Node **sourceRef)
{
    struct Node *newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;

    newNode->next = *destRef;

    *destRef = newNode;
}

// Function to insert a node at the beginning of the linked list
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

// to print nodes in a given linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    //  empty list
    struct Node *res = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;

    // create two sorted linked lists
    // push(&a, 15);
    // push(&a, 10);
    // push(&a, 5);

    // push(&b, 20);
    // push(&b, 3);
    // push(&b, 2);
    int input1;
    printf("Enter values for first linked list (press -1 to stop):\n");
    while (1)
    {
        scanf("%d", &input1);
        if (input1 == -1)
        {
            break;
        }
        push(&a, input1);
    }

    int input;
    printf("Enter values for second linked list (press -1 to stop):\n");
    while (1)
    {
        scanf("%d", &input);
        if (input == -1)
        {
            break;
        }
        push(&b, input);
    }

    // Remove duplicates from linked list
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}