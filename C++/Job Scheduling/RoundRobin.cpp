#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numProcess, timeQuantum; // for storing no. of processes, input elements and time quantum for each process

struct Process
{
    int id;          // process id
    int arrivalTime; // point of time when process arrives
    int burstTime;   // time required to complete the process
};

void roundRobinAlgo(Process *process)
{
    int n = numProcess; // for remaining processes to schedule
    int time = 0;

    // loop to schedule until all processes are scheduled
    while (n)
    {
        bool executed = false; // flag to track if any process has executed in the current iteration

        // loop through the processes
        for (int i = 0; i < numProcess; ++i)
        {
            // if current process' burst time is greater than 0 and it has arrived
            if (process[i].burstTime > 0 && process[i].arrivalTime <= time)
            {
                executed = true;

                // If the remaining burst time is less than or equal to the time quantum
                if (process[i].burstTime <= timeQuantum)
                {
                    cout << "\nProcess " << process[i].id << " starts at : " << time << " & ends at : " << time + process[i].burstTime;
                    time += process[i].burstTime;
                    process[i].burstTime = 0; // Mark the process as completed
                    --n;                      // decrement the number of processes remaining
                }
                else
                {
                    cout << "\nProcess " << process[i].id << " starts at : " << time << " & runs for " << timeQuantum << " units";
                    process[i].burstTime -= timeQuantum;
                    time += timeQuantum;
                }
            }
        }

        // If no process was executed in this iteration, increment the time to the next arrival time
        if (!executed)
        {
            int next_arrival = INT_MAX;
            for (int i = 0; i < numProcess; ++i)
            {
                if (process[i].burstTime > 0 && process[i].arrivalTime > time && process[i].arrivalTime < next_arrival)
                    next_arrival = process[i].arrivalTime;
            }

            if (next_arrival == INT_MAX)
                break;

            time = next_arrival;
        }
    }
}

// main function definition
int main()
{
    cout << "\n\t=== ROUND ROBING SCHEDULING ALGORITHM ===" << endl;

    // input no. of processes
    cout << "\nEnter No. of processes : ";
    cin >> numProcess;

    // input the time quantum
    cout << "\nEnter Time quantum : ";
    cin >> timeQuantum;

    Process process[numProcess]; // array of processes

    // input arrival time for each process
    cout << "\nEnter Arrival Time for each process : ";
    for (int i = 0; i < numProcess; i++)
    {
        process[i].id = i + 1;
        cin >> process[i].arrivalTime;
    }
    // input burst time for each process
    cout << "\nEnter Burst Time for each process : ";
    for (int i = 0; i < numProcess; i++)
    {
        process[i].id = i + 1;
        cin >> process[i].burstTime;
    }

    // display the process table
    cout << "\nEntered processes :\nProcess ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < numProcess; i++)
        cout << "    " << process[i].id << "\t\t    " << process[i].arrivalTime << "\t\t    " << process[i].burstTime << endl;

    roundRobinAlgo(process); // function call for the algorithm

    return 0;
}