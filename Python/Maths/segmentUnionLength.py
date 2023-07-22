'''
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
'''
def segment_union_length(seg):
    n = len(seg)

    points = []
    for s in seg:
        points.append((s[0], False))
        points.append((s[1], True))

    points.sort()

    result = 0
    counter = 0

    for i in range(n * 2):
        if counter > 0:
            result += points[i][0] - points[i - 1][0]

        if points[i][1]:
            counter -= 1
        else:
            counter += 1

    return result

def main():
    choice = 0
    segments = []

    while choice != 3:
        print("Menu:")
        print("1. Add segments")
        print("2. Calculate length of union of segments")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            num_segments = int(input("Enter the number of segments to add: "))

            print("Enter the left and right endpoints of each segment (separated by a space):")
            for _ in range(num_segments):
                left, right = map(int, input().split())
                segments.append((left, right))

            print("Segments added.\n")

        elif choice == 2:
            if not segments:
                print("No segments added.\n")
            else:
                union_length = segment_union_length(segments)
                print("Length of the union of segments:", union_length, "\n")

        elif choice == 3:
            print("Exiting...")
        else:
            print("Invalid choice. Please try again.\n")


if __name__ == "__main__":
    main()