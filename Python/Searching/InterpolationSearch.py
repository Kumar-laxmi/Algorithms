def interpolation_search(arr, x):
    low = 0
    high = len(arr) - 1
 
    while low <= high and x >= arr[low] and x <= arr[high]:
        # Estimate the position of x in the array
        pos = low + ((high - low) // (arr[high] - arr[low])) * (x - arr[low])
 
        # If x is found at position pos
        if arr[pos] == x:
            return pos
 
        # If x is greater, ignore the left half
        if arr[pos] < x:
            low = pos + 1
        # If x is smaller, ignore the right half
        else:
            high = pos - 1
 
    # Element not found
    return -1
 
arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
x = 14
 
# Perform interpolation search
result = interpolation_search(arr, x)
 
# Check if the element was found or not
if result == -1:
    print("Element not found.")
else:
    print(f"Element found at index {result}.")
