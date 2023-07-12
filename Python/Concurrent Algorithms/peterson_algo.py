import threading

# Shared variables
flag = [False, False]
turn = 0

# Process 0
def process0():
    while True:
        flag[0] = True
        turn = 1

        # Wait until Process 1 is not in its critical section or it's not its turn
        while flag[1] and turn == 1:
            pass

        # Critical section
        print("Process 0 is in its critical section.")

        # Exit critical section
        flag[0] = False

        # Remainder section
        print("Process 0 is in its remainder section.")

# Process 1
def process1():
    while True:
        flag[1] = True
        turn = 0

        # Wait until Process 0 is not in its critical section or it's not its turn
        while flag[0] and turn == 0:
            pass

        # Critical section
        print("Process 1 is in its critical section.")

        # Exit critical section
        flag[1] = False

        # Remainder section
        print("Process 1 is in its remainder section.")

# Create two threads for the two processes
thread0 = threading.Thread(target=process0)
thread1 = threading.Thread(target=process1)

# Start the threads
thread0.start()
thread1.start()

# Wait for the threads to finish (which will be never)
thread0.join()
thread1.join()
