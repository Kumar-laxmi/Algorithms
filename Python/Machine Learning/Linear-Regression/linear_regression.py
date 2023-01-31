#!/usr/bin/env python

"""Linear Regression

This script implements multiple linear regression using a closed-form solution
to find optimal fit. User can analyze a dataset of their choice by providing:
    1. relative path to their CSV file
    2. name of the target column
If these are not provided, a demo dataset included with the script is used.
For datasets with two or less independent variables, there is an option to
visualize the fit of the regression model.

Python version: 3.10.8

External packages:
    1. pandas
    2. numpy
    3. matplotlib

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
import argparse

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from typing import Tuple


DEMO_DATA_PATH = "demo_datasets/demo2d.csv"


def prepare_data(
    file_path: str, target_name: str
) -> Tuple[np.ndarray, np.ndarray, list]:
    """Reads data from CSV file and prepares it for model fitting.

    Args:
        file_path (str): relative path to CSV file
        target_name (str): name of dependent variable in the dataset

    Returns:
        Tuple[np.ndarray, np.ndarray, list, str]:
            1. n-dim array of independent variables
            2. 1-dim array of dependent variable
            3. List of feature names
            4. Name of dependent variable (updated in case of demo dataset)
    """
    # read data from file as pandas dataframe
    try:
        data = pd.read_csv(file_path)
    except FileNotFoundError:
        sys.exit("Invalid path provided.")

    # separate features and target
    if target_name:
        y = np.array(data.pop(target_name))
    else:
        target_name = data.columns[-1]
        y = np.array(data.pop(data.columns[-1]))
    features = list(data.columns)
    X = np.array(data)

    # add bias term in the form of constant column
    X = np.column_stack((X, np.ones(len(X))))
    features.append("constant")

    return X, y, features, target_name


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


def plot_regression(
    X: np.ndarray,
    y: np.ndarray,
    predictions: np.ndarray,
    features: list,
    target_name: str,
) -> None:
    """Plots the original data as a scatter plot and the regression fit as a
    line or plane depending on the number of independent variables. Creates a
    2-D plot with a line of best fit for one independent variable. Creates a
    3-D plot with a plane of best-fit for two independent variables. Does not
    handle higher number of features.

    Args:
        X (np.ndarray): n-dim array of original features without the constant
        y (np.ndarray): 1-dim array of original dependent variable
        predictions (np.ndarray): 1-dim array of predictions
        features (list): original list of feature names without the constant
        target_name (str): name of dependent variable
    """
    if len(features) == 1:  # 2-D plot for one independent variable
        x = X.ravel()

        fig, ax = plt.subplots(nrows=1, ncols=1, figsize=(8, 6))
        ax.set_title("Line of best fit", fontsize=20, fontweight="bold")
        ax.set_xlabel(features[0], fontsize=12, fontweight="bold")
        ax.set_ylabel(target_name, fontsize=12, fontweight="bold")
        ax.minorticks_on()

        ax.scatter(x, y, color="black")  # original data
        ax.plot(x, predictions, linewidth=2, color="blue")  # line of best fit
        fig.tight_layout()

    else:  # 3-D plot for two independent variables
        x1, x2 = X[:, 0].ravel(), X[:, 1].ravel()

        fig = plt.figure(figsize=(10, 7))
        ax = plt.axes(projection="3d")
        ax.set_title("Plane of best fit", fontsize=20, fontweight="bold")
        ax.set_xlabel(features[0], fontsize=12, fontweight="bold")
        ax.set_ylabel(features[1], fontsize=12, fontweight="bold")
        ax.set_zlabel(target_name, fontsize=12, fontweight="bold")
        ax.minorticks_on()

        ax.scatter3D(x1, x2, y, color="black")  # original data
        # plane of best fit
        ax.plot_trisurf(x1, x2, predictions, color="blue", alpha=0.3)
        fig.tight_layout()

    plot_name = input("Enter a name for the plot: ").strip()
    file_name = f"plots/{plot_name}.png"
    fig.savefig(file_name, pad_inches=0.1)
    print(f"Figure saved at: {file_name}\n")


def fit_lr(file_path: str, target_name: str) -> None:
    """Fits a linear regression model to the provided data.
    Displays the optimal coefficients for line of best fit, and the mean
    squared error for the predicted values. If the number of independent
    variables is less than 3 (excluding constant term), there is an option
    to save a plot of the regression fit.

    Args:
        file_path (str): relative path to CSV file
        target_name (str): name of dependent variable in the dataset
    """
    X, y, features, target = prepare_data(file_path, target_name)
    coefficients = calculate_coefficients(X, y)
    predictions = predict(X, coefficients)
    error = mean_squared_error(y, predictions)
    print(f"\nCoefficients: {dict(zip(features, coefficients))}")
    print(f"Mean squared error = {error:.5f}\n")

    if len(features) <= 3:
        viz = input(f"Visualize {len(features)}-D plot? [y/n]: ").strip()
        if viz.lower() == "y":
            # dropping constant term, already incorporated in predictions
            plot_regression(X[:, :-1], y, predictions, features[:-1], target)
        else:
            print("Skipping visualization.\n")


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
