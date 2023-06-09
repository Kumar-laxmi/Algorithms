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

/*Explanation:

The towerOfHanoi function is defined with the same logic as in the C code.

The base case and the recursive steps are the same as explained before.

The main function is also similar to the C code, but it uses std::cout and std::cin for input/output instead of printf and scanf.

The user is prompted to enter the number of disks they want to solve the Tower of Hanoi puzzle for.

The towerOfHanoi function is called with the user-inputted number of disks, the source peg 'A', the destination peg 'C', and the auxiliary peg 'B'.

The function executes and prints each move required to solve the puzzle using std::cout.

Finally, the main function returns 0, indicating successful execution of the program.
*/
