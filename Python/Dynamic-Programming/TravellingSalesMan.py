import itertools

def calculate_distance(city1, city2):
    # Calculate the Euclidean distance between two cities
    return ((city1[0] - city2[0])**2 + (city1[1] - city2[1])**2) ** 0.5

def calculate_total_distance(path, cities):
    # Calculate the total distance for a given path
    total_distance = 0
    for i in range(len(path)-1):
        city1 = cities[path[i]]
        city2 = cities[path[i+1]]
        total_distance += calculate_distance(city1, city2)
    return total_distance

def find_minimum_distance(cities):
    # Generate all possible permutations of cities
    all_paths = list(itertools.permutations(range(len(cities))))

    # Initialize variables to track the minimum distance and path
    min_distance = float('inf')
    min_path = []

    # Iterate through all paths and find the minimum distance
    for path in all_paths:
        distance = calculate_total_distance(path, cities)
        if distance < min_distance:
            min_distance = distance
            min_path = path

    return min_path, min_distance

def main():
    # Get the total number of cities from the user
    num_cities = int(input("Enter the total number of cities: "))

    # Initialize an empty list to store the cities' coordinates
    cities = []

    # Get the coordinates of each city from the user
    for i in range(num_cities):
        x = float(input(f"Enter the x-coordinate of city {i+1}: "))
        y = float(input(f"Enter the y-coordinate of city {i+1}: "))
        cities.append((x, y))

    # Find the minimum distance and path
    min_path, min_distance = find_minimum_distance(cities)

    # Print the minimum distance and path
    print("The minimum distance is:", min_distance)
    print("The optimal path is:", min_path)

if __name__ == "__main__":
    main()


