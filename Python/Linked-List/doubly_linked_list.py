#!/usr/bin/env python

"""Doubly Linked List

This script provides a menu-driven interface to demonstrate doubly linked list
operations. A doubly linked list consists of nodes having both forward and backward
connections, making it more flexible compared to a singly linked list.
The following operations are available:
1. Traversal (forward and backward) - O(n)
2. Insert data -
    a. at a particular index - O(n)
    b. at the front - O(1)
    c. at the end - O(1)
3. Delete element -
    a. from a particular index - O(n)
    b. from the front - O(1)
    c. from the end - O(1)
4. Search for an element - O(n)

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
        self.prev = self  # link to previous node


class DoublyLinkedList:
    def __init__(self):  # initialize empty doubly linked list (DLL)
        self.head = None  # pointer to start
        self.tail = None  # pointer to end
        self.size = 0  # number of elements in the list

    # string representation of linked list for convenient printing
    def __str__(self):
        if self.head:
            # not empty
            list_str = f"DLL: head"
            current = self.head
            while current:
                list_str = " <-> ".join([list_str, str(current.data)])
                current = current.next
            list_str = " <-> ".join([list_str, "tail"])
            return list_str
        else:
            return "DLL: currently empty."

    def forward_traversal(self) -> str:
        """Uses the forward connections i.e, 'next', for traversing
        the doubly linked list from head to tail, and display the elements.

        Returns:
            str: Forward traversal of list
        """
        if not self.head:
            return "Doubly linked list is currently empty."
        else:
            forward_str = f"head"
            current = self.head
            while current:
                forward_str = " -> ".join([forward_str, str(current.data)])
                current = current.next
            forward_str = " -> ".join([forward_str, "tail"])
            return forward_str

    def backward_traversal(self) -> str:
        """Uses the backward connections i.e, 'prev', for traversing
        the doubly linked list from tail to head, and display the elements.

        Returns:
            str: Backward traversal of list
        """
        if not self.tail:
            return "Doubly linked list is currently empty."
        else:
            backward_str = f"tail"
            current = self.tail
            while current:
                backward_str = " -> ".join([backward_str, str(current.data)])
                current = current.prev
            backward_str = " -> ".join([backward_str, "head"])
            return backward_str

    def insert_at_front(self, data: Element) -> None:
        """Create a new node with the given data and insert it at the front
        of the linked list (head). If the list is empty, the new node becomes
        the head (and also the tail).

        Args:
            data (Element): element to be inserted at the front
        """
        new_node = Node(data)
        if not self.head:  # for empty list, self.head is None
            self.head = new_node
            self.tail = new_node
            new_node.next = None
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        new_node.prev = None
        self.size += 1

    def insert_at_end(self, data: Element) -> None:
        """Create a new node with the given data and insert it at the end
        of the linked list (tail). If the list is empty, the new node becomes
        the tail (and also the head).

        Args:
            data (Element): element to be inserted at the end
        """
        new_node = Node(data)
        if not self.tail:  # for empty list, self.tail is None
            self.head = new_node
            self.tail = new_node
            new_node.prev = None
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        new_node.next = None
        self.size += 1

    def insert_at_index(self, data: Element, index: int) -> None:
        """Create a new node with the given data and insert it at the given index
        of the linked list. If the index is 0, insert_at_front method is called.
        If the index is size of the list, insert_at_end method is called. If the
        list is empty, the new node becomes the head and the tail.

        Args:
            data (Element): element to be inserted into the list
            index (int): index at which element must be inserted.
                (Valid range is 0 to self.size)
        """
        if index < 0 or index > self.size:
            print(f"Invalid index. Valid range: 0 to {self.size}")
            return

        if not self.head:  # empty list
            new_node = Node(data)
            self.head = new_node
            new_node.prev = None
            self.tail = new_node
            new_node.next = None
            self.size += 1
        elif index == 0:
            self.insert_at_front(data)
        elif index == self.size:
            self.insert_at_end(data)
        else:
            new_node = Node(data)
            current = self.head
            # traverse to required index
            for _ in range(index - 1):
                current = current.next
            temp = current.next
            current.next = new_node
            new_node.prev = current
            new_node.next = temp
            temp.prev = new_node
            self.size += 1

    def delete_from_front(self) -> Element:
        """Delete the element at the front of the list, if deletion is possible,

        Returns:
            Element: data stored in deleted element is returned.
                None if deletion is not performed.
        """
        if not self.head:
            print("Cannot delete from empty list.")
            return None
        else:
            temp = self.head
            self.head = self.head.next  # shift head to new front
            if self.head:  # if list is not empty after deletion
                self.head.prev = None
            data = temp.data
            self.size -= 1
            del temp
            return data

    def delete_from_end(self) -> Element:
        """Delete the element at the end of the list, if deletion is possible,

        Returns:
            Element: data stored in deleted element is returned.
                None if deletion is not performed.
        """
        if not self.tail:
            print("Cannot delete from empty list.")
            return None
        else:
            temp = self.tail
            self.tail = self.tail.prev  # shift tail to new end
            if self.tail:  # if list is not empty after deletion
                self.tail.next = None
            data = temp.data
            self.size -= 1
            del temp
            return data

    def delete_from_index(self, index: int) -> Element:
        """Delete the element at the given index from the list. If index is 0,
        delete_from_front method is called. If the index is self.size-1, delete
        from_end method is called. If the list is empty, deletion is not possible.

        Args:
            index (int): Index from which to delete the element.
                (Valid range is 0 to self.size-1)

        Returns:
            Element: data stored in deleted element is returned.
                None if deletion is not performed.
        """
        if not self.head:
            print("Cannot delete from empty list.")
            return None
        elif index < 0 or index >= self.size:
            print(f"Invalid index. Valid range: 0 to {self.size-1}")
            return None
        elif index == 0:
            self.delete_from_front()
        elif index == self.size - 1:
            self.delete_from_end()
        else:
            current = self.head
            # traverse to required index
            for _ in range(index - 1):
                current = current.next
            temp = current.next  # skip connections
            current.next = temp.next
            temp.next.prev = current
            data = temp.data
            self.size -= 1
            del temp
            return data

    def search(self, data: Element) -> int:
        """Search for an element in the list. Does not search if list is empty.
        If element is found, returns the 0-indexed position.

        Args:
            data (Element): element to be searched for

        Returns:
            int: 0-indexed position of element. None if element not found.
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


def menu_interface(user_list: DoublyLinkedList):
    """Menu-driven interface for doubly linked list operations.
    Runs continuously unless user chooses to exit via appropriate command
    or ends the process.

    Args:
        user_list (DoublyLinkedList): doubly linked list initialized at runtime
            for user's operations.
    """
    menu = (
        "\n---- Doubly Linked List operations ----\n"
        "ID Operation\n"
        "1. Forward traversal\n"
        "2. Backward traversal\n"
        "3. Insert data at index\n"
        "4. Insert data at front\n"
        "5. Insert data at end\n"
        "6. Delete element from index\n"
        "7. Delete element from front\n"
        "8. Delete element from end\n"
        "9. Search for element\n"
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
            case 1:  # Forward traversal
                print(user_list.forward_traversal())
            case 2:  # Backward traversal
                print(user_list.backward_traversal())
            case 3:  # Insert data at index
                data = input("\nEnter data to inserted: ").strip()
                try:
                    index = int(input("Enter index (0-indexed): ").strip())
                except ValueError:
                    print("Invalid index. Only integer values expected.")
                    continue
                user_list.insert_at_index(data, index)
                print(user_list)
            case 4:  # Insert data at front
                data = input("\nEnter data to inserted: ").strip()
                user_list.insert_at_front(data)
                print(user_list)
            case 5:  # Insert data at end
                data = input("\nEnter data to inserted: ").strip()
                user_list.insert_at_end(data)
                print(user_list)
            case 6:  # Delete element from index
                try:
                    index = int(input("\nEnter index (0-indexed): ").strip())
                except ValueError:
                    print("Invalid index. Only integer values expected.")
                    continue
                data = user_list.delete_from_index(index)
                if data:
                    print(f"Deleted element: {data}")
                print(user_list)
            case 7:  # Delete element from front
                data = user_list.delete_from_front()
                if data:
                    print(f"Deleted element: {data}")
                print(user_list)
            case 8:  # Delete element from end
                data = user_list.delete_from_end()
                if data:
                    print(f"Deleted element: {data}")
                print(user_list)
            case 9:  # Search for element
                data = input("\nEnter element to be searched: ").strip()
                index = user_list.search(data)
                if index:
                    print(f"Element found at index: {index}")
                else:
                    print("Element not found.")
            case 0:  # Exit
                sys.exit("\nExiting.")
            case _:
                print("Invalid ID entered. Try again.")

        _ = input("\nPress enter to continue...")


if __name__ == "__main__":
    # initialize empty doubly linked list for current run
    user_list = DoublyLinkedList()
    menu_interface(user_list)
