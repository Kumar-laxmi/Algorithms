# Function to solve the Fractional Knapsack problem
def fractionalKnapsack(capacity, weights, values):
    # Calculate value per unit weight for each item
    valuePerWeight = [v/w for v, w in zip(values, weights)]

    # Create a list of tuples with (weight, value, value per weight)
    items = list(zip(weights, values, valuePerWeight))

    # Sort items based on value per unit weight in descending order
    items.sort(key=lambda x: x[2], reverse=True)

    totalValue = 0.0
    remainingCapacity = capacity

    for weight, value, _ in items:
        if remainingCapacity >= weight:
            # Add the complete item if it can fit in the knapsack
            totalValue += value
            remainingCapacity -= weight
        else:
            # Add a fraction of the item if it cannot fit completely
            fraction = remainingCapacity / weight
            totalValue += fraction * value
            break

    return totalValue


# Main program
capacity = int(input("Enter the capacity of the knapsack: "))
numItems = int(input("Enter the number of items: "))

weights = []
values = []

# Input the weight and value of each item
for i in range(numItems):
    weight, value = map(int, input(f"Enter weight and value for item {i+1}: ").split())
    weights.append(weight)
    values.append(value)

# Solve the Fractional Knapsack problem
maxValue = fractionalKnapsack(capacity, weights, values)

# Display the maximum value that can be obtained
print("Maximum value that can be obtained:", maxValue)
