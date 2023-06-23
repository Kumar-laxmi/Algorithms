/**
* This is a C Implementation of First Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
*
*    Psuedo Code for the algo is as: 
*
*    Initialize a list of memory blocks with fixed sizes.
*    Create a list of free memory blocks initially containing the entire memory.
*    When a new process requests memory allocation:
*        a. Iterate through the list of free memory blocks.
*        b. If a free memory block is found with a size greater than or equal to the requested size:
*            i. Allocate the memory block to the process.
*            ii. Update the size of the memory block to reflect the allocated size.
*            iii. Remove the allocated memory block from the list of free memory blocks.
*            iv. Return the starting address of the allocated memory block to the process.
*    If no suitable free memory block is found:
*        indicate that memory allocation failed.
**/


#include <stdio.h>

void firstFitFixedMemory() {
    int p, n;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int process[p], memory[n];

    int memoryFirstFit[n];

    for (int i = 0; i < n; i++) {
        printf("Enter input for memory block #%d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    for (int i = 0; i < p; i++) {
        printf("Memory required for process #%d: ", i + 1);
        scanf("%d", &process[i]);
    }

    for (int i = 0; i < n; i++) {
        memoryFirstFit[i] = memory[i];
    }

    int outputFirstFit[p];
    for (int i = 0; i < p; i++) {
        outputFirstFit[i] = -1; // Initialize to -1 indicating memory not allocated
        for (int j = 0; j < n; j++) {
            if (process[i] <= memoryFirstFit[j]) {
                outputFirstFit[i] = memoryFirstFit[j];
                memoryFirstFit[j] = -1;
                break;
            }
        }
    }

    printf("\n");
    printf("Process No.\tMemory Block Allocated in First Fit\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t\t\t", i + 1);
        if (outputFirstFit[i] == -1)
            printf("Memory not allocated\t");
        else
            printf("%d\t\t\t", outputFirstFit[i]);
        printf("\n");
    }
}

int main() {
    firstFitFixedMemory();
    return 0;
}
