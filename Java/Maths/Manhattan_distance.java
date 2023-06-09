/*
 The Manhattan distance algorithm, also known as the L1 distance or taxicab distance, is a measure of the distance between two points in a grid-like structure. It is named after the distance a taxicab would travel in a city where movement is restricted to horizontal and vertical paths.
 The Manhattan distance between two points (x1, y1) and (x2, y2) is calculated as the sum of the absolute differences between their x-coordinates and y-coordinates:
 Manhattan distance = |x1 - x2| + |y1 - y2|
 */



 import java.util.Scanner;

public class Manhattan_distance {
    public static int manhattanDistance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x1, y1, x2, y2;

        // Get user input for the coordinates of the first point
        System.out.print("Enter the x-coordinate of the first point: ");
        x1 = scanner.nextInt();
        System.out.print("Enter the y-coordinate of the first point: ");
        y1 = scanner.nextInt();

        // Get user input for the coordinates of the second point
        System.out.print("Enter the x-coordinate of the second point: ");
        x2 = scanner.nextInt();
        System.out.print("Enter the y-coordinate of the second point: ");
        y2 = scanner.nextInt();

        // Calculate the Manhattan distance 
        int distance = manhattanDistance(x1, y1, x2, y2);

        // Print the calculated distance
        System.out.printf("The Manhattan distance between the points (%d, %d) and (%d, %d) is %d\n", x1, y1, x2, y2, distance);

        scanner.close();
    }
}