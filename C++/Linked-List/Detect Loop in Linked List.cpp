// C++ program to detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;

    /* constructor */
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int detectLoop(Node* list)
{
    /* create two pointers slow and fast
    slow will move by 1 step while fast will move by 2 steps. */
	Node *slow = list, *fast = list;

	while (fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;

        /* at any point slow is equal to fast that means loop is present so return true */
		if (slow == fast) {
			return 1;
		}
	}

	return 0;
}

int main()
{
	/* Start with the empty list */
	Node* head = NULL;
    Node* tail = head;

	while(true) {
        int data;
        cin >> data;    /* taling inpt of data from user */

        /* assuming -1 as NULL/end of list */
        if(data == -1) {
            break;
        }
        else {
            /* create first node */
            Node* new_node = new Node(data);

            if(head == NULL) {
                /* point head to first node */
                head = tail = new_node;
            }
            else {
                /* link the old list of the new node */
                tail -> next = new_node;
                
                /* move tail to the new node */
                tail = tail -> next;
            }
        }
    }

	/* Create a loop for testing */
	tail -> next = head;

	if (detectLoop(head)) {
		cout << "Loop Found";
    }
	else {
		cout << "No Loop found";
    }
	return 0;
}

// Time complexity: O(N)
// Auxiliary Space: O(1)