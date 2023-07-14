#include <bits/stdc++.h>
using namespace std;
double generate_neighbor_solution(double solution, const vector<double>& population);
double objective_function(double x) {
    return x * x;
     //represents sum of squares eg- x^2+y^2+..
}
double LB = -100;
double UB = 100;
double artificial_bee_colony(int n_iterations, int NEB, int n_onlooker_bees, int n_trials) {
 vector<double> population(NEB);
 vector<double> fitness(NEB);
 random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(LB, UB);

    for (int i = 0; i < NEB; i++) {
        population[i] = dist(gen);
    }


    double best_solution = population[0];


    for (int iteration = 0; iteration < n_iterations; iteration++) {

        for (int i = 0; i < NEB; i++) {
            double solution = population[i];
            double new_solution = generate_neighbor_solution(solution, population, gen);
            if (objective_function(new_solution) < objective_function(solution)) {
                population[i] = new_solution;
            }
        }

    
        double tf = 0.0;
        for (int i = 0; i < NEB; i++) {
            fitness[i] = 1.0 / (objective_function(population[i]) + 0.01);
            tf += fitness[i];
        }


        vector<double> pr(NEB);
        for (int i = 0; i < NEB; i++) {
            pr[i] = fitness[i] / tf;
        }

        for (int i = 0; i < n_onlooker_bees; i++) {
        
            std::discrete_distribution<int> dist(pr.begin(), pr.end());
            int selected_index = dist(gen);
            double selected_solution = population[selected_index];

            // Generate a neighbor solution
            double new_solution = generate_neighbor_solution(selected_solution, population, gen);
            if (objective_function(new_solution) < objective_function(selected_solution)) {
                population[selected_index] = new_solution;
            }
        }

    
        double BD = fitness[0];
        for (int i = 1; i < NEB; i++) {
            if (objective_function(population[i]) < objective_function(best_solution)) {
                best_solution = population[i];
                BD = fitness[i];
            }
        }
        for (int i = 0; i < NEB; i++) {
            if (fitness[i] > BD) {
                population[i] = dist(gen);
            }
        }

     cout << "Iteration " << (iteration + 1) << ": Best solution = " << objective_function(best_solution) << endl;
    }

    return best_solution;
}

double generate_neighbor_solution(double solution, const vector<double>& population, mt19937& gen) {
 uniform_int_distribution<int> dist(0, population.size() - 1);
    double neighbor = solution;
    while (neighbor == solution) {
        int index = dist(gen);
        neighbor = population[index];
    }
    return neighbor;
}

int main() {
    double best_solution = artificial_bee_colony(10,2,30,30);
 cout << "Optimal solution found is : " << objective_function(best_solution) << endl;
    return 0;
}