class peterson_algo {

    // Shared variables
    volatile boolean[] flag = new boolean[2];
    volatile int turn;

    // Process 0
    class Process0 extends Thread {
        public void run() {
            while (true) {
                flag[0] = true;
                turn = 1;

                // Wait until Process 1 is not in its critical section or it's not its turn
                while (flag[1] && turn == 1) {
                    // Busy wait
                }

                // Critical section
                System.out.println("Process 0 is in its critical section.");

                // Exit critical section
                flag[0] = false;

                // Remainder section
                System.out.println("Process 0 is in its remainder section.");
            }
        }
    }

    // Process 1
    class Process1 extends Thread {
        public void run() {
            while (true) {
                flag[1] = true;
                turn = 0;

                // Wait until Process 0 is not in its critical section or it's not its turn
                while (flag[0] && turn == 0) {
                    // Busy wait
                }

                // Critical section
                System.out.println("Process 1 is in its critical section.");

                // Exit critical section
                flag[1] = false;

                // Remainder section
                System.out.println("Process 1 is in its remainder section.");
            }
        }
    }

    public static void main(String[] args) {
        PetersonSolution solution = new PetersonSolution();

        // Create two threads for the two processes
        Process0 process0 = solution.new Process0();
        Process1 process1 = solution.new Process1();

        // Start the threads
        process0.start();
        process1.start();
    }
}
