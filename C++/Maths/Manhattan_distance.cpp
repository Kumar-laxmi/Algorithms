/*
The Manhattan distance algorithm, also known as the L1 distance or taxicab distance, is a measure of the distance between two points in a grid-like structure. It is named after the distance a taxicab would travel in a city where movement is restricted to horizontal and vertical paths.
The Manhattan distance between two points (x1, y1) and (x2, y2) is calculated as the sum of the absolute differences between their x-coordinates and y-coordinates:
Manhattan distance = |x1 - x2| + |y1 - y2|
*/


#include <iostream>
#include <cstdlib>
using namespace std;

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int x1, y1, x2, y2;

    // Get user input for the coordinates of the first point
    cout<<"Enter the x-coordinate of the first point: ";
    cin>>x1;
    cout<<"Enter the y-coordinate of the first point: ";
    cin>>y1;

    // Get user input for the coordinates of the second point
    cout<<"Enter the x-coordinate of the second point: ";
    cin>>x2;
    cout<<"Enter the y-coordinate of the second point: ";
    cin>>y2;

    // Calculate the Manhattan distance 
    int distance = manhattan_distance(x1, y1, x2, y2);

    // Print the calculated distance
    cout<<"The Manhattan distance between the points (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is "<<distance <<endl;

    return 0;
}