#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100

// Huffman tree node
struct huffmanNode
{

    // input characters
    char data;

    // character frequency
    unsigned freq;

    // Left and right child
    struct huffmanNode *left, *right;
};

// min heap
struct MinHeap
{

    // min heap tree size
    unsigned size;

    // min heap capacity
    unsigned capacity;

    // minheap node pointers' array
    struct huffmanNode **array;
};

// allocate new min heap node
struct huffmanNode *newNode(char data, unsigned freq)
{
    struct huffmanNode *temp = (struct huffmanNode *)malloc(sizeof(struct huffmanNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// create min heap
struct MinHeap *createMinHeap(unsigned capacity)

{

    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));

    // current size = 0
    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array = (struct huffmanNode **)malloc(minHeap->capacity * sizeof(struct huffmanNode *));
    return minHeap;
}

// swap two min heap nodes
void swaphuffmanNode(struct huffmanNode **a,
                     struct huffmanNode **b)

{

    struct huffmanNode *t = *a;
    *a = *b;
    *b = t;
}

// min heapify function.
void minHeapify(struct MinHeap *minHeap, int idx)

{

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swaphuffmanNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// check size of heap
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// extract minimum value node from heap
struct huffmanNode *extractMin(struct MinHeap *minHeap)
{

    struct huffmanNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// insert a new node to Min Heap
void insertMinHeap(struct MinHeap *minHeap, struct huffmanNode *huffmanNode)
{

    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && huffmanNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = huffmanNode;
}

// build min heap
void buildMinHeap(struct MinHeap *minHeap)

{

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i) printf("%d", arr[i]);
    printf("\n");
}

// check if this node is leaf
int isLeaf(struct huffmanNode *root)
{
    return !(root->left) && !(root->right);
}

// Creates a min heap
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)

{

    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// function builds huffman tree
struct huffmanNode *buildHuffmanTree(char data[], int freq[], int size)

{
    struct huffmanNode *left, *right, *top;

    // create a min heap of capacity
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap))
    {

        // extract the two minimum freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // create a new internal node with frequency equal to the sum of the two nodes frequencies
        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// print huffman codes
void printCodes(struct huffmanNode *root, int arr[], int top)

{

    // assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // assign 1 to right edge and recur
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {

        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// build and traverse huffman tree
void HuffmanCodes(char data[], int freq[], int size)
{
    // construct huffman tree
    struct huffmanNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// Driver code
int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
