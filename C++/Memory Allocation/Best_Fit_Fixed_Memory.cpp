/**
 * This is a C++ Implementation of Best Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
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


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bestFitFixedMemory() {
    int p, n;
    cout << "Enter number of processes: ";
    cin >> p;
    cout << "Enter number of memory blocks: ";
    cin >> n;

    vector<int> process(p);
    vector<int> memory(n);
    vector<int> memoryBestFit(n);
    vector<int> temp(n, 0);
    vector<int> outputBestFit(p, -1);

    for (int i = 0; i < n; i++) {
        cout << "Enter input for memory block #" << i + 1 << ": ";
        cin >> memory[i];
    }

    for (int i = 0; i < p; i++) {
        cout << "Memory required for process #" << i + 1 << ": ";
        cin >> process[i];
    }

    memoryBestFit = memory;
    temp = memory;
    sort(temp.begin(), temp.end());

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[j] >= process[i]) {
                outputBestFit[i] = temp[j];
                temp[j] = -1;
                break;
            }
        }
    }

    cout << endl;
    cout << "Process No.\tMemory Block Allocated in Best Fit" << endl;
    for (int i = 0; i < p; i++) {
        cout << i + 1 << "\t\t\t";
        if (outputBestFit[i] == -1)
            cout << "Memory not allocated" << endl;
        else
            cout << outputBestFit[i] << endl;
    }
}

int main() {
    bestFitFixedMemory();
    return 0;
}
