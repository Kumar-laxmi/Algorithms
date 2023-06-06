// Approach-
  
//   Here's a step-by-step explanation of how the algorithm works:

// 1.Initialize the population: The initial population is created with a fixed number of individuals (POPULATION_SIZE). Each individual is represented by a chromosome, which is a randomly generated string of characters from the valid genes (GENES).

// 2.Evaluate fitness: Calculate the fitness of each individual in the population. The fitness is determined by counting the number of characters in the chromosome that differ from the corresponding characters in the target string.

// 3.Selection: Sort the population based on the fitness scores in ascending order. The fittest individuals (lowest fitness scores) are selected to proceed to the next generation. This process is known as elitism, where the top 10% of the population is preserved.

//4. Crossover and mutation: From the remaining individuals, perform the mating process to produce offspring for the new generation. Two parents are randomly selected and a crossover point is chosen. The offspring inherits a portion of genes from each parent, mimicking biological reproduction. Additionally, there is a chance for random mutations, where some genes in the offspring's chromosome are randomly altered to maintain diversity.

//5. Repeat steps 2-4: Continue evaluating fitness, selecting fittest individuals, and generating new offspring until a suitable individual with a fitness score of 0 (an exact match to the target string) is found.

//6. Termination: Once an individual with a fitness score of 0 is found, the algorithm terminates, and the target string has been successfully generated.

// The algorithm uses natural selection and genetic operations (crossover and mutation) to iteratively improve the population and converge towards the target string.



#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Number of individuals in each generation
#define POPULATION_SIZE 100

// Valid Genes
const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"
                     "QRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

// Target string to be generated
const string TARGET = "My name is Diwakar Singh";

// Function to generate random numbers in given range
int random_num(default_random_engine& rng, int start, int end)
{
    uniform_int_distribution<int> distribution(start, end);
    return distribution(rng);
}

// Create random genes for mutation
char mutated_genes(default_random_engine& rng)
{
    int len = GENES.size();
    int r = random_num(rng, 0, len - 1);
    return GENES[r];
}

// create chromosome or string of genes
string create_gnome(default_random_engine& rng)
{
    int len = TARGET.size();
    string gnome = "";
    for (int i = 0; i < len; i++)
        gnome += mutated_genes(rng);
    return gnome;
}

// Class representing individual in population
class Individual
{
public:
    string chromosome;
    int fitness;

    Individual(string chromosome);
    Individual mate(Individual parent2, default_random_engine& rng);
    int cal_fitness();
};

Individual::Individual(string chromosome)
{
    this->chromosome = chromosome;
    fitness = cal_fitness();
}

Individual Individual::mate(Individual par2, default_random_engine& rng)
{
    string child_chromosome = "";

    int len = chromosome.size();
    for (int i = 0; i < len; i++)
    {
        float p = static_cast<float>(random_num(rng, 0, 100)) / 100;

        if (p < 0.45)
            child_chromosome += chromosome[i];
        else if (p < 0.90)
            child_chromosome += par2.chromosome[i];
        else
            child_chromosome += mutated_genes(rng);
    }

    return Individual(child_chromosome);
}

int Individual::cal_fitness()
{
    int len = TARGET.size();
    int fitness = 0;
    for (int i = 0; i < len; i++)
    {
        if (chromosome[i] != TARGET[i])
            fitness++;
    }
    return fitness;
}

bool operator<(const Individual& ind1, const Individual& ind2)
{
    return ind1.fitness < ind2.fitness;
}

int main()
{
    random_device rd;
    default_random_engine rng(rd());
    int generation = 0;
    vector<Individual> population;
    bool found = false;

    // create initial population
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        string gnome = create_gnome(rng);
        population.push_back(Individual(gnome));
    }

    while (!found)
    {
        sort(population.begin(), population.end());

        if (population[0].fitness <= 0)
        {
            found = true;
            break;
        }

        vector<Individual> new_generation;

        int s = (10 * POPULATION_SIZE) / 100;
        for (int i = 0; i < s; i++)
            new_generation.push_back(population[i]);

        s = (90 * POPULATION_SIZE) / 100;
        for (int i = 0; i < s; i++)
        {
            int len = population.size();
            int r = random_num(rng, 0, 50);
            Individual parent1 = population[r];
            r = random_num(rng, 0, 50);
            Individual parent2 = population[r];
            Individual offspring = parent1.mate(parent2, rng);
            new_generation.push_back(offspring);
        }

        population = new_generation;

        cout << "Generation: " << generation << "\t";
        cout << "String: " << population[0].chromosome << "\t";
        cout << "Fitness: " << population[0].fitness << "\n";

        generation++;
    }

    cout << "Generation: " << generation << "\t";
    cout << "String: " << population[0].chromosome << "\t";
    cout << "Fitness: " << population[0].fitness << "\n";

    return 0;
}



