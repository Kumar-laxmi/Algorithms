def flip(arr, i):
    start = 0
    while start < i:
        temp = arr[start]
        arr[start] = arr[i]
        arr[i] = temp
        start += 1
        i -= 1

def findMaxIndex(arr, n):
    maxIndex = 0
    for i in range(1, n):
        if arr[i] > arr[maxIndex]:
            maxIndex = i
    return maxIndex

def pancakeSort(arr):
    n = len(arr)
    currSize = n
    while currSize > 1:
        maxIndex = findMaxIndex(arr, currSize)
        if maxIndex != currSize - 1:
            flip(arr, maxIndex)
            flip(arr, currSize - 1)
        currSize -= 1

arr = [6, 3, 9, 2, 5]

print("Original array:", arr)
pancakeSort(arr)
print("Sorted array:", arr)
