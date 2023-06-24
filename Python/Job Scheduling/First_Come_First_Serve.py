#First Come First Serve
#Criteria for FCFS: Arrival Time
#Mode: Non-premptive->Once the processor starts its execution, it must finish it before executing the other. It can’t be paused in the middle.
#Turn Around Time(TAT)=Completion time - Arrival time;
#Waiting time(WT)=Turn Around Time - Burst Time;
#Average TAT=(Total TAT)/(No. of process);
#Average WT=(Total WT)/(No. of process);

class Process:
    def __init__(self, pid, at, bt):
        self.process_id = pid
        self.at = at
        self.bt = bt
        self.ct = at + bt
        self.tat = 0
        self.wt = 0


n = int(input("Enter number of processes: "))
p = []
avgwt = 0
avgtat = 0

for i in range(n):
    print("Enter details for process", i + 1)
    pid = int(input("Process ID: "))
    at = int(input("Arrival Time: "))
    bt = int(input("Burst Time: "))
    p.append(Process(pid, at, bt))

p[0].tat = p[0].bt
for i in range(1, n):
    p[i].wt = p[i - 1].wt + p[i - 1].bt - p[i].at + p[i - 1].at
    if p[i].wt < 0:
        p[i].wt = 0
    p[i].tat = p[i].wt + p[i].bt

for i in range(n):
    avgwt += p[i].wt
    avgtat += p[i].tat

print("\npid  AT  BT  CT TAT WT")
for i in range(n):
    print(
        p[i].process_id,
        "\t",
        p[i].at,
        "\t",
        p[i].bt,
        "\t",
        p[i].ct,
        "\t",
        p[i].tat,
        "\t",
        p[i].wt,
    )

print("\nGANTT CHART")
for i in range(n):
    print(f"  P[{p[i].process_id}] ", end="")
print()
print("0", end=" ")
for i in range(n):
    print(" ", end="")
    if p[i].tat > 9:
        print("\b", end="")
    print(f"-> {p[i].tat}", end=" ")

print("\nAverage waiting time:", avgwt / n)
print("Average turnaround time:", avgtat / n)
