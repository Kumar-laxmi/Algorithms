def interpolation_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right and target >= arr[left] and target <= arr[right]:
        if left == right:
            if arr[left] == target:
                return left
            return -1

        pos = left + int(((target - arr[left]) * (right - left)) / (arr[right] - arr[left]))

        if arr[pos] == target:
            return pos

        if arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1

    return -1

size = int(input("Enter the size of the array: "))
arr = []
print("Enter the elements of the array: ")
for i in range(size):
    arr.append(int(input()))

target = int(input("Enter the target element to search: "))

index = interpolation_search(arr, target)

if index != -1:
    print("Element found at index", index)
else:
    print("Element not found")
