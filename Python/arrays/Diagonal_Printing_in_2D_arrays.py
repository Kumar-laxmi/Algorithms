'''
 ---------------------------------------------- Problem Statement --------------------------------------------------------

    First line of input consist of number of rows and the second line consist of number of column the third line is the
    matrix elements. We have to print it in diagonal print pattern.

    INPUT :- 3
             3
             1 2 3
             4 5 6
             7 8 9

    OUTPUT :- 1 2 4 7 5 3 6 8 9

 ------------------------------------------------- Complexities ----------------------------------------------------------

    Time Complexity  :- BigO(n*m) --> where n is the number of rows and m is the number of columns
    Space Complexity :- BigO(1)

'''
# Declaring the matrix
matrix = []
# Reading the number of rows from the user
row = int(input("Enter row value = "))
# Reading the number of columns from the user
column = int(input("Enter column value = "))
# Reading the matrix values from the user
for i in range (0,row):
    newrow = []
    for j in range (0,column):
        newrow.append(int(input("Enter matrix elements = ")))
    matrix.append(newrow)
# Printing the matrix
print("The matrix is,")
for i in range(0,row):
    print(matrix[i])
print("Printing matrix in diagnol form,")
# Declaring the iterating variables and putting their value to 0
i = 0
j = 0
k = 0
# A boolean variable to switch directions
isUp = True
# Loop to print in diagnol pattern of 2D arrays
while k<row * column:
    # If isUp = true then iterate from downward to upward
    if isUp:
        # Loop for printing the values from downward to upward
        while i >= 0 and j<row :
            print(str(matrix[i][j]), end = " ")
            k += 1
            j += 1
            i -= 1
        # Set i and j according to isUp value (ie, according to direction)
        if i < 0 and j <= row - 1:
            i = 0
        if j == row:
            i = i + 2
            j -= 1
    # If isUp is =  false then traverse upwards to downwards
    else:
        # Loop for printing the values from upward to downward
        while j >= 0 and i<column :
            print(matrix[i][j], end = " ")
            k += 1
            i += 1
            j -= 1
        # Set i and j according to isUp value (ie, according to direction)
        if j < 0 and i <= column - 1:
            j = 0
        if i == column:
            j = j + 2
            i -= 1
    # Changing the value of isUp according to the direction.
    isUp = not isUp
