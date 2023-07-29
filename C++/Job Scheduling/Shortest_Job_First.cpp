/**
* This is an implementation of Shortest Job First Algorithm in C++
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

#include <bits/stdc++.h>
using namespace std;

struct Process {
   int pid; // Process ID
   int burstTime; // Burst Time - the total time required by a process
   int arrivalTime; // Arrival Time - time at which a process arrives
};

// calculate turn Around time
void calcTurnAroundTime(Process process[], int n, int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++)
        turnAroundTime[i] = process[i].burstTime + waitingTime[i];
}

// to calculate waiting time of all process
void calcWaitingTime(Process process[], int n, int waitingTime[]) {
    int remainingTime[n]; // will calculate the remaining burst time of each process
    for (int i = 0; i < n; i++)
        remainingTime[i] = process[i].burstTime;

    // complete keeps track of number of processes who have completed their execution
    int complete = 0;
    int t = 0; // current time
    // holds the current minimum burst time
    int currentMin = INT_MAX;

    int shortest = 0; // index of the process with the shortest remaining burst time


    int finish_time; // time at which a process finishes execution

    bool check = false; // flag to check if an eligible process is found

    // run until all processes are complete
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            // check eligibility of process for execution
            if ((process[j].arrivalTime <= t) && (remainingTime[j] < currentMin) && remainingTime[j] > 0) {
                currentMin = remainingTime[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false) { // if, no eligible process found
            t++;
            continue;
        }
        // decrementing the remaining time of shortest process
        remainingTime[shortest]--;
        currentMin = remainingTime[shortest];

        if (currentMin == 0)
            currentMin = INT_MAX;

            // if a Process has completed execution
            if (remainingTime[shortest] == 0) {
                complete++;
                check = false;
                finish_time = t + 1;

                // Calculate waiting time for completed process
                waitingTime[shortest] = finish_time - process[shortest].burstTime - process[shortest].arrivalTime;
                if (waitingTime[shortest] < 0)
                    waitingTime[shortest] = 0;
            }
            // Increment time
            t++;
    }
}

// Function to calculate average time
void printResult(Process process[], int n) {

    int waitingTime[n], turnAroundTime[n], totalWaitTime = 0,
    totalTurnAroundTime = 0;

    calcWaitingTime(process, n, waitingTime);
    calcTurnAroundTime(process, n, waitingTime, turnAroundTime);

    // print result & calc total turn around time
    cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        totalWaitTime = totalWaitTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        cout << " " << process[i].pid << "\t\t" << process[i].burstTime << "\t\t " << waitingTime[i] << "\t\t " << turnAroundTime[i] << endl;
    }
    cout << "\nAverage waiting time = " << (float)totalWaitTime / (float)n; cout << "\nAverage turn around time = " << (float)totalTurnAroundTime / (float)n;

}
    
int main() {
    Process process[] = { { 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };
    int n = sizeof(process) / sizeof(process[0]);
    printResult(process, n);
    return 0;
}