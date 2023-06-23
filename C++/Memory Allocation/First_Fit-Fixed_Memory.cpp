/**
* This is a C++ Implementation of First Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
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


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p;

    cout << "Enter number of processes: ";
    cin >> p;
    cout << "Enter number of memory blocks: ";
    cin >> n;

    vector<int> process(p), memory(n);

    int memoryFirstFit[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter input for memory block #" << i + 1 << ": ";
        cin >> memory[i];
    }

    for (int i = 0; i < p; i++)
    {
        cout << "Memory required for process #" << i + 1 << ": ";
        cin >> process[i];
    }

    for (int i = 0; i < n; i++)
    {
        memoryFirstFit[i] = memory[i];
    }

    // First Fit
    int outputFirstFit[p];
    for (int i = 0; i < p; i++)
    {
        outputFirstFit[i] = -1; // Initialize to -1 indicating memory not allocated
        for (int j = 0; j < n; j++)
        {
            if (process[i] <= memoryFirstFit[j])
            {
                outputFirstFit[i] = memoryFirstFit[j];
                memoryFirstFit[j] = -1;
                break;
            }
        }
    }

    cout << endl;
    cout << "Process No."
         << "\t"
         << "Memory Block Allocated in First Fit \t"
         << endl;

    for (int i = 0; i < p; i++)
    {
        cout << i + 1 << "\t\t\t";

        if (outputFirstFit[i] == -1)
            cout << "Memory not allocated"
                 << "\t";
        else
            cout << outputFirstFit[i] << "\t \t \t\t ";

        cout << endl;
    }

    return 0;
}
