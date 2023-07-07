import random
import numpy as np

# Define the objective function to be optimized
def objective_function(x):
    # Example: Sphere function
    return np.sum(np.power(x, 2))

# Define the bounds for the search space
lower_bound = -5.12
upper_bound = 5.12

# Define the ABC algorithm
def artificial_bee_colony(n_iterations, n_employed_bees, n_onlooker_bees, n_trials):
    # Initialize the population
    population = []
    for _ in range(n_employed_bees):
        solution = np.random.uniform(lower_bound, upper_bound)
        population.append(solution)

    # Main loop
    for iteration in range(n_iterations):
        # Employed bees phase
        for i in range(n_employed_bees):
            solution = population[i]
            new_solution = generate_neighbor_solution(solution, population)
            if objective_function(new_solution) < objective_function(solution):
                population[i] = new_solution

        # Calculate the fitness values
        fitness = [1 / (objective_function(solution) + 0.01) for solution in population]
        total_fitness = sum(fitness)

        # Onlooker bees phase
        for i in range(n_onlooker_bees):
            # Select a solution based on its fitness value
            probabilities = [f / total_fitness for f in fitness]
            selected_index = np.random.choice(range(n_employed_bees), p=probabilities)
            selected_solution = population[selected_index]

            # Generate a neighbor solution
            new_solution = generate_neighbor_solution(selected_solution, population)
            if objective_function(new_solution) < objective_function(selected_solution):
                population[selected_index] = new_solution

        # Scout bees phase
        best_solution = min(population, key=objective_function)
        for i in range(n_employed_bees):
            if objective_function(population[i]) > objective_function(best_solution):
                population[i] = np.random.uniform(lower_bound, upper_bound)

        # Print the best solution in the current iteration
        print(f"Iteration {iteration + 1}: Best solution = {objective_function(best_solution)}")

    # Return the best solution found
    return best_solution

# Generate a neighbor solution for a given solution
def generate_neighbor_solution(solution, population):
    neighbor = solution
    while neighbor is solution:
        neighbor = np.random.choice(population)
    return neighbor

# Example usage
best_solution = artificial_bee_colony(n_iterations=10, n_employed_bees=30, n_onlooker_bees=30, n_trials=3)
print(f"Best solution found: {objective_function(best_solution)}")
