#  This is a Java Implementation of Worst Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)

#  Psuedo Code for the algo is as: 
#  Initialize the memory blocks with fixed sizes.
#  Initialize an empty list to store the allocated memory blocks.
#  Repeat the following steps for each incoming memory request:
#        - Read the size of the requested memory block.
#        - Find the largest available memory block that can accommodate the requested size.
#        - If a suitable block is found:
#              - Allocate the memory block to the request.
#              - Reduce the size of the selected memory block by the allocated size.
#              - Add the allocated memory block to the list of allocated blocks.
#              - If no suitable block is found:
#              - Reject the memory request or trigger memory compaction if applicable.
#  Continue processing incoming memory requests until all requests are handled.
#  Optionally, implement a memory compaction routine to reduce fragmentation:
#       - Identify contiguous free memory blocks.
#       - Merge them into a larger block.
#       - Update the list of memory blocks accordingly.


def worst_fit_fixed_memory():
    p = int(input("Enter number of processes: "))
    n = int(input("Enter number of memory blocks: "))

    process = []
    memory = []

    temp = []

    for i in range(n):
        memory_size = int(input("Enter input for memory block #" + str(i + 1) + ": "))
        memory.append(memory_size)

    for i in range(p):
        process_size = int(input("Memory required for process #" + str(i + 1) + ": "))
        process.append(process_size)

    temp = memory.copy()
    temp.sort(reverse=True)

    # Worst Fit
    output_worst_fit = [-1] * p  # Initialize to -1 indicating memory not allocated
    for i in range(p):
        for j in range(n - 1, -1, -1):
            if temp[j] >= process[i]:
                output_worst_fit[i] = temp[j]
                temp[j] = -1
                break

    print()
    print("Process No.\tMemory Block Allocated in Worst Fit")
    for i in range(p):
        print(f"{i + 1}\t\t\t", end="")
        if output_worst_fit[i] == -1:
            print("Memory not allocated\t", end="")
        else:
            print(f"{output_worst_fit[i]}\t\t\t", end="")
        print()

worst_fit_fixed_memory()