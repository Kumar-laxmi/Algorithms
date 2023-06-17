import random

# ------------------------------------------------------------------------------
def objective_function(position):
    x1 = position[0]
    x2 = position[1]

    z = 2*x1*x2 + x2 - x1*x1 - 2*x2*x2
    return z
  
bounds = [(-3000000, 3000000), (-3000000, 3000000)]  # upper and lower bounds of variables
num_variables = 2  # number of variables
optimization_mode = 1  # if minimization problem, optimization_mode = -1; if maximization problem, optimization_mode = 1
   
# PARAMETERS OF PSO
particle_size = 10  # number of particles
iterations = 200  # max number of iterations
inertia_constant = 0.8
cognitive_constant = 1
social_constant = 2


# ------------------------------------------------------------------------------
class Particle:
    def __init__(self, bounds):
        self.position = []  # particle position
        self.velocity = []  # particle velocity
        self.local_best_position = []  # best position of the particle
        self.local_best_fitness = initial_fitness
        self.fitness = initial_fitness
        
        for i in range(num_variables):
            self.position.append(random.uniform(bounds[i][0], bounds[i][1]))
            self.velocity.append(random.uniform(-1, 1))
  
    def evaluate(self, objective_function):
        self.fitness = objective_function(self.position)
        if optimization_mode == -1:
            if self.fitness < self.local_best_fitness:
                self.local_best_position = self.position
                self.local_best_fitness = self.fitness
        elif optimization_mode == 1:
            if self.fitness > self.local_best_fitness:
                self.local_best_position = self.position
                self.local_best_fitness = self.fitness
                
    def update_velocity(self, global_best_position):
        for i in range(num_variables):
            r1 = random.random()
            r2 = random.random()
  
            cognitive_velocity = cognitive_constant * r1 * (self.local_best_position[i] - self.position[i])
            social_velocity = social_constant * r2 * (global_best_position[i] - self.position[i])
            self.velocity[i] = inertia_constant * self.velocity[i] + cognitive_velocity + social_velocity
  
    def update_position(self, bounds):
        for i in range(num_variables):
            self.position[i] = self.position[i] + self.velocity[i]
  
            # check and repair to satisfy the upper bounds
            if self.position[i] > bounds[i][1]:
                self.position[i] = bounds[i][1]
            # check and repair to satisfy the lower bounds
            if self.position[i] < bounds[i][0]:
                self.position[i] = bounds[i][0]
  
class PSO:
    def __init__(self, objective_function, bounds, particle_size, iterations):
        global_best_fitness = initial_fitness
        global_best_position = []
        swarm_particles = []
        
        for _ in range(particle_size):
            swarm_particles.append(Particle(bounds))
        
        for _ in range(iterations):
            for particle in swarm_particles:
                particle.evaluate(objective_function)
                
                if optimization_mode == -1:
                    if particle.fitness < global_best_fitness:
                        global_best_position = list(particle.position)
                        global_best_fitness = particle.fitness
                elif optimization_mode == 1:
                    if particle.fitness > global_best_fitness:
                        global_best_position = list(particle.position)
                        global_best_fitness = particle.fitness
                        
                particle.update_velocity(global_best_position)
                particle.update_position(bounds)
                
        print('RESULT:')
        print('Optimal Solution:', global_best_position)
        print('Objective function value:', global_best_fitness)
        
if optimization_mode == -1:
    initial_fitness = float('inf')
elif optimization_mode == 1:
    initial_fitness = -float('inf')
    
PSO(objective_function, bounds, particle_size, iterations)
