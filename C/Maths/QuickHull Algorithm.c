// Quickhull is a convex hull algorithm that is used to find the convex hull of a set of points in a two-dimensional space.
//  The convex hull of a set of points is the smallest convex polygon that encloses all the points.
// Applications include: collision avoidance, shape analysis, pattern recognition etc, image processing.


// The QuickHull algorithm follows a divide-and-conquer approach and is known for its efficiency. High - level overview  of how the algorithm works:

// 1. Find the point with the minimum and maximum x-coordinate values. These points will be part of the convex hull.
// 2. Divide the points into two subsets based on which side of the line formed by the two points each point lies. The points will be partitioned into two groups: 
// those that lie on the "left" side of the line and those that lie on the "right" side.
// 3. For each of the two subsets, find the point that is farthest from the line. These points will also be part of the convex hull.
// 4. Repeat steps 2 and 3 recursively for the subsets formed by the farthest points and the corresponding sides of the line. 
// This recursion continues until no more points are left on one side of a line, at which point the algorithm terminates.
// 5. Combine the convex hulls obtained from the recursive steps to form the final convex hull.

// Worst case time complexity: O(N^2)
// Average case time complexity: O(N log N)
// Best case time complexity: O(N log N)
// Space complexity: O(N)

#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

// Find the side of a point 'p' with respect to the line segment 'a'-'b'
int findSide(struct Point a, struct Point b, struct Point p) {
    int val = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

    if (val > 0)
        return 1;  // Point is on the left side
    else if (val < 0)
        return -1; // Point is on the right side
    else
        return 0;  // Point is collinear
}

// Returns a value proportional to the distance between the point p and the line joining the points a and b
int lineDist(struct Point a, struct Point b, struct Point p) {
    return abs((p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y));
}

// Recursive function to find the points on the convex hull
void quickHull(struct Point points[], int numPoints, struct Point a, struct Point b, int side, struct Point hull[], int* hullSize) {
    int maxDist = 0;
    int maxDistIndex = -1;

    // Find the point with the maximum distance from the line segment 'a'-'b' and also on the specified side of L
    for (int i = 0; i < numPoints; i++) {
        int currSide = findSide(a, b, points[i]);
        int dist = lineDist(a, b, points[i]);
        if (currSide == side && dist > maxDist) { // side can have value 1 or -1 specifying each of the parts made by the line L
            maxDist = dist;
            maxDistIndex = i;
        }
    }
    // If no point is found, add the end points of the line segment to the convex hull
    if (maxDistIndex == -1) {
        // Check if a and b already exist in the hull
        int aExists = 0, bExists = 0;
        for (int i = 0; i < *hullSize; i++) {
            if (hull[i].x == a.x && hull[i].y == a.y) {
                aExists = 1;
            }
            if (hull[i].x == b.x && hull[i].y == b.y) {
                bExists = 1;
            }
        }

        // Add a and b only if they don't already exist
        if (!aExists) {
            hull[*hullSize] = a;
            (*hullSize)++;
        }
        if (!bExists) {
            hull[*hullSize] = b;
            (*hullSize)++;
        }
        return;
    }

    // Recursively find the points on the convex hull on the two sides of the line segment divided by points[maxDistIndex]
    quickHull(points, numPoints, points[maxDistIndex], a, -findSide(points[maxDistIndex], a, b), hull, hullSize);
    quickHull(points, numPoints, points[maxDistIndex], b, -findSide(points[maxDistIndex], b, a), hull, hullSize);
}

// Wrapper function to compute the convex hull using QuickHull algorithm
void computeConvexHull(struct Point points[], int numPoints, struct Point hull[], int* hullSize) {
    // Find the leftmost and rightmost points
    int minPoint = 0, maxPoint = 0;
    for (int i = 1; i < numPoints; i++) {
        if (points[i].x < points[minPoint].x)
            minPoint = i;
        if (points[i].x > points[maxPoint].x)
            maxPoint = i;
    }

    // Compute the points on one side of the line segment 'minPoint'-'maxPoint'
    quickHull(points, numPoints, points[minPoint], points[maxPoint], 1, hull, hullSize);

    // Compute the points on the other side of the line segment 'minPoint'-'maxPoint'
    quickHull(points, numPoints, points[minPoint], points[maxPoint], -1, hull, hullSize);
}

int main() {
    // Create an array of points
    struct Point points[] = {
        {0, 3},
        {1, 1},
        {2, 2},
        {4, 4},
        {0, 0},
        {1, 2},
        {3, 1},
        {3, 3}
    };
    int numPoints = sizeof(points) / sizeof(points[0]);

    // numPoints should be >= 3 to make a triangle
    if (numPoints < 3) {
        printf("Convex hull not possible\n");
        return 0;
    }

    // Compute the convex hull
    struct Point* hull = malloc(numPoints * sizeof(struct Point));
    int hullSize = 0;
    computeConvexHull(points, numPoints, hull, &hullSize);

    // Print the points on the convex hull
    printf("Points on the convex hull:\n");
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }

    return 0;
}
