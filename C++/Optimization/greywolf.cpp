#include <iostream>
#include <random>
#include <vector>
#include <functional>
#include <limits>

// Objective function
double objective_function(const std::vector<double>& position) {
    double x1 = position[0];
    double x2 = position[1];

    double z = 2 * x1 * x2 + x2 - x1 * x1 - 2 * x2 * x2;
    return z;
}

// Particle class
class Particle {
public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> local_best_position;
    double local_best_fitness;
    double fitness;

    Particle(const std::vector<std::pair<double, double>>& bounds) {
        position.resize(2);
        velocity.resize(2);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis1(bounds[0].first, bounds[0].second);
        std::uniform_real_distribution<double> dis2(bounds[1].first, bounds[1].second);

        position[0] = dis1(gen);
        position[1] = dis2(gen);

        velocity[0] = dis1(gen);
        velocity[1] = dis2(gen);

        local_best_position = position;
        local_best_fitness = std::numeric_limits<double>::max();
        fitness = std::numeric_limits<double>::max();
    }

    void evaluate(const std::function<double(const std::vector<double>&)>& objective_function) {
        fitness = objective_function(position);
        if (fitness < local_best_fitness) {
            local_best_position = position;
            local_best_fitness = fitness;
        }
    }

    void update_velocity(const std::vector<double>& global_best_position, double inertia_constant, double cognitive_constant, double social_constant) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);

        double r1 = dis(gen);
        double r2 = dis(gen);

        double cognitive_velocity = cognitive_constant * r1 * (local_best_position[0] - position[0]);
        double social_velocity = social_constant * r2 * (global_best_position[0] - position[0]);
        velocity[0] = inertia_constant * velocity[0] + cognitive_velocity + social_velocity;

        r1 = dis(gen);
        r2 = dis(gen);

        cognitive_velocity = cognitive_constant * r1 * (local_best_position[1] - position[1]);
        social_velocity = social_constant * r2 * (global_best_position[1] - position[1]);
        velocity[1] = inertia_constant * velocity[1] + cognitive_velocity + social_velocity;
    }

    void update_position(const std::vector<std::pair<double, double>>& bounds) {
        position[0] += velocity[0];
        position[1] += velocity[1];

        // Check and repair to satisfy the upper bounds
        if (position[0] > bounds[0].second) {
            position[0] = bounds[0].second;
        }
        if (position[1] > bounds[1].second) {
            position[1] = bounds[1].second;
        }

        // Check and repair to satisfy the lower bounds
        if (position[0] < bounds[0].first) {
            position[0] = bounds[0].first;
        }
        if (position[1] < bounds[1].first) {
            position[1] = bounds[1].first;
        }
    }
};

// PSO class
class PSO {
public:
    std::function<double(const std::vector<double>&)> objective_function;
    std::vector<std::pair<double, double>> bounds;
    int particle_size;
    int iterations;
    double inertia_constant;
    double cognitive_constant;
    double social_constant;
    double global_best_fitness;
    std::vector<double> global_best_position;
    std::vector<Particle> swarm_particles;

    PSO(const std::function<double(const std::vector<double>&)>& objective_function,
        const std::vector<std::pair<double, double>>& bounds,
        int particle_size,
        int iterations,
        double inertia_constant,
        double cognitive_constant,
        double social_constant)
        : objective_function(objective_function),
          bounds(bounds),
          particle_size(particle_size),
          iterations(iterations),
          inertia_constant(inertia_constant),
          cognitive_constant(cognitive_constant),
          social_constant(social_constant),
          global_best_fitness(std::numeric_limits<double>::max()),
          global_best_position(2) {
        swarm_particles.resize(particle_size);

        for (int i = 0; i < particle_size; ++i) {
            swarm_particles[i] = Particle(bounds);
        }

        for (int i = 0; i < iterations; ++i) {
            for (auto& particle : swarm_particles) {
                particle.evaluate(objective_function);

                if (particle.local_best_fitness < global_best_fitness) {
                    global_best_position = particle.local_best_position;
                    global_best_fitness = particle.local_best_fitness;
                }

                particle.update_velocity(global_best_position, inertia_constant, cognitive_constant, social_constant);
                particle.update_position(bounds);
            }
        }

        std::cout << "RESULT:" << std::endl;
        std::cout << "Optimal Solution: (" << global_best_position[0] << ", " << global_best_position[1] << ")" << std::endl;
        std::cout << "Objective function value: " << global_best_fitness << std::endl;
    }
};

int main() {
    std::vector<std::pair<double, double>> bounds = {std::make_pair(-3000000.0, 3000000.0), std::make_pair(-3000000.0, 3000000.0)};
    int num_variables = 2;
    int optimization_mode = 1;
    int particle_size = 10;
    int iterations = 200;
    double inertia_constant = 0.8;
    double cognitive_constant = 1;
    double social_constant = 2;

    double initial_fitness;
    if (optimization_mode == -1) {
        initial_fitness = std::numeric_limits<double>::infinity();
    } else if (optimization_mode == 1) {
        initial_fitness = -std::numeric_limits<double>::infinity();
    }

    PSO pso(objective_function, bounds, particle_size, iterations, inertia_constant, cognitive_constant, social_constant);

    return 0;
}
