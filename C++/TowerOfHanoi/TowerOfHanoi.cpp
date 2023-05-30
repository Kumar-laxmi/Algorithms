#include <iostream>

// Function to move a disk from the source peg to the destination peg
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    // Base case: If only one disk is present, move it directly from source to destination
    if (n == 1)
    {
        std::cout << "Move disk 1 from peg " << source << " to peg " << destination << std::endl;
        return;
    }

    // Move (n-1) disks from the source peg to the auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the remaining disk from the source peg to the destination peg
    std::cout << "Move disk " << n << " from peg " << source << " to peg " << destination << std::endl;

    // Move the (n-1) disks from the auxiliary peg to the destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    std::cout << "Tower of Hanoi solution:" << std::endl;
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}
