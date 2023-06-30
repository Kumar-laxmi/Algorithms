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
#include <stdio.h>
#include <stdlib.h>

struct Segment
{
    int left;
    int right;
};

int compare(const void *a, const void *b)
{
    return ((struct Segment *)a)->left - ((struct Segment *)b)->left;
}

int segmentUnionLength(struct Segment *seg, int n)
{
    struct Point
    {
        int value;
        int isEnd;
    };

    struct Point *points = (struct Point *)malloc(sizeof(struct Point) * n * 2);

    for (int i = 0; i < n; i++)
    {
        points[i * 2].value = seg[i].left;
        points[i * 2].isEnd = 0;
        points[i * 2 + 1].value = seg[i].right;
        points[i * 2 + 1].isEnd = 1;
    }

    qsort(points, n * 2, sizeof(struct Point), compare);

    int result = 0;
    int counter = 0;

    for (int i = 0; i < n * 2; i++)
    {
        if (counter > 0)
        {
            result += points[i].value - points[i - 1].value;
        }

        if (points[i].isEnd)
        {
            counter--;
        }
        else
        {
            counter++;
        }
    }

    free(points);
    return result;
}

int main()
{
    int choice;
    struct Segment *segments = NULL;
    int numSegments = 0;

    do
    {
        printf("Menu:\n");
        printf("1. Add segments\n");
        printf("2. Calculate length of union of segments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the number of segments to add: ");
            scanf("%d", &numSegments);

            segments = (struct Segment *)malloc(sizeof(struct Segment) * numSegments);

            printf("Enter the left and right endpoints of each segment (separated by a space):\n");
            for (int i = 0; i < numSegments; i++)
            {
                scanf("%d %d", &segments[i].left, &segments[i].right);
            }

            printf("Segments added.\n");
            break;
        }
        case 2:
        {
            if (segments == NULL)
            {
                printf("No segments added.\n");
            }
            else
            {
                int unionLength = segmentUnionLength(segments, numSegments);
                printf("Length of the union of segments: %d\n", unionLength);
            }
            break;
        }
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        printf("\n");

    } while (choice != 3);

    free(segments);

    return 0;
}