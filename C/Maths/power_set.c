// Program to generate power set of a set of elements in C language.

/*In C language, we can calculate the power set of a set using various approaches.
The power set of a set is the collection of all possible subsets of that set.
 Here's an approach to generate the power set using a bit manipulation technique.
 */


// APPROACH 

/*In this approach, we use a counter variable to iterate through all possible combinations. 
For each counter value, we check the corresponding bits and print the elements accordingly.*/





// EXPLANATION

/*Given is  a step-by-step explanation of the code:

1. The printPowerSet function takes an array set and its size n as parameters.

2. We calculate the size of the power set by left-shifting 1 by n (equivalent to 2^n).

3. The outer loop iterates from 0 to powerSetSize - 1, representing all possible combinations.

4. Inside the outer loop, we print the opening brace and start iterating through each element in the set.

5. For each element, we check if the corresponding bit in the counter is set. If set, we print the element.

6. After printing all the elements, we print the closing brace and move to the next combination.

7. The main function initializes the input set, calculates its size, and calls the printPowerSet function.

8. When you run this program, it will generate and print all the possible subsets of the given set.
 
 */



// SOURCE CODE

#include <stdio.h>

void printPowerSet(int set[], int n) {
    // Calculate the size of the power set
    int powerSetSize = 1 << n;

    // Generate all possible subsets
    for (int counter = 0; counter < powerSetSize; counter++) {
        printf("{ ");

        // Iterate through each element in the set
        for (int j = 0; j < n; j++) {
            // Check if j-th bit in the counter is set
            if (counter & (1 << j)) {
                printf("%d ", set[j]);
            }
        }

        printf("}\n");
    }
}

int main() {
    int set[] = {1, 2, 3};
    int n = sizeof(set) / sizeof(set[0]);

    printf("Power set:\n");
    printPowerSet(set, n);

    return 0;
}



