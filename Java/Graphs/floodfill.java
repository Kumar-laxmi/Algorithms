import java.util.Arrays;

public class floodfill {

    // Function to perform the flood fill algorithm
    public static void floodFill(int[][] image, int sr, int sc, int newColor, int originalColor) {
        // Base case: If the current cell is out of bounds or has already been filled with the new color
        if (sr < 0 || sr >= image.length || sc < 0 || sc >= image[0].length || image[sr][sc] != originalColor)
            return;

        // Update the current cell with the new color
        image[sr][sc] = newColor;

        // Recursively fill the neighboring cells in all four directions
        floodFill(image, sr + 1, sc, newColor, originalColor);
        floodFill(image, sr - 1, sc, newColor, originalColor);
        floodFill(image, sr, sc + 1, newColor, originalColor);
        floodFill(image, sr, sc - 1, newColor, originalColor);
    }

    public static void main(String[] args) {
        // Sample image represented as a 2D array
        int[][] image = {
            {1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 0, 1, 0},
            {1, 0, 1, 0},
        };

        int sr = 1;         // Starting row
        int sc = 1;         // Starting column
        int newColor = 2;   // New color to be filled

        int originalColor = image[sr][sc]; // Store the original color for comparison

        // Perform the flood fill algorithm
        floodFill(image, sr, sc, newColor, originalColor);

        // Print the updated image
        for (int[] row : image) {
            System.out.println(Arrays.toString(row));
        }
    }
}
