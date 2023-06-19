#include <stdio.h>
#include <stdlib.h>

// Define the search space boundaries.
const double LOWER_LIMIT = -10;
const double UPPER_LIMIT = 10;

// Define the step size for each iteration.
const double STEP_SIZE = 0.1;

// Define the maximum number of iterations.
const int MAX_ITERATIONS = 100;

// This function returns the value of the objective function at the given point x.
double purposeFunction(double x) {
  // Calculate the objective value of x.
  return -pow(x, 2) + 5;
}

// This function returns a random number between the given lower and upper bounds.
double randomNumber(double lower, double upper) {
  // Generate a random number between the given lower and upper bounds.
  return (double)rand() / RAND_MAX * (upper - lower) + lower;
}

// This function implements the Hill Climbing algorithm for finding the maximum of a function.
void Hill_Climbing(double lowerLimit, double upperLimit, double stepSize, int maxIterations) {
  // Initialize the current best solution.
  double currentAnswer = randomNumber(lowerLimit, upperLimit);
  double currentValue = purposeFunction(currentAnswer);

  // Perform the iterations.
  for (int i = 0; i < maxIterations; i++) {
    // Generate a random neighbor.
    double neighbor = currentAnswer + randomNumber(-stepSize, stepSize);
    neighbor = fmax(fmin(neighbor, upperLimit), lowerLimit); // Ensure the neighbor is within the boundaries

    // Calculate the objective value of the neighbor.
    double neighborValue = purposeFunction(neighbor);

    // Update the current answer if the neighbor is better.
    if (neighborValue > currentValue) {
      currentAnswer = neighbor;
      currentValue = neighborValue;
    }
  }

  // Print the best solution found.
  printf("Best solution: %.2f\n", currentAnswer);
  printf("Best value: %.2f\n", currentValue);
}

// This function sets the seed for random number generation.
void main() {
  // Set the seed for random number generation.
  srand(time(NULL));

  // Run the Hill Climbing algorithm.
  Hill_Climbing(LOWER_LIMIT, UPPER_LIMIT, STEP_SIZE, MAX_ITERATIONS);
}