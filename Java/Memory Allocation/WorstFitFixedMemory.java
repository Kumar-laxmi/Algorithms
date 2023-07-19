/**
* This is a Java Implementation of Worst Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
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

import java.util.Arrays;
import java.util.Scanner;

public class WorstFitFixedMemory {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int p = scanner.nextInt();
        System.out.print("Enter number of memory blocks: ");
        int n = scanner.nextInt();

        int[] process = new int[p];
        int[] memory = new int[n];

        int[] temp = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter input for memory block #" + (i + 1) + ": ");
            memory[i] = scanner.nextInt();
        }

        for (int i = 0; i < p; i++) {
            System.out.print("Memory required for process #" + (i + 1) + ": ");
            process[i] = scanner.nextInt();
        }

        System.arraycopy(memory, 0, temp, 0, n);

        Arrays.sort(temp);

        // Worst Fit
        int[] outputWorstFit = new int[p];
        Arrays.fill(outputWorstFit, -1); // Initialize to -1 indicating memory not allocated
        for (int i = 0; i < p; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (temp[j] >= process[i]) {
                    outputWorstFit[i] = temp[j];
                    temp[j] = -1;
                    break;
                }
            }
        }

        System.out.println();
        System.out.println("Process No.\tMemory Block Allocated in Worst Fit");
        for (int i = 0; i < p; i++) {
            System.out.print(i + 1 + "\t\t\t");
            if (outputWorstFit[i] == -1)
                System.out.print("Memory not allocated\t");
            else
                System.out.print(outputWorstFit[i] + "\t\t\t");
            System.out.println();
        }

        scanner.close();
    }
}
