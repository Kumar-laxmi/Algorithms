from queue import Queue

def highest_response_ratio_next():
    pnum = int(input())
    at = list(map(int, input().split()))
    bt = list(map(int, input().split()))

    v = []
    ready_queue = Queue()
    process_queue = Queue()
    busin = {}
    completion = {}
    tat = {}
    wt = {}

    for i in range(pnum):
        v.append((i, (at[i], bt[i])))

    ct = 0
    listptr = 0

    while listptr < pnum or not process_queue.empty() or not ready_queue.empty():
        while listptr < pnum:
            next_process = v[listptr]
            nxt_arrival_time = next_process[1][0]
            new_process_arrival = (nxt_arrival_time == ct)

            if new_process_arrival:
                ready_queue.put(next_process)
                listptr += 1
            else:
                break

        if not process_queue.empty():
            exec_process = process_queue.queue[0]
            bt_value = exec_process[1][1]
            pid = exec_process[0]

            if busin[pid] + bt_value == ct:
                process_queue.get()
                completion[pid] = ct

        if process_queue.empty():
            mr = -1
            eval_process = None
            tmp_queue = Queue()

            while not ready_queue.empty():
                it = ready_queue.get()
                tmp_queue.put(it)
                atime, btime = it[1]
                wtime = ct - atime
                res = (wtime + btime) / float(btime)

                if res > mr:
                    mr = res
                    eval_process = it

            while not tmp_queue.empty():
                it = tmp_queue.get()
                if it == eval_process:
                    continue
                ready_queue.put(it)

            if mr > -1:
                pid = eval_process[0]
                process_queue.put(eval_process)
                busin[pid] = ct

        ct += 1

    print("The Process ids mapped with the completion times are:")
    for pid, ctime in completion.items():
        print(pid, ctime)

    avg_waiting, avg_tat = 0, 0

    for i in range(pnum):
        tat[i] = completion[i] - at[i]
        wt[i] = tat[i] - bt[i]
        avg_tat += tat[i]
        avg_waiting += wt[i]

    avg_tat /= float(pnum)
    avg_waiting /= float(pnum)

    print("Average TAT is", avg_tat, "units")
    print("Average WT is", avg_waiting, "units")


if __name__ == "__main__":
    highest_response_ratio_next()
