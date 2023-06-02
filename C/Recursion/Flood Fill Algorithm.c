// Flood Fill Algorithm for 2D matrix with 4-directional movement (up, down, left, right) using DFS.

#include <stdio.h>

// Function to perform flood fill
void floodFill(int screen[][8], int x, int y, int newColor, int oldColor) {
    // Base cases
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return;
    
    if (screen[x][y] != oldColor)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newColor;

    // Recursively fill neighboring pixels in 4 directions
    floodFill(screen, x + 1, y, newColor, oldColor);
    floodFill(screen, x - 1, y, newColor, oldColor);
    floodFill(screen, x, y + 1, newColor, oldColor);
    floodFill(screen, x, y - 1, newColor, oldColor);
}

// Function to print the screen
void printScreen(int screen[][8]) {
    printf("Screen:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int screen[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    int x = 4; // x-coordinate of the starting point
    int y = 4; // y-coordinate of the starting point
    int newColor = 2; // New color to be filled

    printf("Before flood fill:\n");
    printScreen(screen);

    int oldColor = screen[x][y];
    floodFill(screen, x, y, newColor, oldColor);

    printf("After flood fill:\n");
    printScreen(screen);

    return 0;
}