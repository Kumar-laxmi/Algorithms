""" Job sequencing algorithm in Python

Problem statement:
Given n jobs with some deadlines {d1, d2, ... dn} where di >= 0 and profits {p1, p2, ... pn} where pi >= 0.
Our task is to find the optimal sequence of jobs to maximize the total profit.

"""

from typing import List, Tuple

def job_sequencing(n: int, jobs: List[Tuple[int, int]]) -> Tuple[int, List[int]]:
    """Sort the jobs in descending order of their profit given"""
    jobs.sort(key=lambda x: x[1], reverse=True)

    # Find the maximum deadline among the given deadlines
    max_deadline = max(jobs, key=lambda x: x[0])[0]

    # Create a slot array to keep the allotted slot of job for execution (create schedule)
    slots = [0] * max_deadline

    max_profit = 0
    optimal_sequence = []

    # Iterate over each job
    for i in range(n):
        # Find a free slot starting from the last of the job's deadline to the beginning of timeline
        t = jobs[i][0] - 1
        while t >= 0 and slots[t]:
            t -= 1

        # If a free slot is found, add the job to the slot array at t index and add the job's profit
        # to the maximum (total) profit.
        # Else, the job is not added to the schedule and its profit is not added.
        if t >= 0 and not slots[t]:
            slots[t] = i + 1
            max_profit += jobs[i][1]
            optimal_sequence.append(i+1)

    return max_profit, optimal_sequence

# Example usage:
"""n = int(input("Enter the number of Jobs: "))
jobs = [(2, 20), (2, 15), (1, 10), (3, 5), (3, 1)]"""

n = int(input("Enter the number of jobs: "))
jobs = []

for i in range(n):
    deadline, profit = map(int, input("Enter the deadline and profit of job {}: ".format(i+1)).split())
    jobs.append((i+1, deadline, profit))

print(job_sequencing(n, jobs))
# Output: (40, [2, 1, 4])
