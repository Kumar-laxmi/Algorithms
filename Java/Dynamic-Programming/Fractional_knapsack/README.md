# Fractional Knapsack Problem

The Fractional Knapsack problem is a classic optimization problem in computer science and mathematics. It involves selecting items from a set, each with its own weight and value, to maximize the total value while staying within a given capacity constraint.

This README provides an overview of the Fractional Knapsack problem and explains the code implementation provided in this repository.

## Problem Description

Given a knapsack with a maximum weight capacity and a set of items, each with its weight and value, the goal is to determine the most valuable combination of items to include in the knapsack. Unlike the 0/1 Knapsack problem, where items must be selected entirely or not at all, the Fractional Knapsack problem allows selecting fractions of items.

The objective is to maximize the total value of the items in the knapsack without exceeding its weight capacity.

## Code Implementation

The code provided in this repository is an implementation of the Fractional Knapsack algorithm in [JAVA]. It calculates the maximum value that can be obtained by solving the problem.

### Dependencies

The code does not have any external dependencies. It only utilizes the standard libraries of the programming language.

### Algorithm Overview

The implemented algorithm follows these steps to solve the Fractional Knapsack problem:

1. Calculate the value per unit weight for each item.

2. Sort the items based on their value per unit weight in descending order.

3. Iterate through the sorted items and add them to the knapsack until the capacity is reached or all items are used.

   - If an item can be fully added, include it entirely.

   - If an item cannot be fully added, calculate the fraction that can be included based on the remaining capacity.

4. Return the total value of the items included in the knapsack.

## Contributing

Contributions to this repository are welcome! If you have any suggestions, improvements, or bug fixes, please feel free to submit a pull request.


