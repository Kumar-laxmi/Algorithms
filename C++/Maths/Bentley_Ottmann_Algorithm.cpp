/*
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
*/
#include <bits/stdc++.h>
using namespace std;

// A point in 2D plane
struct Point
{
    int x, y;
};

// A line segment with left and right end points
struct Segment
{
    Point left, right;
};

// An event has a point, the position
// of the point (whether left or right), and
// the index of the point in the original input
// array of segments.
struct Event
{
    int x, y;
    bool isLeft;
    int index;
    Event(int x, int y, bool isLeft, int index) : x(x), y(y), isLeft(isLeft), index(index) {}

    // By defining this less-than operator, the std::set data structure can keep the events sorted in ascending order of y coordinates. If two events have the same y coordinate, they are sorted based on their x coordinates.
    bool operator<(const Event &e) const
    {
        if (y == e.y)
            return x < e.x;
        return y < e.y;
    }
};

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// To find the orientation of an ordered triplet (p, q, r).
// The function returns the following values:
// 0 --> p, q, and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to check intersection between two line segments
bool doIntersect(Segment s1, Segment s2)
{
    Point p1 = s1.left, q1 = s1.right, p2 = s2.left, q2 = s2.right;

    // Intersection with respect to line segment s1
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);

    // Intersection with respect to line segment s2
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case of simple intersection X, i.e., one clockwise and another counterclockwise
    if (o1 != o2 && o3 != o4)
        return true;

    // Edge Cases
    // p1, q1, and p2 are collinear and p2 lies on segment s1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    // p1, q1, and q2 are collinear and q2 lies on segment s1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2, and p1 are collinear and p1 lies on segment s2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    // p2, q2, and q1 are collinear and q1 lies on segment s2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

// Find predecessor of iterator in s.
set<Event>::iterator pred(set<Event> &s, set<Event>::iterator it)
{
    return it == s.begin() ? s.end() : --it;
}

// Find successor of iterator in s.
set<Event>::iterator succ(set<Event> &s, set<Event>::iterator it)
{
    return ++it;
}

// Function to calculate number of intersection points
int isIntersect(Segment arr[], int n)
{
    // to keep track of pairs for which intersection is already checked
    unordered_set<string> checked;

    // Pushing all points to a vector of events
    vector<Event> eve;
    for (int i = 0; i < n; ++i)
    {
        eve.push_back(Event(arr[i].left.x, arr[i].left.y, true, i));
        eve.push_back(Event(arr[i].right.x, arr[i].right.y, false, i));
    }

    // Sorting all events according to the x-coordinate.
    sort(eve.begin(), eve.end(), [](Event &e1, Event &e2)
         { return e1.x < e2.x; });

    // For storing active segments.
    set<Event> s;
    int ans = 0;

    // Traversing through sorted points
    for (int i = 0; i < 2 * n; i++)
    {
        Event curr = eve[i];
        int index = curr.index;

        // If the current point is the left endpoint of its segment
        if (curr.isLeft)
        {
            // Get the above and below points
            auto next = s.lower_bound(curr);
            auto prev = pred(s, next);

            // Check if the current point intersects with any of its adjacent points
            bool flag = false;
            if (next != s.end() && doIntersect(arr[next->index], arr[index]))
            {
                string s1 = to_string(next->index + 1) + " " + to_string(index + 1);
                if (checked.find(s1) == checked.end())
                {
                    checked.insert(s1);
                    ans++;
                }
                // if not already checked, we can store the string as marked
            }
            if (prev != s.end() && doIntersect(arr[prev->index], arr[index]))
            {
                string s1 = to_string(prev->index + 1) + " " + to_string(index + 1);
                if (checked.find(s1) == checked.end())
                {
                    checked.insert(s1);
                    ans++;
                }
                // if not already checked, we can store the string as marked
            }

            // If the same line segment is there, then decrease the answer as it got increased twice(remove the repeatition part)
            if (prev != s.end() && next != s.end() && next->index == prev->index)
                ans--;

            // Insert the current point (or event)
            s.insert(curr);
        }
        // If the current point is the right endpoint of its segment
        else
        {
            // Find the iterator
            auto it = s.find(Event(arr[index].left.x, arr[index].left.y, true, index));
            // Find the above and below points
            auto next = succ(s, it);
            auto prev = pred(s, it);

            // If the above and below points intersect
            if (next != s.end() && prev != s.end())
            {
                string s1 = to_string(next->index + 1) + " " + to_string(prev->index + 1);
                string s2 = to_string(prev->index + 1) + " " + to_string(next->index + 1);
                if (checked.find(s1) == checked.end() && checked.find(s2) == checked.end() && doIntersect(arr[prev->index], arr[next->index]))
                {
                    checked.insert(s1);
                    ans++;
                }
            }
            // Remove the current segment
            s.erase(it);
        }
    }
    return ans;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "------------------------------------------------"
             << "\n";
        cout << "Menu:\n";
        cout << "1. Find the number of intersection points\n";
        cout << "2. Exit\n";
        cout << "------------------------------------------------"
             << "\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter the number of line segments: ";
            cin >> n;

            Segment *arr = new Segment[n];
            cout << "Enter the coordinates for each line segment:\n";
            for (int i = 0; i < n; ++i)
            {
                cout << "Segment " << i + 1 << ":\n";
                cout << "Left point coordinates (x y): ";
                cin >> arr[i].left.x >> arr[i].left.y;
                cout << "Right point coordinates (x y): ";
                cin >> arr[i].right.x >> arr[i].right.y;
            }

            cout << "Number of intersection points: " << isIntersect(arr, n) << endl;

            delete[] arr;
            break;
        }
        case 2:
        {
            cout << "Exiting the program...\n";
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
