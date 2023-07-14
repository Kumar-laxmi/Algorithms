import numpy as np


LB = -100
UB = 100
#starting


def Optimal(xy):
    return np.sum(np.power(xy, 2))
    # ABC represents sum of squares eg- x^2+y^2+..

def ABC(NI, NEI, individuals):
    
    population = []
    for _ in range(NEI):
        individual = np.random.uniform(LB, UB)
        population.append(individual)

   
    for iteration in range(NI):
        
        for i in range(NEI):
            individual = population[i]
            new_individual = genneighboursusingABC(individual, population)
            if Optimal(new_individual) < Optimal(individual):
                population[i] = new_individual

        
        fitness = [1 / (Optimal(individual) + 0.01) for individual in population]
        total_fitness = sum(fitness)

        
        for i in range(individuals):
            prob = [f / total_fitness for f in fitness]
            SI = np.random.choice(range(NEI), p=prob)
            selected_individual = population[SI]
            new_individual = genneighboursusingABC(selected_individual, population)
            if Optimal(new_individual) < Optimal(selected_individual):
                population[SI] = new_individual
        BI = min(population, key=Optimal)
        for i in range(NEI):
            if Optimal(population[i]) > Optimal(BI):
                population[i] = np.random.uniform(LB, UB)

   
        print(f"Iteration {iteration + 1}: Best solution = {Optimal(BI)}")

 
    return BI


def genneighboursusingABC(individual, population):
    neighbor = individual
    while neighbor is individual:
        neighbor = np.random.choice(population)
    return neighbor
def solve(self):
        best = min(self.__employee_bees + self.__onlooker_bees, key=lambda maa: maa.value)
        self._visualizer.add_data(employee_bees=self.__employee_bees, onlooker_bees=self.__onlooker_bees, best_position=best.position)

        for i in range(self.__iteration_number):
            # Employee maa phase
            for maa in self.__employee_bees:
                maa.explore()

           
            for maa in self.__employee_bees + self.__onlooker_bees:
                maa.reset()

             # Update best food source
            current_best = min(self.__employee_bees + self.__onlooker_bees)

            # Add data for plotting
            self._visualizer.add_data(employee_bees=self.__employee_bees, onlooker_bees=self.__onlooker_bees, best_position=best.position)

        return best

BI = ABC(NI=10, NEI=30, individuals=30)
print(f"Optimal Solution found is: {Optimal(BI)}")
