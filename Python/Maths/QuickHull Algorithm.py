#  Quickhull is a convex hull algorithm that is used to find the convex hull of a set of points in a two-dimensional space.
#   The convex hull of a set of points is the smallest convex polygon that encloses all the points.
#  Applications include: collision avoidance, shape analysis, pattern recognition etc, image processing.


#  The QuickHull algorithm follows a divide-and-conquer approach and is known for its efficiency. High - level overview  of how the algorithm works:

#  1. Find the point with the minimum and maximum x-coordinate values. These points will be part of the convex hull.
#  2. Divide the points into two subsets based on which side of the line formed by the two points each point lies. The points will be partitioned into two groups: 
#  those that lie on the "left" side of the line and those that lie on the "right" side.
#  3. For each of the two subsets, find the point that is farthest from the line. These points will also be part of the convex hull.
#  4. Repeat steps 2 and 3 recursively for the subsets formed by the farthest points and the corresponding sides of the line. 
#  This recursion continues until no more points are left on one side of a line, at which point the algorithm terminates.
#  5. Combine the convex hulls obtained from the recursive steps to form the final convex hull.

#  Worst case time complexity: O(N^2)
#  Average case time complexity: O(N log N)
#  Best case time complexity: O(N log N)
#  Space complexity: O(N)

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def find_side(self, a, b):
        val = (self.y - a.y) * (b.x - a.x) - (self.x - a.x) * (b.y - a.y)
        if val > 0:
            return 1  # Point is on the left side
        elif val < 0:
            return -1  # Point is on the right side
        else:
            return 0  # Point is collinear

    def line_dist(self, a, b):
        return abs((self.y - a.y) * (b.x - a.x) - (self.x - a.x) * (b.y - a.y))


def quick_hull(points, a, b, side, hull):
    num_points = len(points)
    max_dist = 0
    max_dist_index = -1

    # Find the point with the maximum distance from the line segment 'a'-'b' and also on the specified side of L
    for i in range(num_points):
        curr_side = points[i].find_side(a, b)
        dist = points[i].line_dist(a, b)
        if curr_side == side and dist > max_dist:  # side can have value 1 or -1 specifying each of the parts made by the line L
            max_dist = dist
            max_dist_index = i

    # If no point is found, add the end points of the line segment to the convex hull
    if max_dist_index == -1:
        hull.add(a)
        hull.add(b)
        return

    # Recursively find the points on the convex hull on the two sides of the line segment divided by points[max_dist_index]
    quick_hull(points, points[max_dist_index], a, -points[max_dist_index].find_side(a, b), hull)
    quick_hull(points, points[max_dist_index], b, -points[max_dist_index].find_side(b, a), hull)


def compute_convex_hull(points):
    num_points = len(points)
    hull = set()

    # Find the leftmost and rightmost points
    min_point = 0
    max_point = 0
    for i in range(1, num_points):
        if points[i].x < points[min_point].x:
            min_point = i
        if points[i].x > points[max_point].x:
            max_point = i

    # Compute the points on one side of the line segment 'min_point'-'max_point'
    quick_hull(points, points[min_point], points[max_point], 1, hull)

    # Compute the points on the other side of the line segment 'min_point'-'max_point'
    quick_hull(points, points[min_point], points[max_point], -1, hull)

    return hull


# Create a list of points
points = [
    Point(0, 3),
    Point(1, 1),
    Point(2, 2),
    Point(4, 4),
    Point(0, 0),
    Point(1, 2),
    Point(3, 1),
    Point(3, 3)
]

# num_points should be >= 3 to make a triangle
if len(points) < 3:
    print("Convex hull not possible")
else:
    # Compute the convex hull
    convex_hull = compute_convex_hull(points)

    # Print the points on the convex hull
    print("Points on the convex hull:")
    for point in convex_hull:
        print("({}, {})".format(point.x, point.y))
