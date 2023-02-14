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

#include <iostream>
#include <unordered_set>
using namespace std;

// A Doubly Linked List Node
class Node
{
public:
    int pageNo;
    Node *next;
    Node *prev;

    Node(int pageNo)
    {
        this->pageNo = pageNo;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Creating LRU cache with appropriate methods
class LRUCache
{
private:
    int frameSize;          // Size of the Cache
    int pages;              // To keep track of number of pages present in LRU cache
    Node *head;             // Head for the Linked list
    Node *tail;             // Tail for the Linked list
    unordered_set<int> set; // To check if LRU cache contains the page number

public:
    LRUCache(int frameSize)
    {
        this->frameSize = frameSize;
        this->pages = 0;
        this->head = new Node(0);
        this->tail = new Node(0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->head->prev = NULL;
        this->tail->next = NULL;
    }

    // Method for adding a page number to the cache
public:
    void addPage(int pageNo)
    {
        if (set.find(pageNo) != set.end())
        {
            // Page Hit condition -> the page number is already present in the cache
            cout << pageNo << " -> Page Hit" << endl;
            Node *curr = head->next;
            Node *start = curr;
            while (curr != tail)
            {
                if (curr->pageNo == pageNo)
                {
                    // Remove the page from the cache from its initial position and add it to
                    // the staring of the list
                    start = curr;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    Node *nextCurr = curr->next;
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
            cout << pageNo << " -> Page Miss" << endl;
            set.insert(pageNo);
            // Add the new page number to the head of the List
            Node *pg = new Node(pageNo);
            pg->next = head->next;
            pg->prev = head;
            head->next = pg;
            pg->next->prev = pg;
            if (pages == frameSize)
            {
                // If there is no frames left for the new frame then remove the least recently
                // used page(last page from the list)
                Node *rem = tail->prev;
                rem->prev->next = tail;
                tail->prev = rem->prev;
                rem->next = NULL;
                rem->prev = NULL;
                set.erase(rem->pageNo);
            }
            else
                // If there are frames left then increase the number of pages in the cache
                pages++;
        }
    }

    void displayCache()
    {
        if (head->next == tail)
        {
            cout << "Empty Cache" << endl;
            return;
        }
        Node *curr = head->next;
        cout << "\tLRU Cache: | ";
        while (curr != tail)
        {
            cout << curr->pageNo << " | ";
            curr = curr->next;
        }
        cout << "\n"
             << endl;
    }
};

int main()
{
    LRUCache cache(4);

    cout << "\n ----- LRU CACHE ----- " << endl;
    int pageNo;
    cout << "\nEnter -1 to quit process\n"
         << endl;
    while (1)
    {
        cout << "Enter page number: ";
        cin >> pageNo;
        if (pageNo == -1)
        {
            cout << "Terminating..." << endl;
            exit(0);
        }
        cache.addPage(pageNo);
        cache.displayCache();
    }
}
