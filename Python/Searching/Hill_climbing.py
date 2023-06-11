"""
This code implements the Hill Climbing algorithm for finding the maximum of a function.

The algorithm starts with a random solution and then iteratively generates neighbors of the current solution. If a neighbor has a 
higher objective value than the current solution, the current solution is replaced with the neighbor. The algorithm terminates when no 
neighbor has a higher objective value than the current solution.

The code uses the following functions:

* `purpose_function()`: This function returns the value of the objective function at the given point `x`.
* `random_number()`: This function returns a random number between the given lower and upper bounds.
* `Hill_climbing()`: This function implements the Hill Climbing algorithm.
* `main()`: This function sets the seed for random number generation and then runs the Hill Climbing algorithm.
"""
import math
import random
import time

# Define the search space boundaries.
LOWER_LIMIT = -10
UPPER_LIMIT = 10

# Define the step size for each iteration.
STEP_SIZE = 0.1

# Define the maximum number of iterations.
MAX_ITERATIONS = 100

# This function returns the value of the objective function at the given point `x`.
def purpose_function(x):
    # Calculate the objective value of x.
    return -math.pow(x, 2) + 5

# This function returns a random number between the given lower and upper bounds.
def random_number(lower, upper):
    # Generate a random number between the given lower and upper bounds.
    return random.random() * (upper - lower) + lower

# This function implements the Hill Climbing algorithm for finding the maximum of a function.
def hill_climbing(lower_bound, upper_bound, step, max_iter):
    # Initialize the current best solution.
    current_answer = random_number(lower_bound, upper_bound)
    current_val = purpose_function(current_answer)

    # Perform the iterations.
    for i in range(max_iter):
        # Generate a random neighbor.
        neighbor = current_answer + random_number(-step, step)
        neighbor = max(min(neighbor, upper_bound), lower_bound)  # Ensure the neighbor is within the boundaries

        # Calculate the objective value of the neighbor.
        neighbor_val = purpose_function(neighbor)

        # Update the current answer if the neighbor is better.
        if neighbor_val > current_val:
            current_answer = neighbor
            current_val = neighbor_val

    # Print the best solution found.
    print("Best solution: " + str(current_answer))
    print("Best value: " + str(current_val))

# This function sets the seed for random number generation.
def main():
    # Set the seed for random number generation.
    random.seed(time.time())

    # Run the Hill Climbing algorithm.
    hill_climbing(LOWER_LIMIT, UPPER_LIMIT, STEP_SIZE, MAX_ITERATIONS)

if __name__ == "__main__":
    main()
