/**
 * This is a Java Implementation of Best Fit Memory Allocation Algorithm (Fixed Size Memory Blocks)
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



import java.util.Arrays;
import java.util.Scanner;

public class BestFitFixedMemory {
    public static void main(String[] args) {
        bestFitFixedMemory();
    }

    public static void bestFitFixedMemory() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int p = scanner.nextInt();
        System.out.print("Enter number of memory blocks: ");
        int n = scanner.nextInt();

        int[] process = new int[p];
        int[] memory = new int[n];

        int[] memoryBestFit = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter input for memory block #" + (i + 1) + ": ");
            memory[i] = scanner.nextInt();
        }

        for (int i = 0; i < p; i++) {
            System.out.print("Memory required for process #" + (i + 1) + ": ");
            process[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            memoryBestFit[i] = memory[i];
        }

        int[] temp = Arrays.copyOf(memory, n);
        Arrays.sort(temp);

        int[] outputBestFit = new int[p];
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

        System.out.println();
        System.out.println("Process No.\tMemory Block Allocated in Best Fit");
        for (int i = 0; i < p; i++) {
            System.out.print((i + 1) + "\t\t\t");
            if (outputBestFit[i] == -1)
                System.out.print("Memory not allocated\t");
            else
                System.out.print(outputBestFit[i] + "\t\t\t");
            System.out.println();
        }

        scanner.close();
    }
}
