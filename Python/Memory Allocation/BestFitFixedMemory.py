# This is a Python Implementation of Best Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
#
#    Psuedo Code for the algo is as:
#
#    Initialize a list of memory blocks with fixed sizes.
#    Create a list of free memory blocks initially containing the entire memory.
#    When a new process requests memory allocation:
#        a. Iterate through the list of free memory blocks.
#        b. Find the free memory block with the smallest size greater than or equal to the requested size.
#        c. If a suitable free memory block is found:
#            i. Allocate the memory block to the process.
#            ii. Update the size of the memory block to reflect the allocated size.
#            iii. Remove the allocated memory block from the list of free memory blocks.
#            iv. Return the starting address of the allocated memory block to the process.
#    If no suitable free memory block is found:
#        indicate that memory allocation failed.

def best_fit_fixed_memory():
    p = int(input("Enter number of processes: "))
    n = int(input("Enter number of memory blocks: "))

    process = []
    memory = []

    memory_best_fit = []

    for i in range(n):
        memory_block = int(input(f"Enter input for memory block #{i + 1}: "))
        memory.append(memory_block)

    for i in range(p):
        memory_required = int(input(f"Memory required for process #{i + 1}: "))
        process.append(memory_required)

    memory_best_fit = memory.copy()

    temp = sorted(memory)

    output_best_fit = [-1] * p

    for i in range(p):
        for j in range(n):
            if temp[j] >= process[i]:
                output_best_fit[i] = temp[j]
                temp[j] = -1
                break

    print()
    print("Process No.\tMemory Block Allocated in Best Fit")
    for i in range(p):
        print(f"{i + 1}\t\t\t", end="")
        if output_best_fit[i] == -1:
            print("Memory not allocated\t")
        else:
            print(f"{output_best_fit[i]}\t\t\t")
        print()


best_fit_fixed_memory()
