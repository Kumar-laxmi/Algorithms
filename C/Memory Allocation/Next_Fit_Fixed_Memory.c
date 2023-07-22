/**
* This is an implementation of Next Fit Memory Allocation Algorithm (Fixed Size Memory Blocks) in C
*
*    Pseudo code for the algorithm is as follows: 
*
*    Initialize a list of memory blocks with fixed sizes.
*    Create a list of free memory blocks initially containing the entire memory.
*    Initialize a variable j to 0 representing the index of the last allocated memory block.
*    When a new process requests memory allocation:
*        a. Iterate through the list of free memory blocks starting from the last allocated index j.
*        b. If a free memory block is found with a size greater than or equal to the requested size:
*            i. Allocate the memory block to the process.
*            ii. Update the size of the memory block to reflect the allocated size.
*            iii. Remove the allocated memory block from the list of free memory blocks.
*            iv. Set j to the index of the allocated memory block.
*            v. Return the starting address of the allocated memory block to the process.
*        c. If no suitable free memory block is found starting from index j, wrap around to the beginning of the list and continue the search until the last allocated index j is reached again.
*    If no suitable free memory block is found:
*        Indicate that memory allocation failed.
*/

#include <stdio.h>

void nextFitFixedMemory() {
    int p, n;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int process[p];
    int memory[n];
    int memoryNextFit[n];

    for (int i = 0; i < n; i++) {
        printf("Enter input for memory block #%d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    for (int i = 0; i < p; i++) {
        printf("Memory required for process #%d: ", i + 1);
        scanf("%d", &process[i]);
    }

    for (int i = 0; i < n; i++) {
        memoryNextFit[i] = memory[i];
    }

    int outputNextFit[p];
    for (int i = 0; i < p; i++) {
        outputNextFit[i] = -1; // Initialize to -1 indicating memory not allocated
    }
    int j = 0; // Start with the first memory block

    for (int i = 0; i < p; i++) {
        while (1) {
            if (process[i] <= memoryNextFit[j]) {
                outputNextFit[i] = memoryNextFit[j];
                memoryNextFit[j] = -1;
                j = (j + 1) % n; // Move to the next memory block
                break;
            }
            j = (j + 1) % n;
        }
    }

    printf("\n");
    printf("Process No.\tMemory Block Allocated in Next Fit\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t\t\t", i + 1);
        if (outputNextFit[i] == -1)
            printf("Memory not allocated\t");
        else
            printf("%d\t\t\t", outputNextFit[i]);
        printf("\n");
    }
}

int main() {
    nextFitFixedMemory();
    return 0;
}