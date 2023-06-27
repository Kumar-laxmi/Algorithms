#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct priorityScheduling
{
    char name[20];
    int completionTime, arrivalTime, burstTime, turnAroundTime, responseTime, waitingTime, priority;
};

int curr = 0;
double avgTurnAroundTime = 0, avgwaitingTime = 0, avgresponseTime = 0;

void swap(struct priorityScheduling *process, int n)
{
    int position;
    struct priorityScheduling temp;
    for (int i = 0; i < n; i++)
    {
        position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (curr >= process[j].arrivalTime && curr >= process[position].arrivalTime && process[j].priority < process[position].priority)
            {
                position = j;
            }
        }
        temp = process[i];
        process[i] = process[position];
        process[position] = temp;
    }
}

int main()
{
    printf("Enter Number of Processes: ");
    int n;
    scanf("%d", &n);
    fflush(stdin);

    struct priorityScheduling *process = malloc(n * sizeof(struct priorityScheduling));

    printf("Enter Names of Processes: ");
    for (int i = 0; i < n; i++)
    {
        fgets(process[i].name, sizeof(process[i].name), stdin);
        process[i].name[strcspn(process[i].name, "\n")] = '\0';
    }
    printf("Enter Arrival Times of Processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i].arrivalTime);
    }
    printf("Enter Priority of Processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i].priority);
    }
    printf("Enter Burst Times of Processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &process[i].burstTime);
    }

    for (int i = 0; i < n; i++)
    {
        swap(process, n);

        process[i].responseTime = curr - process[i].arrivalTime;
        process[i].completionTime = curr + process[i].burstTime;

        curr = process[i].completionTime;

        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;

        avgTurnAroundTime += process[i].turnAroundTime;
        avgresponseTime += process[i].responseTime;
        avgwaitingTime += process[i].waitingTime;
    }

    printf("    AT\tP\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s:  %d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i].name, process[i].arrivalTime, process[i].priority, process[i].burstTime, process[i].completionTime, process[i].turnAroundTime, process[i].waitingTime, process[i].responseTime);
    }

    printf("\n");
    printf("Average TurnAroundTime: %.2f\n", avgTurnAroundTime / n);
    printf("Average WaitingTime: %.2f\n", avgwaitingTime / n);
    printf("Average ResponseTime: %.2f\n", avgresponseTime / n);

    printf("\n");
    printf("Gantt Chart\n");
    printf("%d  |%s|  ", process[0].arrivalTime, process[0].name);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d  |%s|  ", process[i].completionTime, process[i + 1].name);
    }
    printf("%d\n", process[n - 1].completionTime);

    free(process);
    return 0;
}
