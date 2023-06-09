/*
Grundy Numbers are a mathematical concept used in game theory to determine which player has the advantage in a game of two players. The Grundy value of a game state is defined recursively based on the Grundy values of its possible subsequent states. This recursive definition allows for efficient calculation of the Grundy value for any given state, which can then be used to determine the optimal moves for the player. Grundy Numbers have practical applications in game design, cryptography, and network security.

To calculate the Grundy number for a given game position, the following steps are typically followed:

1. Identify the possible moves from the current position.
2. Calculate the Grundy numbers for each of the possible moves recursively.
3. Determine the smallest non-negative integer that is not present in the set of Grundy numbers obtained from the possible moves.
4. Assign this minimum excluded value as the Grundy number for the current position.
*/


#include <stdio.h>
#include <stdlib.h>

// Function to calculate Grundy number for a given position
int calculate_grundy(int position, int* table, const int* moves, int numMoves) {
    if(position == 0){
        return 0;
    }

    if(table[position] != -1){
        return table[position];
    }

    int* grundySet = (int*)malloc((position + 1)*sizeof(int));
    for(int i = 0; i <= position; i++){
        grundySet[i] = 0;
    }

    // Calculate Grundy numbers for all possible moves
    for(int i = 0; i < numMoves; i++){
        int move = moves[i];
        if (position >= move) {
            grundySet[calculate_grundy(position - move, table, moves, numMoves)] = 1;
        }
    }

    // Find the smallest non-negative integer not present in the set
    int grundyNum = 0;
    while(grundySet[grundyNum] != 0){
        grundyNum++;
    }

    free(grundySet);

    table[position] = grundyNum;
    return grundyNum;
}

int main() {
    int n;
    printf("Enter the maximum position: ");
    scanf("%d", &n);

    // List of possible moves - needs to be specified beforehand
    int moves[] = {1, 5, 8};
    int numMoves = sizeof(moves)/sizeof(moves[0]);

    // Memoization table
    int* table = (int*)malloc((n + 1)*sizeof(int));
    for(int i = 0; i <= n; i++){
        table[i] = -1;
    }

    // Calculate Grundy numbers for positions 0 to n (inclusive)
    for(int i = 0; i <= n; i++){
        int grundy = calculate_grundy(i, table, moves, numMoves);
        printf("Grundy number for position %d is %d\n", i, grundy);
    }

    free(table);

    return 0;
}
