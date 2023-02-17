"""
    ----------------------------------------------- Problem Statement ---------------------------------------------------------

    Given an 2D array of integers we have to print in the spiral order where the first line is the number of rows and second line
    is the number of columns present in the array

    INPUT :- 3
             3
             1 2 3
             4 5 6
             7 8 9
    
    OUTPUT :- 
            1,2,3,6,9,8,7,4,5

    ------------------------------------------------- Spiral Printing ---------------------------------------------------------

    We have to move from left to right first and then by top to bottom and then by right to left at last we have to move from bottom to 
    top you can use 4 for loops and 4 pointers to solve the same problem but it has higher time complexity when compared to this approach.

    Here we create two arrays instead of 4 loops and 4 pointer which performs the same activity of traversing the array in spiral order,
    one array is for traversing the row and second is for traversing the column.
            spiral_row = [0,1,0,-1]
            spiral_col = [1,0,-1,0]

    We have to create a temporary matrix named visited which is of data type boolean if the element is visited then we have to convert it
    into true otherwise it will be in false. It prevents us to add the already visited element.
            visited = [[0 for i in range(col_len)] for j in range(row_len)]

    To change the row visited by next row and to change the column elemnet by next column consequently we have two statements which sets
    the next element that is going to be pointed by them and to get printed.
            nr = x + spiral_row[curr_direction]
            nc = y + spiral_col[curr_direction]


    -------------------------------------------------- Complexities ------------------------------------------------------------

    Time Complexity  --> BigO(N) where N is the total number of elements present in the matrix
    Space Complexity --> BigO(n) because of the boolean visited array in extra.

"""
# Function that performs the spiral printing of matrix
def spiral_print_algorithm (matrix) :
    # Declaring an empty matrix to store the values after spiral conversion
    answer = []

    # Edge case condition if the matrix is empty we will return an empty array
    if(len(matrix) == 0) :
        return answer
    
    # Calculating the length of the row and column in the matrix
    row_len = len(matrix)
    col_len = len(matrix[0])

    """
    A boolean array which is used to check wheather the element is visited or not currently it is 0 for all elements in the matrix
    when it is visited it will be modified as 1 
    """
    visited = [[0 for i in range(col_len)] for j in range(row_len)]

    # Variables for iterating the rows and columns
    x = 0
    y = 0

    # The direction at which the matrix is being traversing that is either top or bottom or right or left.
    curr_direction = 0

    # Declaring how to change the row and columns to print the matrix in spiral order.
    spiral_row = [0,1,0,-1]
    spiral_col = [1,0,-1,0]

    # The loop which performs the spiral traversal of matrix
    for i in range(row_len * col_len) :
        # Adding the element to the answer array since it is not present in it.
        answer.append(matrix[x][y])

        # Modifiying the visited array because the element is added to the answer, since it is visited so converting it to 1
        visited[x][y] = True

        # Changing the index of the row and columns to traverse the next element.
        # It is used to change the rows and columns
        #  It is for the next rows and next columns to be added
        nr = x + spiral_row[curr_direction]
        nc = y + spiral_col[curr_direction]

        # If the current element is not visited and less than size then we should add it to the answer array this condtion performs it.
        if (0 <= nr and nr < row_len and 0 <= nc and nc < col_len and not(visited[nr][nc])):
            x = nr
            y = nc
        # Changing the direction of the rows and columns is done with the help of this condition.
        else:
            curr_direction = (curr_direction + 1) % 4
            x += spiral_row[curr_direction]
            y += spiral_col[curr_direction]

    # Return the array which is converted into spiral order.
    return answer


# Declaring the matrix
matrix = []

# Reading the number of rows from the user
rows = int(input("Enter the number of rows = "))

# Reading the number of columns from the user
columns = int(input("Enter the number of columns = "))

# Reading the matrix  values from the user
for i in range(0,rows) :
    temp = []
    for j in range(0,columns) :
        temp.append(int(input("Enter the elements = ")))
    matrix.append(temp)

# Printing the matrix before printing it into spiral order
print("\nBefore coverting the order of matrix is,")
for i in range(0,rows) :
    for j in range(0,columns) :
        print(matrix[i][j],end=" ")
    print()

# Calling the spiral_print_algorithm and printing the matrix in spiral form
print("\nPrinting in spiral order,")
for k in spiral_print_algorithm(matrix) :
    print(k,end = " ")