'''
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

Below is the implementation of Min-Indexed D-Heap algorithm in PYTHON
'''

# Program starts

class MinIndexedDHeap:
    def __init__(self, d, capacity):
        self.d = max(2, d)  # The number of children for each node
        self.size = 0  # Current size of the heap
        self.heap = [0] * capacity  # The underlying list to store the heap indices
        self.index = [-1] * capacity  # The inverse of the heap list: index[i] stores the position of i in the heap
        self.values = [None] * capacity  # The list to store the values associated with each index

    def parent(self, i):
        return (i - 1) // self.d  # Helper function to get the parent index of a node

    def first_child(self, i):
        return (self.d * i) + 1  # Helper function to get the index of the first child of a node

    def move_up(self, i):
        while i > 0 and self.values[self.heap[i]] < self.values[self.heap[self.parent(i)]]:
            self.swap_positions(i, self.parent(i))
            i = self.parent(i)  # Helper function to move a node up in the heap

    def move_down(self, i):
        smallest = i
        child = self.first_child(i)
        last_child = min(child + self.d, self.size)

        while child < last_child:
            if self.values[self.heap[child]] < self.values[self.heap[smallest]]:
                smallest = child
            child += 1

        if smallest != i:
            self.swap_positions(i, smallest)
            self.move_down(smallest)  # Helper function to move a node down in the heap

    def swap_positions(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
        self.index[self.heap[i]] = i
        self.index[self.heap[j]] = j  # Helper function to swap the positions of two indices in the heap

    def insert(self, idx, value):
        if self.contains(idx):
            print("Index already exists in the heap!")
            return

        self.heap[self.size] = idx
        self.index[idx] = self.size
        self.values[idx] = value
        self.move_up(self.size)
        self.size += 1  # Insert a value with an associated index into the heap

    def contains(self, idx):
        return self.index[idx] != -1  # Check if an index exists in the heap

    def update(self, idx, value):
        if not self.contains(idx):
            print("Index does not exist in the heap!")
            return

        self.values[idx] = value
        self.move_up(self.index[idx])
        self.move_down(self.index[idx])  # Update the value associated with an index

    def extract_min(self):
        if self.size == 0:
            print("Heap is empty!")
            return None

        min_index = self.heap[0]
        min_value = self.values[min_index]

        self.swap_positions(0, self.size - 1)
        self.index[min_index] = -1
        self.size -= 1

        self.move_down(0)

        return min_value  # Extract and return the minimum value from the heap

    def get_value(self, idx):
        if not self.contains(idx):
            print("Index does not exist in the heap!")
            return None

        return self.values[idx]  # Get the value associated with an index

    def is_empty(self):
        return self.size == 0  # Check if the heap is empty


# Main function for testing
if __name__ == "__main__":
    d = int(input("Enter the number of children for each node (d): "))
    capacity = int(input("Enter the maximum capacity of the heap: "))

    heap = MinIndexedDHeap(d, capacity)

    num_values = int(input("Enter the number of values to insert: "))

    print("Enter the key index and value for each value:")
    for _ in range(num_values):
        key_index = int(input("Key Index: "))
        value = int(input("Value: "))
        heap.insert(key_index, value)

    print("Heap values in ascending order:")
    while not heap.is_empty():
        print(heap.extract_min(), end=" ")

    print()
