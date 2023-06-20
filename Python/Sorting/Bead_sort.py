import numpy as np

def display(arr):
    for num in arr:
        print(num, end=" ")
    print()

def bead_sort(arr):
    max_val = max(arr)
    len_arr = len(arr)
    beads = np.zeros((len_arr, max_val), dtype=int)

    for i in range(len_arr):
        for j in range(arr[i]):
            beads[i][j] = 1

    for j in range(max_val):
        sum_val = 0
        for i in range(len_arr):
            sum_val += beads[i][j]
            beads[i][j] = 0
        for i in range(len_arr - sum_val, len_arr):
            beads[i][j] = 1

    for i in range(len_arr):
        j = 0
        while j < max_val and beads[i][j] != 0:
            j += 1
        arr[i] = j

if __name__ == '__main__':
    n = int(input("Enter the size of the array: "))
    arr = []
    elements = input("Enter the elements of the array: ").split()
    for i in range(n):
        arr.append(int(elements[i]))

    print("Original array:", end=" ")
    display(arr)

    bead_sort(arr)

    print("Sorted array:", end=" ")
    display(arr)