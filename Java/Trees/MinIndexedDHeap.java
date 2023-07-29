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

Below is the implementation of Min-Indexed D-Heap algorithm in Java
*/

// Program starts

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MinIndexedDHeap<T extends Comparable<T>> {
    private int d;
    private int size;
    private List<Integer> heap;
    private List<Integer> index;
    private List<T> values;

    public MinIndexedDHeap(int d, int capacity) {
        this.d = d;
        size = 0;
        heap = new ArrayList<>(capacity);
        index = new ArrayList<>(capacity);
        values = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            heap.add(0);
            index.add(-1);
            values.add(null);
        }
    }

    private int parent(int i) {
        return (i - 1) / d;
    }

    private int firstChild(int i) {
        return (d * i) + 1;
    }

    private void moveUp(int i) {
        while (i > 0 && values.get(heap.get(i)).compareTo(values.get(heap.get(parent(i)))) < 0) {
            swapPositions(i, parent(i));
            i = parent(i);
        }
    }

    private void moveDown(int i) {
        int smallest = i;
        int child = firstChild(i);
        int lastChild = Math.min(child + d, size);

        while (child < lastChild) {
            if (values.get(heap.get(child)).compareTo(values.get(heap.get(smallest))) < 0) {
                smallest = child;
            }
            child++;
        }

        if (smallest != i) {
            swapPositions(i, smallest);
            moveDown(smallest);
        }
    }

    private void swapPositions(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
        index.set(heap.get(i), i);
        index.set(heap.get(j), j);
    }

    public void insert(int idx, T value) {
        if (contains(idx)) {
            System.err.println("Index already exists in the heap!");
            return;
        }

        heap.set(size, idx);
        index.set(idx, size);
        values.set(idx, value);
        moveUp(size);
        size++;
    }

    public boolean contains(int idx) {
        return index.get(idx) != -1;
    }

    public void update(int idx, T value) {
        if (!contains(idx)) {
            System.err.println("Index does not exist in the heap!");
            return;
        }

        values.set(idx, value);
        moveUp(index.get(idx));
        moveDown(index.get(idx));
    }

    public T extractMin() {
        if (size == 0) {
            System.err.println("Heap is empty!");
            System.exit(1);
        }

        int minIndex = heap.get(0);
        T minValue = values.get(minIndex);

        swapPositions(0, size - 1);
        index.set(minIndex, -1);
        size--;

        moveDown(0);

        return minValue;
    }

    public T getValue(int idx) {
        if (!contains(idx)) {
            System.err.println("Index does not exist in the heap!");
            System.exit(1);
        }

        return values.get(idx);
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the number of children for each node (d): ");
            int d = scanner.nextInt();
            System.out.print("Enter the maximum capacity of the heap: ");
            int capacity = scanner.nextInt();

            MinIndexedDHeap<Integer> heap = new MinIndexedDHeap<>(d, capacity);

            System.out.print("Enter the number of values to insert: ");
            int numValues = scanner.nextInt();

            System.out.println("Enter the key index and value for each value:");
            for (int i = 0; i < numValues; i++) {
                System.out.print("Key Index: ");
                int keyIndex = scanner.nextInt();
                System.out.print("Value: ");
                int value = scanner.nextInt();
                heap.insert(keyIndex, value);
            }

            System.out.println("Heap values in ascending order:");
            while (!heap.isEmpty()) {
                System.out.print(heap.extractMin() + " ");
            }
        }
        System.out.println();
    }
}
