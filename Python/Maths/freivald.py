
# Given three matrices A, B and C, find if C is a product of A and B.


import random


def matrix_vector_multiplication(matrix, vector):
    result = []
    for row in matrix:
        element = sum(a * b for a, b in zip(row, vector))
        result.append(element)
    return result


def check_product(a, b, c):
    n = len(a)
    m = len(a[0])
    k = len(b[0])

    x = [random.randint(0, 1) for _ in range(m)]

    y = matrix_vector_multiplication(a, matrix_vector_multiplication(b, x))

    z = matrix_vector_multiplication(c, x)

    result = [y_i - z_i for y_i, z_i in zip(y, z)]

    if all(element == 0 for element in result):
        return "Product is correct."
    else:
        return "Product is incorrect."


# Input matrix A
a_rows = int(input("Enter the number of rows in matrix A: "))
a_cols = int(input("Enter the number of columns in matrix A: "))
print("Enter the elements of matrix A (row-wise):")
a = []
for _ in range(a_rows):
    row = list(map(int, input().split()))
    a.append(row)

# Input matrix B
b_rows = a_cols
b_cols = int(input("Enter the number of columns in matrix B: "))
print("Enter the elements of matrix B (row-wise):")
b = []
for _ in range(b_rows):
    row = list(map(int, input().split()))
    b.append(row)

# Input matrix C
c_rows = a_rows
c_cols = b_cols
print("Enter the elements of matrix C (row-wise):")
c = []
for _ in range(c_rows):
    row = list(map(int, input().split()))
    c.append(row)

output = check_product(a, b, c)
print(output)
