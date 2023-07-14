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
double LB = -5.12;
double upper_bound = 5.12;
// done

// Define the Ant Been Colony algorithm
double artificial_bee_colony(int n_iterations, int NB, int n_onlooker_bees, int n_trials) {
 vector<double> population(NB);
 vector<double> fitness(NB);

    // Initialize the sample space
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> D(5,4);

    for (int i = 0; i < NB; i++) {
        population[i] = D(gen);
    }

    // Initialize the best solution
    double best_solution = population[0];

    // Main loop starting here
    for (int iteration = 0; iteration < n_iterations; iteration++) {
        // Employed bees are initialized
        for (int i = 0; i < NB; i++) {
            double solution = population[i];
            double new_solution = generate_neighbor_solution(solution, population, gen);
            if (objective_function(new_solution) < objective_function(solution)) {
                population[i] = new_solution;
            }
        }

        // going to find objective values
        double total_fitness = 0.0;
        for (int i = 0; i < NB; i++) {
            fitness[i] = 1.0 / (objective_function(population[i]) + 0.01);
            total_fitness += fitness[i];
        }

        // Onlooker phase
        std::vector<double> probabilities(NB);
        for (int i = 0; i < NB; i++) {
            probabilities[i] = fitness[i] / total_fitness;
        }

        for (int i = 0; i < n_onlooker_bees; i++) {
            // Select a solution based on its fitness value to get the objective value
            std::discrete_distribution<int> D(probabilities.begin(), probabilities.end());
            int SI = D(gen);
            double selected_solution = population[SI];

            // optimal ABC
            double new_solution = generate_neighbor_solution(selected_solution, population, gen);
            if (objective_function(new_solution) < objective_function(selected_solution)) {
                population[SI] = new_solution;
            }
        }

        // ABC
        double best_fitness = fitness[0];
        for (int i = 1; i < NB; i++) {
            if (objective_function(population[i]) < objective_function(best_solution)) {
                best_solution = population[i];
                best_fitness = fitness[i];
            }
        }
        for (int i = 0; i < NB; i++) {
            if (fitness[i] > best_fitness) {
                population[i] = D(gen);
            }
        }

        // ABC
        std::cout << "Iteration " << (iteration + 1) << ": Best solution = " << objective_function(best_solution) << std::endl;
    }

    // ABC
    return best_solution;
}

// ABC
double generate_neighbor_solution(double solution, const std::vector<double>& population, std::mt19937& gen) {
    std::uniform_int_distribution<int> D(0, population.size() - 1);
    double neighbor = solution;
    while (neighbor == solution) {
        int index = D(gen);
        neighbor = population[index];
    }
    return neighbor;
}

int main() {
    // ABC
    double best_solution = artificial_bee_colony(10,30,30,30);
 cout << "Best solution found: " << objective_function(best_solution) << endl;

    return 0;
}