/*
                Problem Statement

    LRU Cache Design:-

Cache is the memory very close to CPU and has less access time. Cache is fast but also has less Space compared to RAM. Since it is small we need to have efficient utilization of small size memory. LRU(Least Recently Used) is one of the techniques for this purpose.
In LRU Cache we keep the recently accessed item least recently used item. This can be implemented using Doubly Linked List and Hash Set

    Algorithm:-
=> Look for the page number in Set
=> If found(page hit) then find the node with this page number and move it to the front of the linked list
=> If not found(page miss) then:
    => Insert a new node with this page number at the front of the linked list
    => Insert an entry to the Set
    => If there are no empty frames left then remove the last node from the linked list
    => If there are empty frames left then increase the number of pages by 1

    Example:-
We have the frame size of 4
and we want to add the pages: 10, 20, 30, 10, 40, 50, 30
Initially the Cache will be empty

Page Miss -> If the page which is being added is not present in the cache
Page Hit -> If the page which is being added is present in the cache

For adding each page:-
10 -> Page Miss
Cache: | 10 |
20 -> Page Miss
Cache: | 20 | 10 |
30 -> Page Miss
Cache: | 30 | 20 | 10 |
10 -> Page Hit
Cache: | 10 | 30 | 20 |
40 -> Page Miss
Cache: | 40 | 10 | 30 | 20 |
50 -> Page Miss
Cache: | 50 | 40 | 10 | 30 |
30 -> Page Hit
Cache: | 30 | 50 | 40 | 10 |
*/

#include <stdio.h>
#include <stdlib.h>

#define SET_SIZE 100
#define FRAME_SIZE 4 // Size of the Cache
int set[SET_SIZE];
int pages = 0; // To keep track of number of pages present in LRU cache

// Hash table for Set
int hash_function(int x)
{
    return x % SET_SIZE;
}

// Inserting into hash table
void set_insert(int x)
{
    int index = hash_function(x);
    while (set[index] != 0)
        index = (index + 1) % SET_SIZE;
    set[index] = x;
}

// Removing from hash table
void set_remove(int x)
{
    int index = hash_function(x);
    while (set[index] != x)
        index = (index + 1) % SET_SIZE;
    set[index] = 0;
}

// Search for an element in hash table
int set_contains(int x)
{
    int index = hash_function(x);
    while (set[index] != x)
    {
        index = (index + 1) % SET_SIZE;
        if (set[index] == 0)
            return 0;
    }
    return 1;
}

// A Doubly Linked List Node
struct DllNode
{
    int pageNo;
    struct DllNode *next;
    struct DllNode *prev;
};
typedef struct DllNode *Node;

Node newNode(int x)
{
    Node temp = (Node)malloc(sizeof(struct DllNode));
    temp->pageNo = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Creating LRU cache with appropriate methods
Node mainConstructor()
{
    Node head = newNode(0); // Head for the Linked list
    Node tail = newNode(0); // Tail for the Linked list
    head->next = tail;
    tail->prev = head;
    return head;
}

// Method for adding a page number to the cache
void addPage(Node head, Node tail, int pageNo)
{
    if (set_contains(pageNo))
    {
        // Page Hit condition -> the page number is already present in the cache
        printf("%d -> Page Hit\n", pageNo);
        Node curr = head->next;
        Node start = curr;
        while (curr != tail)
        {
            if (curr->pageNo == pageNo)
            {
                // Remove the page from the cache from its initial position and add it to
                // the staring of the list
                start = curr;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                Node nextCurr = curr->next;
                curr->next = NULL;
                curr->prev = NULL;
                curr = nextCurr;
            }
            else
                curr = curr->next;
        }
        start->next = head->next;
        start->prev = head;
        head->next = start;
        start->next->prev = start;
    }
    else
    {
        // Page Miss condition -> the page number is not present in the cache
        printf("%d -> Page Miss\n", pageNo);
        set_insert(pageNo);
        // Add the new page number to the head of the List
        Node pg = newNode(pageNo);
        pg->next = head->next;
        pg->prev = head;
        head->next = pg;
        pg->next->prev = pg;
        if (pages == FRAME_SIZE)
        {
            // If there is no frames left for the new frame then remove the least recently
            // used page(last page from the list)
            Node rem = tail->prev;
            rem->prev->next = tail;
            tail->prev = rem->prev;
            rem->next = NULL;
            rem->prev = NULL;
            set_remove(pageNo);
        }
        else
            // If there are frames left then increase the number of pages in the cache
            pages++;
    }
}

void displayCache(Node head, Node tail)
{
    if (head->next == tail)
    {
        printf("Empty cache\n");
        return;
    }
    Node curr = head->next;
    printf("\tLRU Cache: | ");
    while (curr != tail)
    {
        printf("%d | ", curr->pageNo);
        curr = curr->next;
    }
    printf("\n\n");
}

int main()
{
    Node head = mainConstructor();
    Node tail = head->next;

    int pageNo;
    printf("\n ----- LRU CACHE -----\n");
    printf("\nEnter -1 to quit process\n\n");

    while (1)
    {
        printf("Enter page number: ");
        scanf("%d", &pageNo);
        if (pageNo == -1)
        {
            printf("Terminating...");
            exit(0);
        }
        addPage(head, tail, pageNo);
        displayCache(head, tail);
    }
}
