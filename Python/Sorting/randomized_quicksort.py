import random

def partition(arr, p, r):
    x = arr[r]
    i = p - 1
    for j in range(p, r):
        if arr[j] <= x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[r] = arr[r], arr[i+1]
    return i+1

def randomized_partition(arr, p, r):
    i = p + random.randrange(0, r-p+1)
    arr[i], arr[r] = arr[r], arr[i]
    return partition(arr, p, r)

def randomized_quicksort(arr, p, r):
    if p < r:
        q = randomized_partition(arr, p, r)
        randomized_quicksort(arr, p, q-1)
        randomized_quicksort(arr, q+1, r)

arr = [78, 9, 10, -1, 2, -45, 91]
n = len(arr)
random.seed()
randomized_quicksort(arr, 0, n-1)
print("Sorted array using Randomized quicksort is:")
for i in range(n):
    print(arr[i], end=" ")
print()