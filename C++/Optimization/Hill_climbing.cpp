#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <cmath>


// Define the purpose function.
double purpose_function(double x) {
    // This function returns the value of the purpose function at the given point x.
    return -std::pow(x, 2) + 5;
}

// Define the search space boundaries.
double lower_limit = -10;
double upper_limit = 10;

// Define the step size for each iteration.
double step = 0.1;

// Define the maximum number of iterations.
int max_iter = 100;

// Define a function to generate a random number between two values.
double random_number(double lower, double upper) {
    // This function returns a random number between the given lower and upper bounds.
    return ((double) rand() / RAND_MAX) * (upper - lower) + lower;
}

// Define the Hill Climbing algorithm.
void Hill_climbing(double lower_bound, double upper_bound, double step, int max_iter) {
    // This function implements the Hill Climbing algorithm for finding the maximum of a function.

    // Initialize the current best solution.
    double current_answer = random_number(lower_bound, upper_bound);
    double current_val = purpose_function(current_answer);

    // Perform the iterations.
    for (int j = 0; j < max_iter; j++) {
        // Generate a random neighbor.
        double neighbor = current_answer + random_number(-step, step);
        neighbor = std::fmax(std::fmin(neighbor, upper_bound), lower_bound);  // Ensure the neighbor is within the boundaries

        // Calculate the objective value of the neighbor.
        double neighbor_val = purpose_function(neighbor);

        // Update the current answer if the neighbor is better.
        if (neighbor_val > current_val) {
            current_answer = neighbor;
            current_val = neighbor_val;
        }
    }

    // Print the best solution found.
    cout << "Best solution: " << current_answer << endl;
    cout << "Best value: " << current_val << endl;
}

int main() {
    // Set the seed for random number generation.
    std::srand(std::time(NULL));

    // Run the Hill Climbing algorithm.
    Hill_climbing(lower_limit, upper_limit, step, max_iter);

    return 0;
}