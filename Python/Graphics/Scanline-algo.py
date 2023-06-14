

# =============================Problem Statement=============================
# We are given an array and n queries, in each query we are provided with the range (start and end index) along with the value which needs to be added in the given range in array.

# Example:

# Input: 

# 7               (size of the input array)
# 1 2 3 4 5 6 7     (given array)
# 2               (number of queries)
# 1 3 4           (Add 4 to positions 1 to 3 in the array)
# 2 4 2           (Add 2 to positions 2 to 4 in the array)

# Output:

# 1 6 9 10 7 6 7  


# ============================LOGIC============================

# The problem can be solved by using Scanline algorithm.

# Time complexity: O(n + q), where n is the size of the input array and q is the number of queries.
# Space Complexity: O(n), where n is the size of the array.

# ====================CODE=====================================


# Size of the input array
print("Enter the size of the array")
n = int(input())

# Read input values into the array
print("Enter the array elements")
arr = list(map(int, input().split()))

# Create a dummy list of size n+1 initialized with 0
dummy_array = [0] * (n + 1)

# Number of queries
print("Enter the number of queries")
q = int(input())

queryCnt = 1

# Process the queries
for _ in range(q):

    print("Query", queryCnt)

    # Range (start and end index)
    print("Enter the starting index of the range")
    s = int(input())

    print("Enter the ending index of the range")
    e = int(input())

    # Value to be added in the given range
    print("Enter the value to be added in the given range")
    val = int(input())

    # Add the value to the starting position 's' in the dummy array
    dummy_array[s] += val

    # Subtract the value from the next position after the ending position 'e' in the dummy array
    dummy_array[e + 1] -= val

    queryCnt+=1

# Compute cumulative sum of the dummy array
for i in range(1, n + 1):
    dummy_array[i] += dummy_array[i - 1]

# Add the corresponding values from the dummy array to the original array
for i in range(n):
    arr[i] += dummy_array[i]

# Print the updated array
print("Output:")
for num in arr:
    print(num, end=' ')

print()




# Summary: The code basically updates the array based on the queries by using a dummy array to track the changes at specific positions. By calculating the prefix sum of the dummy array and adding it to the original array, the final output is obtained.

