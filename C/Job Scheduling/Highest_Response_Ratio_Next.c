#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS_NUM 100

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
} Process;

typedef struct {
    Process data[MAX_PROCESS_NUM];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isQueueFull(Queue* queue) {
    return (queue->rear == MAX_PROCESS_NUM - 1);
}

void enqueue(Queue* queue, Process process) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isQueueEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear++;

    queue->data[queue->rear] = process;
}

Process dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        Process emptyProcess = { -1, -1, -1 };
        return emptyProcess;
    }

    Process process = queue->data[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    return process;
}

int main() {
    int pnum;
    scanf("%d", &pnum);

    // Taking in arrival and burst times
    Process processes[MAX_PROCESS_NUM];

    for (int i = 0; i < pnum; i++) {
        scanf("%d", &processes[i].arrival_time);
    }

    for (int i = 0; i < pnum; i++) {
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i;
    }

    // Maintaining a ready and a process queue
    Queue ready_queue, process_queue;
    initializeQueue(&ready_queue);
    initializeQueue(&process_queue);
    int busin[MAX_PROCESS_NUM] = { 0 }; // pid -> in bus

    for (int i = 0; i < pnum; i++) {
        enqueue(&ready_queue, processes[i]);
    }

    // Mapping the ct, tat, and wt to the pids
    int ct = 0;
    int listptr = 0;
    int completion[MAX_PROCESS_NUM] = { 0 };
    int tat[MAX_PROCESS_NUM] = { 0 };
    int wt[MAX_PROCESS_NUM] = { 0 };

    // Implementation
    while (listptr < pnum || !isQueueEmpty(&process_queue) || !isQueueEmpty(&ready_queue)) {
        while (listptr < pnum) {
            Process nextProcess = processes[listptr];
            int nxtArrivalTime = nextProcess.arrival_time;
            int nxtBurstTime = nextProcess.burst_time;
            int newProcessArrival = (nxtArrivalTime == ct);

            if (newProcessArrival) {
                enqueue(&ready_queue, nextProcess);
                listptr++;
            } else {
                break;
            }
        }

        if (!isQueueEmpty(&process_queue)) {
            Process execProcess = dequeue(&process_queue);
            int bt = execProcess.burst_time;
            int at = execProcess.arrival_time;
            int pid = execProcess.pid;
            if (busin[pid] + bt == ct) {
                completion[pid] = ct;
            } else {
                enqueue(&process_queue, execProcess);
            }
        }

        if (isQueueEmpty(&process_queue)) {
            float mr = -1;
            Process evalProcess;
            Queue tmp_queue;
            initializeQueue(&tmp_queue);

            while (!isQueueEmpty(&ready_queue)) {
                Process it = dequeue(&ready_queue);
                enqueue(&tmp_queue, it);
                int atime = it.arrival_time;
                int btime = it.burst_time;
                int wtime = ct - atime;
                float res = (wtime + btime) / (btime * 1.0);

                if (res > mr) {
                    mr = res;
                    evalProcess = it;
                }
            }

            while (!isQueueEmpty(&tmp_queue)) {
                Process it = dequeue(&tmp_queue);
                if (it.pid == evalProcess.pid) continue;
                enqueue(&ready_queue, it);
            }

            if (mr > -1) {
                enqueue(&process_queue, evalProcess);
                busin[evalProcess.pid] = ct;
            }
        }

        ct++;
    }

    printf("The Process ids mapped with the completion times are:\n");
    for (int i = 0; i < pnum; i++) {
        printf("%d %d\n", i, completion[i]);
    }

    float avg_waiting, avg_tat;

    for (int i = 0; i < pnum; i++) {
        tat[i] = completion[i] - processes[i].arrival_time;
    }

    for (int i = 0; i < pnum; i++) {
        wt[i] = tat[i] - processes[i].burst_time;
    }

    int waitSum = 0, tatSum = 0;

    for (int i = 0; i < pnum; i++) {
        waitSum += wt[i];
        tatSum += tat[i];
    }

    avg_tat = tatSum / ((float)pnum);
    avg_waiting = waitSum / ((float)pnum);

    printf("Average TAT is %.2f units\n", avg_tat);
    printf("Average WT is %.2f units\n", avg_waiting);

    return 0;
}
