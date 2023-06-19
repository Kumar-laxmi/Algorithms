def reverseArray(arr, i):
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

def pancakeSort(arr, n):
    for i in range(n, 1, -1):
        maxIndex = findMaxIndex(arr, i)
        if maxIndex != i - 1:
            reverseArray(arr, maxIndex)
            reverseArray(arr, i - 1)

n = int(input("Enter the size of the array: "))
print("Enter the elements of the array:")
arr = list(map(int, input("Enter an element: ").split()))

print("Original array:", arr)

pancakeSort(arr, n)

print("Sorted array:", arr)