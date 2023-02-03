from collections import defaultdict, Counter

import numpy as np


class KNN:
    '''Implementation from scratch of the KNN algorithm
        The following metrics will be implemented : 
            - Manhattan
            - Euclidean
            - Chebyshev
    '''

    def __init__(self, n_neighbors=5, metric='euclidean',regression=False):
        self.n_neighbors = n_neighbors
        self.metric = self.set_metric(metric)
        self.regression = regression

    def fit_predict(self, X, y, X_infer):
        '''Compute the distances for each test point and select the K
        closest points in the training set. Then, predict the current 
        observation, based on the given problem.
        
        If regression is False, consider the "majority class", 
        otherwise, take the average. 
        '''

        self.n_neighbors = min(self.n_neighbors, len(X))

        distances = defaultdict(list) # save { test_idx : [(target,distance),...], ...}

        for idx_test, x_test in enumerate(X_infer):
            # iterate on the train data
            for idx_train, x_train in enumerate(X):
                distance = self.compute_distance(x_test,x_train)
                distances[idx_test].append((idx_train,distance))

        # select the K nearest neighbors and predict the value
        predictions = []
        for idx_test, list_distances in distances.items():

            # sort and take the K nearest points
            sorted_k = sorted(list_distances, key = lambda x : x[1])[:self.n_neighbors]
            
            # get only the target
            target_k = [ y[idx] for idx,_ in sorted_k]

            # take the average
            if self.regression:
                predictions.append(np.mean(target_k))
            # take the majority class
            else:
                predictions.append(list(Counter(target_k).keys())[0])

        # return the predictions
        return predictions

    def set_metric(self,metric):
        '''Set the metric used for calculating the distances
        between points
        
        Args:
            metric (str) : distance metric provided by the user
        Returns:
            return the given metric if it has been implemented, otherwise
            raise an Error
        '''    
        if metric in ['euclidean','manhattan','chebyshev']:
            return metric
        else:
            raise ValueError('{} has not been implemented - refer to [euclidean,manhattan,chebyshev]'.format(metric))

    def compute_distance(self, v1,v2):
        '''Compute the distance, according to the selected one'''

        if self.metric == 'euclidean':
            return self.euclidean_distance(v1,v2)
        elif self.metric == 'manhattan':
            return self.manhattan_distance(v1,v2)
        elif self.metric == 'chebyshev':
            return self.chebyshev_distance(v1,v2)

    def manhattan_distance(self, v1, v2):
        '''Compute the Manhattan distance between x1 and x2
                \sum_i | v1_i - v2_i | 
        '''
        v1, v2 = np.array(v1), np.array(v2) # convert to np arrays

        if len(v1) == 0 or len(v2) == 0:
            raise ValueError('The Manhattan distance cannot be computed from None')
        if len(v1) != len(v2):
            raise ValueError('Cannot compare arrays with different lengths ({},{})'.format(len(v1),len(v2)))
        if np.isnan(v1).any() or np.isnan(v2).any():
            raise ValueError('Cannot compare arrays with NaN values ({},{})'.format(np.isnan(v1).any(),np.isnan(v2).any()))
        
        return np.sum(np.abs((v1-v2)))

    def euclidean_distance(self, v1, v2):
        '''Compute the euclidean distance between x1 and x2
                \sqrt { \sum {v1_i - v2_i}^2 }
        '''
        v1, v2 = np.array(v1), np.array(v2) # convert to np arrays

        if len(v1) == 0 or len(v2) == 0:
            raise ValueError('The euclidean distance cannot be computed from None')
        if len(v1) != len(v2):
            raise ValueError('Cannot compare arrays with different lengths ({},{})'.format(len(v1),len(v2)))
        if np.isnan(v1).any() or np.isnan(v2).any():
            raise ValueError('Cannot compare arrays with NaN values ({},{})'.format(np.isnan(v1).any(),np.isnan(v2).any()))
        
        return np.sqrt(np.sum((v1-v2)**2))

    def chebyshev_distance(self, v1, v2):
        '''Compute the Chebyshev distance between x1 and x2
                \max_i |v1_i - v2_i|
        '''
        v1, v2 = np.array(v1), np.array(v2) # convert to np arrays

        if len(v1) == 0 or len(v2) == 0:
            raise ValueError('The Chebyshev distance cannot be computed from None')
        if len(v1) != len(v2):
            raise ValueError('Cannot compare arrays with different lengths ({},{})'.format(len(v1),len(v2)))
        if np.isnan(v1).any() or np.isnan(v2).any():
            raise ValueError('Cannot compare arrays with NaN values ({},{})'.format(np.isnan(v1).any(),np.isnan(v2).any()))
        return np.max(np.abs(v1-v2))
        

if __name__ == '__main__':

    from sklearn.datasets import make_classification
    from sklearn.neighbors import KNeighborsClassifier
    from sklearn.metrics import accuracy_score
    

    X, y = make_classification(
        n_samples=1000, 
        n_features=10, 
        n_informative = 7,
        n_classes = 2, 
        random_state=42 
    )


    X_train, y_train = X[:700], y[:700]
    X_test, y_test = X[700:], y[700:]

    knn = KNN(n_neighbors=5, metric='euclidean')
    y_pred = knn.fit_predict(X_train,y_train,X_test)
    print(f'Accuracy (M) = {accuracy_score(y_test,y_pred):.2f}')

    scikit_knn = KNeighborsClassifier(n_neighbors=5, algorithm='brute', p=2)
    scikit_knn.fit(X_train,y_train)
    scikit_pred = scikit_knn.predict(X_test)
    print(f'Accuracy (S) = {accuracy_score(y_test,scikit_pred):.2f}')

    '''
    Accuracy (M) = 0.90 # my implementation
    Accuracy (S) = 0.90 # ScikitLearn's implementation
    '''
