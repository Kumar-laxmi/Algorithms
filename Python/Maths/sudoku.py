import math

# Function to check if a number can be placed in the Sudoku grid at a particular position
def can_place(mat, i, j, n, no):
    # Checking if the number already exists in the same row or column
    for x in range(n):
        if mat[x][j] == no or mat[i][x] == no:
            return False

    # Determining the starting index of the current sub-grid
    rn = int(math.sqrt(n))
    sx = (i // rn) * rn
    sy = (j // rn) * rn

    # Checking if the number already exists in the sub-grid
    for x in range(sx, sx + rn):
        for y in range(sy, sy + rn):
            if mat[x][y] == no:
                return False

    return True

# Function to solve the Sudoku puzzle
def solve_sudoku(mat, i, j, n):
    # Base case: If we have reached the last row, print the Sudoku solution
    if i == n:
        for x in range(n):
            for y in range(n):
                print(mat[x][y], end=" ")
            print()
        return True  # Return True to indicate a solution is found

    # If we have reached the last column, move to the next row
    if j == n:
        return solve_sudoku(mat, i + 1, 0, n)

    # If the current cell already contains a number, move to the next column
    if mat[i][j] != 0:
        return solve_sudoku(mat, i, j + 1, n)

    # Try placing numbers from 1 to n in the current empty cell
    for no in range(1, n + 1):
        if can_place(mat, i, j, n, no):
            mat[i][j] = no  # Place the number in the current cell

            # Recursively solve the Sudoku puzzle for the next cell
            could = solve_sudoku(mat, i, j + 1, n)
            if could:
                return True  # Return True if a solution is found

    # If no number can be placed in the current cell, backtrack
    mat[i][j] = 0
    return False

if __name__ == "__main__":
    mat = [[0] * 9 for _ in range(9)]
    n = int(input())

    # Input the Sudoku grid
    for i in range(n):
        mat[i] = list(map(int, input().split()))

    solve_sudoku(mat, 0, 0, n)  # Solve the Sudoku puzzle
