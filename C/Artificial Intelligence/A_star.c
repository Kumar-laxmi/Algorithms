#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROW 9
#define COL 10

// Structure to hold the necessary parameters
struct Cell {
    int parent_i, parent_j;
    double f, g, h;
};

// Function to check whether a given cell (row, col) is a valid cell or not
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check whether the given cell is blocked or not
bool isUnblocked(int grid[ROW][COL], int row, int col) {
    return grid[row][col] == 1;
}

// Function to check whether the destination cell has been reached or not
bool isDestination(int row, int col, int dest[2]) {
    return (row == dest[0] && col == dest[1]);
}

// Function to calculate the 'h' heuristics
double calculateHValue(int row, int col, int dest[2]) {
    return sqrt((row - dest[0]) * (row - dest[0]) + (col - dest[1]) * (col - dest[1]));
}

// Function to trace the path from the source to destination
void tracePath(struct Cell cellDetails[ROW][COL], int dest[2]) {
    printf("The Path is ");
    int row = dest[0], col = dest[1];

    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
        printf("-> (%d,%d) ", row, col);
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    printf("-> (%d,%d)\n", row, col);
}

// Function to find the shortest path between a given source cell to a destination cell according to A* Search Algorithm
void aStarSearch(int grid[ROW][COL], int src[2], int dest[2]) {
    // If the source is out of range
    if (!isValid(src[0], src[1])) {
        printf("Source is invalid\n");
        return;
    }

    // If the destination is out of range
    if (!isValid(dest[0], dest[1])) {
        printf("Destination is invalid\n");
        return;
    }

    // Either the source or the destination is blocked
    if (!isUnblocked(grid, src[0], src[1]) || !isUnblocked(grid, dest[0], dest[1])) {
        printf("Source or the destination is blocked\n");
        return;
    }

    // If the destination cell is the same as the source cell
    if (isDestination(src[0], src[1], dest)) {
        printf("We are already at the destination\n");
        return;
    }

    // Create a closed list and initialize it to false, which means that no cell has been included yet
    bool closedList[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closedList[i][j] = false;
        }
    }

    // Declare a 2D array of Cell objects to hold the details of that cell
    struct Cell cellDetails[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
            cellDetails[i][j].f = INFINITY;
            cellDetails[i][j].g = INFINITY;
            cellDetails[i][j].h = INFINITY;
        }
    }

    int i = src[0], j = src[1];
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    // Create an open list (PriorityQueue) using a custom comparator
    typedef struct {
        double f;
        int cell[2];
    } Pair;
    Pair openList[ROW * COL];
    int openListSize = 1; // Initialize with 1 to represent the source cell
    openList[0].f = 0.0;
    openList[0].cell[0] = i;
    openList[0].cell[1] = j;

    // We set this boolean value as false as initially, the destination is not reached
    bool foundDest = false;

    // Define the 8 possible movements from a cell
    int movesRow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int movesCol[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (openListSize > 0) {
        // Find the cell with the least f value from the open list
        double minF = INFINITY;
        int minIndex = 0;
        for (int k = 0; k < openListSize; k++) {
            if (openList[k].f < minF) {
                minF = openList[k].f;
                minIndex = k;
            }
        }

        // Remove the cell with the least f value from the open list
        Pair current = openList[minIndex];
        openList[minIndex] = openList[openListSize - 1];
        openListSize--;

        i = current.cell[0];
        j = current.cell[1];

        // Add this cell to the closed list
        closedList[i][j] = true;

        for (int k = 0; k < 8; k++) {
            // Generate all the 8 successors of this cell
            int new_i = i + movesRow[k];
            int new_j = j + movesCol[k];

            // Only process this cell if this is a valid one
            if (isValid(new_i, new_j)) {
                // If the destination cell is the same as the current successor
                if (isDestination(new_i, new_j, dest)) {
                    // Set the Parent of the destination cell
                    cellDetails[new_i][new_j].parent_i = i;
                    cellDetails[new_i][new_j].parent_j = j;
                    printf("The destination cell is found\n");
                    tracePath(cellDetails, dest);
                    foundDest = true;
                    return;
                }

                // If the successor is already on the closed list or if it is blocked, then ignore it
                if (!closedList[new_i][new_j] && isUnblocked(grid, new_i, new_j)) {
                    double gNew = cellDetails[i][j].g + 1.0;
                    double hNew = calculateHValue(new_i, new_j, dest);
                    double fNew = gNew + hNew;

                    // If it isn’t on the open list, add it to the open list
                    if (cellDetails[new_i][new_j].f == INFINITY || cellDetails[new_i][new_j].f > fNew) {
                        openList[openListSize].f = fNew;
                        openList[openListSize].cell[0] = new_i;
                        openList[openListSize].cell[1] = new_j;

                        // Update the details of this cell
                        cellDetails[new_i][new_j].f = fNew;
                        cellDetails[new_i][new_j].g = gNew;
                        cellDetails[new_i][new_j].h = hNew;
                        cellDetails[new_i][new_j].parent_i = i;
                        cellDetails[new_i][new_j].parent_j = j;

                        openListSize++;
                    }
                }
            }
        }
    }

    // If the destination cell is not found, print an error message
    if (!foundDest) {
        printf("Failed to find the destination cell\n");
    }
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}
    };

    int src[2] = {0, 0};
    int dest[2] = {8, 9};

    aStarSearch(grid, src, dest);

    return 0;
}
