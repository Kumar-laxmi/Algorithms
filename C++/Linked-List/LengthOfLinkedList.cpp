#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int getLinkedListLength(Node* head) {
    int length = 0;
    Node* current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    std::cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Find the length of the linked list
    int length = getLinkedListLength(head);

    std::cout << "Length of the linked list: " << length << std::endl;

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
