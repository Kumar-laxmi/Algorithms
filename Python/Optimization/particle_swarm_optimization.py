import random
import math
import copy
import sys

def objective_function(position):
    fitness_val = 0.0
    for i in range(len(position)):
        xi = position[i]
        fitness_val += (xi * xi) - (10 * math.cos(2 * math.pi * xi)) + 10
    return fitness_val


class Particle:
    def __init__(self, objective_function, dim, min_val, max_val, seed):
        self.random = random.Random(seed)
        self.position = [0.0] * dim
        self.velocity = [0.0] * dim
        self.best_position = [0.0] * dim

        for i in range(dim):
            self.position[i] = (max_val - min_val) * self.random.random() + min_val
            self.velocity[i] = (max_val - min_val) * self.random.random() + min_val

        self.fitness = objective_function(self.position)
        self.best_position = copy.copy(self.position)
        self.best_fitness_val = self.fitness

def particle_swarm_optimization(objective_function, max_iter, num_particles, dim, min_val, max_val):
    inertia_weight = 0.8
    cognitive_weight = 1.49445
    social_weight = 1.49445
    random_generator = random.Random(0)
    swarm = [Particle(objective_function, dim, min_val, max_val, i) for i in range(num_particles)]
    best_swarm_position = [0.0] * dim
    best_swarm_fitness_val = sys.float_info.max

    for i in range(num_particles):
        if swarm[i].fitness < best_swarm_fitness_val:
            best_swarm_fitness_val = swarm[i].fitness
            best_swarm_position = copy.copy(swarm[i].position)

    iteration = 0
    while iteration < max_iter:
        if iteration % 10 == 0 and iteration > 1:
            print("Iteration = " + str(iteration) + " best fitness = %.3f" % best_swarm_fitness_val)

        for i in range(num_particles):
            for k in range(dim):
                r1 = random_generator.random()
                r2 = random_generator.random()

                swarm[i].velocity[k] = (
                    (inertia_weight * swarm[i].velocity[k]) +
                    (cognitive_weight * r1 * (swarm[i].best_position[k] - swarm[i].position[k])) +
                    (social_weight * r2 * (best_swarm_position[k] - swarm[i].position[k]))
                )

                if swarm[i].velocity[k] < min_val:
                    swarm[i].velocity[k] = min_val
                elif swarm[i].velocity[k] > max_val:
                    swarm[i].velocity[k] = max_val

            for k in range(dim):
                swarm[i].position[k] += swarm[i].velocity[k]

            swarm[i].fitness = objective_function(swarm[i].position)

            if swarm[i].fitness < swarm[i].best_fitness_val:
                swarm[i].best_fitness_val = swarm[i].fitness
                swarm[i].best_position = copy.copy(swarm[i].position)

            if swarm[i].fitness < best_swarm_fitness_val:
                best_swarm_fitness_val = swarm[i].fitness
                best_swarm_position = copy.copy(swarm[i].position)

        iteration += 1

    return best_swarm_position

print("Particle Swarm Optimization Starts\n")
dim = 3
objective_function = objective_function
for i in range(dim - 1):
    print("0, ", end="")
print("0)")

num_particles = 50
max_iter = 100

print("Setting num_particles = " + str(num_particles))
print("Setting max_iter = " + str(max_iter))
print("\nStarting PSO algorithm\n")

best_position = particle_swarm_optimization(objective_function, max_iter, num_particles, dim, -10.0, 10.0)

print("\nPSO completed\n")
print("\nBest solution found:")
print(["%.6f" % best_position[k] for k in range(dim)])
fitness_val = objective_function(best_position)
print("Fitness of best solution = %.6f" % fitness_val)

print("\nParticle Swarm Optimization Ends\n")
