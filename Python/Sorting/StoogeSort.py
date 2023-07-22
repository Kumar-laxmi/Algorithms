def stooge_sort(arr, low, high):
    if low >= high:
        return
    # If the first element is greater than the last element, swap them
    if arr[low] > arr[high]:
        arr[low], arr[high] = arr[high], arr[low]
    # If there are more than 2 elements in the array
    if high - low + 1 > 2:
        t = (high - low + 1) // 3
        # Sort the first two-thirds of the array
        stooge_sort(arr, low, high - t)
        # Sort the last two-thirds of the array
        stooge_sort(arr, low + t, high)
        # Sort the first two-thirds of the array again
        stooge_sort(arr, low, high - t)
# Function to print the array
def print_array(arr):
    for num in arr:
        print(num, end=" ")
    print()
# Driver Code
arr = [10, 5, 8, 2, 1, 6]
print("Original array:", end=" ")
print_array(arr)
stooge_sort(arr, 0, len(arr) - 1)
print("Sorted array:", end=" ")
print_array(arr)