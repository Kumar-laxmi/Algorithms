#!/usr/bin/env python

"""Job Sequencing

This script solves the Job Sequencing problem using Greedy algorithm.
User is prompted to enter:
    1. number of jobs
    2. deadline of each job
    3. profit from each job
The maximum possible profit that can be made after sequencing the jobs
and the optimal job schedule are returned.

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import Tuple, List


def read_input() -> Tuple[List[int], List[float]]:
    """Reads from standard input, removes leading/trailing whitespace,
    casts the values to their appropriate datatypes, and performs basic
    validation.

    Returns:
        Tuple[List[int], List[float]]:
            1. list of deadlines of each job
            2. list of profits of each job
    """
    try:
        num_jobs = int(input("Number of jobs: ").strip())
    except ValueError:
        sys.exit("Integer value expected.")
    try:
        deadlines = list(map(int, input("Deadlines: ").strip().split()))
    except ValueError:
        sys.exit("Integer values expected.")
    try:
        profits = list(map(float, input("Profits: ").strip().split()))
    except ValueError:
        sys.exit("Numerical values (int/float) expected.")

    if len(deadlines) != num_jobs:
        sys.exit("Deadlines do not match with number of jobs.")
    if len(profits) != num_jobs:
        sys.exit("Profits do not match with number of jobs.")

    return deadlines, profits


def pick_latest_slot(deadline: int, schedule: List[int]) -> int:
    """Picks the latest available slot based on a job's deadline.

    Args:
        deadline (int): deadline for a specific job
        schedule (List[int]): current state of the schedule

    Returns:
        int: chosen slot
    """
    # iterate in reverse over the slots starting from the deadline
    for idx in range(deadline - 1, -1, -1):
        if schedule[idx] is not None:
            continue  # skip the slot if already allotted to a job
        else:
            return idx
    return None  # if no valid slot can be found the job will be skipped


def greedy_schedule(deadlines: List[int], profits: List[float]) -> Tuple[float, str]:
    """Solves the job sequencing problem using a greedy approach. Initiates an
    empty schedule, then iterates through jobs in decresing order of profits, and
    allots latest available slot to each job based on its deadline.

    Args:
        deadlines (List[int]): list of deadlines of each job
        profits (List[float]): list of profits of each job

    Returns:
        Tuple[float, str]:
            1. Total profit from the scheduled jobs
            2. Final schedule after all jobs are considered for scheduling
    """
    num_jobs = len(deadlines)
    schedule = [None] * num_jobs
    total_profit = 0
    # Get indices of jobs in descending order of profits
    sorted_profits_idx = sorted(range(num_jobs), key=profits.__getitem__, reverse=True)
    for job_idx in sorted_profits_idx:
        slot = pick_latest_slot(deadlines[job_idx], schedule)
        if slot is not None:  # if valid slot is returned, update the schedule
            schedule[slot] = job_idx
            total_profit += profits[job_idx]
    # remove empty slots
    schedule = [f"J{j}" for j in schedule if j is not None]
    return total_profit, " -> ".join(schedule)


def job_sequencing():
    deadlines, profits = read_input()
    total_profit, schedule = greedy_schedule(deadlines, profits)
    print(f"\nFinal schedule: {schedule}")
    print(f"Total profit = {total_profit:.2f}\n")


if __name__ == "__main__":
    job_sequencing()
