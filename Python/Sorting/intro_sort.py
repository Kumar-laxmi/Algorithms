def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def introsort(arr):
    maxdepth = (len(arr).bit_length() - 1)*2
    intro_er(arr, 0, len(arr), maxdepth)

def intro_er(arr, start, end, maxdepth):
    if end - start <= 1:
        return
    elif maxdepth == 0:
        heapsort(arr, start, end)
    else:
        p = partition(arr, start, end)
        intro_er(arr, start, p+1, maxdepth - 1)
        intro_er(arr, p+1, end, maxdepth - 1)

def partition(arr, start, end):
    pivot = arr[start]
    i = start - 1
    j = end

    while True:
        i += 1
        while arr[i] < pivot:
            i += 1

        j -= 1
        while arr[j] > pivot:
            j -= 1

        if i >= j:
            return j

        swap(arr, i, j)

def max_heap(arr, start, end):
    def parent(i):
        return (i-1)//2
    length = end - start
    index = parent(length - 1)
    while index >= 0:
        max_heapify(arr, index, start, end)
        index -= 1

def max_heapify(arr, index, start, end):
    def left(i):
        return 2*i + 1
    def right(i):
        return 2*i + 2

    size = end - start
    leftSide = left(index)
    rightSide = right(index)
    if (leftSide < size and arr[start + leftSide] > arr[start + index]):
        largest = leftSide
    else:
        largest = index
    if (rightSide < size and arr[start + rightSide] > arr[start + largest]):
        largest = rightSide
    if largest != index:
        swap(arr, start+largest, start+index)
        max_heapify(arr, largest, start, end)

def heapsort(arr, start, end):
    max_heap(arr, start, end)
    for i in range(end - 1, start, -1):
        swap(arr, start, i)
        max_heapify(arr, index=0, start=start, end=i)


print("Enter elements to sort (seperated by spaces): ")
arr = [int(i) for i in input().split()]
introsort(arr)
print("Sorted array: ")
print(arr)

'''
Sample Input:
4 -3 2 1 9 3
Sample Output:
[0, 1, 1, 2, 3, 5, 9]
'''
