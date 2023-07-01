#include <bits/stdc++.h>
using namespace std;
int curr = 0;
double avgTurnAroundTime = 0, avgwaitingTime = 0, avgresponseTime = 0;

class priorityScheduling
{
public:
    string name;
    int completionTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime, priority;
};

bool cmp(const priorityScheduling &o1, const priorityScheduling &o2)
{
    if (curr >= o2.arrivalTime && curr >= o1.arrivalTime)
    {
        return o1.priority < o2.priority;
    }
    return false;
}

int main()
{
    cout << "Enter Number of Processes: ";
    int n;
    cin >> n;

    vector<priorityScheduling> process(n);

    cout << "Enter Name of Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i].name;
    }
    cout << "Enter Arrival Time of Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i].arrivalTime;
    }
    cout << "Enter Priority of Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i].priority;
    }
    cout << "Enter Burst Time of Processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i].burstTime;
    }

    for (int i = 0; i < n; i++)
    {
        sort(process.begin(), process.end(), cmp);

        process[i].responseTime = curr - process[i].arrivalTime;
        process[i].completionTime = curr + process[i].burstTime;

        curr = process[i].completionTime;

        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;

        avgTurnAroundTime += process[i].turnAroundTime;
        avgresponseTime += process[i].responseTime;
        avgwaitingTime += process[i].waitingTime;
    }

    cout << "    AT\tP\tBT\tCT\tTAT\tWT\tRT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i].name << ":  ";
        cout << process[i].arrivalTime << "\t" << process[i].priority << "\t" << process[i].burstTime << "\t" << process[i].completionTime << "\t" << process[i].turnAroundTime << "\t" << process[i].waitingTime << "\t" << process[i].responseTime;
        cout << endl;
    }

    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "Average TurnAroundTime: " << avgTurnAroundTime / n << "\n";
    cout << "Average WaitingTime: " << avgwaitingTime / n << "\n";
    cout << "Average ResponseTime: " << avgresponseTime / n << "\n";

    cout << endl;
    cout << "Gantt Chart" << endl;
    cout << process[0].arrivalTime << "  |" << process[0].name << "|  ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << process[i].completionTime << "  |" << process[i + 1].name << "|  ";
    }
    cout << process[n - 1].completionTime;
    cout << endl;
}