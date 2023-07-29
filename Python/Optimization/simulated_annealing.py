import numpy as np

def generate_adjacent_route(route, rnd):
  n = len(route)
  result = np.copy(route)
  i = rnd.randint(n)
  j = rnd.randint(n)
  tmp = result[i]
  result[i] = result[j]
  result[j] = tmp
  return result

def calculate_total_dist(route):
  d = 0.0
  n = len(route)
  for i in range(n-1):
    if route[i] < route[i+1]:
      d += (route[i+1] - route[i]) * 1.0
    else:
      d += (route[i] - route[i+1]) * 1.5
  return d
def calculate_error(route):
  n = len(route)
  d = calculate_total_dist(route)
  min_dist = n - 1
  return d - min_dist

def generate_adjacent_route(route, rnd):
  n = len(route)
  result = np.copy(route)
  i = rnd.randint(n)
  j = rnd.randint(n)
  tmp = result[i]
  result[i] = result[j]
  result[j] = tmp
  return result

def solve_tsp(n_cities, rnd, max_iter, start_temperature, alpha):
  curr_temperature = start_temperature
  solution = np.arange(n_cities, dtype=np.int64)
  rnd.shuffle(solution)
  err = calculate_error(solution)
  iteration = 0
  interval = int(max_iter / 10)
  accept_p = 0.0

  while iteration < max_iter and err > 0.0:
    adj_route = generate_adjacent_route(solution, rnd)
    adj_err = calculate_error(adj_route)

    if adj_err < err:
      solution = adj_route
      err = adj_err
    else:
      accept_p = np.exp((err - adj_err) / curr_temperature)
      p = rnd.random()
      if p < accept_p:
        solution = adj_route
        err = adj_err

    if iteration % interval == 0:
      print("Iteration: %6d | Current error: %7.2f | Temperature: %10.4f" % (iteration, err, curr_temperature))

    if curr_temperature < 0.00001:
      curr_temperature = 0.00001
    else:
      curr_temperature *= alpha
    iteration += 1

  return solution

def main():
  print('The problem involved is Travelling Salesman Problem')
  print("\nBeginning The Simulated Annealing Optimization process")
  num_cities = 20
  print("\nSetting number of states(cities) = %d" % num_cities)
  print("\nOptimal solution is 0, 1, 2, ..., %d" % (num_cities-1))
  print("Optimal solution has total distance = %0.1f" % (num_cities-1))
  rnd = np.random.RandomState(4)
  max_iter = 2500
  start_temperature = 10000.0
  alpha = 0.99

  print("\nSettings:")
  print("max_iter = %d" % max_iter)
  print("start_temperature = %0.1f" % start_temperature)
  print("alpha = %0.2f" % alpha)

  best_solution = solve_tsp(num_cities, rnd, max_iter, start_temperature, alpha)
  

  print("\nBest solution found:")
  print(best_solution)
  dist = calculate_total_dist(best_solution)
  print("\nTotal distance: %0.1f" % dist)

  print("\nEnd ")

if __name__ == "__main__":
  main()
