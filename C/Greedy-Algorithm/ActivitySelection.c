//In this implementation user is required to enter the start and finish time already sorted according to finish time 
#include<stdio.h>
void printActivity(int start[],int finish[],int n){
    int i,j;
    printf("Following activities are selected :");
    i=0;//i reperesents the index of the activity 
    printf("(%d %d) ,",start[i],finish[i]);
    for(j=1;j<n;j++){
        // If this activity has start time greater than or equal to the finish time of previously selected
        // activity, then select it
        if(start[j]>=finish[i]){
            printf("(%d %d) ,",start[j],finish[j]);
            i=j;
        }
    }
} 
int main()
{
    int n;//n is the number of activities or processes
    printf("Enter the number of activities:\n");
    scanf("%d",&n);
    printf("Enter the start and end time :\n");
    int start[n],finish[n];//Input start time and end time
    for(int i=0;i<n;i++){
        scanf("%d",&start[i]);
        scanf("%d",&finish[i]);
    }
    printActivity(start,finish,n);
}