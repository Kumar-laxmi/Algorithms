#include <bits/stdc++.h>

using namespace std;
// Forward declaration
double generate_neighbor_solution(double solution, const vector<double>& population, mt19937& gen);

// Define the objective function to be optimized
double objective_function(double x) {
    // Example: Sphere function
    return x * x;
}

// Define the bounds for the search space
double lower_bound = -5.12;
double upper_bound = 5.12;

// Define the ABC algorithm
double artificial_bee_colony(int n_iterations, int n_employed_bees, int n_onlooker_bees, int n_trials) {
 vector<double> population(n_employed_bees);
 vector<double> fitness(n_employed_bees);

    // Initialize the population
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(5,4);

    for (int i = 0; i < n_employed_bees; i++) {
        population[i] = dist(gen);
    }

    // Initialize the best solution
    double best_solution = population[0];

    // Main loop
    for (int iteration = 0; iteration < n_iterations; iteration++) {
        // Employed bees phase
        for (int i = 0; i < n_employed_bees; i++) {
            double solution = population[i];
            double new_solution = generate_neighbor_solution(solution, population, gen);
            if (objective_function(new_solution) < objective_function(solution)) {
                population[i] = new_solution;
            }
        }

        // Calculate the fitness values
        double total_fitness = 0.0;
        for (int i = 0; i < n_employed_bees; i++) {
            fitness[i] = 1.0 / (objective_function(population[i]) + 0.01);
            total_fitness += fitness[i];
        }

        // Onlooker bees phase
        std::vector<double> probabilities(n_employed_bees);
        for (int i = 0; i < n_employed_bees; i++) {
            probabilities[i] = fitness[i] / total_fitness;
        }

        for (int i = 0; i < n_onlooker_bees; i++) {
            // Select a solution based on its fitness value
            std::discrete_distribution<int> dist(probabilities.begin(), probabilities.end());
            int selected_index = dist(gen);
            double selected_solution = population[selected_index];

            // Generate a neighbor solution
            double new_solution = generate_neighbor_solution(selected_solution, population, gen);
            if (objective_function(new_solution) < objective_function(selected_solution)) {
                population[selected_index] = new_solution;
            }
        }

        // Scout bees phase
        double best_fitness = fitness[0];
        for (int i = 1; i < n_employed_bees; i++) {
            if (objective_function(population[i]) < objective_function(best_solution)) {
                best_solution = population[i];
                best_fitness = fitness[i];
            }
        }
        for (int i = 0; i < n_employed_bees; i++) {
            if (fitness[i] > best_fitness) {
                population[i] = dist(gen);
            }
        }

        // Print the best solution in the current iteration
        std::cout << "Iteration " << (iteration + 1) << ": Best solution = " << objective_function(best_solution) << std::endl;
    }

    // Return the best solution found
    return best_solution;
}

// Generate a neighbor solution for a given solution
double generate_neighbor_solution(double solution, const std::vector<double>& population, std::mt19937& gen) {
    std::uniform_int_distribution<int> dist(0, population.size() - 1);
    double neighbor = solution;
    while (neighbor == solution) {
        int index = dist(gen);
        neighbor = population[index];
    }
    return neighbor;
}

int main() {
    // Example usage
    double best_solution = artificial_bee_colony(10,30,30,30);
 cout << "Best solution found: " << objective_function(best_solution) << endl;

    return 0;
}