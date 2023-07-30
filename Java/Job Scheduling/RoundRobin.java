import java.util.Scanner;

public class RoundRobin {

  static int numProcess, timeQuantum; // for storing no. of processes, input elements, and time quantum for each process

  static class Process {

    int id; // process id
    int arrivalTime; // point of time when process arrives
    int burstTime; // time required to complete the process

    Process(int id, int arrivalTime, int burstTime) {
      this.id = id;
      this.arrivalTime = arrivalTime;
      this.burstTime = burstTime;
    }
  }

  static void roundRobinAlgo(Process[] process) {
    int n = numProcess; // for remaining processes to schedule
    int time = 0;

    // loop to schedule until all processes are scheduled
    while (n > 0) {
      boolean executed = false; // flag to track if any process has executed in the current iteration

      // loop through the processes
      for (int i = 0; i < numProcess; ++i) {
        // if current process' burst time is greater than 0 and it has arrived
        if (process[i].burstTime > 0 && process[i].arrivalTime <= time) {
          executed = true;

          // If the remaining burst time is less than or equal to the time quantum
          if (process[i].burstTime <= timeQuantum) {
            System.out.println(
              "\nProcess " +
              process[i].id +
              " starts at : " +
              time +
              " & ends at : " +
              (time + process[i].burstTime)
            );
            time += process[i].burstTime;
            process[i].burstTime = 0; // Mark the process as completed
            --n; // decrement the number of processes remaining
          } else {
            System.out.println(
              "\nProcess " +
              process[i].id +
              " starts at : " +
              time +
              " & runs for " +
              timeQuantum +
              " units"
            );
            process[i].burstTime -= timeQuantum;
            time += timeQuantum;
          }
        }
      }

      // If no process was executed in this iteration, increment the time to the next arrival time
      if (!executed) {
        int next_arrival = Integer.MAX_VALUE;
        for (int i = 0; i < numProcess; ++i) {
          if (
            process[i].burstTime > 0 &&
            process[i].arrivalTime > time &&
            process[i].arrivalTime < next_arrival
          ) next_arrival = process[i].arrivalTime;
        }

        if (next_arrival == Integer.MAX_VALUE) break;

        time = next_arrival;
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("\n\t=== ROUND ROBIN SCHEDULING ALGORITHM ===");

    // input no. of processes
    System.out.print("\nEnter No. of processes : ");
    numProcess = scanner.nextInt();

    // input the time quantum
    System.out.print("\nEnter Time quantum : ");
    timeQuantum = scanner.nextInt();

    Process[] process = new Process[numProcess]; // array of processes

    // input arrival time and burst time for each process
    for (int i = 0; i < numProcess; i++) {
      System.out.print("\nEnter Arrival Time for process " + (i + 1) + " : ");
      int arrivalTime = scanner.nextInt();
      System.out.print("Enter Burst Time for process " + (i + 1) + " : ");
      int burstTime = scanner.nextInt();
      process[i] = new Process(i + 1, arrivalTime, burstTime);
    }

    // display the process table
    System.out.println(
      "\nEntered processes :\nProcess ID\tArrival Time\tBurst Time"
    );
    for (int i = 0; i < numProcess; i++) System.out.println(
      "    " +
      process[i].id +
      "\t\t    " +
      process[i].arrivalTime +
      "\t\t    " +
      process[i].burstTime
    );

    roundRobinAlgo(process); // function call for the algorithm

    scanner.close();
  }
}
