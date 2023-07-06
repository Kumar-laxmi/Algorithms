'''
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

Below is the implementation of Convex Hull Algorithm using the Graham's scan algorithm in PYTHON
'''

# Program starts

# Structure to represent a 2D point
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Function to determine the orientation of three points
def orientation(p, q, r):
    val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)
    if val == 0:
        return 0             # Collinear points
    return 1 if val > 0 else 2 # Clockwise or counterclockwise

# Function to find the convex hull of a set of points
def convexHull(points):
    n = len(points)
    if n < 3:
        return # Not enough points for a convex hull

    hull = [] # Stores the points in the convex hull

    # Find the leftmost point
    leftmost = 0
    for i in range(1, n):
        if points[i].x < points[leftmost].x:
            leftmost = i

    p = leftmost
    q = None
    while True:
        hull.append(points[p]) # Add the current point to the hull
        q = (p + 1) % n       # Set the next point on the hull

        # Find the next point on the hull by checking the orientation of all points
        for i in range(n):
            if orientation(points[p], points[i], points[q]) == 2:
                q = i
        p = q

        if p == leftmost:
            break

    # Print the points in the convex hull
    for point in hull:
        print(f"({point.x}, {point.y})")

n = int(input("\nEnter the number of points: "))
points = []

print("\nEnter the coordinates of the points")
for i in range(n):
    x = int(input("\nx = "))
    y = int(input("y = "))
    points.append(Point(x, y))

print("\nConvex Hull - \n")
convexHull(points)
print("\n")
