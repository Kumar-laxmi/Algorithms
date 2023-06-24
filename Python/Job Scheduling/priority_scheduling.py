class PriorityScheduling:
    def __init__(self):
        self.name = ""
        self.completionTime = 0
        self.arrivalTime = 0
        self.burstTime = 0
        self.turnAroundTime = 0
        self.responseTime = 0
        self.waitingTime = 0
        self.priority = 0


curr = 0

if __name__ == "__main__":
    avgTurnAroundTime = 0
    avgWaitingTime = 0
    avgResponseTime = 0

    print("Enter Number of Processes: ")
    n = int(input())

    process = []

    print("Enter Name of Processes: ")
    for i in range(n):
        p = PriorityScheduling()
        p.name = input()
        process.append(p)

    print("Enter Arrival Time of Processes: ")
    for i in range(n):
        process[i].arrivalTime = int(input())

    print("Enter Priority of Processes: ")
    for i in range(n):
        process[i].priority = int(input())

    print("Enter Burst Time of Processes: ")
    for i in range(n):
        process[i].burstTime = int(input())

    for i in range(n):
        process.sort(key=lambda x: x.priority-curr)
        
        process[i].responseTime = curr - process[i].arrivalTime
        process[i].completionTime = curr + process[i].burstTime

        curr = process[i].completionTime

        process[i].turnAroundTime = process[i].completionTime - \
            process[i].arrivalTime
        process[i].waitingTime = process[i].turnAroundTime - \
            process[i].burstTime

        avgTurnAroundTime += process[i].turnAroundTime
        avgResponseTime += process[i].responseTime
        avgWaitingTime += process[i].waitingTime

    print("    AT\tP\tBT\tCT\tTAT\tWT\tRT")
    for i in range(n):
        print(process[i].name + ":  " + str(process[i].arrivalTime) + "\t" + str(process[i].priority) + "\t" + str(process[i].burstTime) + "\t" + str(
            process[i].completionTime) + "\t" + str(process[i].turnAroundTime) + "\t" + str(process[i].waitingTime) + "\t" + str(process[i].responseTime))

    print()
    print("Average TurnAroundTime: " + str(avgTurnAroundTime / n))
    print("Average WaitingTime: " + str(avgWaitingTime / n))
    print("Average ResponseTime: " + str(avgResponseTime / n))

    print()
    print("Gantt Chart")
    print(str(process[0].arrivalTime) + "  |" +
          process[0].name + "|  ", end="")
    for i in range(n - 1):
        print(str(process[i].completionTime) + "  |" +
              process[i + 1].name + "|  ", end="")
    print(str(process[n - 1].completionTime))
