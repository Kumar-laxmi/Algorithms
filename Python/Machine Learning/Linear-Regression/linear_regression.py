#!/usr/bin/env python

"""Linear Regression

This script implements multiple linear regression using a closed-form solution
to find optimal fit. User can analyze a dataset of their choice by providing:
    1. relative path to their CSV file
    2. name of the target column
If these are not provided, a demo dataset included with the script is used.

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


DEMO_DATA_PATH = "demo_dataset.csv"


def prepare_data(
    file_path: str, target_variable: str
) -> Tuple[np.ndarray, np.ndarray, list]:
    """Reads data from CSV file and prepares it for model fitting.

    Args:
        file_path (str): relative path to CSV file
        target_variable (str): name of dependent variable in the dataset

    Returns:
        Tuple[np.ndarray, np.ndarray, list]:
            1. n-dim array of independent variables
            2. 1-dim array of dependent variable
            3. List of feature names
    """
    # read data from file as pandas dataframe
    try:
        data = pd.read_csv(file_path)
    except FileNotFoundError:
        sys.exit("Invalid path provided.")

    # separate features and target
    if target_variable:
        y = np.array(data.pop(target_variable))
    else:
        y = np.array(data.pop(data.columns[-1]))
    features = list(data.columns)
    X = np.array(data)

    # add bias term in the form of constant column
    X = np.column_stack((X, np.ones(len(X))))
    features.append("constant")

    return X, y, features


def calculate_coefficients(X: np.ndarray, y: np.ndarray) -> np.ndarray:
    """Calculates optimal coefficients for independent variables using
    closed form solution to linear regression:
        coefficients = ((X-transpose.X)-inverse).X-transpose.y
    where, '.' represents Dot-product.

    Args:
        X (np.ndarray): n-dim array of independent variables
        y (np.ndarray): 1-dim array of dependent variable

    Returns:
        np.ndarray: 1-dim array of coefficients of dependent
            variables for optimal solution (line of best fit).
    """
    return np.linalg.inv((X.T).dot(X)).dot((X.T).dot(y))


def predict(X: np.ndarray, coefficients: np.ndarray) -> np.ndarray:
    """Calculate predicted values of dependent variable based on line of
    best fit represented by 'coefficients'.

    Args:
        X (np.ndarray): n-dim array of dependent variables
        coefficients (np.ndarray): 1-dim array of coefficients for dependent
            variables representing the line of best fit.

    Returns:
        np.ndarray: 1-dim array of predicted values of dependent variable
    """
    return np.dot(X, coefficients)


def mean_squared_error(labels: np.ndarray, predictions: np.ndarray) -> float:
    """Calculates the average squared distance between observed and
    predicted values.

    Args:
        labels (np.ndarray): 1-dim array of observed values
        predictions (np.ndarray): 1-dim array of predicted values

    Returns:
        float: average squared distance between observed and predicted values
    """
    total_squared_error = np.sum(np.square(labels - predictions))
    return total_squared_error / len(labels)


def fit_lr(file_path: str, target: str) -> None:
    """Fits a linear regression model to the provided data.
    Displays the optimal coefficients for line of best fit,
    and the mean squared error for the predicted values.

    Args:
        file_path (str): relative path to CSV file
        target (str): name of dependent variable in the dataset
    """
    X, y, features = prepare_data(file_path, target)
    coefficients = calculate_coefficients(X, y)
    predictions = predict(X, coefficients)
    error = mean_squared_error(y, predictions)
    print(f"\nCoefficients: {dict(zip(features, coefficients))}")
    print(f"\nMean squared error = {error:.5f}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Fit a linear regression model to the data.",
    )
    parser.add_argument(
        "file_path",
        default=DEMO_DATA_PATH,
        nargs="?",
        help="Relative path to CSV file.",
    )
    parser.add_argument(
        "target_column",
        default=None,
        nargs="?",
        help="Name of target column in the dataset.",
    )
    args = parser.parse_args()
    fit_lr(args.file_path, args.target_column)
