import math

def euclidean_distance(x1, x2):
    # Calculate the Euclidean distance between two points
    distance = 0
    for i in range(len(x1)):
        distance += pow((x1[i] - x2[i]), 2)
        return math.sqrt(distance)

def get_neighbors(train_set, test_instance, k):
    distances = []
    for train_instance in train_set:
        dist = euclidean_distance(test_instance, train_instance[:-1])
        distances.append((train_instance, dist))
    distances.sort(key=lambda x: x[1])  # Sort distances in ascending order
    neighbors = [dist[0] for dist in distances[:k]]  # Get the k nearest neighbors
    return neighbors

def predict_classification(neighbors):
    # Count the occurrences of each class label
    class_counts = {}
    for neighbor in neighbors:
        label = neighbor[-1]
        if label in class_counts:
            class_counts[label] += 1
        else:
            class_counts[label] = 1
    # Return the class label with the highest count
    return max(class_counts, key=class_counts.get)

# Example usage
train_set = [[2.0, 1.8, 'A'], [1.0, 2.0, 'A'], [4.0, 2.5, 'B'], [3.5, 2.8, 'B']]
test_instance = [2.5, 2.0]
k = 3

neighbors = get_neighbors(train_set, test_instance, k)
predicted_class = predict_classification(neighbors)

print("Predicted Class:", predicted_class)
