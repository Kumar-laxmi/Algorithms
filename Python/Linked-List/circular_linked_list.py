#!/usr/bin/env python

"""Circular Linked List

This script provides a menu-driven interface to demonstrate circular linked
list operations. A circular linked list is a unique case of singly linked list
where the last element points to the first element instead of being null.
The following operations are available:
1. Display current elements (Traversal) - O(n)
2. Insert data - O(n)
    a. at a particular index
    b. at the front
    c. at the end
3. Delete element - O(n)
    a. from a particular index
    b. from the front
    c. from the end
4. Search for an element - O(n)
5. Get the current size - O(1)

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import Union

Element = Union[int, float, str]


class Node:
    def __init__(self, data: Element):
        self.data = data  # element stored in node
        self.next = self  # link to next node


class CircularLinkedList:
    def __init__(self):  # initialize empty circular linked list (CLL)
        self.head = None  # pointer to start and end of CLL
        self.size = 0  # number of elements in the list

    # string representation of linked list for convenient printing
    def __str__(self):
        if self.head:
            # not empty
            list_str = f"CLL: head -> {self.head.data}"
            current = self.head.next
            while current != self.head:  # head also represents end of the CLL
                list_str = " -> ".join([list_str, str(current.data)])
                current = current.next
            list_str = " -> ".join([list_str, "head"])
            return list_str
        else:
            return "CLL: currently empty."

    def insert_at_index(self, data: Element, index: int):
        """Insert an element into the circular linked list.
        Validates the index and inserts accordingly.

        Args:
            data (Element): value to be inserted in the list
            index (int): 0-indexed position at which to insert the element
        """
        if index < 0:
            print("Invalid index. Cannot be negative.")

        elif index > self.size:
            print(f"Invalid index. Maximum allowed value: {self.size}")

        elif not self.head:  # empty list
            new_node = Node(data)
            self.head = new_node
            new_node.next = self.head  # circular link
            self.size += 1

        elif index == 0:  # insertion at front
            new_node = Node(data)
            new_node.next = self.head  # current head shifted to second
            current = self.head.next
            # traversing to last node to recreate the circular link
            while current.next != self.head:
                current = current.next
            current.next = new_node
            self.head = new_node  # head changes to new Node
            self.size += 1

        else:
            current = self.head  # traverse to required index
            for _ in range(index - 1):
                current = current.next
            temp_link = current.next  # storing next node link before breaking
            new_node = Node(data)
            current.next = new_node  # existing link broken by new Node
            new_node.next = temp_link  # new Node now points to stored link
            self.size += 1

    def delete_at_index(self, index: int) -> Element:
        """Deletes the element at specified index.
        Validates the index first and deletes accordingly.

        Args:
            index (int): 0-indexed position from which to delete the element

        Returns:
            Element: deleted element
        """
        if index < 0:
            print("Invalid index. Cannot be negative.")
            return None

        elif not self.head:
            print("\nCannot delete from empty list.")
            return None

        elif index > self.size - 1:
            print(f"Invalid index. Maximum allowed value: {self.size - 1}")
            return None

        elif index == 0:  # deletion from front
            temp = self.head
            current = self.head.next
            # traversing to last node to recreate the circular link
            while current.next != self.head:
                current = current.next
            current.next = self.head.next
            self.head = self.head.next
            data = temp.data
            self.size -= 1  # update size after deletion
            del temp  # free memory for deleted node
            return data

        else:
            current = self.head  # traverse to required index
            for _ in range(index - 1):
                current = current.next
            temp = current.next  # node to be deleted
            current.next = temp.next  # skipping the node to be deleted
            data = temp.data
            self.size -= 1  # update size after deletion
            del temp  # free memory for deleted node
            return data

    def search(self, data: Element) -> int:
        """Search for an element in the list. Does not search
        if list is empty. If element is found, returns the
        0-indexed position.

        Args:
            data (Element): element to be searched for

        Returns:
            int: 0-indexed position of element. 'None' if element not found.
        """
        if not self.head:
            print("List is empty.", end=" ")
            return None
        else:
            current = self.head
            for index in range(self.size):
                if current.data == data:
                    return index
                else:
                    current = current.next
            return None


def menu_interface(user_cll: CircularLinkedList):
    """Menu-driven interface for circular linked list operations.
    Runs continuously unless user chooses to exit via appropriate command
    or ends the process.

    Args:
        user_cll (CircularLinkedList): circular linked list initialized at
            runtime for user's operations.
    """
    menu = (
        "\n---- Circular Linked List operations ----\n"
        "ID Operation\n"
        "1. Display current list\n"
        "2. Insert data at index\n"
        "3. Insert data at front\n"
        "4. Insert data at end\n"
        "5. Delete element from index\n"
        "6. Delete element from front\n"
        "7. Delete element from end\n"
        "8. Search for element\n"
        "9. Get current size of the list\n"
        "0. Exit\n"
    )

    while True:
        print(menu)

        try:
            choice = int(input("Enter operation ID: ").strip())
        except ValueError:
            print("Invalid ID entered. Try again.")
            continue

        match choice:
            case 1:  # Display current list
                print(user_cll)
            case 2:  # Insert data at index
                data = input("\nEnter data to inserted: ").strip()
                try:
                    index = int(input("Enter index (0-indexed): ").strip())
                except ValueError:
                    print("Invalid index. Only integer values expected.")
                    continue
                user_cll.insert_at_index(data, index)
                print(user_cll)
            case 3:  # Insert data at front
                data = input("\nEnter data to inserted: ").strip()
                user_cll.insert_at_index(data, 0)
                print(user_cll)
            case 4:  # Insert data at end
                data = input("\nEnter data to inserted: ").strip()
                user_cll.insert_at_index(data, user_cll.size)
                print(user_cll)
            case 5:  # Delete element from index
                try:
                    index = int(input("\nEnter index (0-indexed): ").strip())
                except ValueError:
                    print("Invalid index. Only integer values expected.")
                    continue
                data = user_cll.delete_at_index(index)
                if data:
                    print(f"Deleted element: {data}")
                print(user_cll)
            case 6:  # Delete element from front
                data = user_cll.delete_at_index(0)
                if data:
                    print(f"Deleted element: {data}")
                print(user_cll)
            case 7:  # Delete element from end
                data = user_cll.delete_at_index(user_cll.size - 1)
                if data:
                    print(f"Deleted element: {data}")
                print(user_cll)
            case 8:  # Search for element
                data = input("\nEnter element to be searched: ").strip()
                index = user_cll.search(data)
                if index:
                    print(f"Element found at index: {index}")
                else:
                    print("Element not found.")
            case 9:  # Get current size of the list
                print(f"Size = {user_cll.size}")
            case 0:  # Exit
                sys.exit("\nExiting.")
            case _:
                print("Invalid ID entered. Try again.")

        _ = input("\nPress enter to continue...")


if __name__ == "__main__":
    user_cll = CircularLinkedList()  # initialize empty list for current run
    menu_interface(user_cll)
