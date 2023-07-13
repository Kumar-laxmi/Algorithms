def sentinel_search(arr, key):
    n = len(arr)
    last = arr[n - 1]  # Last element of the array
    arr[n - 1] = key  # Element to be searched and placed at the last index
    i = 0
    while arr[i] != key:
        i += 1
    # Putting the last element back
    arr[n - 1] = last
    if i < n - 1 or arr[n - 1] == key:
        print(key, "present at the index", i)
    else:
        print("Element not found")

# Main function
if __name__ == '__main__':
    n = int(input("Enter the size of the array: "))
    arr = []
    print("Enter the array elements:")
    for _ in range(n):
        arr.append(int(input()))
    key = int(input("Enter the element to search: "))
    sentinel_search(arr, key)
