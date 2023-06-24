//First Come First Serve(FCFS):

//Criteria for FCFS: Arrival Time
//Mode: Non-premptive->Once the processor starts its execution, it must finish it before executing the other. It can’t be paused in the middle.
//Turn Around Time(TAT)=Completion time - Arrival time;
//Waiting time(WT)=Turn Around Time - Burst Time;
//Average TAT=(Total TAT)/(No. of process);
//Average WT=(Total WT)/(No. of process);
#include <iostream>
using namespace std;

struct Process {
    int process_id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void calculateProcessTimes(Process p[], int n) {
    p[0].tat = p[0].bt;
    p[0].wt=0;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt - p[i].at + p[i - 1].at;

        if (p[i].wt < 0) {
            p[i].wt = 0;
        }

        p[i].tat = p[i].wt + p[i].bt;
    }
}

void printProcessDetails(Process p[], int n) {
    cout << "\npid\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << p[i].process_id << "\t" << p[i].at << "\t" << p[i].bt << "\t"
            << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }
}

void printGanttChart(Process p[], int n) {
    cout << "\nGANTT CHART\n";

    for (int i = 0; i < n; i++) {
        cout << "  P[" << p[i].process_id << "] ";
    }

    cout << endl;
    cout << "  0"; // starting time of process:0

    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < p[i].bt; j++)
        cout << " ";

        if (p[i].tat > 9) { // not a universal threshold for TAT, for formatting Gantt chart in display
            cout << "\b";
        }

        cout << "-> " << p[i].tat << " ";
    }
    cout << endl;
}

int main() {
    Process p[100];
    float avgwt = 0;
    float avgtat = 0;
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter details of process id, arrival time, burst time: ";
        int pid, at, bt;
        cin >> pid >> at >> bt;
        p[i].process_id = pid;
        p[i].at = at;
        p[i].bt = bt;
        p[i].ct = at + bt;
    }

    calculateProcessTimes(p, n);

    for (int i = 0; i < n; i++) {
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }

    printProcessDetails(p, n);
    printGanttChart(p, n);

    cout << "\nAverage waiting time: " << avgwt / n;     // printing average waiting time.
    cout << "\nAverage turnaround time: " << avgtat / n;

    return 0;
}
