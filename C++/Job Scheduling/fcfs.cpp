#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// this is an implementation of first come first serve CPU Job Scheduling Algorithm in C++
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int turnaround_time;
    int waiting_time;
};

bool compare(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

void fcfs(vector<Process> processes) {
    queue<Process> ready_queue;
    int current_time = 0;
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;

    sort(processes.begin(), processes.end(), compare);

    for (int i = 0; i < processes.size(); i++) {
        ready_queue.push(processes[i]);
    }

    while (!ready_queue.empty()) {
        Process process = ready_queue.front();
        ready_queue.pop();

        process.start_time = max(current_time, process.arrival_time);
        current_time = process.start_time + process.burst_time;
        process.end_time = current_time;

        process.turnaround_time = process.end_time - process.arrival_time;
        process.waiting_time = process.turnaround_time - process.burst_time;

        total_turnaround_time += process.turnaround_time;
        total_waiting_time += process.waiting_time;

        cout << "Process " << process.pid << ":" << endl;
        cout << "Arrival Time: " << process.arrival_time << endl;
        cout << "Burst Time: " << process.burst_time << endl;
        cout << "Start Time: " << process.start_time << endl;
        cout << "End Time: " << process.end_time << endl;
        cout << "Turnaround Time: " << process.turnaround_time << endl;
        cout << "Waiting Time: " << process.waiting_time << endl;
        cout << endl;
    }

    float avg_turnaround_time = total_turnaround_time / processes.size();
    float avg_waiting_time = total_waiting_time / processes.size();

    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}

int main() {
    vector<Process> processes = {
            {1, 0, 10},
            {2, 3, 5},
            {3, 4, 8},
            {4, 7, 3},
            {5, 9, 6}
    };

    fcfs(processes);

    return 0;
}