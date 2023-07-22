#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> generate_adjacent_route(const vector<int>& route, mt19937& rnd) {
    int n = route.size();
    vector<int> result = route;
    int i = rnd() % n;
    int j = rnd() % n;
    swap(result[i], result[j]);
    return result;
}

double calculate_total_dist(const vector<int>& route) {
    double d = 0.0;
    int n = route.size();
    for (int i = 0; i < n - 1; i++) {
        if (route[i] < route[i + 1]) {
            d += (route[i + 1] - route[i]) * 1.0;
        } else {
            d += (route[i] - route[i + 1]) * 1.5;
        }
    }
    return d;
}

double calculate_error(const vector<int>& route) {
    int n = route.size();
    double d = calculate_total_dist(route);
    double min_dist = n - 1;
    return d - min_dist;
}

vector<int> solve_tsp(int n_cities, mt19937& rnd, int max_iter, double start_temperature, double alpha) {
    double curr_temperature = start_temperature;
    vector<int> solution(n_cities);
    iota(solution.begin(), solution.end(), 0);
    shuffle(solution.begin(), solution.end(), rnd);
    double err = calculate_error(solution);
    int iteration = 0;
    int interval = max_iter / 10;
    double accept_p = 0.0;

    while (iteration < max_iter && err > 0.0) {
        vector<int> adj_route = generate_adjacent_route(solution, rnd);
        double adj_err = calculate_error(adj_route);

        if (adj_err < err) {
            solution = adj_route;
            err = adj_err;
        } else {
            accept_p = exp((err - adj_err) / curr_temperature);
            double p = generate_canonical<double, numeric_limits<double>::digits>(rnd);
            if (p < accept_p) {
                solution = adj_route;
                err = adj_err;
            }
        }

        if (iteration % interval == 0) {
            cout << "Iteration: " << setw(6) << left << iteration
                << " | Current error: " << setw(7) << left << err
                << " | Temperature: " << setw(10) << left << curr_temperature << endl;
        }

        if (curr_temperature < 0.00001) {
            curr_temperature = 0.00001;
        } else {
            curr_temperature *= alpha;
        }
        iteration++;
    }

    return solution;
}

int main() {
    cout << "The problem involved is Travelling Salesman Problem" << endl;
    cout << "\nBeginning The Simulated Annealing Optimization process" << endl;
    int num_cities = 20;
    cout << "\nSetting number of states(cities) = " << num_cities << endl;
    cout << "\nOptimal solution is 0, 1, 2, ..., " << (num_cities - 1) << endl;
    cout << "Optimal solution has total distance = " << (num_cities - 1) << endl;
    mt19937 rnd(4);
    int max_iter = 2500;
    double start_temperature = 10000.0;
    double alpha = 0.99;

    cout << "\nSettings:" << endl;
    cout << "max_iter = " << max_iter << endl;
    cout << "start_temperature = " << start_temperature << endl;
    cout << "alpha = " << alpha << endl;

    vector<int> best_solution = solve_tsp(num_cities, rnd, max_iter, start_temperature, alpha);

    cout << "\nBest solution found:" << endl;
    for (int city : best_solution) {
        cout << city << " ";
    }
    double dist = calculate_total_dist(best_solution);
    cout << "\nTotal distance: " << dist << endl;

    cout << "\nEnd" << endl;

    return 0;
}
