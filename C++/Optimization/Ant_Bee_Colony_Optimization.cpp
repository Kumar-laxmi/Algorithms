#include <bits/stdc++.h>

using namespace std;

const int LB = -100;
const int UB = 100;

double Optimal(const vector<double>& xy) {
    double sum = 0.0;
    for (double val : xy) {
        sum += pow(val, 2);
    }
    return sum;
}

double fetrand(double lb, double ub) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> dis(lb, ub);
    return dis(gen);
}

vector<double> genneighbours(const vector<double>& individual, const vector<vector<double>>& population) {
    vector<double> neighbor = individual;
    while (neighbor == individual) {
        int randIndex = rand() % population.size();
        neighbor = population[randIndex];
    }
    return neighbor;
}

vector<double> ABC(int NI, int NEI, int individuals) {
    vector<vector<double>> population;
    for (int i = 0; i < NEI; ++i) {
        vector<double> individual;
        for (int j = 0; j < individuals; ++j) {
            individual.push_back(fetrand(LB, UB));
        }
        population.push_back(individual);
    }

    for (int iteration = 0; iteration < NI; ++iteration) {
        for (int i = 0; i < NEI; ++i) {
            vector<double> individual = population[i];
            vector<double> newIndividual = genneighbours(individual, population);
            if (Optimal(newIndividual) < Optimal(individual)) {
                population[i] = newIndividual;
            }
        }

        vector<double> fitness;
        for (const vector<double>& individual : population) {
            fitness.push_back(1.0 / (Optimal(individual) + 0.01));
        }
        double totalFitness = 0.0;
        for (double f : fitness) {
            totalFitness += f;
        }

        for (int i = 0; i < individuals; ++i) {
            vector<double> prob;
            for (double f : fitness) {
                prob.push_back(f / totalFitness);
            }
            double randVal = fetrand(0.0, 1.0);
            double probSum = 0.0;
            int SI = 0;
            for (double p : prob) {
                probSum += p;
                if (randVal <= probSum) {
                    break;
                }
                SI++;
            }

            vector<double> selectedIndividual = population[SI];
            vector<double> newIndividual = genneighbours(selectedIndividual, population);
            if (Optimal(newIndividual) < Optimal(selectedIndividual)) {
                population[SI] = newIndividual;
            }
        }

        vector<double> BI = population[0];
        for (const vector<double>& individual : population) {
            if (Optimal(individual) < Optimal(BI)) {
                BI = individual;
            }
        }
        for (int i = 0; i < NEI; ++i) {
            if (Optimal(population[i]) > Optimal(BI)) {
                vector<double> individual;
                for (int j = 0; j < individuals; ++j) {
                    individual.push_back(fetrand(LB, UB));
                }
                population[i] = individual;
            }
        }

        cout << "Iteration " << (iteration + 1) << ": Best solution = " << Optimal(BI) << endl;
    }

    return {};
}

int main() {
    vector<double> irla = ABC(10, 30, 30);
    cout << "Optimal Solution found for the sphere function is: " << Optimal(irla) << endl;

    return 0;
}
