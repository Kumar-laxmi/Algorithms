import math
import heapq

# Define ROW and COL
ROW = 9
COL = 10

# Creating a shortcut for int, int pair type
Pair = tuple[int, int]

# A structure to hold the necessary parameters
class Cell:
    def __init__(self):
        self.parent_i = -1
        self.parent_j = -1
        self.f = math.inf
        self.g = math.inf
        self.h = math.inf

# A Utility Function to check whether given cell (row, col) is a valid cell or not.
def is_valid(row, col):
    return 0 <= row < ROW and 0 <= col < COL

# A Utility Function to check whether the given cell is blocked or not
def is_unblocked(grid, row, col):
    return grid[row][col] == 1

# A Utility Function to check whether destination cell has been reached or not
def is_destination(row, col, dest):
    return (row, col) == dest

# A Utility Function to calculate the 'h' heuristics
def calculate_h_value(row, col, dest):
    return math.sqrt((row - dest[0]) ** 2 + (col - dest[1]) ** 2)

# A Utility Function to trace the path from the source to destination
def trace_path(cell_details, dest):
    print("The Path is", end=" ")
    row, col = dest
    path = []

    while not (cell_details[row][col].parent_i == row and cell_details[row][col].parent_j == col):
        path.append((row, col))
        temp_row, temp_col = cell_details[row][col].parent_i, cell_details[row][col].parent_j
        row, col = temp_row, temp_col

    path.append((row, col))
    while path:
        print("->", path.pop(), end=" ")
    print()

# A Function to find the shortest path between a given source cell to a destination cell according to A* Search Algorithm
def a_star_search(grid, src, dest):
    # If the source is out of range
    if not is_valid(src[0], src[1]):
        print("Source is invalid")
        return

    # If the destination is out of range
    if not is_valid(dest[0], dest[1]):
        print("Destination is invalid")
        return

    # Either the source or the destination is blocked
    if not is_unblocked(grid, src[0], src[1]) or not is_unblocked(grid, dest[0], dest[1]):
        print("Source or the destination is blocked")
        return

    # If the destination cell is the same as the source cell
    if is_destination(src[0], src[1], dest):
        print("We are already at the destination")
        return

    # Create a closed list and initialize it to False, which means that no cell has been included yet
    closed_list = [[False for _ in range(COL)] for _ in range(ROW)]

    # Declare a 2D array of Cell objects to hold the details of that cell
    cell_details = [[Cell() for _ in range(COL)] for _ in range(ROW)]

    i, j = src[0], src[1]
    cell_details[i][j].f = 0.0
    cell_details[i][j].g = 0.0
    cell_details[i][j].h = 0.0
    cell_details[i][j].parent_i = i
    cell_details[i][j].parent_j = j

    # Create an open list using heapq (priority queue)
    open_list = [(0.0, src)]

    # We set this boolean value as False as initially, the destination is not reached
    found_dest = False

    # Define the 8 possible movements from a cell
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

    while open_list:
        f, (i, j) = heapq.heappop(open_list)

        # Add this vertex to the closed list
        closed_list[i][j] = True

        for move_i, move_j in moves:
            # Generate all the 8 successors of this cell
            new_i, new_j = i + move_i, j + move_j

            # Only process this cell if this is a valid one
            if is_valid(new_i, new_j):
                # If the destination cell is the same as the current successor
                if is_destination(new_i, new_j, dest):
                    # Set the Parent of the destination cell
                    cell_details[new_i][new_j].parent_i = i
                    cell_details[new_i][new_j].parent_j = j
                    print("The destination cell is found")
                    trace_path(cell_details, dest)
                    found_dest = True
                    return

                # If the successor is already on the closed list or if it is blocked, then ignore it
                elif not closed_list[new_i][new_j] and is_unblocked(grid, new_i, new_j):
                    g_new = cell_details[i][j].g + 1.0
                    h_new = calculate_h_value(new_i, new_j, dest)
                    f_new = g_new + h_new

                    # If it isn't on the open list, add it to the open list
                    # Make the current square the parent of this square
                    # Record the f, g, and h costs of the square cell
                    # OR
                    # If it is on the open list already, check to see if this path to that square is better
                    if cell_details[new_i][new_j].f == math.inf or cell_details[new_i][new_j].f > f_new:
                        heapq.heappush(open_list, (f_new, (new_i, new_j)))

                        # Update the details of this cell
                        cell_details[new_i][new_j].f = f_new
                        cell_details[new_i][new_j].g = g_new
                        cell_details[new_i][new_j].h = h_new
                        cell_details[new_i][new_j].parent_i = i
                        cell_details[new_i][new_j].parent_j = j

    # When the destination cell is not found and the open list is empty, then we conclude that we failed to reach the destination cell
    if not found_dest:
        print("Failed to find the Destination Cell")

# Driver program to test the above function
if __name__ == "__main__":
    # Description of the Grid-
    # 1--> The cell is not blocked
    # 0--> The cell is blocked
    grid = [[1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
            [1, 1, 1, 0, 1, 1, 1, 0, 1, 1],
            [1, 1, 1, 1, 0, 1, 1, 1, 0, 1],
            [0, 0, 1, 0, 1, 1, 1, 0, 1, 1],
            [1, 1, 1, 0, 1, 1, 1, 0, 1, 0],
            [1, 0, 1, 1, 1, 1, 0, 1, 0, 0],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 1],
            [1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
            [1, 1, 1, 0, 0, 0, 1, 0, 0, 1]]

    # Source coordinates
    src = (0, 0)

    # Destination coordinates
    dest = (8, 9)

    # Call the A* Search algorithm
    a_star_search(grid, src, dest)
