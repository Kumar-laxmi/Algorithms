#include <stdio.h>

// Function to move a disk from the source peg to the destination peg
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    // Base case: If only one disk is present, move it directly from source to destination
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }

    // Move (n-1) disks from the source peg to the auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the remaining disk from the source peg to the destination peg
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);

    // Move the (n-1) disks from the auxiliary peg to the destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    printf("Tower of Hanoi solution:\n");
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}

/*Explanation:

The towerOfHanoi function is a recursive function that takes four parameters:

n: the number of disks to be moved
source: the source peg from which the disks are initially placed
destination: the destination peg to which the disks are to be moved
auxiliary: the auxiliary peg used for temporarily holding the disks
The base case of the recursive function is when there is only one disk (n == 1). In this case, the function simply prints the move from the source peg to the destination peg.

For the case of more than one disk, the function follows the steps of the Tower of Hanoi algorithm:

Step 1: Move (n-1) disks from the source peg to the auxiliary peg using recursion. The destination peg is used as the auxiliary peg in this step.
Step 2: Move the remaining disk from the source peg to the destination peg directly.
Step 3: Move the (n-1) disks from the auxiliary peg to the destination peg using recursion. The source peg is used as the auxiliary peg in this step.
In the main function, the user is prompted to enter the number of disks they want to solve the Tower of Hanoi puzzle for.

The towerOfHanoi function is then called with the user-inputted number of disks, the source peg 'A', the destination peg 'C', and the auxiliary peg 'B'.

The function executes and prints each move required to solve the puzzle.

Finally, the main function returns 0, indicating successful execution of the program.
*/
