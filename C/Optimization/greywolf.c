#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Objective function
double objective_function(double position[], int num_variables) {
    double x1 = position[0];
    double x2 = position[1];

    double z = 2 * x1 * x2 + x2 - x1 * x1 - 2 * x2 * x2;
    return z;
}

// Particle structure
typedef struct {
    double* position;
    double* velocity;
    double* local_best_position;
    double local_best_fitness;
    double fitness;
} Particle;

// Particle initialization
void initialize_particle(Particle* particle, double bounds[][2], int num_variables) {
    particle->position = (double*)malloc(num_variables * sizeof(double));
    particle->velocity = (double*)malloc(num_variables * sizeof(double));
    particle->local_best_position = (double*)malloc(num_variables * sizeof(double));

    for (int i = 0; i < num_variables; i++) {
        particle->position[i] = bounds[i][0] + ((double)rand() / RAND_MAX) * (bounds[i][1] - bounds[i][0]);
        particle->velocity[i] = -1 + ((double)rand() / RAND_MAX) * 2;
        particle->local_best_position[i] = particle->position[i];
    }

    particle->local_best_fitness = INFINITY;
    particle->fitness = INFINITY;
}

// Particle evaluation
void evaluate_particle(Particle* particle, double (*objective_function)(double[], int)) {
    particle->fitness = objective_function(particle->position, 2);

    if (particle->fitness < particle->local_best_fitness) {
        particle->local_best_fitness = particle->fitness;

        for (int i = 0; i < 2; i++) {
            particle->local_best_position[i] = particle->position[i];
        }
    }
}

// Particle velocity update
void update_particle_velocity(Particle* particle, double global_best_position[], double inertia_constant, double cognitive_constant, double social_constant) {
    double r1 = (double)rand() / RAND_MAX;
    double r2 = (double)rand() / RAND_MAX;

    for (int i = 0; i < 2; i++) {
        double cognitive_velocity = cognitive_constant * r1 * (particle->local_best_position[i] - particle->position[i]);
        double social_velocity = social_constant * r2 * (global_best_position[i] - particle->position[i]);
        particle->velocity[i] = inertia_constant * particle->velocity[i] + cognitive_velocity + social_velocity;
    }
}

// Particle position update
void update_particle_position(Particle* particle, double bounds[][2], int num_variables) {
    for (int i = 0; i < num_variables; i++) {
        particle->position[i] = particle->position[i] + particle->velocity[i];

        // Check and repair to satisfy the upper bounds
        if (particle->position[i] > bounds[i][1]) {
            particle->position[i] = bounds[i][1];
        }
        // Check and repair to satisfy the lower bounds
        if (particle->position[i] < bounds[i][0]) {
            particle->position[i] = bounds[i][0];
        }
    }
}

// Particle swarm optimization
void particle_swarm_optimization(double (*objective_function)(double[], int), double bounds[][2], int num_variables, int particle_size, int iterations, double inertia_constant, double cognitive_constant, double social_constant) {
    Particle* swarm_particles = (Particle*)malloc(particle_size * sizeof(Particle));
    double global_best_position[2];
    double global_best_fitness = INFINITY;

    for (int i = 0; i < particle_size; i++) {
        initialize_particle(&swarm_particles[i], bounds, num_variables);
    }

    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < particle_size; i++) {
            evaluate_particle(&swarm_particles[i], objective_function);

            if (swarm_particles[i].local_best_fitness < global_best_fitness) {
                global_best_fitness = swarm_particles[i].local_best_fitness;
                for (int j = 0; j < num_variables; j++) {
                    global_best_position[j] = swarm_particles[i].local_best_position[j];
                }
            }

            update_particle_velocity(&swarm_particles[i], global_best_position, inertia_constant, cognitive_constant, social_constant);
            update_particle_position(&swarm_particles[i], bounds, num_variables);
        }
    }

    printf("RESULT:\n");
    printf("Optimal Solution: (%f, %f)\n", global_best_position[0], global_best_position[1]);
    printf("Objective function value: %f\n", global_best_fitness);

    // Cleanup
    for (int i = 0; i < particle_size; i++) {
        free(swarm_particles[i].position);
        free(swarm_particles[i].velocity);
        free(swarm_particles[i].local_best_position);
    }
    free(swarm_particles);
}

int main() {
    double bounds[2][2] = { {-3000000.0, 3000000.0}, {-3000000.0, 3000000.0} };
    int num_variables = 2;
    int particle_size = 10;
    int iterations = 200;
    double inertia_constant = 0.8;
    double cognitive_constant = 1;
    double social_constant = 2;

    particle_swarm_optimization(objective_function, bounds, num_variables, particle_size, iterations, inertia_constant, cognitive_constant, social_constant);

    return 0;
}
