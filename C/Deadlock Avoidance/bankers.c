/*
 Safety Algorithm:-
  This algorithm checks whether the system is in safe state or not.
    1.Let Work and Complete be vectors of length ‘m’ and ‘n’ respectively. Initialize: Work= Available Complete[i]=false; for i=1,2,……,n
    2 Find an i such that both a)  Complete[i]=false b) Need_i<=work if no such i exists then we will go to step(4)
    3.Work=Work + Allocation_i Complete[i]= true will go to step(2)
    4.If Finish[i]=true for all i, then the system is in safe state.
*/
#include<stdio.h>
void bank(int process,int res,int reNeed[100][100],int allocation[100][100],int available[100])
{
    
    //Safety
    int complete[100];
    for(int i=0;i<process;i++)
    {
        complete[i]=0;
    }
    for(int i=0;i<process;i++)
    {
        int flag=0;
        if(complete[i]==0)
        {
            for(int j=0;j<res;j++)
            {
                if(reNeed[i][j]>available[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                complete[i]=1;
                for(int j=0;j<res;j++)
                {
                    available[j]+=allocation[i][j];
                }
                i=-1;
            }
        }
    }
    int flag=0;
    for(int i=0;i<process;i++)
    {
        if(complete[i]==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("deadlock occured");
    }
    else
    {
        printf("No deadlock");
    }
}
void main()
{
    int res,process,i,j;
    printf("Enter total number of processes: ");
    scanf("%d",&process);
    printf("Enter total number of resources: ");
    scanf("%d",&res);
    int allocation[100][100],max[100][100],available[100],reNeed[100][100];
    
    for(i=0;i<process;i++)
    {
        printf("Enter allocation for processes: ");
        for(j=0;j<res;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
        printf("Enter maximum for processes: ");
        for(j=0;j<res;j++)
        {
            scanf("%d",&max[i][j]);
        }
        //Calculating reneed
        for(j=0;j<res;j++)
        {
            reNeed[i][j]=max[i][j]-allocation[i][j];
        }

    }
    printf("Enter available for processes: ");
    for(i=0;i<res;i++)
    {
        scanf("%d",&available[i]);
    }
    bank(process,res,reNeed,allocation,available);
}

