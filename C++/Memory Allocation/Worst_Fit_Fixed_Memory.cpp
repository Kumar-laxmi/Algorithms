/**
* This is a C++ Implementation of Worst Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
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

#include <iostream>
#include <algorithm>
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

    int temp[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Entry input for memory block #" << i + 1 << ": ";
        cin >> memory[i];
    }

    for (int i = 0; i < p; i++)
    {
        cout << "Memory required for process #" << i + 1 << ": ";
        cin >> process[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp[i] = memory[i];
    }

    sort(temp, temp + n, greater<int>());

    // Worst Fit
    int outputWorstFit[p]; // Fixed array size to p
    for (int i = 0; i < p; i++)
    {
        outputWorstFit[i] = -1; // Initialize to -1 indicating memory not allocated
        for (int j = 0; j < n; j++)
        {
            if (temp[j] >= process[i])
            {
                outputWorstFit[i] = temp[j];
                temp[j] = -1;
                break;
            }
        }
    }

    cout << endl;

    cout << "Process No."
         << "\t"
         << "Memory Block Allocated in Worst Fit \t"
         << endl;

    for (int i = 0; i < p; i++)
    {
        cout << i + 1 << "\t\t\t";

        if (outputWorstFit[i] == -1)
            cout << "Memory not allocated"
                 << "\t";
        else
            cout << outputWorstFit[i] << "\t \t \t\t ";

        cout << endl;
    }

    return 0;
}