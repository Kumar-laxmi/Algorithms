import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class priority_scheduling {
    static class PriorityScheduling {
        public String name;
        public int completionTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime;
        public int priority;
    }

    static class PriorityComparator implements Comparator<PriorityScheduling> {
        private int curr;

        public PriorityComparator(int curr) {
            this.curr = curr;
        }

        @Override
        public int compare(PriorityScheduling o1, PriorityScheduling o2) {
            if (curr >= o2.arrivalTime && curr >= o1.arrivalTime) {
                return Integer.compare(o1.priority, o2.priority);
            }
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Number of Processes: ");
        int n = scanner.nextInt();

        List<PriorityScheduling> process = new ArrayList<>();

        System.out.print("Enter Name of Processes: ");
        for (int i = 0; i < n; i++) {
            PriorityScheduling ps = new PriorityScheduling();
            ps.name = scanner.next();
            process.add(ps);
        }
        System.out.print("Enter Arrival Time of Processes: ");
        for (int i = 0; i < n; i++) {
            process.get(i).arrivalTime = scanner.nextInt();
        }
        System.out.print("Enter Priority of Processes: ");
        for (int i = 0; i < n; i++) {
            process.get(i).priority = scanner.nextInt();
        }
        System.out.print("Enter Burst Time of Processes: ");
        for (int i = 0; i < n; i++) {
            process.get(i).burstTime = scanner.nextInt();
        }

        int curr = 0;
        double avgTurnAroundTime = 0, avgWaitingTime = 0, avgResponseTime = 0;

        for (int i = 0; i < n; i++) {
            Collections.sort(process, new PriorityComparator(curr));

            process.get(i).responseTime = curr - process.get(i).arrivalTime;
            process.get(i).completionTime = curr + process.get(i).burstTime;

            curr = process.get(i).completionTime;

            process.get(i).turnAroundTime = process.get(i).completionTime - process.get(i).arrivalTime;
            process.get(i).waitingTime = process.get(i).turnAroundTime - process.get(i).burstTime;

            avgTurnAroundTime += process.get(i).turnAroundTime;
            avgWaitingTime += process.get(i).waitingTime;
            avgResponseTime += process.get(i).responseTime;
        }

        System.out.println("    AT\tP\tBT\tCT\tTAT\tWT\tRT");
        for (int i = 0; i < n; i++) {
            PriorityScheduling ps = process.get(i);
            System.out.printf("%s:  %d\t%d\t%d\t%d\t%d\t%d\t%d\n", ps.name, ps.arrivalTime, ps.priority, ps.burstTime,
                    ps.completionTime, ps.turnAroundTime, ps.waitingTime, ps.responseTime);
        }

        System.out.println();
        System.out.printf("Average TurnAroundTime: %.2f\n", avgTurnAroundTime / n);
        System.out.printf("Average WaitingTime: %.2f\n", avgWaitingTime / n);
        System.out.printf("Average ResponseTime: %.2f\n", avgResponseTime / n);

        System.out.println();
        System.out.println("Gantt Chart");
        System.out.print(process.get(0).arrivalTime + "  |" + process.get(0).name + "|  ");
        for (int i = 0; i < n - 1; i++) {
            System.out.print(process.get(i).completionTime + "  |" + process.get(i + 1).name + "|  ");
        }
        System.out.print(process.get(n - 1).completionTime);
        System.out.println();
    }
}
