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


# README FILE CONTENT 
# #K-Nearest Neighbors (KNN) Algorithm

# This file contains a Python implementation of the K-Nearest Neighbors (KNN) 
# algorithm without using any machine learning libraries. The KNN algorithm is a simple 
# yet effective supervised learning algorithm used for classification tasks.

# ##Algorithm Description

# As it was told to notuse the ml-libraries , I have made solution without the libraries

# The K-Nearest Neighbors (KNN) algorithm works as follows:


# 1)Euclidean Distance Calculation: The algorithm starts by calculating the Euclidean distance between the test 
# instance and each instance in the training set. The Euclidean distance measures the similarity between two instances.

# 2)Finding the Nearest Neighbors: Based on the calculated distances, the K nearest neighbors are selected. 
# The value of K is a hyperparameter that needs to be predefined.

# 3)Class Label Prediction: For classification tasks, the algorithm predicts the class label of the test
#  instance based on the majority voting of the class labels of its K nearest neighbors. The class with the highest count among the neighbors is chosen as the predicted class label.

# 4)Algorithm Evaluation: To evaluate the performance of the KNN algorithm, various metrics such as accuracy, 
# precision, recall, or F1 score can be used. These metrics compare the predicted class labels with the true 
# class labels of the test instances.

# For a bigger dataset I used Iris dataset to evaluate KNN in python 

# ##This is the dataset explaination :

# # Load your own dataset or use the Iris dataset
# from sklearn.datasets import load_iris
# from sklearn.model_selection import train_test_split
# from sklearn.metrics import accuracy_score

# # Load the dataset (replace with your own dataset loading steps)
# iris = load_iris()
# X = iris.data  # Features
# y = iris.target  # Target variable

# # Split the dataset into training and test sets
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# # Perform KNN classification (replace or modify the KNN algorithm implementation according to your needs)
# k = 3

# # Your KNN algorithm implementation goes here

# # Evaluate the performance of the classifier
# y_pred = []
# # Your prediction and evaluation code goes here

# # Calculate the accuracy of the classifier
# accuracy = accuracy_score(y_test, y_pred)
# print("Accuracy:", accuracy)
