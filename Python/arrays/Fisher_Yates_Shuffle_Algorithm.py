import random

# Function to perform Fisher-Yates shuffle
def fisherYatesShuffle(arr):
    n = len(arr)

    for i in range(n - 1, 0, -1):
        j = random.randint(0, i) # Generate a random index between 0 and i (inclusive)
        arr[i], arr[j] = arr[j], arr[i] # Swap the elements at indices i and j

# Create a list of integers
size = int(input("Enter the size of the array: "))
numbers = []

print("Enter the elements of the array: ")
for _ in range(size):
    numbers.append(int(input()))

# Print the original list
print("Original list:", numbers)

# Shuffle the list using Fisher-Yates shuffle
fisherYatesShuffle(numbers)

# Print the shuffled list
print("Shuffled list:", numbers)
