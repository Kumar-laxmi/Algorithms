# Approach---


# 1. Define the target string: Set the desired target string that you want to generate. This will be the string that the algorithm will evolve towards.

# 2. Initialize the population: Create an initial population of individuals, where each individual represents a possible solution (a string) to the problem. The population size is determined by the `POPULATION_SIZE` variable.

# 3. Fitness calculation: Calculate the fitness of each individual in the population. In this case, the fitness is defined as the number of characters in the individual's string that differ from the target string. Lower fitness values indicate a closer match to the target.

# 4. Selection: Select the fittest individuals from the population to be part of the next generation. In this implementation, the algorithm uses elitism, where the top 10% of the fittest individuals automatically proceed to the next generation.

# 5. Reproduction: Generate new offspring for the next generation through the process of mating. The algorithm randomly selects two parents from the fittest individuals and performs crossover and mutation to create a new child individual. Crossover involves combining genetic material from the parents, while mutation introduces random changes to maintain diversity in the population.

# 6. Repeat: Repeat steps 3 to 5 until the target string is generated or a stopping criteria is met. The algorithm continues to generate new generations by selecting the fittest individuals and creating new offspring through mating. The process continues until the target string is found or any other stopping condition is satisfied.

# 7. Termination: Once the algorithm terminates, the fittest individual in the final generation represents the generated string that closely matches the target string.


# Code----

import random

# Number of individuals in each generation
POPULATION_SIZE = 100

# Valid genes
GENES = '''abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP
QRSTUVWXYZ 1234567890, .-;:_!"#%&/()=?@${[]}'''

# Target string to be generated
TARGET = "My name is Diwakar SIngh"

class Individual(object):
    '''
    Class representing an individual in the population
    '''
    def __init__(self, chromosome):
        self.chromosome = chromosome
        self.fitness = self.cal_fitness()

    @classmethod
    def mutated_genes(cls):
        '''
        Create random genes for mutation
        '''
        global GENES
        gene = random.choice(GENES)
        return gene

    @classmethod
    def create_gnome(cls):
        '''
        Create a chromosome or string of genes
        '''
        global TARGET
        gnome_len = len(TARGET)
        return [cls.mutated_genes() for _ in range(gnome_len)]

    def mate(self, par2):
        '''
        Perform mating and produce new offspring
        '''

        # Chromosome for offspring
        child_chromosome = []
        for gp1, gp2 in zip(self.chromosome, par2.chromosome):

            # Random probability
            prob = random.random()

            # If prob is less than 0.45, insert gene
            # from parent 1
            if prob < 0.45:
                child_chromosome.append(gp1)

            # If prob is between 0.45 and 0.90, insert
            # gene from parent 2
            elif prob < 0.90:
                child_chromosome.append(gp2)

            # Otherwise, insert random gene (mutate)
            # for maintaining diversity
            else:
                child_chromosome.append(self.mutated_genes())

        # Create new Individual (offspring) using
        # generated chromosome for offspring
        return Individual(child_chromosome)

    def cal_fitness(self):
        '''
        Calculate fitness score, which is the number of
        characters in the string that differ from the target
        string.
        '''
        global TARGET
        fitness = sum(1 for gs, gt in zip(self.chromosome, TARGET) if gs != gt)
        return fitness

def main():
    global POPULATION_SIZE

    # Current generation
    generation = 1

    found = False
    population = []

    # Create initial population
    for _ in range(POPULATION_SIZE):
        gnome = Individual.create_gnome()
        population.append(Individual(gnome))

    while not found:
        # Sort the population in increasing order of fitness score
        population = sorted(population, key=lambda x: x.fitness)

        # If the individual with the lowest fitness score (0),
        # we have reached the target and break the loop
        if population[0].fitness <= 0:
            found = True
            break

        # Otherwise, generate new offspring for the new generation
        new_generation = []

        # Perform Elitism, where 10% of the fittest population
        # goes to the next generation
        s = int((10 * POPULATION_SIZE) / 100)
        new_generation.extend(population[:s])

        # From 50% of the fittest population, individuals
        # will mate to produce offspring
        s = int((90 * POPULATION_SIZE) / 100)
        for _ in range(s):
            parent1 = random.choice(population[:50])
            parent2 = random.choice(population[:50])
            child = parent1.mate(parent2)
            new_generation.append(child)

        population = new_generation

        print("Generation: {}\tString: {}\tFitness: {}".format(
            generation,
            "".join(population[0].chromosome),
            population[0].fitness))

        generation += 1

    print("Generation: {}\tString: {}\tFitness: {}".format(
        generation,
        "".join(population[0].chromosome),
        population[0].fitness))

if __name__ == '__main__':
    main()
