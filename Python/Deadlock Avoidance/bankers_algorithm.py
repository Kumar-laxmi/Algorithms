#!/usr/bin/env python

"""Banker's Algorithm

This script demonstrates Banker's algorithm for deadlock avoidance. User
inputs the current system state in the form of MAXIMUM and ALLOCATED matrices,
and TOTAL vector. 
The NEED matrix and AVAILABLE vector are calculated first. Then safety status
of the system and safe sequence are determined using the Safety algorithm. If
the system is deemed safe, there is an option to request additional resources,
which demonstrates the Resource-Request algorithm. If the system is safe after 
granting additional resources to a process, a new safe sequence is determined.

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys
from typing import Tuple


def calculate_need(maximum: list, allocated: list) -> list:
    """Calculates the need matrix using:
        NEED = MAXIMUM - ALLOCATED
    with all the matrices having shape m x n, where:
        m = number of processes
        n = number of resources

    Args:
        maximum (list): 2-D matrix for maximum resources required by processes.
        allocated (list): 2-D matrix for current resources allocated to processes.

    Returns:
        list: 2-D matrix for resources required by processes to complete.
    """
    need_matrix = []
    num_process = len(maximum)
    num_resource = len(maximum[0])
    for p in range(num_process):
        process_need = []
        for r in range(num_resource):
            process_need.append(maximum[p][r] - allocated[p][r])
        need_matrix.append(process_need)
    return need_matrix


def calculate_available(total: list, allocated: list) -> list:
    """Calculates the availale vector by first finding sum of allocated
    resources for all processes and subtracting it from the total
    resources of each type.

    Args:
        total (list): 1-D vector of total resources of each type.
        allocated (list): 2-D matrix of current resources allocated to processes.

    Returns:
        list: 1-D vector of current available resources of each type.
    """
    available = []
    num_process = len(allocated)
    num_resource = len(total)
    for r in range(num_resource):
        allocated_sum = 0
        for p in range(num_process):
            allocated_sum += allocated[p][r]
        available.append(total[r] - allocated_sum)
    return available


def can_finish(process: int, need: list, available: list) -> bool:
    """Checks whether the process can be completed immediately by comparing
    its needed resources with the available vector.

    Args:
        process (int): process number
        need (list): 2-D matrix for resources required by processes to complete.
        available (list): 1-D vector for current available resources of each type.

    Returns:
        bool: whether the process can be completed immediately or not.
    """
    num_resource = len(available)
    for resource in range(num_resource):
        if need[process][resource] > available[resource]:
            return False
    return True


def check_safety(allocated: list, need: list, available: list) -> str:
    """Determines the safety state and safe sequence of the system based on
    currently allocated resources, resources needed by processes for completion,
    and the resources available for allocation. If no safe sequence can be determined,
    it means the system is in an unsafe state.

    Args:
        allocated (list): 2-D matrix of current resources allocated to processes.
        need (list): 2-D matrix for resources required by processes to complete.
        available (list): 1-D vector for current available resources of each type.

    Returns:
        str: Safe sequence for completion of all processes. None if system is unsafe.
    """
    safe_sequence = []
    num_process = len(allocated)
    num_resource = len(available)
    finished = [False] * num_process  # all processes unfinished initially

    # waiting for all processes to complete
    while sum(finished) < num_process:
        # keeps track of whether at least one process could be allocated
        allocation_flag = False
        for p in range(num_process):
            if not finished[p]:  # only checking unfinished processes
                if can_finish(p, need, available):
                    allocation_flag = True
                    safe_sequence.append(p)
                    finished[p] = True
                    # available resources updated after process completion
                    for r in range(num_resource):
                        available[r] += allocated[p][r]
        if allocation_flag:
            continue
        else:
            # if no process could be alloted resources in this cycle, system is deadlocked
            break

    if sum(finished) < num_process:
        return None
    else:  # safe sequence returned only if all processes are completed
        safe_sequence = [f"P{i}" for i in safe_sequence]
        return " -> ".join(safe_sequence)


def check_resource_request(
    allocated: list, need: list, available: list, process: int, request: list
) -> Tuple[bool, str]:
    num_resource = len(available)
    num_process = len(allocated)

    # Condition 1: requested resources should not exceed actual need
    for r in range(num_resource):
        if request[r] > need[process][r]:
            return (False, "Request is more than actual need. Denied.\n")

    # Condition 2: requested resources should not exceed available resources
    for r in range(num_resource):
        if request[r] > available[r]:
            return (False, "Request is more than available resources. Denied.\n")

    # if above two conditions are satisfied, assume the request is granted
    # and update the system state
    for r in range(num_resource):
        allocated[process][r] += request[r]
        need[process][r] -= request[r]
        available[r] -= request[r]

    # check safety with the assumption that request was granted
    safe_sequence = check_safety(allocated, need, available.copy())
    if safe_sequence:
        return (True, safe_sequence)
    else:
        return (False, "System unsafe after granting additional request. Denied.\n")


def bankers_algorithm():
    print("\n----Input system state----")
    try:
        num_resource = int(input("\nNumber of resources: ").strip())
        num_process = int(input("Number of processes: ").strip())
    except ValueError:
        sys.exit("Integer values expected.")

    maximum = []
    allocated = []
    total = []

    print("\nMAXIMUM:")
    for i in range(num_process):
        try:
            process_max = list(map(int, input(f"P{i}: ").strip().split()))
        except ValueError:
            sys.exit("Integer values expected.")
        maximum.append(process_max)

    print("\nALLOCATED:")
    for i in range(num_process):
        try:
            process_alloc = list(map(int, input(f"P{i}: ").strip().split()))
        except ValueError:
            sys.exit("Integer values expected.")
        allocated.append(process_alloc)

    try:
        total = list(map(int, input(f"\nTOTAL: ").strip().split()))
    except ValueError:
        sys.exit("Integer values expected.")

    print("\nCalculating need matrix and available vector...")
    need = calculate_need(maximum, allocated)
    available = calculate_available(total, allocated)
    print("\nNEED:")
    for p in range(num_process):
        print(f"P{p}: {need[p]}")

    print(f"\nAVAILABLE: {available}")

    print("\nChecking safe state...")
    safe_sequence = check_safety(allocated, need, available.copy())
    if safe_sequence:
        print(f"The system is in a safe state.\nSafe sequence: {safe_sequence}")
    else:
        print("The system is in an unsafe state.\n")

    # Resource-request algorithm demonstrated only for system in safe state
    if safe_sequence:
        choice = input("\nTry requesting additional resources? [y/n]: ").strip().lower()
        if choice == "y":
            try:
                process = int(input("Process number: ").strip())
                request = list(map(int, input("Request: ").strip().split()))
            except ValueError:
                sys.exit("Integer values expected.")
            still_safe, new_safe_sequence = check_resource_request(
                allocated, need, available, process, request
            )
            if still_safe:
                print(
                    f"System remains in a safe state after granting the additional request.\n"
                    f"New safe sequence: {new_safe_sequence}\n"
                )
            else:
                print(new_safe_sequence)


if __name__ == "__main__":
    bankers_algorithm()
