def bidirectional_selection_sort(arr):
    left = 0
    right = len(arr) - 1

    while left < right:
        minimum = arr[left]
        maximum = arr[right]
        min_index = left
        max_index = right

        for i in range(left, right + 1):
            if arr[i] < minimum:
                minimum = arr[i]
                min_index = i
            if arr[i] > maximum:
                maximum = arr[i]
                max_index = i

        if min_index == right:
            arr[left], arr[min_index] = arr[min_index], arr[left]
        else:
            arr[left], arr[min_index] = arr[min_index], arr[left]
            arr[right], arr[max_index] = arr[max_index], arr[right]

        left += 1
        right -= 1

n = int(input("Enter the number of elements in the array: "))
array = list(map(int, input("Enter the elements: ").split()))

print("Original array:", array)

bidirectional_selection_sort(array)

print("Sorted array:", array)
