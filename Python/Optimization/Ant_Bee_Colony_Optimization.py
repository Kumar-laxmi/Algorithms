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
def artificial_bee_colony(n_iterations, n_employed_individuals, n_onlooker_individuals, n_trials):
    # Initialize the population
    population = []
    for _ in range(n_employed_individuals):
        individual = np.random.uniform(lower_bound, upper_bound)
        population.append(individual)

    # Main loop
    for iteration in range(n_iterations):
        # Employed bees phase
        for i in range(n_employed_individuals):
            individual = population[i]
            new_individual = generate_neighbor_individual(individual, population)
            if objective_function(new_individual) < objective_function(individual):
                population[i] = new_individual

        # Calculate the fitness values
        fitness = [1 / (objective_function(individual) + 0.01) for individual in population]
        total_fitness = sum(fitness)

        # Onlooker bees phase
        for i in range(n_onlooker_individuals):
            # Select an individual based on its fitness value
            probabilities = [f / total_fitness for f in fitness]
            selected_index = np.random.choice(range(n_employed_individuals), p=probabilities)
            selected_individual = population[selected_index]

            # Generate a neighbor individual
            new_individual = generate_neighbor_individual(selected_individual, population)
            if objective_function(new_individual) < objective_function(selected_individual):
                population[selected_index] = new_individual

        # Scout bees phase
        best_individual = min(population, key=objective_function)
        for i in range(n_employed_individuals):
            if objective_function(population[i]) > objective_function(best_individual):
                population[i] = np.random.uniform(lower_bound, upper_bound)

        # Print the best solution in the current iteration
        print(f"Iteration {iteration + 1}: Best solution = {objective_function(best_individual)}")

    # Return the best solution found
    return best_individual

# Generate a neighbor individual for a given individual
def generate_neighbor_individual(individual, population):
    neighbor = individual
    while neighbor is individual:
        neighbor = np.random.choice(population)
    return neighbor

# Example usage
best_individual = artificial_bee_colony(n_iterations=10, n_employed_individuals=30, n_onlooker_individuals=30, n_trials=3)
print(f"Best solution found: {objective_function(best_individual)}")
