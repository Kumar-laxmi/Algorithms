def multiply(a, b, c):
    # function to multiply two matrices
    N = len(a)
    for i in range(N):
        for j in range(N):
            c[i][j] = 0
            for k in range(N):
                c[i][j] += a[i][k] * b[k][j]

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
b = [[9, 8, 7],
     [6, 5, 4],
     [3, 2, 1]]
c = [[0, 0, 0],
     [0, 0, 0],
     [0, 0, 0]]  # empty matrix to store the result

multiply(a, b, c)

# print the result
for row in c:
    print(row)
