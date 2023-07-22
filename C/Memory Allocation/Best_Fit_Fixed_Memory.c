/**
 * This is a C Implementation of Best Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
 *
 *    Psuedo Code for the algo is as:
 *
 *    Initialize a list of memory blocks with fixed sizes.
 *    Create a list of free memory blocks initially containing the entire memory.
 *    When a new process requests memory allocation:
 *        a. Iterate through the list of free memory blocks.
 *        b. Find the free memory block with the smallest size greater than or equal to the requested size.
 *        c. If a suitable free memory block is found:
 *            i. Allocate the memory block to the process.
 *            ii. Update the size of the memory block to reflect the allocated size.
 *            iii. Remove the allocated memory block from the list of free memory blocks.
 *            iv. Return the starting address of the allocated memory block to the process.
 *    If no suitable free memory block is found:
 *        indicate that memory allocation failed.
**/


#include <stdio.h>

void sortMemory(int temp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int tempVal = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempVal;
            }
        }
    }
}

void bestFitFixedMemory() {
    int p, n;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int process[p], memory[n];

    int memoryBestFit[n];

    for (int i = 0; i < n; i++) {
        printf("Enter input for memory block #%d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    for (int i = 0; i < p; i++) {
        printf("Memory required for process #%d: ", i + 1);
        scanf("%d", &process[i]);
    }

    for (int i = 0; i < n; i++) {
        memoryBestFit[i] = memory[i];
    }

    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = memory[i];
    }

    sortMemory(temp, n);

    int outputBestFit[p];
    for (int i = 0; i < p; i++) {
        outputBestFit[i] = -1; // Initialize to -1 indicating memory not allocated
        for (int j = 0; j < n; j++) {
            if (temp[j] >= process[i]) {
                outputBestFit[i] = temp[j];
                temp[j] = -1;
                break;
            }
        }
    }

    printf("\n");
    printf("Process No.\tMemory Block Allocated in Best Fit\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t\t\t", i + 1);
        if (outputBestFit[i] == -1)
            printf("Memory not allocated\t");
        else
            printf("%d\t\t\t", outputBestFit[i]);
        printf("\n");
    }
}

int main() {
    bestFitFixedMemory();
    return 0;
}
