//First Come First Serve(FCFS):

//Criteria for FCFS: Arrival Time
//Mode: Non-premptive->Once the processor starts its execution, it must finish it before executing the other. It can’t be paused in the middle.
//Turn Around Time(TAT)=Completion time - Arrival time;
//Waiting time(WT)=Turn Around Time - Burst Time;
//Average TAT=(Total TAT)/(No. of process);
//Average WT=(Total WT)/(No. of process);


import java.util.*;
public class FCFS_Java {
    public static void main(String[] args) {
        Process[] p=new Process[100];
        float avgwt=0;
        float avgtat=0;
        //int[] tat=new int[20];
        //int[] wt=new int[20];
        Scanner input=new Scanner(System.in);
        System.out.println("Enter number of processes:");
        int n=input.nextInt();
        for(int i=0;i<n;i++)
        {
            System.out.println("enter details of process id,arrival time ,burst time");
            p[i]=new Process(input.nextInt(),input.nextInt(),input.nextInt());
           // System.out.println(p[i].ct);
        }



        p[0].tat = p[0].bt;
            for (int i = 1; i < n; i++) {
                p[i].wt = p[i - 1].wt + p[i - 1].bt-p[i].at+p[i-1].at;
                if(p[i].wt<0)
                {
                    p[i].wt=0;
                }
                p[i].tat = p[i].wt + p[i].bt;
            }
        for (int i = 0; i < n; i++) {
            avgwt += p[i].wt;
            avgtat += p[i].tat;
        }
        System.out.println("\npid  AT  BT  CT TAT WT");
        for(int  i = 0 ; i< n;  i++)
        {
            System.out.println(p[i].process_id + "  \t " + p[i].at + "\t" + p[i].bt + "\t" + p[i].ct + "\t" + p[i].tat + "\t"  + p[i].wt ) ;
        }
        System.out.println();

        System.out.println("\nGANTT CHART\n");
        for (int i = 0; i < n; i++) {
            System.out.printf("  P[%d] ", p[i].process_id);
        }
        System.out.println();
        System.out.print("0"); // starting time of process:0
        for (int i = 0; i < n; i++) {
            //for (int j = 0; j < p[i].bt; j++)
                System.out.print(" ");
            if (p[i].tat > 9) {//not a universal threshold for TAT,for formatting Gantt chart in display
                System.out.print("\b");
            }
            System.out.printf("-> %d ", p[i].tat);
        }
        //System.out.println(avgtat);
        System.out.print("\naverage waiting time:"+ (avgwt/n));     // printing average waiting time.

        System.out.print("\naverage turnaround time:"+(avgtat/n));



    }
}
 class Process{
    int process_id;
    int at;
    int bt;
    int ct;
    int tat=0;
    int wt=0;

    Process(int pid,int at,int bt){
        this.process_id=pid;
        this.at=at;
        this.bt=bt;
        this.ct=at+bt;
    }


}