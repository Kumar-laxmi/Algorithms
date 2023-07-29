/*
------------------------------------- Min-Indexed D-Heap Algorithm -------------------------------------

Approach

1. The Min-indexed D-array Heap is a data structure that maintains a collection of elements with associated indices.

2. It is based on a binary heap with additional support for efficient indexing and updating of values.

3. The number of children for each node, denoted by 'd', is specified during initialization.

4. The heap is represented using three arrays: 'heap' to store the indices, 'index' to store the positions of indices in the heap, 
and 'values' to store the associated values.

5. The heap is a complete tree structure, where each node's value is smaller than or equal to its children's values.

6. The 'insert' operation inserts a value with an associated index into the heap and maintains the heap property by moving the node up if necessary.

7. The 'update' operation updates the value associated with a given index and restores the heap property by moving the node up or down if necessary.

8. The 'extract_min' operation removes and returns the minimum value from the heap, ensuring the heap property is preserved.

9. The 'get_value' operation retrieves the value associated with a given index.

10. The 'contains' operation checks if a given index exists in the heap.

11. The 'is_empty' operation checks if the heap is empty.

12. The main function demonstrates the usage of the MinIndexedDHeap class by taking user input for the number of children, maximum capacity, 
values to insert, and their associated indices. It then performs operations on the heap and prints the heap values in ascending order.

Below is the implementation of Min-Indexed D-Heap algorithm in C++
*/

// Program starts

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Min-indexed D-ary Heap class
template<typename T>
class MinIndexedDHeap {
private:
    int d;                         // The number of children for each node
    int size;                      // Current size of the heap
    vector<int> heap;              // The underlying vector to store the heap indices
    vector<int> index;             // The inverse of the heap array: index[i] stores the position of i in the heap
    vector<T> values;              // The array to store the values associated with each index

    // Helper function to get the parent index of a node
    int parent(int i) {
        return (i - 1) / d;
    }

    // Helper function to get the index of the first child of a node
    int firstChild(int i) {
        return (d * i) + 1;
    }

    // Helper function to move a node up in the heap
    void moveUp(int i) {
        while (i > 0 && values[heap[i]] < values[heap[parent(i)]]) {
            swapPositions(i, parent(i));
            i = parent(i);
        }
    }

    // Helper function to move a node down in the heap
    void moveDown(int i) {
        int smallest = i;
        int child = firstChild(i);
        int lastChild = min(child + d, size);

        while (child < lastChild) {
            if (values[heap[child]] < values[heap[smallest]]) {
                smallest = child;
            }
            child++;
        }

        if (smallest != i) {
            swapPositions(i, smallest);
            moveDown(smallest);
        }
    }

    // Helper function to swap the positions of two indices in the heap
    void swapPositions(int i, int j) {
        swap(heap[i], heap[j]);
        index[heap[i]] = i;
        index[heap[j]] = j;
    }

public:
    // Constructor
    MinIndexedDHeap(int d, int capacity) : d(d), size(0) {
        heap.resize(capacity);
        index.resize(capacity, -1);
        values.resize(capacity);
    }

    // Insert a value with an associated index into the heap
    void insert(int idx, T value) {
        if (contains(idx)) {
            cerr << "Index already exists in the heap!" << endl;
            return;
        }

        heap[size] = idx;
        index[idx] = size;
        values[idx] = value;
        moveUp(size);
        size++;
    }

    // Check if an index exists in the heap
    bool contains(int idx) {
        return index[idx] != -1;
    }

    // Update the value associated with an index
    void update(int idx, T value) {
        if (!contains(idx)) {
            cerr << "Index does not exist in the heap!" << endl;
            return;
        }

        values[idx] = value;
        moveUp(index[idx]);
        moveDown(index[idx]);
    }

    // Extract and return the minimum value from the heap
    T extractMin() {
        if (size == 0) {
            cerr << "Heap is empty!" << endl;
            exit(1);
        }

        int minIndex = heap[0];
        T minValue = values[minIndex];

        swapPositions(0, size - 1);
        index[minIndex] = -1;
        size--;

        moveDown(0);

        return minValue;
    }

    // Get the value associated with an index
    T getValue(int idx) {
        if (!contains(idx)) {
            cerr << "Index does not exist in the heap!" << endl;
            exit(1);
        }

        return values[idx];
    }

    // Check if the heap is empty
    bool isEmpty() {
        return size == 0;
    }
};

// Main function for testing
int main() {
    int d, capacity;
    cout << "Enter the number of children for each node (d): ";
    cin >> d;
    cout << "Enter the maximum capacity of the heap: ";
    cin >> capacity;

    MinIndexedDHeap<int> heap(d, capacity);

    int numValues;
    cout << "Enter the number of values to insert: ";
    cin >> numValues;

    cout << "Enter the key index and value for each value:" << endl;
    for (int i = 0; i < numValues; i++) {
        int keyIndex, value;
        cout << "Key Index: ";
        cin >> keyIndex;
        cout << "Value: ";
        cin >> value;
        heap.insert(keyIndex, value);
    }

    cout << "Heap values in ascending order:" << endl;
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}
