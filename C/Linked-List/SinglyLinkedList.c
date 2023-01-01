#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertAtEnd(int);
struct node
{
    int data;
    struct node *next;
} *start = NULL;
void createList(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter data of node %d:- ", i + 1);
        insertAtEnd(1);
    }

    printf("\nSUCCESSFULLY CREATED\n");
};
void traverse()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nEmpty Linked List");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
};
struct node *elementSearch(int s, int skey)
{
    int key = 0;
    struct node *ptr, *preptr; // preptr for before and after insert;
    if (start == NULL)
    {
        printf("\nEmpty Linked List");
        return 0;
    }
    ptr = start;
    preptr = start;
    while (ptr != NULL)
    {

        if (ptr->data == s)
        {
            key = 1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    if (key == 1)
    {
        printf("\nElement found! at memory address %d\n", ptr);
    }
    else
    {
        printf("\nElement not found!\n");
        return 0;
    }
    if (skey == 1)
    {

        return preptr;
    }
    else
        return ptr;
}
void insertAtBeginning()
{
    struct node *nptr;
    int data;
    nptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to assign at beginning:- ");
    scanf("%d", &nptr->data);
    if (start == NULL)
    {
        nptr->next = NULL;
        start = nptr;
        return;
    }
    nptr->next = start;
    start = nptr;
    printf("\nSUCCESSFULLY ADDED \n");
};
void insertAtEnd(int key)
{
    struct node *nptr, *ptr;
    nptr = (struct node *)malloc(sizeof(struct node));
    nptr->next = NULL;
    if (key == 0)
    {
        printf("\nEnter element to assign at the end:- ");
    }
    scanf("%d", &nptr->data);

    if (start == NULL)
    {
        if (key == 0)
        {
            printf("\nLinked list is empty so inserted at first\n");
        }
        start = nptr;
        return;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = nptr;

    if (key == 0)
        printf("\nSUCCESSFULLY ADDED \n");
};
void insertBefGivNode()
{
    int el;
    struct node *preptr, *nptr;
    nptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element before which you want to insert a node:- ");
    scanf("%d", &el);
    preptr = elementSearch(el, 1);
    if (preptr == 0)
        return;
    printf("\nEnter element to enter:- ");
    scanf("%d", &nptr->data);
    if (preptr == start)
    {
        nptr->next = start;
        start = nptr; // or start=nptr
    }
    else
    {
        nptr->next = preptr->next;
        preptr->next = nptr;
    }
    printf("\nSUCCESSFULLY ADDED \n");
};
void insertAftGivNode()
{
    int el;
    struct node *aftptr, *nptr;
    nptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element after which you want to insert a node:- ");
    scanf("%d", &el);
    aftptr = elementSearch(el, 0);
    if (aftptr == 0)
        return;
    printf("\nEnter element to enter:- ");
    scanf("%d", &nptr->data);
    if (aftptr == start)
    {
        start->next = nptr;
        nptr->next = NULL;
    }
    else
    {
        nptr->next = aftptr->next;
        aftptr->next = nptr;
    }
    printf("\nSUCCESSFULLY ADDED \n");
};

void delAtStart()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nEmpty linked list(underflow)");
        return;
    }
    ptr = start;
    start = start->next;

    printf("\nData deleted = %d\n", ptr->data);

    /* Clears the memory occupied by first node*/
    free(ptr);

    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
};
void delAtEnd()
{
    struct node *ptr, *preptr;
    if (start == NULL)
    {
        printf("\nEmpty linked list(underflow)");
        return;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;

    printf("\nData deleted = %d\n", ptr->data);

    /* Clears the memory occupied by first node*/
    free(ptr);

    printf("SUCCESSFULLY DELETED LAST NODE FROM LIST\n");
}

void delGivNode()
{
    struct node *ptr, *preptr;
    int toDelete, key = 0;
    if (start == NULL)
    {
        printf("\nEmpty linked list(underflow)");
        return;
    }
    printf("\nEnter element to delete:- ");
    scanf("%d", &toDelete);
    ptr = start;
    while (ptr->next != NULL)
    {
        if (ptr->data == toDelete)
            break;
        preptr = ptr;
        key = 1;
        ptr = ptr->next;
    }
    if (ptr == start)
    {
        printf("\nData deleted = %d\n", ptr->data);

        /* Clears the memory occupied by first node*/
        start = NULL;
        printf("SUCCESSFULLY DELETED LAST NODE FROM LIST\n");
        return;
    }
    if (key == 1)
    {
        preptr->next = ptr->next;
        printf("\nData deleted = %d\n", ptr->data);

        /* Clears the memory occupied by first node*/
        free(ptr);

        printf("SUCCESSFULLY DELETED LAST NODE FROM LIST\n");
    }
    else
    {
        printf("\nElement not found in LL");
    }
};

int main()
{
    int ch;
    char Opr[][31] = {"Create a List", "Traversal", "Searching in a list", "Insertion at the beginning", "Insertion at the end", "Insert before the given Node", "Insert after the given Node ", "Delete the first node", "Delete the last node", "Delete the given node", "Exit"};
    do
    {
        printf("\n*****Main Menu*****\n");
        for (int i = 0; i < sizeof(Opr) / 31; i++)
            printf("%d. %s\n", i, Opr[i]);
        printf("                        Enter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
        {
            int n;
            printf("\nEnter no. of node :- ");
            scanf("%d", &n);
            createList(n);
            break;
        }
        case 1:
        {
            traverse();
            break;
        }
        case 2:
        {
            int s, skey = -1;
            printf("\nEnter element to search :- ");
            scanf("%d", &s);
            elementSearch(s, skey); // skey=search key for before and after insert
            break;
        }
        case 3:
        {
            insertAtBeginning();
            break;
        }
        case 4:
        {
            insertAtEnd(0);
            break;
        }
        case 5:
        {
            insertBefGivNode();
            break;
        }
        case 6:
        {
            insertAftGivNode();
            break;
        }
        case 7:
        {
            delAtStart();
            break;
        }
        case 8:
        {
            delAtEnd();
            break;
        }
        case 9:
        {
            delGivNode();
            break;
        }
        default:
        {
            if (ch > 10 || ch < 0)
                printf("\nWrong selection!\n");
        }
        }
    } while (ch != 10);
    return 0;
}
