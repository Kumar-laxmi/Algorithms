#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

// Shared variables
bool flag[2];
int turn;

// Process 0
void* process0(void* arg)
{
    while (true) {
        flag[0] = true;
        turn = 1;

        // Wait until Process 1 is not in its critical section or it's not its turn
        while (flag[1] && turn == 1) {}

        // Critical section
        printf("Process 0 is in its critical section.\n");

        // Exit critical section
        flag[0] = false;

        // Remainder section
        printf("Process 0 is in its remainder section.\n");
    }

    return NULL;
}

// Process 1
void* process1(void* arg)
{
    while (true) {
        flag[1] = true;
        turn = 0;

        // Wait until Process 0 is not in its critical section or it's not its turn
        while (flag[0] && turn == 0) {}

        // Critical section
        printf("Process 1 is in its critical section.\n");

        // Exit critical section
        flag[1] = false;

        // Remainder section
        printf("Process 1 is in its remainder section.\n");
    }

    return NULL;
}

int main()
{
    // Initialize shared variables
    flag[0] = false;
    flag[1] = false;
    turn = 0;

    // Create two threads for the two processes
    pthread_t thread0, thread1;
    pthread_create(&thread0, NULL, process0, NULL);
    pthread_create(&thread1, NULL, process1, NULL);

    // Wait for the threads to finish (which will be never)
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);

    return 0;
}
