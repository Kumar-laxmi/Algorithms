#include <stdio.h>  // for basic input output
#include <limits.h> // for INT_MAX : maximum integer value

int numProcess, timeQuantum; // for storing no. of processes, input elements, and time quantum for each process

struct Process
{
    int id;          // process id
    int arrivalTime; // point of time when process arrives
    int burstTime;   // time required to complete the process
};

void roundRobinAlgo(struct Process *process)
{
    int n = numProcess; // for remaining processes to schedule
    int time = 0;

    // loop to schedule until all processes are scheduled
    while (n)
    {
        int executed = 0; // flag to track if any process has executed in the current iteration

        // loop through the processes
        for (int i = 0; i < numProcess; ++i)
        {
            // if current process' burst time is greater than 0 and it has arrived
            if (process[i].burstTime > 0 && process[i].arrivalTime <= time)
            {
                executed = 1;

                // If the remaining burst time is less than or equal to the time quantum
                if (process[i].burstTime <= timeQuantum)
                {
                    printf("\nProcess %d starts at : %d & ends at : %d", process[i].id, time, time + process[i].burstTime);
                    time += process[i].burstTime;
                    process[i].burstTime = 0; // Mark the process as completed
                    --n;                      // decrement the number of processes remaining
                }
                else
                {
                    printf("\nProcess %d starts at : %d & runs for %d units", process[i].id, time, timeQuantum);
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
    printf("\n\t=== ROUND ROBIN SCHEDULING ALGORITHM ===\n");

    // input no. of processes
    printf("\nEnter No. of processes : ");
    scanf("%d", &numProcess);

    // input the time quantum
    printf("\nEnter Time quantum : ");
    scanf("%d", &timeQuantum);

    struct Process process[numProcess]; // array of processes

    // input arrival time for each process
    printf("\nEnter Arrival Time for each process : ");
    for (int i = 0; i < numProcess; i++)
    {
        process[i].id = i + 1;
        scanf("%d", &process[i].arrivalTime);
    }
    // input burst time for each process
    printf("\nEnter Burst Time for each process : ");
    for (int i = 0; i < numProcess; i++)
    {
        process[i].id = i + 1;
        scanf("%d", &process[i].burstTime);
    }

    // display the process table
    printf("\nEntered processes :\nProcess ID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < numProcess; i++)
        printf("    %d\t\t    %d\t\t    %d\n", process[i].id, process[i].arrivalTime, process[i].burstTime);

    roundRobinAlgo(process); // function call for the algorithm

    return 0;
}
