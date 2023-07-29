# class of process
class Process:
    def __init__(self, id, arrivalTime, burstTime):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime


# round robin function definition
def roundRobin(numProcess, timeQuantum, process):
    n = numProcess  # for remaining processes to schedule
    time = 0

    # loop to schedule until all processes are scheduled
    while n > 0:
        executed = False  # flag to track if any process has executed in the current iteration

        # loop through the processes
        for p in process:
            # if current process' burst time is greater than 0 and it has arrived
            if p.burstTime > 0 and p.arrivalTime <= time:
                executed = True
                # If the remaining burst time is less than or equal to the time quantum
                if p.burstTime <= timeQuantum:
                    print(
                        "\nProcess", p.id, "starts at :", time, "& ends at :", time)
                    time += p.burstTime
                    p.burstTime = 0  # mark the process as completed
                    n -= 1  # decrement the no. of processes remaining
                else:
                    print("\nProcess", p.id, "starts at :",
                          time, "& runs for :", timeQuantum, "units")
                    p.burstTime = timeQuantum
                    time += timeQuantum

        # if no process was executed in this iteration, increment time to next arrival time
        if executed == False:
            nxtArrival = "INF"
            for p in process:
                if p.burstTime > 0 and p.arrivalTime > time and p.arrivalTime < nxtArrival:
                    nxtArrival = p.arrivalTime
            if nxtArrival == "INF":
                break
            time = nxtArrival


# main function call
def main():
    process = []  # for list of processes

    print("\n\t=== ROUND ROBIN SCHEDULING ALGORITHM ===")

    # input no. of processes
    n = int(input("Enter no. of processes : "))
    # input time quantum
    timeQuantum = int(input("Enter time quantum : "))

    # input arrival & burst time for each process
    arrivalTime = input("Enter Arrival Time for each process : ")
    arrivalTime = [int(x) for x in arrivalTime.split()]
    burstTime = input("Enter Burst Time for each process : ")
    burstTime = [int(x) for x in burstTime.split()]
    for i in range(n):
        process.append(Process(i + 1, arrivalTime[i], burstTime[i]))

    # display the process table
    print("Entered processes :\nProcess ID\tArrival Time\tBurst Time")
    for p in process:
        print("   ", p.id, "\t\t   ", p.arrivalTime, "\t\t   ", p.burstTime)

    roundRobin(n, timeQuantum, process)  # function call for the algorithm


main()  # main function call
