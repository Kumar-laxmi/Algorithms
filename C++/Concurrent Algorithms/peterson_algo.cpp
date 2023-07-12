#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

// Shared variables
atomic<bool> flag[2];
atomic<int> turn;

// Process 0
void process0()
{
    while (true) {
        turn = 1;

        // Wait until Process 1 is not in its critical section or it's not its turn
        while (flag[1] && turn == 1) {}

        // Critical section
        cout << "Process 0 is in its critical section." << endl;

        // Exit critical section
        flag[0] = false;

        // Remainder section
        cout << "Process 0 is in its remainder section." << endl;
    }
}

// Process 1
void process1()
{
    while (true) {
        flag[1] = true;
        turn = 0;

        // Wait until Process 0 is not in its critical section or it's not its turn
        while (flag[0] && turn == 0) {}

        // Critical section
        cout << "Process 1 is in its critical section." << endl;

        // Exit critical section
        flag[1] = false;

        // Remainder section
        cout << "Process 1 is in its remainder section." << endl;
    }
}

int main()
{
    // Initialize shared variables
    flag[0] = false;
    flag[1] = false;
    turn = 0;

    // Create two threads for the two processes
    thread thread0(process0);
    thread thread1(process1);

    // Wait for the threads to finish (which will be never)
    thread0.join();
    thread1.join();

    return 0;
}
