/*
The Manhattan distance algorithm, also known as the L1 distance or taxicab distance, is a measure of the distance between two points in a grid-like structure. It is named after the distance a taxicab would travel in a city where movement is restricted to horizontal and vertical paths.
The Manhattan distance between two points (x1, y1) and (x2, y2) is calculated as the sum of the absolute differences between their x-coordinates and y-coordinates:
Manhattan distance = |x1 - x2| + |y1 - y2|
*/


#include <stdio.h>
#include <stdlib.h>

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int x1, y1, x2, y2;

    // Get user input for the coordinates of the first point
    printf("Enter the x-coordinate of the first point: ");
    scanf("%d", &x1);
    printf("Enter the y-coordinate of the first point: ");
    scanf("%d", &y1);

    // Get user input for the coordinates of the second point
    printf("Enter the x-coordinate of the second point: ");
    scanf("%d", &x2);
    printf("Enter the y-coordinate of the second point: ");
    scanf("%d", &y2);

    // Calculate the Manhattan distance 
    int distance = manhattan_distance(x1, y1, x2, y2);

    // Print the calculated distance
    printf("The Manhattan distance between the points (%d, %d) and (%d, %d) is %d\n", x1, y1, x2, y2, distance);

    return 0;
}