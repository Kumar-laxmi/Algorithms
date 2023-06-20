def fcfs(processes):
    processes.sort(key=lambda x: x[1])

    total_turnaround_time = 0.0
    total_waiting_time = 0.0

    current_time = 0

    for pid, arrival_time, burst_time in processes:
        start_time = max(current_time, arrival_time)
        current_time = start_time + burst_time
        end_time = current_time

        turnaround_time = end_time - arrival_time
        waiting_time = turnaround_time - burst_time

        total_turnaround_time += turnaround_time
        total_waiting_time += waiting_time

        print(f"Process {pid}:")
        print(f"Arrival Time: {arrival_time}")
        print(f"Burst Time: {burst_time}")
        print(f"Start Time: {start_time}")
        print(f"End Time: {end_time}")
        print(f"Turnaround Time: {turnaround_time}")
        print(f"Waiting Time: {waiting_time}\n")

    avg_turnaround_time = total_turnaround_time / len(processes)
    avg_waiting_time = total_waiting_time / len(processes)

    print(f"Average Turnaround Time: {avg_turnaround_time}")
    print(f"Average Waiting Time: {avg_waiting_time}")

processes = [
    (1, 0, 10),
    (2, 3, 5),
    (3, 4, 8),
    (4, 7, 3),
    (5, 9, 6)
]

fcfs(processes)