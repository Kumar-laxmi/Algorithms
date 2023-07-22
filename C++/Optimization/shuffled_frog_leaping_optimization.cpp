#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

double objectiveFunction(double value) {
    double output = pow(value, 2) - 3 * value + 9;
    return std::abs(output - 6.75);
}

std::vector<double> generateFrogs(int frogCount, double sigma, double mu) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distribution(mu, sigma);

    std::vector<double> frogs(frogCount);
    for (int i = 0; i < frogCount; ++i) {
        frogs[i] = distribution(gen);
    }

    return frogs;
}

std::vector<std::vector<int>> sortFrogs(const std::vector<double>& frogs, int memeplexCount) {
    int frogCount = frogs.size();
    std::vector<int> sortedIndices(frogCount);
    std::iota(sortedIndices.begin(), sortedIndices.end(), 0);

    std::sort(sortedIndices.begin(), sortedIndices.end(), [&](int a, int b) {
        return objectiveFunction(frogs[a]) < objectiveFunction(frogs[b]);
    });

    std::vector<std::vector<int>> memeplexes(memeplexCount, std::vector<int>(frogCount / memeplexCount));
    for (int j = 0; j < frogCount / memeplexCount; ++j) {
        for (int i = 0; i < memeplexCount; ++i) {
            if (j % 2 == 0) {
                memeplexes[i][j] = sortedIndices[i + (memeplexCount * j)];
            } else {
                memeplexes[memeplexCount - 1 - i][j] = sortedIndices[i + (memeplexCount * j)];
            }
        }
    }

    return memeplexes;
}

std::vector<double> performLocalSearch(std::vector<double>& frogs, const std::vector<int>& memeplex, double sigma, double mu) {
    int frogCount = frogs.size();
    int worstFrogIndex = memeplex[memeplex.size() - 1];
    int bestFrogIndex = memeplex[0];
    int greatestFrogIndex = memeplex[0];

    double frogWorst = frogs[worstFrogIndex];
    double frogBest = frogs[bestFrogIndex];
    double frogGreatest = frogs[greatestFrogIndex];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(0, 1);

    double frogWorstNew = frogWorst + (distribution(gen) * (frogBest - frogWorst));

    if (objectiveFunction(frogWorstNew) > objectiveFunction(frogWorst)) {
        frogWorstNew = frogWorst + (distribution(gen) * (frogGreatest - frogWorst));
    }

    if (objectiveFunction(frogWorstNew) > objectiveFunction(frogWorst)) {
        std::vector<double> newFrog = generateFrogs(1, sigma, mu);
        frogs[worstFrogIndex] = newFrog[0];
    } else {
        frogs[worstFrogIndex] = frogWorstNew;
    }

    return frogs;
}

std::vector<std::vector<int>> shuffleMemeplexes(const std::vector<std::vector<int>>& memeplexes) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<int> temp;
    for (const auto& memeplex : memeplexes) {
        temp.insert(temp.end(), memeplex.begin(), memeplex.end());
    }

    std::shuffle(temp.begin(), temp.end(), gen);

    std::vector<std::vector<int>> shuffledMemeplexes(memeplexes.size(), std::vector<int>(memeplexes[0].size()));
    int index = 0;
    for (auto& memeplex : shuffledMemeplexes) {
        std::copy(temp.begin() + index, temp.begin() + index + memeplex.size(), memeplex.begin());
        index += memeplex.size();
    }

    return shuffledMemeplexes;
}

std::vector<double> shuffledFrogLeapingAlgorithm(int frogCount, int dimension, double sigma, double mu, int memeplexCount, int memeplexIterations, int solutionIterations) {
    std::vector<double> frogs = generateFrogs(frogCount, sigma, mu);
    std::vector<std::vector<int>> memeplexes = sortFrogs(frogs, memeplexCount);
    std::vector<double> bestSolution = { frogs[memeplexes[0][0]] };

    for (int i = 0; i < solutionIterations; ++i) {
        memeplexes = shuffleMemeplexes(memeplexes);

        for (const auto& memeplex : memeplexes) {
            for (int j = 0; j < memeplexIterations; ++j) {
                frogs = performLocalSearch(frogs, memeplex, sigma, mu);
            }

            memeplexes = sortFrogs(frogs, memeplexCount);
            double newBestSolution = frogs[memeplexes[0][0]];

            if (objectiveFunction(newBestSolution) < objectiveFunction(bestSolution[0])) {
                bestSolution[0] = newBestSolution;
            }
        }
    }

    return bestSolution;
}

int main() {
    int frogCount = 100;
    int dimension = 1;
    double sigma = 1.0;
    double mu = 1.5;
    int memeplexCount = 5;
    int memeplexIterations = 1;
    int solutionIterations = 50;

    std::vector<double> bestSolution = shuffledFrogLeapingAlgorithm(frogCount, dimension, sigma, mu, memeplexCount, memeplexIterations, solutionIterations);
    std::cout << "Optimal Solution (closest to 6.75): " << bestSolution[0] << std::endl;
    std::cout << "Function value for optimal solution: " << pow(bestSolution[0], 2) - 3 * bestSolution[0] + 9 << std::endl;

    return 0;
}
