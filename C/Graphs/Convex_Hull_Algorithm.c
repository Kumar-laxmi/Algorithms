/*
------------------------------------- Convex Hull Algorithm -------------------------------------

Approach

1. Create a vector to store the points.

2. Implement the orientation function that determines the orientation of three points.
    - Given three points p, q, and r, calculate the cross product of the vectors (q - p) and (r - q).
    - If the cross product is zero, the points are collinear.
    - If the cross product is positive, the points are in counterclockwise order (left turn).
    - If the cross product is negative, the points are in clockwise order (right turn).

3. Implement the convexHull function that calculates the convex hull for the given points.
    - If the number of points is less than 3, return.
    - Find the leftmost point as the starting point and initialize an empty vector for the convex hull.
    - Set the current point p as the leftmost point.
    - Iterate until the current point p becomes the leftmost point again:
    - Add the current point p to the convex hull vector.
    - Initialize the next point q as the next point on the convex hull (initially set as the point following p).
    - Iterate through all points and find the point q that makes the largest counterclockwise turn from p.
    - Set the current point p as the next point q.
    - Print the points in the convex hull.

4. Call the convexHull function with the vector of points.

5. The convex hull points are printed, representing the outer boundary of the given set of points.

Below is the implementation of Convex Hull Algorithm using the Graham's scan algorithm in C
*/

// Program starts

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a 2D point
struct Point
{
    int x, y;
};

// Function to determine the orientation of three points
int orientation(const struct Point *p, const struct Point *q, const struct Point *r)
{
    int val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
    if (val == 0)
        return 0;             // Collinear points
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Function to find the convex hull of a set of points
void convexHull(struct Point points[], int n)
{
    if (n < 3)
        return; // Not enough points for a convex hull

    struct Point hull[n]; // Stores the points in the convex hull

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    int p = leftmost, q;
    int m = 0;
    do
    {
        hull[m] = points[p]; // Add the current point to the hull
        q = (p + 1) % n;     // Set the next point on the hull

        // Find the next point on the hull by checking the orientation of all points
        for (int i = 0; i < n; i++)
        {
            if (orientation(&points[p], &points[i], &points[q]) == 2)
                q = i;
        }
        p = q;
        m++;
    } while (p != leftmost);

    // Print the points in the convex hull
    for (int i = 0; i < m; i++)
    {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of points: ");
    scanf("%d", &n);

    struct Point points[n]; // Create an array to store the points
    printf("\nEnter the coordinates of the points:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nx = ");
        scanf("%d", &points[i].x);
        printf("y = ");
        scanf("%d", &points[i].y);
    }

    printf("\nConvex Hull - \n\n");
    convexHull(points, n); // Calculate and print the convex hull
    printf("\n");

    return 0;
}
