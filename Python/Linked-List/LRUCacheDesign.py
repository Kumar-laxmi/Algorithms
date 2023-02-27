"""
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
"""


class Node:
    def __init__(self, pageNo):
        self.pageNo = pageNo
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, frameSize):
        self.frameSize = frameSize  # Size of the Cache
        self.pages = 0  # To keep track of number of pages present in LRU cache
        self.set = set()  # To check if LRU cache contains the page number
        self.head = Node(0)  # Head for the Linked list
        self.tail = Node(0)  # Tail for the Linked list
        self.head.next = self.tail
        self.tail.prev = self.head

    def addPage(self, pageNo):
        if pageNo in self.set:
            # Page Hit condition -> the page number is already present in the cache
            print(f'{pageNo} -> Page Hit')
            curr = self.head.next
            start = curr
            while curr != self.tail:
                if curr.pageNo == pageNo:
                    # Remove the page from the cache from its initial position and add it to
                    # the staring of the list
                    start = curr
                    curr.prev.next = curr.next
                    curr.next.prev = curr.prev
                    nextCurr = curr.next
                    curr.next = None
                    curr.prev = None
                    curr = nextCurr
                else:
                    curr = curr.next
            start.next = self.head.next
            start.prev = self.head
            self.head.next = start
            start.next.prev = start
        else:
            # Page Miss condition -> the page number is not present in the cache
            print(f'{pageNo} -> Page Miss')
            self.set.add(pageNo)
            # Add the new page number to the head of the List
            pg = Node(pageNo)
            pg.next = self.head.next
            pg.prev = self.head
            self.head.next = pg
            pg.next.prev = pg
            if self.pages == self.frameSize:
                # If there is no frames left for the new frame then remove the least recently
                # used page(last page from the list)
                rem = self.tail.prev
                rem.prev.next = self.tail
                self.tail.prev = rem.prev
                rem.next = None
                rem.prev = None
                self.set.remove(rem.pageNo)
            else:
                # If there are frames left then increase the number of pages in the cache
                self.pages += 1

    def displayCache(self):
        curr = self.head.next
        if curr == self.tail:
            print("Cache is Empty")
            return
        print("\tLRU Cache: | ", end=" ")
        while curr != self.tail:
            print(curr.pageNo, " | ", end="")
            curr = curr.next
        print("\n")


def LRUCacheDesign():
    cache = LRUCache(4)
    print("\n ----- LRU CACHE ----- ")
    print("\nEnter -1 to quit process\n")
    while(True):
        pageNo = int(input("Enter page number: "))
        if(pageNo == -1):
            print("Terminating...")
            break
        cache.addPage(pageNo)
        cache.displayCache()


if __name__ == "__main__":
    LRUCacheDesign()
