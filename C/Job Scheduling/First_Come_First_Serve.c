//First Come First Serve(FCFS):

//Criteria for FCFS: Arrival Time
//Mode: Non-premptive->Once the processor starts its execution, it must finish it before executing the other. It can’t be paused in the middle.
//Turn Around Time(TAT)=Completion time - Arrival time;
//Waiting time(WT)=Turn Around Time - Burst Time;
//Average TAT=(Total TAT)/(No. of process);
//Average WT=(Total WT)/(No. of process);
#include <stdio.h>

struct Process {
    int process_id;
    int at;
    int bt;
    int ct;
    int tat;
   int wt;
};

void calculateProcessTimes(struct Process p[], int n) {
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

void printProcessDetails(struct Process p[], int n) {
    printf("\npid\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].process_id, p[i].at, p[i].bt,
            p[i].ct, p[i].tat, p[i].wt);
    }
}

void printGanttChart(struct Process p[], int n) {
    printf("\nGANTT CHART\n");

    for (int i = 0; i < n; i++) {
        printf("  P[%d] ", p[i].process_id);
    }

    printf("\n");
    printf("  0"); // starting time of process:0

    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < p[i].bt; j++)
        printf(" ");

        if (p[i].tat > 9) { // not a universal threshold for TAT, for formatting Gantt chart in display
            printf("\b");
        }

        printf("-> %d ", p[i].tat);
    }
    printf("\n");
}

int main() {
    struct Process p[100];
    float avgwt = 0;
    float avgtat = 0;
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details of process id, arrival time, burst time: ");
        int pid, at, bt;
        scanf("%d %d %d", &pid, &at, &bt);
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

    printf("\nAverage waiting time: %.2f", avgwt / n);     // printing average waiting time.
    printf("\nAverage turnaround time: %.2f", avgtat / n);

    return 0;
}

