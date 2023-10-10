import java.util.*;

// A structure to hold the necessary parameters
class Cell {
    int parent_i, parent_j;
    double f, g, h;

    public Cell() {
        parent_i = -1;
        parent_j = -1;
        f = Double.POSITIVE_INFINITY;
        g = Double.POSITIVE_INFINITY;
        h = Double.POSITIVE_INFINITY;
    }
}

public class AStarSearch {
    static final int ROW = 9;
    static final int COL = 10;

    // A Utility Function to check whether given cell (row, col) is a valid cell or not.
    static boolean isValid(int row, int col) {
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
    }

    // A Utility Function to check whether the given cell is blocked or not
    static boolean isUnblocked(int[][] grid, int row, int col) {
        return grid[row][col] == 1;
    }

    // A Utility Function to check whether destination cell has been reached or not
    static boolean isDestination(int row, int col, int[] dest) {
        return (row == dest[0] && col == dest[1]);
    }

    // A Utility Function to calculate the 'h' heuristics
    static double calculateHValue(int row, int col, int[] dest) {
        return Math.sqrt((row - dest[0]) * (row - dest[0]) + (col - dest[1]) * (col - dest[1]));
    }

    // A Utility Function to trace the path from the source to destination
    static void tracePath(Cell[][] cellDetails, int[] dest) {
        System.out.print("The Path is ");
        int row = dest[0], col = dest[1];
        Stack<int[]> path = new Stack<>();

        while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
            path.push(new int[]{row, col});
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }

        path.push(new int[]{row, col});

        while (!path.isEmpty()) {
            int[] point = path.pop();
            System.out.print("-> (" + point[0] + "," + point[1] + ") ");
        }
        System.out.println();
    }

    // A Function to find the shortest path between a given source cell to a destination cell according to A* Search Algorithm
    static void aStarSearch(int[][] grid, int[] src, int[] dest) {
        // If the source is out of range
        if (!isValid(src[0], src[1])) {
            System.out.println("Source is invalid");
            return;
        }

        // If the destination is out of range
        if (!isValid(dest[0], dest[1])) {
            System.out.println("Destination is invalid");
            return;
        }

        // Either the source or the destination is blocked
        if (!isUnblocked(grid, src[0], src[1]) || !isUnblocked(grid, dest[0], dest[1])) {
            System.out.println("Source or the destination is blocked");
            return;
        }

        // If the destination cell is the same as the source cell
        if (isDestination(src[0], src[1], dest)) {
            System.out.println("We are already at the destination");
            return;
        }

        // Create a closed list and initialize it to false, which means that no cell has been included yet
        boolean[][] closedList = new boolean[ROW][COL];

        // Declare a 2D array of Cell objects to hold the details of that cell
        Cell[][] cellDetails = new Cell[ROW][COL];

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cellDetails[i][j] = new Cell();
            }
        }

        int i = src[0], j = src[1];
        cellDetails[i][j].f = 0.0;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = 0.0;
        cellDetails[i][j].parent_i = i;
        cellDetails[i][j].parent_j = j;

        // Create an open list (PriorityQueue) using a custom comparator
        PriorityQueue<Pair<Double, int[]>> openList = new PriorityQueue<>(new Comparator<Pair<Double, int[]>>() {
            public int compare(Pair<Double, int[]> p1, Pair<Double, int[]> p2) {
                return Double.compare(p1.getKey(), p2.getKey());
            }
        });

        openList.add(new Pair<>(0.0, src));

        // We set this boolean value as false as initially, the destination is not reached
        boolean foundDest = false;

        // Define the 8 possible movements from a cell
        int[] movesRow = {-1, 1, 0, 0, -1, -1, 1, 1};
        int[] movesCol = {0, 0, -1, 1, -1, 1, -1, 1};

        while (!openList.isEmpty()) {
            Pair<Double, int[]> p = openList.poll();
            double f = p.getKey();
            int[] current = p.getValue();

            i = current[0];
            j = current[1];

            // Add this vertex to the closed list
            closedList[i][j] = true;

            for (int k = 0; k < 8; k++) {
                // Generate all the 8 successors of this cell
                int new_i = i + movesRow[k];
                int new_j = j + movesCol[k];

                // Only process this cell if this is a valid one
                if (isValid(new_i, new_j)) {
                    // If the destination cell is the same as the current successor
                    if (isDestination(new_i, new_j, dest)) {
                        // Set the Parent of the destination cell
                        cellDetails[new_i][new_j].parent_i = i;
                        cellDetails[new_i][new_j].parent_j = j;
                        System.out.println("The destination cell is found");
                        tracePath(cellDetails, dest);
                        foundDest = true;
                        return;
                    }

                    // If the successor is already on the closed list or if it is blocked, then ignore it
                    if (!closedList[new_i][new_j] && isUnblocked(grid, new_i, new_j)) {
                        double gNew = cellDetails[i][j].g + 1.0;
                        double hNew = calculateHValue(new_i, new_j, dest);
                        double fNew = gNew + hNew;

                        // If it isn't on the open list, add it to the open list
                        // Make the current square the parent of this square
                        // Record the f, g, and h costs of the square cell
                        // OR
                        // If it is on the open list already, check to see if this path to that square is better, using 'f' as the measurement.
                        if (cellDetails[new_i][new_j].f == Double.POSITIVE_INFINITY || cellDetails[new_i][new_j].f > fNew) {
                            openList.add(new Pair<>(fNew, new int[]{new_i, new_j}));
                            cellDetails[new_i][new_j].f = fNew;
                            cellDetails[new_i][new_j].g = gNew;
                            cellDetails[new_i][new_j].h = hNew;
                            cellDetails[new_i][new_j].parent_i = i;
                            cellDetails[new_i][new_j].parent_j = j;
                        }
                    }
                }
            }
        }

        if (!foundDest) {
            System.out.println("Failed to find the destination cell");
        }
    }

    public static void main(String[] args) {
        int[][] grid = {
            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}
        };

        int[] src = {0, 0};
        int[] dest = {8, 9};

        aStarSearch(grid, src, dest);
    }
}
