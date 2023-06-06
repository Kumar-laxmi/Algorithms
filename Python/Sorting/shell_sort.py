def shell_sort(arr):
    n = len(arr)

    # Start with a big gap, then reduce the gap
    gap = n // 2
    while gap > 0:
        # Do a gapped insertion sort for this gap size.
        # The first gap elements a[0..gap-1] are already in gapped order.
        # Keep adding one more element until the entire array is gap sorted.
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                # Shift earlier gap-sorted elements up until the correct location for a[i] is found.
                arr[j] = arr[j - gap]
                j -= gap
            # Put temp (the original a[i]) in its correct location.
            arr[j] = temp
        gap //= 2

    return arr

# Test the algorithm
arr = [9, 8, 1, 7, 4, 3]
print("Array before sorting:")
print(arr)
sorted_arr = shell_sort(arr)
print("Array after sorting:")
print(sorted_arr)