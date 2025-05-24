#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int finish;
    int waiting;
    int turnaround;
    bool completed = false;
};

int32_t main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time for Process " << p[i].pid << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int completed = 0, current_time = 0;
    int prev = -1;
    vector<int> timeline;
    double total_waiting = 0, total_turnaround = 0;

    while (completed != n) {
        int idx = -1;
        int min_remaining = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].completed && p[i].remaining < min_remaining && p[i].remaining > 0) {
                min_remaining = p[i].remaining;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            timeline.push_back(p[idx].pid);

            if (p[idx].remaining == 0) {
                p[idx].completed = true;
                completed++;
                p[idx].finish = current_time + 1;
                p[idx].turnaround = p[idx].finish - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_waiting += p[idx].waiting;
                total_turnaround += p[idx].turnaround;
            }
        } 
        else {
            timeline.push_back(-1);
        }

        current_time++;
    }

    cout << "\nSRTF Scheduling:\n";
    cout << "PID\tArrival\tBurst\tFinish\tWaiting\tTurnaround\n";
    for (auto& proc : p) {
        cout << proc.pid << "\t" << proc.arrival << "\t" << proc.burst << "\t"
             << proc.finish << "\t" << proc.waiting << "\t" << proc.turnaround << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << endl;

    cout << "\nGantt Chart (Time: PID):\n";
    for (int i = 0; i < timeline.size(); i++) {
        if(timeline[i] == -1)
            cout << i +1<< ": idle\n";
        else
            cout << i+1 << ": P" << timeline[i] << "\n";
    }

    return 0;
}
