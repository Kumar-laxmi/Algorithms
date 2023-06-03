arr = [5, 1, 4, 2, 8, 0, 2, 3, 9, 7]
print(arr)
k_start = 0
k_end = len(arr) - 1
length = len(arr)  # Renamed variable from 'len' to 'length'
swapped = False
if length % 2 == 0:
    length = length // 2
else:
    length = length // 2 + 1
for i in range(length):
    for j in range(len(arr) - i - 1 - k_start):
        if arr[j] > arr[j + 1]:
            temp = arr[j + 1]
            arr[j + 1] = arr[j]
            arr[j] = temp
            swapped = True
    if not swapped:
        break
    for x in range(k_end, k_start + 1, -1):
        if arr[x - 1] > arr[x]:
            temp = arr[x - 1]
            arr[x - 1] = arr[x]
            arr[x] = temp
    k_end -= 1
    k_start += 1
print(arr)

print("Thank You")
