#Shuffled Frog Leaping Optimization Code
import numpy as np


def objective_function(value):
    output = value ** 2 - 3 * value + 9
    return abs(output - 6.75)


def generate_population(population_size, dimension, sigma, mu):
    population = sigma * (np.random.randn(population_size, dimension)) + mu
    return population


def sort_population(population, memeplex_count, objective_function):
    fitness = np.array(list(map(objective_function, population)))
    sorted_fitness = np.argsort(fitness)
    memeplexes = np.zeros((memeplex_count, int(population.shape[0] / memeplex_count)))

    for j in range(memeplexes.shape[1]):
        for i in range(memeplex_count):
            if j % 2 == 0:
                memeplexes[i, j] = sorted_fitness[i + (memeplex_count * j)]
            else:
                memeplexes[-(i + 1), j] = sorted_fitness[i + (memeplex_count * j)]
    return memeplexes


def perform_local_search(population, memeplex, objective_function, sigma, mu):
    frog_worst = population[int(memeplex[-1])]
    frog_best = population[int(memeplex[0])]
    frog_greatest = population[0]

    frog_worst_new = frog_worst + (np.random.rand() * (frog_best - frog_worst))

    if objective_function(frog_worst_new) > objective_function(frog_worst):
        frog_worst_new = frog_worst + (np.random.rand() * (frog_greatest - frog_worst))

    if objective_function(frog_worst_new) > objective_function(frog_worst):
        frog_worst_new = generate_population(1, population.shape[1], sigma, mu)[0]

    population[int(memeplex[-1])] = frog_worst_new
    return population


def shuffle_memeplexes(memeplexes):
    temp = memeplexes.flatten()
    np.random.shuffle(temp)
    temp = temp.reshape((memeplexes.shape[0], memeplexes.shape[1]))
    return temp


def shuffled_frog_leaping_algorithm(objective_function, population_size=50, dimension=1, sigma=1, mu=0, memeplex_count=25,
                                    memeplex_iterations=1, solution_iterations=5):
    population = generate_population(population_size, dimension, sigma, mu)
    memeplexes = sort_population(population, memeplex_count, objective_function)
    best_solution = population[int(memeplexes[0, 0])]

    for i in range(solution_iterations):
        memeplexes = shuffle_memeplexes(memeplexes)

        for mplx_idx, memeplex in enumerate(memeplexes):
            for j in range(memeplex_iterations):
                population = perform_local_search(population, memeplex, objective_function, sigma, mu)

            memeplexes = sort_population(population, memeplex_count, objective_function)
            new_best_solution = population[int(memeplexes[0, 0])]

            if objective_function(new_best_solution) < objective_function(best_solution):
                best_solution = new_best_solution

    return best_solution, population, memeplexes.astype(int)


def main():
    optimal_solution, population, memeplexes = shuffled_frog_leaping_algorithm(
        objective_function, 100, 1, 1, 1.5, 5, 1, 50)
    print("Minimizing the function of x^2 -3*x + 9")
    print("Optimal Solution, which is the decision value: {}".format(optimal_solution))
    print("Optimal Function Value (It should come close to 6.75) for the above function is: {}".format(optimal_solution ** 2 - 3 * optimal_solution + 9))


if __name__ == '__main__':
    main()
