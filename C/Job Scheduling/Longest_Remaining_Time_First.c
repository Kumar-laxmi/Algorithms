#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
	Author: Aman Goel
	email: amangoel998@gmail.com
*/
typedef struct Process{
	int Process_Id;
	int Initial_Burst;
	int Burst_Time;
	int Start_Time;
	int Finish_Time;
	bool Completed;
}Process;
typedef struct Gantt{
	int Process_Id;
	int Start_Time;
	int Finish_Time;
}Gantt;
Process Process_Queue[]={{2132,2,2,0,0,false},{2102,4,4,0,0,false},{2483,8,8,0,0,false}};
Gantt Gantt_Chart[15];
int Time_Value=0,i;
int Turnaround_Time[3],Waiting_Time[3],Avg_TT,Avg_WT;

void Display_Sequence();
int Display_Avg();

int main(){
	int count=0;
	Process *t,*pq;
	Gantt *g=Gantt_Chart;
	int startime=0;
	while(count<3){
		t=Process_Queue;
		pq=Process_Queue;
		for(i=0;i<2;i++){
			*pq++;
			if(!pq->Completed){
				if(pq->Burst_Time>t->Burst_Time)t=pq;
				else if(pq->Burst_Time==t->Burst_Time)
					if(pq->Process_Id<t->Process_Id)
						t=pq;
			}
		}
		t->Burst_Time-=1;
		g->Process_Id=t->Process_Id;
		g->Start_Time=Time_Value;
		g->Finish_Time=++Time_Value;
		if(t->Burst_Time<=0){
			t->Finish_Time=Time_Value;
			t->Completed=true;
			count++;
		}
		*g++;
	}
	t=Process_Queue;
	for(i=0;i<3;i++){
		printf("P%d finished at %d \n",t->Process_Id,t->Finish_Time);
		t++;
	}
	printf("\n");
	Display_Sequence();
	Display_Avg();
	return 0;
}
int Display_Avg(){
	int *Tt=Turnaround_Time,*Wt=Waiting_Time;
	Process *t=Process_Queue;
	for(i=0;i<3;i++){
		*(Tt+i)=t->Finish_Time-t->Burst_Time;
		*(Wt+i)=*(Tt+i)-(t->Initial_Burst);
		*t++;
	}
	for(i=0;i<3;i++){
		printf("TT: %d WT: %d\n",*(Tt+i),*(Wt+i));
		Avg_TT+=*(Tt+i);
		Avg_WT+=*(Wt+i);
	}
	printf("Avg TT: %d Avg WT: %d\n",Avg_TT/3,Avg_WT/3);
}
void Display_Sequence(){
	Gantt *g=Gantt_Chart;int i;
	for(i=0;i<Time_Value;i++){
		if(g->Start_Time>=9)printf("|P%d|   ",g->Process_Id);
		else printf("|P%d| ",g->Process_Id);
		*g++;
	}
	g=Gantt_Chart;
	printf("\n");
	for(i=0;i<Time_Value;i++){
		if(g->Start_Time>9)printf("%d    %d  ",g->Start_Time,g->Finish_Time);
		else printf("%d     %d ",g->Start_Time,g->Finish_Time);
		*g++;
	}
	printf("\n");
}