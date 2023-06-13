import numpy as np

class SVM:
    def __init__(self, learning_rate=0.01, num_iterations=1000, C=1.0):
        self.learning_rate = learning_rate
        self.num_iterations = num_iterations
        self.C = C
        self.W = None
        self.b = None

    def fit(self, X, y):
        n_samples, n_features = X.shape

        # Initialize parameters
        self.W = np.zeros(n_features)
        self.b = 0

        # Gradient descent
        for _ in range(self.num_iterations):
            for i in range(n_samples):
                if y[i] * (np.dot(X[i], self.W) - self.b) >= 1:
                    self.W -= self.learning_rate * (2 * self.C * self.W)
                else:
                    self.W -= self.learning_rate * (2 * self.C * self.W - np.dot(X[i], y[i]))
                    self.b -= self.learning_rate * y[i]

    def predict(self, X):
        return np.sign(np.dot(X, self.W) - self.b)

# Generate a larger dataset
np.random.seed(42)
X = np.random.randn(1000, 10)
y = np.where(np.sum(X, axis=1) > 0, 1, -1)

# Split the dataset into training and testing sets
split_ratio = 0.8
split_index = int(split_ratio * len(X))

X_train, y_train = X[:split_index], y[:split_index]
X_test, y_test = X[split_index:], y[split_index:]

# Train the SVM model
svm = SVM()
svm.fit(X_train, y_train)

# Make predictions on the testing set
predictions = svm.predict(X_test)
print(predictions)
