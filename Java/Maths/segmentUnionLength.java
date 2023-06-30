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
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class segmentUnionLength {
    public static class Segment {
        int left;
        int right;
    
        Segment(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public static class Point {
        int value;
        boolean isEnd;
    
        Point(int value, boolean isEnd) {
            this.value = value;
            this.isEnd = isEnd;
        }
    }
    private static Comparator<Point> pointComparator = new Comparator<Point>() {
        @Override
        public int compare(Point p1, Point p2) {
            return p1.value - p2.value;
        }
    };

    private static int segmentUnionLength(List<Segment> seg) {
        int n = seg.size();

        List<Point> points = new ArrayList<>(n * 2);
        for (Segment s : seg) {
            points.add(new Point(s.left, false));
            points.add(new Point(s.right, true));
        }

        points.sort(pointComparator);

        int result = 0;
        int counter = 0;

        for (int i = 0; i < n * 2; i++) {
            if (counter > 0) {
                result += points.get(i).value - points.get(i - 1).value;
            }

            if (points.get(i).isEnd) {
                counter--;
            } else {
                counter++;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        List<Segment> segments = new ArrayList<>();

        do {
            System.out.println("Menu:");
            System.out.println("1. Add segments");
            System.out.println("2. Calculate length of union of segments");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1: {
                    System.out.print("Enter the number of segments to add: ");
                    int numSegments = scanner.nextInt();

                    System.out.println("Enter the left and right endpoints of each segment (separated by a space):");
                    for (int i = 0; i < numSegments; i++) {
                        int left = scanner.nextInt();
                        int right = scanner.nextInt();
                        segments.add(new Segment(left, right));
                    }

                    System.out.println("Segments added.");
                    break;
                }
                case 2: {
                    if (segments.isEmpty()) {
                        System.out.println("No segments added.");
                    } else {
                        int unionLength = segmentUnionLength(segments);
                        System.out.println("Length of the union of segments: " + unionLength);
                    }
                    break;
                }
                case 3:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }

            System.out.println();

        } while (choice != 3);

        scanner.close();
    }
}