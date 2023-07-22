# This is a Python implementation of Next Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
#
#    Pseudo code for the algorithm is as follows: 
#
#    Initialize a list of memory blocks with fixed sizes.
#    Create a list of free memory blocks initially containing the entire memory.
#    Initialize a variable j to 0 representing the index of the last allocated memory block.
#    When a new process requests memory allocation:
#        a. Iterate through the list of free memory blocks starting from the last allocated index j.
#        b. If a free memory block is found with a size greater than or equal to the requested size:
#            i. Allocate the memory block to the process.
#            ii. Update the size of the memory block to reflect the allocated size.
#            iii. Remove the allocated memory block from the list of free memory blocks.
#            iv. Set j to the index of the allocated memory block.
#            v. Return the starting address of the allocated memory block to the process.
#        c. If no suitable free memory block is found starting from index j, wrap around to the beginning of the list and continue the search until the last allocated index j is reached again.
#    If no suitable free memory block is found:
#        Indicate that memory allocation failed.

def next_fit_fixed_memory():
    p = int(input("Enter number of processes: "))
    n = int(input("Enter number of memory blocks: "))

    process = []
    memory = []

    memory_next_fit = []

    for i in range(n):
        memory_size = int(input("Enter input for memory block #" + str(i + 1) + ": "))
        memory.append(memory_size)

    for i in range(p):
        process_size = int(input("Memory required for process #" + str(i + 1) + ": "))
        process.append(process_size)

    memory_next_fit = memory.copy()

    output_next_fit = [-1] * p  # Initialize to -1 indicating memory not allocated
    j = 0  # Start with the first memory block

    for i in range(p):
        while True:
            if process[i] <= memory_next_fit[j]:
                output_next_fit[i] = memory_next_fit[j]
                memory_next_fit[j] = -1
                j = (j + 1) % n  # Move to the next memory block
                break
            j = (j + 1) % n

    print()
    print("Process No.\tMemory Block Allocated in Next Fit")
    for i in range(p):
        print(f"{i + 1}\t\t\t", end="")
        if output_next_fit[i] == -1:
            print("Memory not allocated\t", end="")
        else:
            print(f"{output_next_fit[i]}\t\t\t", end="")
        print()


next_fit_fixed_memory()
