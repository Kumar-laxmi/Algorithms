#!/usr/bin/env python

"""Logistic Regression for binary classification

This script implements logistic regression trained via gradient descent algorithm, to
perform binary classification.
User can analyze a dataset of their choice by providing the relative path to their CSV file.
Model training can also be customized by providing the number of iterations for running
gradient descent, and the learning rate to determine the shrinkage factor for updating model
parameters in each iteration.
If these are not provided, a demo dataset included with the script is used. Default number of
iterations and learning rate are also defined for demonstration.
Script usage can also be understood using the following via command line:    
    python logistic_regression.py -h

Python version: 3.10.8

External packages:
    1. pandas
    2. numpy

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
import argparse
import numpy as np
import pandas as pd
from typing import Tuple

DEMO_DATA_PATH = "datasets/demo_1.csv"


def prepare_data(file_path: str) -> Tuple[np.ndarray, np.ndarray, list]:
    """Reads data from CSV file into pandas DataFrame. Separates features
    and target, scales the features, and converts into numpy arrays for
    fast processing.

    Args:
        file_path (str): relative path to dataset CSV file

    Returns:
        Tuple[np.ndarray, np.ndarray, list]:
            1. 2-D array of features
            2. 1-D array of target variable
            3. list of feature names
    """
    try:
        data = pd.read_csv(file_path)
    except FileNotFoundError:
        sys.exit("Invalid path provided.")
    # separate target from features
    target = data.columns[-1]
    y = np.array(data.pop(target))
    features = list(data.columns)
    # scaling the features for optimal training
    data = (data - data.mean()) / data.std()
    X = np.array(data)
    return X, y, features


def predict_proba(X: np.ndarray, weights: np.ndarray, bias: float) -> np.ndarray:
    """Calculates the probability of sample(s) belonging to positive class.

    Args:
        X (np.ndarray): 2-D array of features
        weights (np.ndarray): 1-D array of coefficients
        bias (float): constant term added to weighted features

    Returns:
        np.ndarray: 1-D array of probabilities of samples belonging to positive class.
    """

    def sigmoid(z: np.ndarray) -> np.ndarray:
        # squishes value between 0 and 1 to denote probability
        return 1 / (1 + np.exp(-z))

    z = np.matmul(weights, X.T) + bias
    return sigmoid(z)


def predict(
    X: np.ndarray, weights: np.ndarray, bias: float, threshold: float = 0.5
) -> np.ndarray:
    """Converts the predicted probability to one of the two classes based on
    whether it is less than the threshold value or not. Threshold can be adjusted
    for datasets with imbalanced classes.

    Args:
        X (np.ndarray): 2-D array of features
        weights (np.ndarray): 1-D array of coefficients
        bias (float): constant term added to weighted features
        threshold (float, optional): boundary value for probability to class conversion.
            Defaults to 0.5.

    Returns:
        np.ndarray: 1-D array of predicted classes
    """
    predicted_proba = predict_proba(X, weights, bias)
    predicted_class = [1 if p >= threshold else 0 for p in predicted_proba]
    return np.array(predicted_class)


def accuracy(y_true: np.ndarray, y_pred: np.ndarray) -> float:
    """Calculates the accuracy of predicted classes based on overall fraction of
    correct predictions irrespective of the class balance.

    Args:
        y_true (np.ndarray): 1-D array of ground-truth labels
        y_pred (np.ndarray): 1-D array of predicted classes

    Returns:
        float: fraction of correct predictions
    """
    correct_predictions = np.sum(y_true == y_pred)
    return correct_predictions / len(y_true)


def gradient_descent(
    X: np.ndarray,
    y: np.ndarray,
    predicted_proba: np.ndarray,
    learning_rate: float,
    weights: np.ndarray,
    bias: float,
) -> Tuple[np.ndarray, float]:
    """Updates the model parameters in the direction of decreasing loss.
    Loss is evaluated based on predicted probabilites using current parameters,
    which is then shrunk based on learning rate and applied to the parameters to
    update them.

    Args:
        X (np.ndarray): 2-D array of features
        y (np.ndarray): 1-D array of ground-truth labels
        predicted_proba (np.ndarray): 1-D array of predicted probabilies
            based on current parameters
        learning_rate (float): shrinkage factor for updating current parameters
        weights (np.ndarray): feature coefficients (current)
        bias (float): constant term added to weighted features (current)

    Returns:
        Tuple[np.ndarray, float]:
            1. Updated version of feature coefficients
            2. Updated version of constant term
    """
    # calculating gradients to update the parameters
    gradient_loss = predicted_proba - y
    gradient_bias = np.mean(gradient_loss)
    gradient_weights = np.matmul(X.T, gradient_loss)
    gradient_weights = np.asarray([np.mean(col) for col in gradient_weights])
    # update parameters
    updated_weights = weights - learning_rate * gradient_weights
    updated_bias = bias - learning_rate * gradient_bias
    return updated_weights, updated_bias


def fit(X, y, n_iter, learning_rate) -> Tuple[np.ndarray, float]:
    """Fit the logistic regression model by updating parameters for 'n_iter'
    iterations via gradient descent algorithm.

    Args:
        X (_type_): 2-D array of features
        y (_type_): 1-D array of ground-truth labels
        n_iter (_type_): number of iterations for updating parameters
        learning_rate (_type_): shrinkage factor for updating parameters

    Returns:
        Tuple[np.ndarray, float]:
            1. Final version of updated weights (feature coefficients)
            2. Final version of updated bias (constant term)
    """
    # initialize weights and bias with zeros
    weights = np.zeros(X.shape[1])
    bias = 0
    # update weights and bias using gradient descent algorithm
    for _ in range(n_iter):
        predicted_proba = predict_proba(X, weights, bias)
        weights, bias = gradient_descent(
            X, y, predicted_proba, learning_rate, weights, bias
        )
    return weights, bias


def handle_test_samples(weights: np.ndarray, bias: float, features: list):
    """Interface for accepting new samples and predicting their class using
    the trained model (weights and bias). Available only after initial fit of
    the model.

    Args:
        weights (np.ndarray): 1-D array of feature coefficients
        bias (float): constant term added to weighted features
        features (list): feature names for input interface
    """
    while True:
        X_test = []
        print("\nEnter feature values:")
        for feat in features:
            try:
                val = float(input(f"{feat} = ").strip())
            except ValueError:
                print("Numerical value expected. Re-enter sample.")
                break
            X_test.append(val)
        X_test = np.array(X_test).reshape(1, len(X_test))

        predicted_proba = predict_proba(X_test, weights, bias)[0]
        predicted_class = predict(X_test, weights, bias)[0]
        confidence = predicted_proba if predicted_class == 1 else (1 - predicted_proba)
        print(
            f"Predicted class: {predicted_class} [Probability: {confidence * 100:.2f}%]"
        )

        choice_test = input("\nContinue testing new samples? [y/n]: ").strip()
        if choice_test == "y":
            continue
        else:
            return


def logistic_regression(file_path: str, n_iter: int, learning_rate: float):
    """Logistic Regression model demonstration. Accepts dataset CSV file,
    number of iterations and learning rate via the command line. Fits the model
    by updating parameters using gradient descent. Displays final parameters of
    the fit model, accuracy of predicted classes, and provides an interface for
    testing the model on new samples.

    Args:
        file_path (str): relative path to dataset CSV file
        n_iter (int): number of iterations for training the model
        learning_rate (float): shrinkage factor for updating model parameters
    """
    X, y, features = prepare_data(file_path)
    weights, bias = fit(X, y, n_iter, learning_rate)
    predictions = predict(X, weights, bias)
    final_accuracy = accuracy(y, predictions)

    weights_dict = dict(zip(features, weights))
    weights_dict["constant"] = bias
    print(f"Weights:\n{weights_dict}")
    print(f"Accuracy = {final_accuracy * 100:.2f}%\n")

    choice_test = input("Predict for test sample? [y/n]: ").strip().lower()
    if choice_test == "y":
        handle_test_samples(weights, bias, features)
    else:
        print("Skipping prediction on test sample...")
    print("\nExiting.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Fit a logistic regression model to classify the target.",
    )
    parser.add_argument(
        "file_path",
        default=DEMO_DATA_PATH,
        nargs="?",
        help="Relative path to CSV file.",
    )
    parser.add_argument(
        "n_iter",
        default=100,
        nargs="?",
        help="Number of iterations for training the model. Default = 100",
    )
    parser.add_argument(
        "learning_rate",
        default=0.1,
        nargs="?",
        help="Learning rate for the model. Default = 0.1",
    )
    args = parser.parse_args()
    try:
        n_iter = int(args.n_iter)
    except ValueError:
        sys.exit("Invalid value for iterations. Integer expected.")
    try:
        learning_rate = float(args.learning_rate)
    except ValueError:
        sys.exit("Invalid value for learning rate. Numerical value expected.")

    logistic_regression(args.file_path, n_iter, learning_rate)
