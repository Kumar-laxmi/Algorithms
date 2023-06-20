import java.util.Arrays;
import java.util.Comparator;

// this is an implementation of first come first serve CPU Job Scheduling Algorithm in java
public class FCFS {
    static class Process {
        int pid;
        int arrival_time;
        int burst_time;
        int start_time;
        int end_time;
        int turnaround_time;
        int waiting_time;

        public Process(int pid, int arrival_time, int burst_time) {
            this.pid = pid;
            this.arrival_time = arrival_time;
            this.burst_time = burst_time;
        }
    }

    static class ProcessComparator implements Comparator<Process> {
        public int compare(Process p1, Process p2) {
            return Integer.compare(p1.arrival_time, p2.arrival_time);
        }
    }

    public static void fcfs(Process[] processes) {
        Arrays.sort(processes, new ProcessComparator());

        float total_turnaround_time = 0.0f;
        float total_waiting_time = 0.0f;

        int current_time = 0;

        for (Process process : processes) {
            process.start_time = Math.max(current_time, process.arrival_time);
            current_time = process.start_time + process.burst_time;
            process.end_time = current_time;

            process.turnaround_time = process.end_time - process.arrival_time;
            process.waiting_time = process.turnaround_time - process.burst_time;

            total_turnaround_time += process.turnaround_time;
            total_waiting_time += process.waiting_time;

            System.out.println("Process " + process.pid + ":");
            System.out.println("Arrival Time: " + process.arrival_time);
            System.out.println("Burst Time: " + process.burst_time);
            System.out.println("Start Time: " + process.start_time);
            System.out.println("End Time: " + process.end_time);
            System.out.println("Turnaround Time: " + process.turnaround_time);
            System.out.println("Waiting Time: " + process.waiting_time);
            System.out.println();
        }

        float avg_turnaround_time = total_turnaround_time / processes.length;
        float avg_waiting_time = total_waiting_time / processes.length;

        System.out.println("Average Turnaround Time: " + avg_turnaround_time);
        System.out.println("Average Waiting Time: " + avg_waiting_time);
    }

    public static void main(String[] args) {
        Process[] processes = {
                new Process(1, 0, 10),
                new Process(2, 3, 5),
                new Process(3, 4, 8),
                new Process(4, 7, 3),
                new Process(5, 9, 6)
        };

        fcfs(processes);
    }
}
