//JOB SEQUENCING IN JAVA USING GREEDY APPROACH

import java.util.*;

class Job_Sequencing {

    // Declaring variables
    int n; // Size of the array/ No of jobs
    String a[]; // String array to store job numbers
    int b[]; // Integer array to store the profit associated with each job
    int c[]; // Integer array to store the deadline associated with each job

    // Input function to take input from user
    void input() {
        Scanner sc = new Scanner(System.in);
        //taking user input
        System.out.println("Enter number of jobs: ");
        n = sc.nextInt();
        a = new String[n];
        b = new int[n];
        c = new int[n];
        System.out.println("Enter Job No, Profit and Deadline of the job");
        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        sc.close();

        System.out.println("Arranged Order of Jobs: ");
        System.out.print("Jobs:     ");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();

        System.out.print("Profit:    ");
        for (int i = 0; i < n; i++) {
            System.out.print(b[i] + " ");
        }
        System.out.println();

        System.out.print("Deadline:   ");
        for (int i = 0; i < n; i++) {
            System.out.print(c[i] + " ");
        }
        System.out.println();
    }

    // Arranging jobs in descending order if not sorted
    void sort() {
        int temp;
        String temp1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (b[i] < b[j]) {
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;

                    temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;

                    temp1 = a[i];
                    a[i] = a[j];
                    a[j] = temp1;
                }
            }
        }

        //printing the arranged jobs in descending order

        System.out.println();
        System.out.println("Sorted Order of Jobs: ");
        System.out.print("Jobs:     ");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();

        System.out.print("Profit:    ");
        for (int i = 0; i < n; i++) {
            System.out.print(b[i] + " ");
        }
        System.out.println();

        System.out.print("Deadline:  ");
        for (int i = 0; i < n; i++) {
            System.out.print(c[i] + " ");
        }
        System.out.println();
    }

    //Function to schedule the jobs and find maximum profit
    void job_sequencing() {
        int max = c[0];
        for (int i = 0; i < n; i++) {
            if (c[i] > max) {
                max = c[i];  // storing the maximum deadline
            }
        }

        String a1[] = new String[max]; //Store the jobs that can yeild highest profit
        //int b1[] = new int[max];
        int profit = 0;

        //finding a free time slot
        for (int i = 0; i < n; i++) {
            int p = c[i];
            p = p - 1;
            if (a1[p] == null) {
                a1[p] = a[i];
                profit += b[i];  //If a slot is found, mark that slot with the job ID, and add its profit to the answer
            } 
            
             //else go to next job and calculate profit
            else {
                while (p != -1) {
                    if (a1[p] == null) {
                        a1[p] = a[i];
                        profit += b[i];
                        break;
                    }
                    p -= 1;
                }
            }
        }

        for (int i = 0; i < max; i++) {
            System.out.print("    " + a1[i]);
        }
        System.out.println();
        System.out.print("Profit Earned " + profit);  // Printing the maximised profit
    }

    //driver code
    public static void main(String args[]) {
        Job_Sequencing ob = new Job_Sequencing();
        ob.input();
        ob.sort();
        ob.job_sequencing();
    }
}
