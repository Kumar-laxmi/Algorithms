'''This code is the Python implementation of the Cocktail Sort algorithm to sort an integer list in ascending order. Here's a brief explanation of the code:

1. The integer list `arr` is defined with some initial values.

2. The initial list is printed using `print(arr)`.

3. Variables `k_start` and `k_end` are initialized to track the starting and ending indices for the second pass of the Cocktail Sort.

4. The length of the list is stored in the variable `length`. Note that the variable name `len` has been changed to `length` to avoid conflicting with the built-in `len()` function in Python.

5. A boolean variable `swapped` is set to `False` to keep track of whether any swaps have been made during the sorting process.

6. The code then determines the number of iterations required for the Cocktail Sort loop based on the length of the list. If the length is even, the number of iterations is half the length; otherwise, it is half the length plus one.

7. The first pass of the Cocktail Sort is performed using nested loops. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element. If a swap occurs, the `swapped` variable is set to `True`.

8. After completing the first pass, the code checks if any swaps were made during the pass. If no swaps occurred, it means the list is already sorted, and the loop is terminated.

9. The second pass of the Cocktail Sort starts, iterating in reverse from `k_end` to `k_start + 1`. It compares adjacent elements and swaps them if the preceding element is greater than the succeeding element.

10. The values of `k_end` and `k_start` are adjusted to narrow down the range of elements that need to be sorted in the next iteration.

11. Steps 7 to 10 are repeated until the list is fully sorted.

12. The sorted list is printed using `print(arr)`.

The code effectively demonstrates the Cocktail Sort algorithm by sorting the given integer list in ascending order.'''
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
