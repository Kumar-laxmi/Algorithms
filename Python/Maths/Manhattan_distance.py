"""
The Manhattan distance algorithm, also known as the L1 distance or taxicab distance, is a measure of the distance between two points in a grid-like structure. It is named after the distance a taxicab would travel in a city where movement is restricted to horizontal and vertical paths.
The Manhattan distance between two points (x1, y1) and (x2, y2) is calculated as the sum of the absolute differences between their x-coordinates and y-coordinates:
Manhattan distance = |x1 - x2| + |y1 - y2|
"""


def manhattan_distance(x1, y1, x2, y2):
    # Calculate the absolute difference between the x-coordinates and add it to the absolute difference between the y-coordinates
    distance = abs(x1 - x2) + abs(y1 - y2)
    return distance

# Get user input for the coordinates of the first point
x1 = int(input("Enter the x-coordinate of the first point: "))
y1 = int(input("Enter the y-coordinate of the first point: "))

# Get user input for the coordinates of the second point
x2 = int(input("Enter the x-coordinate of the second point: "))
y2 = int(input("Enter the y-coordinate of the second point: "))

# Calculate the Manhattan distance 
distance = manhattan_distance(x1, y1, x2, y2)

# Print the calculated distance
print("The Manhattan distance between the points ({}, {}) and ({}, {}) is {}".format(x1, y1, x2, y2, distance))