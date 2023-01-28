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

import java.util.HashSet;
import java.util.Scanner;

// A Doubly Linked List Node
class Node {
    int pageNo;
    Node prev;
    Node next;

    Node(int pageNo) {
        this.pageNo = pageNo;
    }
}

// Creating LRU cache with appropriate methods
class LRUCache {
    private int frameSize; // Size of the Cache
    private int pages; // To keep track of number of pages present in LRU cache
    private HashSet<Integer> set; // To check if LRU cache contains the page number
    private Node head; // Head for the Linked list
    private Node tail; // Tail for the Linked list

    LRUCache(int frameSize) {
        this.frameSize = frameSize;
        set = new HashSet<>();
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
        head.prev = null;
        tail.next = null;
    }

    // Method for adding a page number to the cache
    public void addPage(int pageNo) {
        if (set.contains(pageNo)) {
            // Page Hit condition -> the page number is already present in the cache
            System.out.println(pageNo + " -> Page Hit");
            Node curr = head.next;
            Node start = curr;
            while (curr != tail) {
                if (curr.pageNo == pageNo) {
                    // Remove the page from the cache from its initial position and add it to
                    // the staring of the list
                    start = curr;
                    curr.prev.next = curr.next;
                    curr.next.prev = curr.prev;
                    Node nextCurr = curr.next;
                    curr.next = null;
                    curr.prev = null;
                    curr = nextCurr;
                } else
                    curr = curr.next;
            }
            start.next = head.next;
            start.prev = head;
            head.next = start;
            start.next.prev = start;
        } else {
            // Page Miss condition -> the page number is not present in the cache
            System.out.println(pageNo + " -> Page Miss");
            set.add(pageNo);
            // Add the new page number to the head of the List
            Node pg = new Node(pageNo);
            pg.next = head.next;
            pg.prev = head;
            head.next = pg;
            pg.next.prev = pg;
            if (pages == frameSize) {
                // If there is no frames left for the new frame then remove the least recently
                // used page(last page from the list)
                Node rem = tail.prev;
                rem.prev.next = tail;
                tail.prev = rem.prev;
                rem.next = null;
                rem.prev = null;
                set.remove(rem.pageNo);
            } else
                // If there are frames left then increase the number of pages in the cache
                pages++;
        }
    }

    public void displayCache() {
        Node curr = head.next;
        if (pages == 0) {
            System.out.println("Empty cache");
            return;
        }
        System.out.print("\tLRU Cache: | ");
        while (curr != tail) {
            System.out.print(curr.pageNo + " | ");
            curr = curr.next;
        }
        System.out.println("\n");
    }
}

public class LRUCacheDesign {

    static int pageNo;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LRUCache cache = new LRUCache(4);

        System.out.println("\n----- LRU CACHE -----\n");
        System.out.println("Enter -1 to quit process\n");
        while (true) {
            System.out.print("Enter page number: ");
            pageNo = sc.nextInt();
            if (pageNo == -1) {
                System.out.println("Terminating...");
                break;
            }
            cache.addPage(pageNo);
            cache.displayCache();
        }

        sc.close();
    }
}
