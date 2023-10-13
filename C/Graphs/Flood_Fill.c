#include <stdio.h>

// Function to perform the flood fill algorithm
void floodFill(int image[4][4], int sr, int sc, int newColor, int originalColor)
{
    // Base case: If the current cell is out of bounds or has already been filled with the new color
    if (sr < 0 || sr >= 4 || sc < 0 || sc >= 4 || image[sr][sc] != originalColor)
        return;

    // Update the current cell with the new color
    image[sr][sc] = newColor;

    // Recursively fill the neighboring cells in all four directions
    floodFill(image, sr + 1, sc, newColor, originalColor);
    floodFill(image, sr - 1, sc, newColor, originalColor);
    floodFill(image, sr, sc + 1, newColor, originalColor);
    floodFill(image, sr, sc - 1, newColor, originalColor);
}

int main()
{
    // Sample image represented as a 2D array
    int image[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 0},
    };

    int sr = 1;       // Starting row
    int sc = 1;       // Starting column
    int newColor = 2; // New color to be filled

    int originalColor = image[sr][sc]; // Store the original color for comparison

    // Perform the flood fill algorithm
    floodFill(image, sr, sc, newColor, originalColor);

    // Print the updated image
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
