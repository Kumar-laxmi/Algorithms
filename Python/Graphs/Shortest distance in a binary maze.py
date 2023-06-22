


import heapq

# Helper function to check if a cell is valid and can be visited
def is_valid(grid, row, col):
    rows = len(grid)
    cols = len(grid[0])
    return row >= 0 and row < rows and col >= 0 and col < cols and grid[row][col] == 1

# Helper function to get the neighbors of a cell
def get_neighbors(grid, row, col):
    neighbors = []
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # Right, Left, Down, Up

    for dr, dc in directions:
        new_row = row + dr
        new_col = col + dc

        if is_valid(grid, new_row, new_col):
            neighbors.append((new_row, new_col))

    return neighbors

# Main function to find the shortest distance in a binary maze
def shortest_distance_binary_maze(grid, source, destination):
    rows = len(grid)
    cols = len(grid[0])

    # Initialize the distance array with infinity for all cells
    distances = [[float('inf')] * cols for _ in range(rows)]

    # Initialize the distance of the source cell as 0
    distances[source[0]][source[1]] = 0

    # Priority queue to store the cells with their distances
    pq = [(0, source)]

    while pq:
        dist, cell = heapq.heappop(pq)
        row, col = cell

        # Check if we reached the destination cell
        if cell == destination:
            return dist

        # Ignore the cell if we have already found a shorter path
        if dist > distances[row][col]:
            continue

        # Visit the neighbors of the current cell
        neighbors = get_neighbors(grid, row, col)

        for neighbor in neighbors:
            nrow, ncol = neighbor
            weight = 1  # Assuming the weight of each edge is 1

            # Relax the edge if a shorter distance is found
            if dist + weight < distances[nrow][ncol]:
                distances[nrow][ncol] = dist + weight
                heapq.heappush(pq, (dist + weight, neighbor))

    # If no path is found, return -1
    return -1

# Get the input from the user
rows, cols = map(int, input("Enter the number of rows and columns (space-separated): ").split())

grid = []
for i in range(rows):
    row = list(map(int, input(f"Enter the values for row {i+1} (space-separated): ").split()))
    grid.append(row)

source_row, source_col = map(int, input("Enter the row and column index of the source cell (space-separated): ").split())
source = (source_row, source_col)

destination_row, destination_col = map(int, input("Enter the row and column index of the destination cell (space-separated): ").split())
destination = (destination_row, destination_col)

# Call the function to find the shortest distance
shortest_dist = shortest_distance_binary_maze(grid, source, destination)

# Print the result
print("Shortest Distance:", shortest_dist)