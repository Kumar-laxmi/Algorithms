#!/usr/bin/env python

"""Fractional Knapsack - Greedy algorithm

This script solves the fractional knapsack problem using Greedy algorithm.
User is prompted to enter:
    1. capacity of the knapsack
    2. number of items available
    3. values of the items
    4. weights of the items
The maximum possible value that can be stored in the knapsack is returned,
along with the chosen items and their fractions.

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import List, Tuple


def read_input() -> Tuple[float, int, List[float], List[float]]:
    """Reads input from the command line, removes leading/trailing
    whitespace, and casts the values to their appropriate datatypes.

    Returns:
        Tuple[float, int, List[float], List[float]]:
            1. total capacity of the knapsack (float)
            2. number of items available to be picked (int)
            3. values of the available items (List[float])
            4. weights of the available items (List[float])
    """
    capacity = float(input("\nCapacity of the knapsack: ").strip())
    num_items = int(input("Number of items available: ").strip())
    values = list(map(float, input("Values: ").strip().split()))
    weights = list(map(float, input("Weights: ").strip().split()))

    return capacity, num_items, values, weights


def greedy_fill(
    capacity: float, num_items: int, values: List[float], weights: List[float]
) -> Tuple[float, dict]:
    """Calculates the maximum value that can be filled in the knapsack using
    the available items.

    Args:
        capacity (float): total capacity of the knapsack
        num_items (int): number of items available to be picked
        values (List[float]): values of the available items
        weights (List[float]): weights of the available items

    Returns:
        Tuple[float, dict]:
            1. Total value filled in the knapsack (float)
            2. Chosen items and their fractions (dict)
    """
    total_value = 0
    chosen_items = {}  # {index of item: fraction of item}
    try:
        # calculate the value-to-weight ratio to determine 'unit value' of item
        value_ratios = [values[i] / weights[i] for i in range(num_items)]
    except ZeroDivisionError:
        sys.exit("Cannot have an item with zero weight.")

    # indices of items sorted by their unit value in descending order
    sorted_ratios_idx = sorted(
        range(num_items), key=value_ratios.__getitem__, reverse=True
    )

    for idx in sorted_ratios_idx:
        if capacity == 0:
            break

        if weights[idx] <= capacity:  # choose the complete item
            total_value += values[idx]
            capacity -= weights[idx]
            chosen_items[idx] = 1.0
        else:  # fill the remaining capacity with required fraction of the item
            total_value += capacity * value_ratios[idx]
            chosen_items[idx] = capacity / weights[idx]
            capacity = 0

    return total_value, chosen_items


if __name__ == "__main__":
    capacity, num_items, values, weights = read_input()
    total_value, chosen = greedy_fill(capacity, num_items, values, weights)
    print("\nChosen items and their fractions: ")
    for idx, fraction in chosen.items():
        print(
            f"Item {idx+1} ({values[idx]:.2f}): "
            f"{fraction:.2f} ({fraction * values[idx]:.2f})"
        )
    print(f"\nMaximum possible value = {total_value:.2f}")
