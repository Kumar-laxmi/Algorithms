#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main() {
int n,weight[10],profit[10],W,i;  

printf ("Enter the number of items(n): ");
scanf ("%d", &n);
printf ("Enter the capacity of the Knapsack(m): ");
scanf ("%d", &W);

printf ("Enter the Weights of items: \n");
for (i = 0; i < n; i++)
{
printf ("Weight of item %d = ", i + 1);
scanf ("%d", &weight[i]);
}
printf ("\nEnter the Profit Values of items: \n");
for (i = 0; i < n; i++)
{
printf ("Profit of item %d = ", i + 1);
scanf ("%d", &profit[i]);
}

    int cur_w;
    float tot_v;
    int maxi;
    int used[10];
 
    for (i = 0; i < n; ++i){
        used[i] = 0;
    }
 
    cur_w = W;
    while (cur_w > 0) { 
        
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)profit[i]/weight[i] > (float)profit[maxi]/weight[maxi])))
                maxi = i;
 
        used[maxi] = 1; 
        cur_w -= weight[maxi]; 
        tot_v += profit[maxi];
        if (cur_w >= 0)
            printf("Added item %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, profit[maxi], weight[maxi], cur_w);
        else {
            printf("Added %d%% (%d$, %dKg) of item %d in the bag.\n", (int)((1 + (float)cur_w/weight[maxi]) * 100), profit[maxi], weight[maxi], maxi + 1);
            tot_v -= profit[maxi];
            tot_v += (1 + (float)cur_w/weight[maxi]) * profit[maxi];
        }
    }
 
    printf("Filled the bag with items worth %.2f$.\n", tot_v);
    getch();
}
