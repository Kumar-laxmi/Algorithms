#K-Nearest Neighbors (KNN) Algorithm

This file contains a Python implementation of the K-Nearest Neighbors (KNN) 
algorithm without using any machine learning libraries. The KNN algorithm is a simple 
yet effective supervised learning algorithm used for classification tasks.

##Algorithm Description

As it was told to notuse the ml-libraries , I have made solution without the libraries

The K-Nearest Neighbors (KNN) algorithm works as follows:


1)Euclidean Distance Calculation: The algorithm starts by calculating the Euclidean distance between the test instance and each instance in the training set. The Euclidean distance measures the similarity between two instances.

2)Finding the Nearest Neighbors: Based on the calculated distances, the K nearest neighbors are selected. The value of K is a hyperparameter that needs to be predefined.

3)Class Label Prediction: For classification tasks, the algorithm predicts the class label of the test instance based on the majority voting of the class labels of its K nearest neighbors. The class with the highest count among the neighbors is chosen as the predicted class label.

4)Algorithm Evaluation: To evaluate the performance of the KNN algorithm, various metrics such as accuracy, precision, recall, or F1 score can be used. These metrics compare the predicted class labels with the true class labels of the test instances.

##Example

train_set = [[2.0, 1.8, 'A'], [1.0, 2.0, 'A'], [4.0, 2.5, 'B'], [3.5, 2.8, 'B']]
test_instance = [2.5, 2.0]
k = 3

neighbors = get_neighbors(train_set, test_instance, k)
predicted_class = predict_classification(neighbors)

print("Predicted Class:", predicted_class)

In this example, the train_set contains the training instances, each with its features and corresponding class label. The test_instance represents the instance for which we want to make a prediction. The value of k determines the number of nearest neighbors to consider.
The script will calculate the Euclidean distance between instances, find the nearest neighbors, and predict the class label of the test instance based on majority voting. The predicted class label will be printed as the output.