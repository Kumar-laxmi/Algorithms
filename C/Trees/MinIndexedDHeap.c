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

Below is the implementation of Min-Indexed D-Heap algorithm in C
*/

// Program starts

#include <stdio.h>
#include <stdlib.h>

// Min-indexed D-ary Heap struct
typedef struct
{
    int d;       // The number of children for each node
    int size;    // Current size of the heap
    int *heap;   // The underlying array to store the heap indices
    int *index;  // The inverse of the heap array: index[i] stores the position of i in the heap
    int *values; // The array to store the values associated with each index
} MinIndexedDHeap;

// Helper function to get the parent index of a node
int parent(int i, int d)
{
    return (i - 1) / d;
}

// Helper function to get the index of the first child of a node
int firstChild(int i, int d)
{
    return (d * i) + 1;
}

// Helper function to move a node up in the heap
void moveUp(MinIndexedDHeap *heap, int i)
{
    while (i > 0 && heap->values[heap->heap[i]] < heap->values[heap->heap[parent(i, heap->d)]])
    {
        // Swap positions in heap array
        int temp = heap->heap[i];
        heap->heap[i] = heap->heap[parent(i, heap->d)];
        heap->heap[parent(i, heap->d)] = temp;

        // Update index array
        heap->index[heap->heap[i]] = i;
        heap->index[heap->heap[parent(i, heap->d)]] = parent(i, heap->d);

        i = parent(i, heap->d);
    }
}

// Helper function to move a node down in the heap
void moveDown(MinIndexedDHeap *heap, int i)
{
    int smallest = i;
    int child = firstChild(i, heap->d);
    int lastChild = child + heap->d;

    while (child < lastChild && child < heap->size)
    {
        if (heap->values[heap->heap[child]] < heap->values[heap->heap[smallest]])
        {
            smallest = child;
        }
        child++;
    }

    if (smallest != i)
    {
        // Swap positions in heap array
        int temp = heap->heap[i];
        heap->heap[i] = heap->heap[smallest];
        heap->heap[smallest] = temp;

        // Update index array
        heap->index[heap->heap[i]] = i;
        heap->index[heap->heap[smallest]] = smallest;

        moveDown(heap, smallest);
    }
}

// Helper function to create a MinIndexedDHeap
MinIndexedDHeap *createMinIndexedDHeap(int d, int capacity)
{
    MinIndexedDHeap *heap = (MinIndexedDHeap *)malloc(sizeof(MinIndexedDHeap));
    heap->d = d;
    heap->size = 0;
    heap->heap = (int *)malloc(sizeof(int) * capacity);
    heap->index = (int *)malloc(sizeof(int) * capacity);
    heap->values = (int *)malloc(sizeof(int) * capacity);

    // Initialize index array
    for (int i = 0; i < capacity; i++)
    {
        heap->index[i] = -1;
    }

    return heap;
}

// Helper function to check if an index exists in the heap
int contains(MinIndexedDHeap *heap, int idx)
{
    return heap->index[idx] != -1;
}

// Insert a value with an associated index into the heap
void insert(MinIndexedDHeap *heap, int idx, int value)
{
    if (contains(heap, idx))
    {
        printf("Index already exists in the heap!\n");
        return;
    }

    heap->heap[heap->size] = idx;
    heap->index[idx] = heap->size;
    heap->values[idx] = value;
    moveUp(heap, heap->size);
    heap->size++;
}

// Update the value associated with an index
void update(MinIndexedDHeap *heap, int idx, int value)
{
    if (!contains(heap, idx))
    {
        printf("Index does not exist in the heap!\n");
        return;
    }

    heap->values[idx] = value;
    moveUp(heap, heap->index[idx]);
    moveDown(heap, heap->index[idx]);
}

// Extract and return the minimum value from the heap
int extractMin(MinIndexedDHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap is empty!\n");
        exit(1);
    }

    int minIndex = heap->heap[0];
    int minValue = heap->values[minIndex];

    // Swap positions in heap array
    int temp = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->heap[heap->size - 1] = temp;

    // Update index array
    heap->index[heap->heap[0]] = 0;
    heap->index[heap->heap[heap->size - 1]] = -1;

    heap->size--;

    moveDown(heap, 0);

    return minValue;
}

// Get the value associated with an index
int getValue(MinIndexedDHeap *heap, int idx)
{
    if (!contains(heap, idx))
    {
        printf("Index does not exist in the heap!\n");
        exit(1);
    }

    return heap->values[idx];
}

// Check if the heap is empty
int isEmpty(MinIndexedDHeap *heap)
{
    return heap->size == 0;
}

// Main function for testing
int main()
{
    int d, capacity;
    printf("Enter the number of children for each node (d): ");
    scanf("%d", &d);
    printf("Enter the maximum capacity of the heap: ");
    scanf("%d", &capacity);

    MinIndexedDHeap *heap = createMinIndexedDHeap(d, capacity);

    int numValues;
    printf("Enter the number of values to insert: ");
    scanf("%d", &numValues);

    printf("Enter the key index and value for each value:\n");
    for (int i = 0; i < numValues; i++)
    {
        int keyIndex, value;
        printf("Key Index: ");
        scanf("%d", &keyIndex);
        printf("Value: ");
        scanf("%d", &value);
        insert(heap, keyIndex, value);
    }

    printf("Heap values in ascending order:\n");
    while (!isEmpty(heap))
    {
        printf("%d ", extractMin(heap));
    }
    printf("\n");

    free(heap->heap);
    free(heap->index);
    free(heap->values);
    free(heap);

    return 0;
}
