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

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Point {
    public:
    int x, y;

    // Constructor
    Point(int x, int y) : x(x), y(y) {}
     bool operator<(const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

// Find the side of a point 'p' with respect to the line segment 'a'-'b'
int findSide(Point a, Point b, Point p) {
    // Computing the cross product of two vectors: the vector from 'a' to 'p' and the vector from 'a' to 'b' which determines which side of the line segment a point lies.
    int val = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

    if (val > 0)
        return 1;  // Point is on the left side
    else if (val < 0)
        return -1; // Point is on the right side
    else
        return 0;  // Point is collinear
}
// Returns a value proportional to the distance  between the point p and the line joining the points a and b
int lineDist(Point a, Point b, Point p)
{
return abs ((p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y));
}


// Recursive function to find the points on the convex hull
void quickHull( vector<Point>& points, Point a, Point b, int side, set<Point>& hull) {
    int numPoints = points.size();
    int maxDist = 0;
    int maxDistIndex = -1;
    
    // Find the point with the maximum distance from the line segment 'a'-'b' and also on the specified side of L
    for (int i = 0; i < numPoints; i++) {
        int currSide = findSide(a, b, points[i]);
        int dist = lineDist(a,b,points[i]);
        if (currSide == side and dist > maxDist) { //side can have value 1 or -1 specifying each of the parts made by the line L
            maxDist = dist;
            maxDistIndex = i;
        }
    }
    // If no point is found, add the end points of the line segment to the convex hull
    if (maxDistIndex == -1) {
        hull.insert(a);
        hull.insert(b);
        return;
    }

    // Recursively find the points on the convex hull on the two sides of the line segment divided by points[maxDistIndex]
    quickHull(points, points[maxDistIndex], a, -findSide(points[maxDistIndex], a, b), hull);
    quickHull(points, points[maxDistIndex], b, -findSide(points[maxDistIndex], b, a), hull);
}

// Wrapper function to compute the convex hull using QuickHull algorithm

set<Point> computeConvexHull( vector<Point>& points) {
    int numPoints = points.size();
    
    set<Point> hull;

    // Find the leftmost and rightmost points
    int minPoint = 0, maxPoint = 0;
    for (int i = 1; i < numPoints; i++) {
        if (points[i].x < points[minPoint].x)
            minPoint = i;
        if (points[i].x > points[maxPoint].x)
            maxPoint = i;
    }

    // Compute the points on the one side of the line segment 'minPoint'-'maxPoint'
    quickHull(points, points[minPoint], points[maxPoint], 1, hull);
    
    // Compute the points on the other side of the line segment 'minPoint'-'maxPoint'
    quickHull(points, points[minPoint], points[maxPoint], -1, hull);

    return hull;
}

int main() {
    // Create a vector of points
    
    vector<Point> points = {
        Point(0, 3),
        Point(1, 1),
        Point(2, 2),
        Point(4, 4),
        Point(0, 0),
        Point(1, 2),
        Point(3, 1),
        Point(3, 3)
    };
    
    // numPoints should be > =3 to make a triangle
    if (points.size() < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }
    // Compute the convex hull
    
    set<Point> convexHull = computeConvexHull(points);

    // Print the points on the convex hull
    
    cout << "Points on the convex hull:\n";
    for (const auto& point : convexHull) {
        
        cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}