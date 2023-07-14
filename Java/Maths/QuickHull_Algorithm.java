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
import java.util.HashSet;
import java.util.Set;

class Point {
    public int x, y;

    // Constructor
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Point other = (Point) obj;
        return x == other.x && y == other.y;
    }

    @Override
    public int hashCode() {
        return 31 * x + y;
    }
}

class QuickHull_Algorithm {
    // Find the side of a point 'p' with respect to the line segment 'a'-'b'
    private static int findSide(Point a, Point b, Point p) {
        // Computing the cross product of two vectors: the vector from 'a' to 'p' and the vector from 'a' to 'b' which determines which side of the line segment a point lies.
        int val = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

        if (val > 0)
            return 1;  // Point is on the left side
        else if (val < 0)
            return -1; // Point is on the right side
        else
            return 0;  // Point is collinear
    }

    // Returns a value proportional to the distance between the point p and the line joining the points a and b
    private static int lineDist(Point a, Point b, Point p) {
        return Math.abs((p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y));
    }

    // Recursive function to find the points on the convex hull
    private static void quickHull(Set<Point> points, Point a, Point b, int side, Set<Point> hull) {
        int maxDist = 0;
        Point maxDistPoint = null;

        // Find the point with the maximum distance from the line segment 'a'-'b' and also on the specified side of L
        for (Point p : points) {
            int currSide = findSide(a, b, p);
            int dist = lineDist(a, b, p);
            if (currSide == side && dist > maxDist) {
                maxDist = dist;
                maxDistPoint = p;
            }
        }

        // If no point is found, add the end points of the line segment to the convex hull
        if (maxDistPoint == null) {
            hull.add(a);
            hull.add(b);
            return;
        }

        // Recursively find the points on the convex hull on the two sides of the line segment divided by maxDistPoint
        quickHull(points, maxDistPoint, a, -findSide(maxDistPoint, a, b), hull);
        quickHull(points, maxDistPoint, b, -findSide(maxDistPoint, b, a), hull);
    }

    // Wrapper function to compute the convex hull using QuickHull algorithm
    private static Set<Point> computeConvexHull(Set<Point> points) {
        Set<Point> hull = new HashSet<>();

        // Find the leftmost and rightmost points
        Point minPoint = null;
        Point maxPoint = null;
        for (Point p : points) {
            if (minPoint == null || p.x < minPoint.x) {
                minPoint = p;
            }
            if (maxPoint == null || p.x > maxPoint.x) {
                maxPoint = p;
            }
        }

        // Compute the points on one side of the line segment 'minPoint'-'maxPoint'
        quickHull(points, minPoint, maxPoint, 1, hull);

        // Compute the points on the other side of the line segment 'minPoint'-'maxPoint'
        quickHull(points, minPoint, maxPoint, -1, hull);

        return hull;
    }

    public static void main(String[] args) {
        Set<Point> points = new HashSet<>();
        points.add(new Point(0, 3));
        points.add(new Point(1, 1));
        points.add(new Point(2, 2));
        points.add(new Point(4, 4));
        points.add(new Point(0, 0));
        points.add(new Point(1, 2));
        points.add(new Point(3, 1));
        points.add(new Point(3, 3));

        // numPoints should be >= 3 to form a triangle
        if (points.size() < 3) {
            System.out.println("Convex hull not possible");
            return;
        }

        // Compute the convex hull
        Set<Point> convexHull = computeConvexHull(points);

        // Print the points on the convex hull
        System.out.println("Points on the convex hull:");
        for (Point point : convexHull) {
            System.out.println("(" + point.x + ", " + point.y + ")");
        }
    }
}
