# This is a Python Implementation of First Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
#
#    Psuedo Code for the algo is as: 
#
#    Initialize a list of memory blocks with fixed sizes.
#    Create a list of free memory blocks initially containing the entire memory.
#    When a new process requests memory allocation:
#        a. Iterate through the list of free memory blocks.
#        b. If a free memory block is found with a size greater than or equal to the requested size:
#            i. Allocate the memory block to the process.
#            ii. Update the size of the memory block to reflect the allocated size.
#            iii. Remove the allocated memory block from the list of free memory blocks.
#            iv. Return the starting address of the allocated memory block to the process.
#    If no suitable free memory block is found:
#        indicate that memory allocation failed.

def first_fit_fixed_memory():
    p = int(input("Enter number of processes: "))
    n = int(input("Enter number of memory blocks: "))

    process = []
    memory = []

    memory_first_fit = []

    for i in range(n):
        memory_size = int(input("Enter input for memory block #" + str(i + 1) + ": "))
        memory.append(memory_size)

    for i in range(p):
        process_size = int(input("Memory required for process #" + str(i + 1) + ": "))
        process.append(process_size)

    memory_first_fit = memory.copy()

    output_first_fit = [-1] * p  # Initialize to -1 indicating memory not allocated
    for i in range(p):
        for j in range(n):
            if process[i] <= memory_first_fit[j]:
                output_first_fit[i] = memory_first_fit[j]
                memory_first_fit[j] = -1
                break

    print()
    print("Process No.\tMemory Block Allocated in First Fit")
    for i in range(p):
        print(f"{i + 1}\t\t\t", end="")
        if output_first_fit[i] == -1:
            print("Memory not allocated\t", end="")
        else:
            print(f"{output_first_fit[i]}\t\t\t", end="")
        print()


first_fit_fixed_memory()
