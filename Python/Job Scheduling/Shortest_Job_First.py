# This is an implementation of pre-emptive shortest job first scheduling algo in python
# The psuedo code or algo is as follows:
#  - Retrieve the arrival time and burst time for each process.
#  - Initialize an empty ready queue to hold the processes that have arrived but not yet    executed.
#  - Sort the processes based on their burst time in ascending order.
#  - Set the current time to 0.
#  - While there are processes in the ready queue or unprocessed processes:
#     - Check for any arriving processes at the current time and add them to the ready queue. 
# *    - If the ready queue is empty, increment the current time.
#     - If the ready queue is not empty:
#       - Sort the ready queue based on the remaining burst time of each process (assuming  
#        the burst time decreases with each execution).
# *      - Select the process with the shortest burst time from the ready queue.
#       - Execute the selected process for one time unit.
# *      - Update the remaining burst time for the executed process.
#       - If the remaining burst time of the process is 0, calculate and store it turnaround
#         time and waiting time.
#       - Increment the current time by one unit.
#  - Calculate the average turnaround time and average waiting time for all executed processes.
# * - Display the average turnaround time and average waiting time.

class Process:
    def __init__(self, pid, burstTime, arrivalTime):
        self.pid = pid  # Process ID
        self.burstTime = burstTime  # Burst Time - the total time required by a process
        self.arrivalTime = arrivalTime  # Arrival Time - time at which a process arrives


# Calculate turn around time
def calcTurnAroundTime(processes, n, waitingTime, turnAroundTime):
    for i in range(n):
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i]


# Calculate waiting time of all processes
def calcWaitingTime(processes, n, waitingTime):
    remainingTime = [processes[i].burstTime for i in range(n)]  # Calculate the remaining burst time of each process

    complete = 0  # Keeps track of the number of processes that have completed their execution
    t = 0  # Current time
    currentMin = float('inf')  # Holds the current minimum burst time
    shortest = 0  # Index of the process with the shortest remaining burst time
    finishTime = 0  # Time at which a process finishes execution
    check = False  # Flag to check if an eligible process is found

    # Run until all processes are complete
    while complete != n:
        for j in range(n):
            # Check eligibility of process for execution
            if processes[j].arrivalTime <= t and remainingTime[j] < currentMin and remainingTime[j] > 0:
                currentMin = remainingTime[j]
                shortest = j
                check = True

        if not check:  # If no eligible process found
            t += 1
            continue

        # Decrement the remaining time of the shortest process
        remainingTime[shortest] -= 1
        currentMin = remainingTime[shortest]

        if currentMin == 0:
            currentMin = float('inf')

        # If a process has completed execution
        if remainingTime[shortest] == 0:
            complete += 1
            check = False
            finishTime = t + 1

            # Calculate waiting time for the completed process
            waitingTime[shortest] = finishTime - processes[shortest].burstTime - processes[shortest].arrivalTime
            if waitingTime[shortest] < 0:
                waitingTime[shortest] = 0

        # Increment time
        t += 1


# Function to calculate average time
def printResult(processes, n):
    waitingTime = [0] * n
    turnAroundTime = [0] * n
    totalWaitTime = 0
    totalTurnAroundTime = 0

    calcWaitingTime(processes, n, waitingTime)
    calcTurnAroundTime(processes, n, waitingTime, turnAroundTime)

    # Print results and calculate total turn around time
    print("Processes\tBurst time\tWaiting time\tTurn around time")
    for i in range(n):
        totalWaitTime += waitingTime[i]
        totalTurnAroundTime += turnAroundTime[i]
        print(f"{processes[i].pid}\t\t{processes[i].burstTime}\t\t{waitingTime[i]}\t\t{turnAroundTime[i]}")

    print("\nAverage waiting time =", totalWaitTime / n)
    print("Average turn around time =", totalTurnAroundTime / n)


if __name__ == '__main__':
    processes = [
        Process(1, 5, 1),
        Process(2, 3, 1),
        Process(3, 6, 2),
        Process(4, 5, 3)
    ]
    n = len(processes)
    printResult(processes, n)
