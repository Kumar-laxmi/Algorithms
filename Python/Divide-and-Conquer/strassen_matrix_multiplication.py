#!/usr/bin/env python

"""Strassen's Matrix Multiplication algorithm

This script demonstrates Strassen's algorithm which multiplies two square matrices
using a divide-and-conquer pattern. The unique computations after dividing the
matrices into quadrants result in lowering the time complexity from an order of n^3
to n^log7 i.e., approximately n^2.8.
The product computed using Strassen's algorithm is compared with the product computed
using a built-in method for verification.

Python: 3.10.8

External packages: numpy

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
import numpy as np
from typing import Tuple


def read_input() -> Tuple[np.ndarray, np.ndarray]:
    """Reads the elements of two square matrices in a row-wise manner from
    standard input and returns them in the form of numpy arrays.

    Returns:
        Tuple[np.ndarray, np.ndarray]: Two user-input matrices to be multiplied
    """
    # Strassen's algorithm can only be applied to square matrices of size 2^n
    try:
        size = int(input("Enter the size of the square matrices: ").strip())
    except ValueError:
        sys.exit("Integer value expected.")

    if not np.log2(size).is_integer():  # log base-2 will be an integer for size = 2^n
        sys.exit("Size must be a power of two.")

    print("Input the first matrix (row-wise):")
    first_matrix = []
    for i in range(size):
        row = list(map(int, input(f"Row {i+1}: ").strip().split()))
        first_matrix.append(row)
    print("Input the second matrix (row-wise):")
    second_matrix = []
    for i in range(size):
        row = list(map(int, input(f"Row {i+1}: ").strip().split()))
        second_matrix.append(row)

    return np.asarray(first_matrix), np.asarray(second_matrix)


def display(matrix):
    """Prints the elements of a matrix with appropriate formatting.

    Args:
        matrix (_type_): Matrix to be displayed
    """
    rows, cols = matrix.shape
    for i in range(rows):
        for j in range(cols):
            print(f"{matrix[i][j]:<3}", end=" ")
        print()


def split_matrix(
    matrix: np.ndarray,
) -> Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    """Splits the given matrix into four quadrants for the 'divide' portion of
    Strassen's algorithm.

    Args:
        matrix (np.ndarray): Matrix to be split

    Returns:
        Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]: Four quadrants of the matrix
    """
    rows, cols = matrix.shape
    mid_row = rows // 2
    mid_col = cols // 2

    top_left = matrix[:mid_row, :mid_col]
    top_right = matrix[:mid_row, mid_col:]
    bottom_left = matrix[mid_row:, :mid_col]
    bottom_right = matrix[mid_row:, mid_col:]

    return top_left, top_right, bottom_left, bottom_right


def strassen_multiplication(
    first_matrix: np.ndarray, second_matrix: np.ndarray
) -> np.ndarray:
    """Computes product of two matrices using Strassen's divide-and-conquer algorithm.
    Called recursively for computing the Strassen products using the matrix quadrants.

    Args:
        first_matrix (np.ndarray): First matrix in product
        second_matrix (np.ndarray): Second matrix in product

    Returns:
        np.ndarray: Product of the two matrices
    """
    # Base case
    if first_matrix.shape[0] == 1 or second_matrix.shape[0] == 1:
        return first_matrix * second_matrix

    # Divide - split matrices into four quadrants
    a, b, c, d = split_matrix(first_matrix)
    e, f, g, h = split_matrix(second_matrix)

    # Computing the seven Strassen products in a recursive manner
    p1 = strassen_multiplication(a, f - h)
    p2 = strassen_multiplication(a + b, h)
    p3 = strassen_multiplication(c + d, e)
    p4 = strassen_multiplication(d, g - e)
    p5 = strassen_multiplication(a + d, e + h)
    p6 = strassen_multiplication(b - d, g + h)
    p7 = strassen_multiplication(a - c, e + f)

    # Conquer - compute quadrants using Strassen products
    top_left = p4 + p5 + p6 - p2
    top_right = p1 + p2
    bottom_left = p3 + p4
    bottom_right = p1 + p5 - p3 - p7
    # create result matrix by combining the quadrants
    left_half = np.row_stack((top_left, bottom_left))
    right_half = np.row_stack((top_right, bottom_right))
    result = np.column_stack((left_half, right_half))

    return result


if __name__ == "__main__":
    first_matrix, second_matrix = read_input()
    # first_matrix = np.asarray([[0, 1, 2], [1, 2, 3], [2, 3, 4]])
    # second_matrix = np.asarray([[3, 4, 5], [4, 5, 6], [5, 6, 7]])
    result = strassen_multiplication(first_matrix, second_matrix)
    print("\nResult using Strassen's algorithm:")
    display(result)
    print("\nResult using built-in method:")
    display(np.matmul(first_matrix, second_matrix))
