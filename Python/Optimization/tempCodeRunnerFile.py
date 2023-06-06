
    def __init__(self, bounds):
        self.position = []  # particle position
        self.velocity = []  # particle velocity
        self.local_best_position = []  # best position of the particle
        self.local_best_fitness = initial_fitness
        self.fitness = initial_fitness