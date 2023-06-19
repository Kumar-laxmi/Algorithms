'''
Implementation of a Adaboost algorithm.
Author - Abhishek Pote
Requirements:
    - Numpy
Python:
    - 3.8.10
'''
import numpy as np
from sklearn.metrics import confusion_matrix,accuracy_score
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split

class AdaBoostClassifier:
    def __init__(self, num_classifiers):
        self.num_classifiers = num_classifiers
        self.classifiers = []
        self.alphas = []
        self.classes = []
    
    def fit(self, X, y):
        n_samples = X.shape[0]
        n_features = X.shape[1]
        
        self.classes = np.unique(y)
        n_classes = len(self.classes)
        
        # Initialize weights uniformly
        weights = np.ones(n_samples) / n_samples
        
        for _ in range(self.num_classifiers):
            classifier = {}  # Weak classifier dictionary
            
            # Find best weak classifier based on weighted error
            best_error = float('inf')
            
            for feature in range(n_features):
                for threshold in np.unique(X[:, feature]):
                    prediction = np.ones(n_samples)
                    prediction[X[:, feature] < threshold] = -1
                    
                    # Calculate weighted error
                    weighted_error = np.sum(weights[y != prediction])
                    
                    if weighted_error < best_error:
                        best_error = weighted_error
                        classifier['feature'] = feature
                        classifier['threshold'] = threshold
                        classifier['prediction'] = prediction.copy()
            
            # Calculate classifier weight (alpha)
            classifier['alpha'] = 0.5 * np.log((1.0 - best_error) / (best_error + 1e-10))
            
            # Update weights
            predictions = classifier['prediction']
            is_correct = (predictions == y)
            weights *= np.exp(-classifier['alpha'] * y * predictions)
            weights /= np.sum(weights)
            
            # Save classifier and alpha
            self.classifiers.append(classifier)
            self.alphas.append(classifier['alpha'])
    
    def predict(self, X):
        n_samples = X.shape[0]
        n_classes = len(self.classes)
        scores = np.zeros((n_samples, n_classes))
        
        for classifier, alpha in zip(self.classifiers, self.alphas):
            feature = classifier['feature']
            threshold = classifier['threshold']
            prediction = np.ones(n_samples)
            prediction[X[:, feature] < threshold] = -1
            
            for i, cls in enumerate(self.classes):
                scores[:, i] += alpha * (prediction == cls)
        
        return self.classes[np.argmax(scores, axis=1)]

# Example usage:
# X = np.array([[1, 2], [2, 1], [3, 4], [4, 3], [1, 3], [4, 2]])
# y = np.array([0, 0, 1, 2, 1, 2])

# adaboost = AdaBoostClassifier(num_classifiers=3)
# adaboost.fit(X, y)

# X_test = np.array([[1, 1], [3, 3]])
# y_pred = adaboost.predict(X_test)

# print("Predictions:", y_pred)
if __name__ == '__main__':
    #data_path = "Python/Machine Learning/XGBoost/Data.csv"
    #X, y= prepare_data(data_path)
    dataset = load_breast_cancer()
    X = dataset.data
    y = dataset.target

# Split data into training and testing sets
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Create an instance of XGBoostClassifier or XGBoostRegressor and fit the model
    model = AdaBoostClassifier(num_classifiers=3)  # or XGBoostRegressor()
    model.fit(X_train, y_train)

# Make predictions using the trained model
    y_pred = model.predict(X_test)
    cm = confusion_matrix(y_test, y_pred)
    print(cm)
    print(accuracy_score(y_test,y_pred))