import java.util.*;
import java.util.LinkedList;

public class Highest_Response_Ratio_Next {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int pnum = scanner.nextInt();
        ArrayList<Integer> at = new ArrayList<>();
        ArrayList<Integer> bt = new ArrayList<>();

        for (int i = 0; i < pnum; i++) {
            at.add(scanner.nextInt());
        }

        for (int i = 0; i < pnum; i++) {
            bt.add(scanner.nextInt());
        }

        ArrayList<Pair<Integer, Pair<Integer, Integer>>> v = new ArrayList<>();
        Queue<Pair<Integer, Pair<Integer, Integer>>> readyQueue = new LinkedList<>();
        Queue<Pair<Integer, Pair<Integer, Integer>>> processQueue = new LinkedList<>();
        Map<Integer, Integer> busin = new HashMap<>();
        Map<Integer, Integer> tat = new HashMap<>();
        Map<Integer, Integer> wt = new HashMap<>();

        //ind->in bus

        for (int i = 0; i < pnum; i++) {
            v.add(new Pair<>(i, new Pair<>(at.get(i), bt.get(i))));
        }

        int ct = 0;
        int listptr = 0;
        Map<Integer, Integer> completion = new HashMap<>();

        while (listptr < pnum || !processQueue.isEmpty() || !readyQueue.isEmpty()) {
            while (listptr < pnum) {
                Pair<Integer, Pair<Integer, Integer>> nextProcess = v.get(listptr);
                int nxtArrivalTime = nextProcess.second.first;
                boolean newProcessArrival = (nxtArrivalTime == ct);

                if (newProcessArrival) {
                    readyQueue.add(nextProcess);
                    listptr++;
                } else {
                    break;
                }
            }

            if (!processQueue.isEmpty()) {
                Pair<Integer, Pair<Integer, Integer>> execProcess = processQueue.peek();
                int btValue = execProcess.second.second;
                int pid = execProcess.first;
                if (busin.get(pid) + btValue == ct) {
                    processQueue.poll();
                    completion.put(pid, ct);
                }
            }

            if (processQueue.isEmpty()) {
                float mr = -1;
                Pair<Integer, Pair<Integer, Integer>> evalProcess = null;
                Queue<Pair<Integer, Pair<Integer, Integer>>> tmpQueue = new LinkedList<>();

                while (!readyQueue.isEmpty()) {
                    Pair<Integer, Pair<Integer, Integer>> it = readyQueue.poll();
                    tmpQueue.add(it);
                    int atime = it.second.first;
                    int btime = it.second.second;
                    int wtime = ct - atime;
                    float res = (wtime + btime) / (float) btime;

                    if (res > mr) {
                        mr = res;
                        evalProcess = it;
                    }
                }

                while (!tmpQueue.isEmpty()) {
                    Pair<Integer, Pair<Integer, Integer>> it = tmpQueue.poll();
                    if (it.equals(evalProcess)) continue;
                    readyQueue.add(it);
                }

                if (mr > -1) {
                    int pid = evalProcess.first;
                    processQueue.add(evalProcess);
                    busin.put(pid, ct);
                }
            }

            ct++;
        }

        System.out.println("The Process ids: mapped with the completion times are:");
        for (Map.Entry<Integer, Integer> entry : completion.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        float avg_waiting, avg_tat;
        
        for(int i = 0;i<pnum;i++) {
            // tat[i] = completion[i] - at[i];
            tat.put(i, completion.get(i) - at.get(i));
        }

        for(int i = 0;i<pnum;i++) {
            // wt[i] = tat[i] - bt[i];
            wt.put(i, tat.get(i) - bt.get(i));
        }

        int waitSum = 0,tatSum = 0;

        for(int i = 0;i<pnum;i++) {
            waitSum += wt.get(i);
            tatSum += tat.get(i);
        }

        avg_tat = tatSum/((float)pnum);
        avg_waiting = waitSum/((float)pnum);

        System.out.println("Average TAT is " + avg_tat + " units");
        System.out.println("Average WT is " + avg_waiting + " units");

        scanner.close();
    }

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }
}
