import itertools

def generate_power_set(original_set):
    n = len(original_set)
    power_set = []

    for i in range(2**n):
        subset = [original_set[j] for j in range(n) if (i & (1 << j)) != 0]
        power_set.append(subset)

    return power_set

def print_power_set(power_set):
    for subset in power_set:
        print("{", end=" ")
        print(*subset, end=" ")
        print("}")

def remove_duplicates(original_set):
    return list(set(original_set))

num_elements = int(input("Enter the number of elements in the original set: "))
original_set = []
print("Enter the elements of the original set: ")
for _ in range(num_elements):
    original_set.append(input())

# Remove duplicates from the original set
original_set = remove_duplicates(original_set)

# Generate the power set
power_set = generate_power_set(original_set)

# Print the power set
print("Power Set:")
print_power_set(power_set)