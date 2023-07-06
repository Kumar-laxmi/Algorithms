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

Below is the implementation of Convex Hull Algorithm using the Graham's scan algorithm in JAVA
*/

// Program starts

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Structure to represent a 2D point
class Point {
    int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Convex_Hull_Algorithm {
    // Function to determine the orientation of three points
    static int orientation(Point p, Point q, Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0)
            return 0; // Collinear points
        return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
    }

    // Function to find the convex hull of a set of points
    static void convexHull(List<Point> points) {
        int n = points.size();
        if (n < 3)
            return; // Not enough points for a convex hull

        List<Point> hull = new ArrayList<>(); // Stores the points in the convex hull

        // Find the leftmost point
        int leftmost = 0;
        for (int i = 1; i < n; i++) {
            if (points.get(i).x < points.get(leftmost).x)
                leftmost = i;
        }

        int p = leftmost, q;
        do {
            hull.add(points.get(p)); // Add the current point to the hull
            q = (p + 1) % n; // Set the next point on the hull

            // Find the next point on the hull by checking the orientation of all points
            for (int i = 0; i < n; i++) {
                if (orientation(points.get(p), points.get(i), points.get(q)) == 2)
                    q = i;
            }
            p = q;
        } while (p != leftmost);

        // Print the points in the convex hull
        for (Point point : hull) {
            System.out.println("(" + point.x + ", " + point.y + ")");
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("\nEnter the number of points: ");
            int n = scanner.nextInt();

            List<Point> points = new ArrayList<>();
            System.out.println("\nEnter the coordinates of the points:");
            for (int i = 0; i < n; i++) {
                System.out.print("\nx = ");
                int x = scanner.nextInt();
                System.out.print("y = ");
                int y = scanner.nextInt();
                points.add(new Point(x, y));
            }

            System.out.println("\nConvex Hull - \n");
            convexHull(points);
            System.out.println("\n");
        }
    }
}
