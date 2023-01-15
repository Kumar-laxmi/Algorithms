import java.io.*;
import java.util.*;
// Driver class
// Java program for activity selection problem
// when input activities may not be sorted.
public class ActivitySelection{
    public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int n,i,j;
    System.out.println("Enter no. of activities");
    n=sc.nextInt();
    int start[]=new int[n];
    int finish[]=new int[n];
    System.out.println("Enter THE START and FINISH time for activities:");
    for(i=0;i<n;i++)
    { 
        start[i]=sc.nextInt();
        finish[i]=sc.nextInt();
    }
    //Sorting the activites according to finish time
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(finish[i]>finish[j])
            {
                int temp=finish[i];//Swapping finish time
                finish[i]=finish[j];
                finish[j]=temp;
                int temp1=start[i];//Swapping start time
                start[i]=start[j];
                start[j]=temp1;
            }  
        }
    }
    System.out.println("FINAL-EXECUTION-CHART");
    System.out.print("("+start[0]+" "+finish[0]+")");
    int x=0;
    for(i=1;i<n;i++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if(start[i]>=finish[x])
        {
            System.out.print("("+start[i]+" "+finish[i]+")");
            x=i;
        }
    }
  }
}
