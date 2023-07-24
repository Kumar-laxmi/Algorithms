#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

static bool comp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b) {
    return a.second.first < b.second.first;
}

int main() {
    fast_io;
    
    int pnum;
    cin >> pnum;

    //taking in arrival and bus times
    vector<int> at(pnum),bt(pnum);

    for(int i = 0;i<pnum;i++) {
        cin >> at[i];
    }

    for(int i = 0;i<pnum;i++) {
        cin >> bt[i];
    }

    //maintaining a ready and a process queue
    vector<pair<int,pair<int,int>>> v;
    queue<pair<int,pair<int,int>>> ready_queue;
    queue<pair<int,pair<int,int>>> process_queue;
    map<int,int> busin;

    //ind->in bus

    for(int i = 0;i<pnum;i++) {
        v.push_back({i,{at[i],bt[i]}});
    }

    //mapping the ct,tat,and wt to the pids
    int ct = 0;
    int listptr = 0;
    map<int,int> completion,tat,wt;

    //implementation
    while(listptr < pnum || process_queue.size() || ready_queue.size()) {
        while(listptr < pnum) {
            auto nextProcess = v[listptr];
            int nxtArrivalTime = nextProcess.second.first;
            int nxtBurstTime = nextProcess.second.second;
            bool newProcessArrival = (nxtArrivalTime == ct);

            if(newProcessArrival) {
                ready_queue.push(nextProcess);
                listptr++;
            } else {
                break;
            }
        }
        
        if(process_queue.size()) {
            auto execProcess = process_queue.front();
            int bt = execProcess.second.second;
            int at = execProcess.second.first;
            int pid = execProcess.first;
            if(busin[pid] + bt == ct) {
                process_queue.pop();
                completion[pid] = ct;
            }
        }

        if(!process_queue.size()) {
            float mr = -1;
            pair<int,pair<int,int>> evalProcess;
            queue<pair<int,pair<int,int>>> tmp_queue;

            while(ready_queue.size()) {
                auto it = ready_queue.front();
                ready_queue.pop();
                tmp_queue.push(it);
                int atime = it.second.first;
                int btime = it.second.second;
                int wtime = ct - atime;
                float res = (wtime + btime)/(btime*1.0);

                if(res > mr) {
                    mr = res;
                    evalProcess = it;
                }
            }

            while(tmp_queue.size()) {
                auto it = tmp_queue.front();
                tmp_queue.pop();
                if(it == evalProcess) continue;
                ready_queue.push(it);
            }

            if(mr > -1) {
                process_queue.push(evalProcess);
                busin[evalProcess.first] = ct;
            }
        }

        ct++;
    }
     
    cout << "The Process ids: mapped with the completion times are:" << endl;
    for(auto it: completion) {
        cout << it.first << " " << it.second << endl;
    }

    float avg_waiting, avg_tat;
    
    for(int i = 0;i<pnum;i++) {
        tat[i] = completion[i] - at[i];
    }

    for(int i = 0;i<pnum;i++) {
        wt[i] = tat[i] - bt[i];
    }

    int waitSum = 0,tatSum = 0;

    for(int i = 0;i<pnum;i++) {
        waitSum += wt[i];
        tatSum += tat[i];
    }

    avg_tat = tatSum/((float)pnum);
    avg_waiting = waitSum/((float)pnum);

    cout << "Average TAT is" << " " << avg_tat << " units" << endl;
    cout << "Average WT is" << " " << avg_waiting << " units"  << endl;

    return 0;
}
