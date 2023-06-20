#include <stdio.h>

// this is an implementation of first come first serve CPU Job Scheduling Algorithm in C
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int turnaround_time;
    int waiting_time;
};

void sort(struct Process processes[], int n) {
    struct Process temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void fcfs(struct Process processes[], int n) {
    int current_time = 0;
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;

    sort(processes, n);

    for (int i = 0; i < n; i++) {
        struct Process process = processes[i];

        process.start_time = current_time > process.arrival_time ? current_time : process.arrival_time;
        current_time = process.start_time + process.burst_time;
        process.end_time = current_time;

        process.turnaround_time = process.end_time - process.arrival_time;
        process.waiting_time = process.turnaround_time - process.burst_time;

        total_turnaround_time += process.turnaround_time;
        total_waiting_time += process.waiting_time;

        printf("Process %d:\n", process.pid);
        printf("Arrival Time: %d\n", process.arrival_time);
        printf("Burst Time: %d\n", process.burst_time);
        printf("Start Time: %d\n", process.start_time);
        printf("End Time: %d\n", process.end_time);
        printf("Turnaround Time: %d\n", process.turnaround_time);
        printf("Waiting Time: %d\n\n", process.waiting_time);
    }

    float avg_turnaround_time = total_turnaround_time / n;
    float avg_waiting_time = total_waiting_time / n;

    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

int main() {
    struct Process processes[] = {
            {1, 0, 10},
            {2, 3, 5},
            {3, 4, 8},
            {4, 7, 3},
            {5, 9, 6}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    fcfs(processes, n);

    return 0;
}