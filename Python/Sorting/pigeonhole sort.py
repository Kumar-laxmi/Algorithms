def pigeonhole_sort(arr):
    min_val = min(arr)
    max_val = max(arr)
    size = max_val - min_val + 1
    pigeonholes = [0] * size

    for num in arr:
        pigeonholes[num - min_val] += 1

    index = 0
    for i in range(size):
        while pigeonholes[i] > 0:
            arr[index] = i + min_val
            pigeonholes[i] -= 1
            index += 1

    return arr

n = int(input("Enter the number of elements: "))
arr = []
print("Enter the elements:")
for _ in range(n):
    arr.append(int(input()))

arr = pigeonhole_sort(arr)

print("Sorted array:", arr)
