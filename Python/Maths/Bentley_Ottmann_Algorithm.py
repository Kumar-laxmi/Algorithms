'''
Title: Efficient Line Segment Intersection Detection Using the Sweep Line Algorithm

Introduction:
    In computational geometry, the problem of detecting intersections between line segments is a fundamental task with various applications. While a naive approach involves comparing every pair of line segments of O(n^2), the Sweep Line Algorithm offers a more efficient solution with a time complexity of O(nlogn).

The Sweep Line Algorithm:
    The Sweep Line Algorithm tackles the line segment intersection problem by incrementally sweeping a vertical line from left to right across the line segments. By maintaining an ordered set of active line segments, it efficiently determines if any two line segments intersect.

Algorithm:
    Sorting the End Points:
        - Represent each line segment with its two end points.
        - Sort the end points along the x-axis from left to right.
        - Mark each point as the left or right endpoint of its corresponding line segment.
        - Time Complexity: O(nlogn)
    Sweeping the Vertical Line:
        - Start from the leftmost point and sweep a vertical line from left to right.
        - For each encountered point, perform the following operations:
        a) Left Endpoint:
            - If the current point is a left endpoint, check for intersections with the line segments directly above and below it.
            - Consider only active line segments (segments whose right endpoints have not been encountered yet).
            - Add the current line segment to the active line segment set.
            - Time Complexity: O(logn) for each intersection check, and there can be at most n intersection checks in total.
        b) Right Endpoint:
            - If the current point is a right endpoint, remove its corresponding line segment from the active line segment set.
            - Check if the two neighboring line segments (immediately above and below the removed segment) intersect with each other.
            - Time Complexity: O(logn) for each intersection check, and there can be at most two intersection checks.
            - Time Complexity: O(nlogn) for all point operations, as each point is processed once.

Overall Time Complexity:
    The time complexity of sorting the end points is O(nlogn). The time complexity of sweeping the vertical line is O(nlogn) for point operations. Therefore, the overall time complexity of the algorithm is O(nlogn).

Efficient Data Structures:
    Prob: In the second step of the algorithm, we need to efficiently store and manipulate the active line segments. This requires the following operations to be performed optimally:
        a) Insertion and Deletion of a new line segment.
        b) Finding the predecessor and successor line segments based on their y-coordinate values.
    Sol: To accomplish these operations efficiently, we can utilize self-balancing binary search trees (BSTs).With a self-balancing BST, all the aforementioned operations can be performed in O(logn) time, ensuring an efficient implementation of the Sweep Line Algorithm.

Conclusion:
    The Sweep Line Algorithm provides an efficient solution to the problem of detecting intersections between line segments. By employing a sweeping vertical line and utilizing self-balancing binary search trees, we can achieve a time complexity of O(nlogn) for this task. This algorithm finds applications in various geometric problems, making it a valuable tool in computational geometry.

Credit link:- https://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/
'''
# A point in 2D plane


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# A line segment with left and right end points


class Segment:
    def __init__(self, left, right):
        self.left = left
        self.right = right

# An event has a point, the position
# of the point (whether left or right), and
# the index of the point in the original input
# array of segments.


class Event:
    def __init__(self, x, y, isLeft, index):
        self.x = x
        self.y = y
        self.isLeft = isLeft
        self.index = index

    # By defining this less-than operator, the sorted data structure can keep the events sorted in ascending order of y coordinates.
    # If two events have the same y coordinate, they are sorted based on their x coordinates.
    def __lt__(self, other):
        if self.y == other.y:
            return self.x < other.x
        return self.y < other.y

# Given three collinear points p, q, r, the function checks if
# point q lies on line segment 'pr'


def onSegment(p, q, r):
    if q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y):
        return True
    return False

# To find the orientation of an ordered triplet (p, q, r).
# The function returns the following values:
# 0 --> p, q, and r are collinear
# 1 --> Clockwise
# 2 --> Counterclockwise


def orientation(p, q, r):
    val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)
    if val == 0:
        return 0
    return 1 if val > 0 else 2

# Function to check intersection between two line segments


def doIntersect(s1, s2):
    p1, q1, p2, q2 = s1.left, s1.right, s2.left, s2.right

    # Intersection with respect to line segment s1
    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)

    # Intersection with respect to line segment s2
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    # General case of simple intersection X, i.e., one clockwise and another counterclockwise
    if o1 != o2 and o3 != o4:
        return True

    # Edge Cases
    # p1, q1, and p2 are collinear and p2 lies on segment s1
    if o1 == 0 and onSegment(p1, p2, q1):
        return True
    # p1, q1, and q2 are collinear and q2 lies on segment s1
    if o2 == 0 and onSegment(p1, q2, q1):
        return True

    # p2, q2, and p1 are collinear and p1 lies on segment s2
    if o3 == 0 and onSegment(p2, p1, q2):
        return True
    # p2, q2, and q1 are collinear and q1 lies on segment s2
    if o4 == 0 and onSegment(p2, q1, q2):
        return True

    return False

# Find predecessor of iterator in s.


def pred(s, it):
    return max(filter(lambda x: x < it, s), default=None)

# Find successor of iterator in s.


def succ(s, it):
    return min(filter(lambda x: x > it, s), default=None)

# Function to calculate the number of intersection points


def isIntersect(arr):
    # To keep track of pairs for which intersection is already checked
    checked = set()

    # Pushing all points to a list of events
    eve = []
    for i in range(len(arr)):
        eve.append(Event(arr[i].left.x, arr[i].left.y, True, i))
        eve.append(Event(arr[i].right.x, arr[i].right.y, False, i))

    # Sorting all events according to the x-coordinate.
    eve.sort(key=lambda event: event.x)

    # For storing active segments.
    s = []
    ans = 0

    # Traversing through sorted points
    for i in range(2 * len(arr)):
        curr = eve[i]
        index = curr.index

        # If the current point is the left endpoint of its segment
        if curr.isLeft:
            # Get the above and below points
            next_point = succ(s, curr)
            prev_point = pred(s, curr)

            # Check if the current point intersects with any of its adjacent points
            if next_point is not None and doIntersect(arr[next_point.index], arr[index]):
                s1 = f"{next_point.index + 1} {index + 1}"
                if s1 not in checked:
                    checked.add(s1)
                    ans += 1

            if prev_point is not None and doIntersect(arr[prev_point.index], arr[index]):
                s1 = f"{prev_point.index + 1} {index + 1}"
                if s1 not in checked:
                    checked.add(s1)
                    ans += 1

            # If the same line segment is there, then decrease the answer as it got increased twice (remove the repetition part)
            if prev_point is not None and next_point is not None and next_point.index == prev_point.index:
                ans -= 1

            # Insert the current point (or event)
            s.append(curr)
        # If the current point is the right endpoint of its segment
        else:
            # Find the iterator
            it = next((x for x in s if x.x ==
                      arr[index].left.x and x.y == arr[index].left.y and x.isLeft), None)
            # Find the above and below points
            next_point = succ(s, it)
            prev_point = pred(s, it)

            # If the above and below points intersect
            if next_point is not None and prev_point is not None:
                s1 = f"{next_point.index + 1} {prev_point.index + 1}"
                s2 = f"{prev_point.index + 1} {next_point.index + 1}"
                if s1 not in checked and s2 not in checked and doIntersect(arr[prev_point.index], arr[next_point.index]):
                    checked.add(s1)
                    ans += 1

            # Remove the current segment
            s.remove(it)

    return ans


def main():
    while True:
        print("------------------------------------------------")
        print("Menu:")
        print("1. Find the number of intersection points")
        print("2. Exit")
        print("------------------------------------------------")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter the number of line segments: "))
            arr = []
            print("Enter the coordinates for each line segment:")
            for i in range(n):
                print(f"Segment {i + 1}:")
                left_x, left_y = map(int, input(
                    "Left point coordinates (x y): ").split())
                right_x, right_y = map(int, input(
                    "Right point coordinates (x y): ").split())
                arr.append(Segment(Point(left_x, left_y),
                           Point(right_x, right_y)))

            print("Number of intersection points:", isIntersect(arr))
        elif choice == 2:
            print("Exiting the program...")
            exit(0)
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
