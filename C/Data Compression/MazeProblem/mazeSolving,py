n = 4
  
# A utility function to check if x, y is valid
# index for N * N Maze
  
  
def isValid(n, maze, x, y, res):
    if x >= 0 and y >= 0 and x < n and y < n and maze[x][y] == 1 and res[x][y] == 0:
        return True
    return False
  
# A recursive utility function to solve Maze problem
  
  
def RatMaze(n, maze, move_x, move_y, x, y, res):
    # if (x, y is goal) return True
    if x == n-1 and y == n-1:
        return True
    for i in range(4):
        # Generate new value of x
        x_new = x + move_x[i]
  
        # Generate new value of y
        y_new = y + move_y[i]
  
        # Check if maze[x][y] is valid
        if isValid(n, maze, x_new, y_new, res):
  
            # mark x, y as part of solution path
            res[x_new][y_new] = 1
            if RatMaze(n, maze, move_x, move_y, x_new, y_new, res):
                return True
            res[x_new][y_new] = 0
    return False
  
  
def solveMaze(maze):
    # Creating a 4 * 4 2-D list
    res = [[0 for i in range(n)] for i in range(n)]
    res[0][0] = 1
  
    # x matrix for each direction
    move_x = [-1, 1, 0, 0]
  
    # y matrix for each direction
    move_y = [0, 0, -1, 1]
  
    if RatMaze(n, maze, move_x, move_y, 0, 0, res):
        for i in range(n):
            for j in range(n):
                print(res[i][j], end=' ')
            print()
    else:
        print('Solution does  not exist')
  
  
# Driver program to test above function
if __name__ == "__main__":
    # Initialising the maze
    maze = [[1, 0, 0, 0],
             [1, 1, 0, 1],
             [0, 1, 0, 0],
             [1, 1, 1, 1]]
  
    solveMaze(maze)