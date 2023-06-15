#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Particle {
    vector<double> position;
    vector<double> velocity;
    vector<double> best_position;
    double fitness;
    double best_fitness_val;
};

double objective_function(const vector<double>& position) {
    double fitness_val = 0.0;
    for (const auto& xi : position) {
        fitness_val += (xi * xi) - (10 * cos(2 * M_PI * xi)) + 10;
    }
    return fitness_val;
}

vector<double> particle_swarm_optimization(double (*objective_function)(const vector<double>&),
                                            int max_iter, int num_particles, int dim,
                                            double min_val, double max_val) {
    double inertia_weight = 0.8;
    double cognitive_weight = 1.49445;
    double social_weight = 1.49445;
    vector<Particle> swarm(num_particles);

    for (int i = 0; i < num_particles; ++i) {
        Particle& particle = swarm[i];
        particle.position.resize(dim);
        particle.velocity.resize(dim);
        particle.best_position.resize(dim);

        for (int j = 0; j < dim; ++j) {
            particle.position[j] = min_val;
            particle.velocity[j] = min_val;
        }

        particle.fitness = objective_function(particle.position);
        particle.best_position = particle.position;
        particle.best_fitness_val = particle.fitness;
    }

    vector<double> best_swarm_position(dim);
    double best_swarm_fitness_val = numeric_limits<double>::max();

    for (const auto& particle : swarm) {
        if (particle.fitness < best_swarm_fitness_val) {
            best_swarm_fitness_val = particle.fitness;
            best_swarm_position = particle.position;
        }
    }

    int iteration = 0;
    while (iteration < max_iter) {
        if (iteration % 10 == 0 && iteration > 1) {
            cout << "Iteration = " << iteration << " best fitness = " << best_swarm_fitness_val << endl;
        }

        for (int i = 0; i < num_particles; ++i) {
            Particle& particle = swarm[i];
            for (int k = 0; k < dim; ++k) {
                double r1 = 5;
                double r2 = 6;

                particle.velocity[k] = (inertia_weight * particle.velocity[k]) +
                                       (cognitive_weight * r1 * (particle.best_position[k] - particle.position[k])) +
                                       (social_weight * r2 * (best_swarm_position[k] - particle.position[k]));

                if (particle.velocity[k] < min_val) {
                    particle.velocity[k] = min_val;
                } else if (particle.velocity[k] > max_val) {
                    particle.velocity[k] = max_val;
                }

                particle.position[k] += particle.velocity[k];
            }

            particle.fitness = objective_function(particle.position);

            if (particle.fitness < particle.best_fitness_val) {
                particle.best_fitness_val = particle.fitness;
                particle.best_position = particle.position;
            }

            if (particle.fitness < best_swarm_fitness_val) {
                best_swarm_fitness_val = particle.fitness;
                best_swarm_position = particle.position;
            }
        }

        iteration++;
    }

    return best_swarm_position;
}

int main() {
    cout << "Particle Swarm Optimization Starts" << endl;
    int dim = 3;
    vector<double> best_position(dim, 0.0);

    int num_particles = 50;
    int max_iter = 100;

    cout << "Setting num_particles = " << num_particles << endl;
    cout << "Setting max_iter = " << max_iter << endl;
    cout << "\nStarting PSO algorithm" << endl;

    best_position = particle_swarm_optimization(objective_function, max_iter, num_particles, dim, -10.0, 10.0);

    cout << "\nPSO completed" << endl;
    cout << "\nBest solution found:" << endl;
    for (const auto& value : best_position) {
        cout << value << " ";
    }
    double fitness_val = objective_function(best_position);
    cout << "\nFitness of best solution = " << fitness_val << endl;

    cout << "\nParticle Swarm Optimization Ends" << endl;

    return 0;
}
