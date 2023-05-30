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
