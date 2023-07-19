/**
* This is a C Implementation of Worst Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
* Psuedo Code for the algo is as: 
* Initialize the memory blocks with fixed sizes.
* Initialize an empty list to store the allocated memory blocks.
* Repeat the following steps for each incoming memory request:
*      - Read the size of the requested memory block.
*      - Find the largest available memory block that can accommodate the requested size.
*      - If a suitable block is found:
*             - Allocate the memory block to the request.
*             - Reduce the size of the selected memory block by the allocated size.
*             - Add the allocated memory block to the list of allocated blocks.
*       - If no suitable block is found:
*             - Reject the memory request or trigger memory compaction if applicable.
* Continue processing incoming memory requests until all requests are handled.
* Optionally, implement a memory compaction routine to reduce fragmentation:
*      - Identify contiguous free memory blocks.
*      - Merge them into a larger block.
*      - Update the list of memory blocks accordingly.
**/

#include <stdio.h>

void worstFitFixedMemory(int p, int n) {

    int process[p], memory[n];

    int temp[n];

    for (int i = 0; i < n; i++) {
        printf("Enter input for memory block #%d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    for (int i = 0; i < p; i++) {
        printf("Memory required for process #%d: ", i + 1);
        scanf("%d", &process[i]);
    }

    for (int i = 0; i < n; i++) {
        temp[i] = memory[i];
    }

    for (int i = 0; i < p; i++) {
        int maxIndex = -1;
        for (int j = 0; j < n; j++) {
            if (temp[j] >= process[i]) {
                if (maxIndex == -1 || temp[j] > temp[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        if (maxIndex != -1) {
            temp[maxIndex] -= process[i];
            printf("Process No. %d\tMemory Block Allocated in Worst Fit: %d\n", i + 1, memory[maxIndex]);
        }
        else {
            printf("Process No. %d\tMemory not allocated\n", i + 1);
        }
    }
}

int main() {
    int p, n;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    worstFitFixedMemory(p,n);
    return 0;
}
