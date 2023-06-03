# Load the Iris dataset
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import math

iris = load_iris()
X = iris.data  # Features
y = iris.target  # Target variable

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Perform KNN classification
k = 3

def euclidean_distance(instance1, instance2):
    distance = 0
    for i in range(len(instance1)):
        distance += pow((instance1[i] - instance2[i]), 2)
    return math.sqrt(distance)

def get_neighbors(train_set, test_instance, k):
    distances = []
    for train_instance, train_label in train_set:
        dist = euclidean_distance(test_instance, train_instance)
        distances.append((train_instance, train_label, dist))
    distances.sort(key=lambda x: x[2])
    neighbors = [dist[:2] for dist in distances[:k]]
    return neighbors

def predict_classification(neighbors):
    class_votes = {}
    for neighbor in neighbors:
        label = neighbor[1]
        if label in class_votes:
            class_votes[label] += 1
        else:
            class_votes[label] = 1
    sorted_votes = sorted(class_votes.items(), key=lambda x: x[1], reverse=True)
    return sorted_votes[0][0]

y_pred = []
for test_instance in X_test:
    neighbors = get_neighbors(list(zip(X_train, y_train)), test_instance, k)
    predicted_class = predict_classification(neighbors)
    y_pred.append(predicted_class)

# Calculate the accuracy of the classifier
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)
