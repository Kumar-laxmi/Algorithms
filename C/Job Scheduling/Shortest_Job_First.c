/**
* This is an implementation of Shortest Job First Algorithm in C
* The psuedo code or algo is as follows: 
* - Retrieve the arrival time and burst time for each process.
* - Initialize an empty ready queue to hold the processes that have arrived but not yet    executed.
* - Sort the processes based on their burst time in ascending order.
* - Set the current time to 0.
* - While there are processes in the ready queue or unprocessed processes:
*    - Check for any arriving processes at the current time and add them to the ready queue. 
*    - If the ready queue is empty, increment the current time.
*    - If the ready queue is not empty:
*      - Sort the ready queue based on the remaining burst time of each process (assuming the *        burst time decreases with each execution).
*      - Select the process with the shortest burst time from the ready queue.
*      - Execute the selected process for one time unit.
*      - Update the remaining burst time for the executed process.
*      - If the remaining burst time of the process is 0, calculate and store its turnaround *         time and waiting time.
*      - Increment the current time by one unit.
* - Calculate the average turnaround time and average waiting time for all executed processes.
* - Display the average turnaround time and average waiting time.
**/

#include <stdio.h>
#include <limits.h>

struct Process {
   int pid; // Process ID
   int burstTime; // Burst Time - the total time required by a process
   int arrivalTime; // Arrival Time - time at which a process arrives
};

// Calculate turn around time
void calcTurnAroundTime(struct Process process[], int n, int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++)
        turnAroundTime[i] = process[i].burstTime + waitingTime[i];
}

// Calculate waiting time of all processes
void calcWaitingTime(struct Process process[], int n, int waitingTime[]) {
    int remainingTime[n]; // Will calculate the remaining burst time of each process
    for (int i = 0; i < n; i++)
        remainingTime[i] = process[i].burstTime;

    int complete = 0; // Keeps track of the number of processes that have completed their execution
    int t = 0; // Current time
    int currentMin = INT_MAX; // Holds the current minimum burst time
    int shortest = 0; // Index of the process with the shortest remaining burst time
    int finishTime; // Time at which a process finishes execution
    int check = 0; // Flag to check if an eligible process is found

    // Run until all processes are complete
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            // Check eligibility of process for execution
            if ((process[j].arrivalTime <= t) && (remainingTime[j] < currentMin) && remainingTime[j] > 0) {
                currentMin = remainingTime[j];
                shortest = j;
                check = 1;
            }
        }
        if (check == 0) { // If no eligible process found
            t++;
            continue;
        }
        // Decrement the remaining time of the shortest process
        remainingTime[shortest]--;
        currentMin = remainingTime[shortest];

        if (currentMin == 0)
            currentMin = INT_MAX;

        // If a process has completed execution
        if (remainingTime[shortest] == 0) {
            complete++;
            check = 0;
            finishTime = t + 1;

            // Calculate waiting time for the completed process
            waitingTime[shortest] = finishTime - process[shortest].burstTime - process[shortest].arrivalTime;
            if (waitingTime[shortest] < 0)
                waitingTime[shortest] = 0;
        }
        // Increment time
        t++;
    }
}

// Function to calculate average time
void printResult(struct Process process[], int n) {
    int waitingTime[n], turnAroundTime[n], totalWaitTime = 0, totalTurnAroundTime = 0;

    calcWaitingTime(process, n, waitingTime);
    calcTurnAroundTime(process, n, waitingTime, turnAroundTime);

    // Print results and calculate total turn around time
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");
    for (int i = 0; i < n; i++) {
        totalWaitTime = totalWaitTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].pid, process[i].burstTime, waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage waiting time = %.2f", (float)totalWaitTime / (float)n);
    printf("\nAverage turn around time = %.2f", (float)totalTurnAroundTime / (float)n);
}

int main() {
    struct Process process[] = { { 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };
    int n = sizeof(process) / sizeof(process[0]);
    printResult(process, n);
    return 0;
}
