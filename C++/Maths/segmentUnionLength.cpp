/*
Title: Exploring Klee's Algorithm for Finding the Length of the Union of Segments

Introduction:
Klee's algorithm, also known as the "Interval Scheduling Algorithm," offers an efficient approach to calculate the length of the union of segments or intervals. This algorithm holds significant value in various applications, such as computational geometry, scheduling problems, and data analysis.

Problem Statement:
Given a set of segments on a line, the objective is to determine the total length of their union, which represents the continuous regions covered by these segments.

Klee's Algorithm for segmentUnionLength:

    1) Initialize an empty vector points to store the endpoints of the segments.
    2) Iterate over each segment in the segments collection:
        - Add the left endpoint of the segment with a tag left to the points vector.
        - Add the right endpoint of the segment with a tag of right to the points vector.
    3) Sort the points vector in ascending order.
    4) Initialize a variable result to 0 to store the total length of the union.
    5) Initialize a variable counter to 0 to keep track of the count of open segments.
    6) Iterate over each endpoint in the sorted points vector:
        - If counter is greater than 0, add the difference between the current endpoint and the previous endpoint to result.
        - If the current endpoint is the left endpoint of a segment, increment counter by 1; otherwise, decrement counter by 1.
    7) Return the calculated result as the length of the union of segments.

Time Complexity
    - The algorithm has a time complexity of O(N log N), where N is the number of segments.
    - It involves sorting the points vector, which takes O(N log N) time.
    - The subsequent iteration over the points vector has a linear time complexity of O(N).
    - Overall, the algorithm efficiently calculates the length of the union of segments.

Real-World Applications:
Klee's algorithm finds applications in various domains, such as:

Computational Geometry: Determining the intersection or coverage of geometric shapes, like line segments or intervals.

Scheduling Problems: Efficiently allocating time intervals for tasks or events without overlap.

Data Analysis: Analyzing and summarizing temporal data, identifying overlapping intervals, or finding time-based patterns.

Conclusion:
Klee's algorithm offers an elegant and efficient solution for calculating the length of the union of segments. By following the algorithm, you can accurately determine the continuous regions covered by a set of segments.This algorithm finds practical use in multiple fields, allowing for effective scheduling, data analysis, and computational geometry.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int segmentUnionLength(const vector<pair<int, int>>& seg) {
    int n = seg.size();

    // Create a vector to store starting and ending points
    vector<pair<int, bool>> points(n * 2);
    for (int i = 0; i < n; i++) {
        //true is used for left end
        points[i * 2] = make_pair(seg[i].first, true);
        //false is used for right end
        points[i * 2 + 1] = make_pair(seg[i].second, false);
    }

    // Sorting all points by point value
    sort(points.begin(), points.end());

    int result = 0; // Initialize result

    // To keep track of counts of current open segments
    // (Starting point is processed, but ending point is not)
    int Counter = 0;

    // Traverse through all points
    for (int i = 0; i < n * 2; i++) {
        // If there are open points, then we add the difference between previous and current point(independent of its end).
        if (Counter)
            result += (points[i].first - points[i - 1].first);

        // If this is an ending point, reduce count of open points.
        (points[i].second) ? Counter++ : Counter--;
    }
    return result;
}

int main() {
    int choice;
    vector<pair<int, int>> segments;

    do {
        cout << "Menu:\n";
        cout << "1. Add segments\n";
        cout << "2. Calculate length of union of segments\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numSegments;
                cout << "Enter the number of segments to add: ";
                cin >> numSegments;

                cout << "Enter the left and right endpoints of each segment (separated by a space):\n";
                for (int i = 0; i < numSegments; i++) {
                    int left, right;
                    cin >> left >> right;
                    segments.push_back(make_pair(left, right));
                }
                cout << "Segments added.\n";
                break;
            }
            case 2: {
                if (segments.empty()) {
                    cout << "No segments added.\n";
                } else {
                    int unionLength = segmentUnionLength(segments);
                    cout << "Length of the union of segments: " << unionLength << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}