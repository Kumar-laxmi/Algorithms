// ====================== Problem Statement ==========================
/*
There are n jobs with some deadline {d1,d2,...dn} where di>=0. 
Each job i has profit {p1,p2,...pn} where pi>=0.
If the job ji is completed within its deadline, then  only its proft is added.
Our task is to achieve maximum total profit and also find the optimal sequence of job execution.

For example, consider the following jobs:
   J1  J2  J3  J4 J5
P  20  15  10  5  1
D  2   2   1   3  3

{J2,J1,J4} is the optimal sequence for executing the jobs and total maximum profit is 40.  
Solution-

The greedy approach is often used to solve this problem 
step 1: Arrange jobs in descending order of their profit
step2: One by one  take a job and check if a slot is available before the deadline. If it is then
 allocate the last slot available and add the job's profit to the total profit and 
 add that job at that slot in the schedule
array, otherwise, the job is not scheduled.
*/

// // ====================== Code with C ==========================


#include<stdio.h>
#include<stdlib.h>

// Item structure to store job no, deadinee and profit for each job.
typedef struct job{
	int no;
	int deadline;
	int profit;
}job;

// function that return the index of the job with max profit among all unchecked jobs
int  maxprofitjob(job *jobs,int *checked, int n){
        int maxi=-1;
           for(int i=0; i<n; i++ ){
            if(checked[i]==0 && (maxi==-1 || jobs[i].profit>jobs[maxi].profit)){
                maxi=i;
            }
           }
           return maxi;
}

int main(){
	int n;
	int t,i, maxprofit=0;
	
    //take input
	printf("Enter no. of jobs: ");
	scanf("%d", &n);
    //array of jobs
	job *jobs = (job*)malloc(n*sizeof(job));
    int *checked = (int*)malloc(n*sizeof(int));

	printf("Enter deadline and profit of each job:\n");
	for(int i=0; i<n; i++){
		scanf("%d", &jobs[i].deadline);
        scanf("%d", &jobs[i].profit);
		jobs[i].no= i+1;
	}

    for(int i=0; i<n; i++){
         checked[i]=0;
    }
    //find maximum deadline among the given deadlines
	int maxdeadline = jobs[0].deadline;
	for(int i=1; i<n; i++){
		if(maxdeadline<jobs[i].deadline){
			maxdeadline = jobs[i].deadline;
		}
	}

    //create slot array to keep the alloted slot of job for execution(create schedule)
    int *slots = (int*)malloc(sizeof(int)*maxdeadline);
    for(int i=0 ; i<maxdeadline; i++){
		slots[i]=0;
	}
    
    printf("Maximum Profit at the end of each iteration-\n");
    i=1;
    while(i<=n){

        int maxi = maxprofitjob(jobs,checked, n);
        checked[maxi]=1;
        
        //find a free slot starting from the last of the job's deadline to the beginning of timeline
        t=jobs[maxi].deadline-1;
        while(t>=0 && slots[t]){
			t--;
		}
        //if a free slot is found add the job to the slot array at t index and add the job's profit
        //to the maximum(total) profit 
        //else the job is not added to the schedule and its profit is not added. 
		if(t>=0 && !slots[t]){
			slots[t]= jobs[maxi].no;
			maxprofit+=jobs[maxi].profit;
		}
        //print the total profit so far
		printf("%d\n", maxprofit);

        i++;

    }
    printf("Total Profit= %d\n",maxprofit);
    //print the computed schedule(sequence in which job has to be done)
	printf("The optimal sequence\n");
	for(int i=0 ; i<maxdeadline; i++){
		if(slots[i]){
			printf(" %d ", slots[i]);
		}
	}

	return 0;
}
