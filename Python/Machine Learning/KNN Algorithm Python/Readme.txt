#K-Nearest Neighbors (KNN) Algorithm

This file contains a Python implementation of the K-Nearest Neighbors (KNN) 
algorithm without using any machine learning libraries. The KNN algorithm is a simple 
yet effective supervised learning algorithm used for classification tasks.

##Algorithm Description

As it was told to notuse the ml-libraries , I have made solution without the libraries

The K-Nearest Neighbors (KNN) algorithm works as follows:


1)Euclidean Distance Calculation: The algorithm starts by calculating the Euclidean distance between the test 
instance and each instance in the training set. The Euclidean distance measures the similarity between two instances.

2)Finding the Nearest Neighbors: Based on the calculated distances, the K nearest neighbors are selected. 
The value of K is a hyperparameter that needs to be predefined.

3)Class Label Prediction: For classification tasks, the algorithm predicts the class label of the test
 instance based on the majority voting of the class labels of its K nearest neighbors. The class with the highest count among the neighbors is chosen as the predicted class label.

4)Algorithm Evaluation: To evaluate the performance of the KNN algorithm, various metrics such as accuracy, 
precision, recall, or F1 score can be used. These metrics compare the predicted class labels with the true 
class labels of the test instances.

For a bigger dataset I used Iris dataset to evaluate KNN in python 

##This is the dataset explaination :

# Load your own dataset or use the Iris dataset
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Load the dataset (replace with your own dataset loading steps)
iris = load_iris()
X = iris.data  # Features
y = iris.target  # Target variable

# Split the dataset into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Perform KNN classification (replace or modify the KNN algorithm implementation according to your needs)
k = 3

# Your KNN algorithm implementation goes here

# Evaluate the performance of the classifier
y_pred = []
# Your prediction and evaluation code goes here

# Calculate the accuracy of the classifier
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)
