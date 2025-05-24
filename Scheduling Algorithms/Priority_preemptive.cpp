#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int start = -1;
    int finish = 0;
    int waiting = 0;
    int turnaround = 0;
    bool completed = false;
};

int32_t main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time for Process " << p[i].pid << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
        cout << "Enter Priority for Process " << p[i].pid << ": ";
        cin >> p[i].priority;
    }

    int current_time = 0, completed = 0;
    double total_waiting = 0, total_turnaround = 0;
    vector<int> timeline;

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= current_time && !p[i].completed) {
                if (p[i].priority < highest_priority || 
                    (p[i].priority == highest_priority && (idx == -1 || p[i].arrival < p[idx].arrival))) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (p[idx].start == -1)
                p[idx].start = current_time;

            p[idx].remaining--;
            timeline.push_back(p[idx].pid);

            if (p[idx].remaining == 0) {
                p[idx].completed = true;
                p[idx].finish = current_time + 1;
                p[idx].turnaround = p[idx].finish - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                total_turnaround += p[idx].turnaround;
                total_waiting += p[idx].waiting;
                completed++;
            }
        } else {
            timeline.push_back(-1);
        }

        current_time++;
    }

    cout << "\nPreemptive Priority Scheduling:\n";
    cout << "PID\tArrival\tBurst\tPriority\tStart\tFinish\tWaiting\tTurnaround\n";
    for (const auto& proc : p) {
        cout << "P" << proc.pid << "\t"
             << proc.arrival << "\t"
             << proc.burst << "\t"
             << proc.priority << "\t\t"
             << proc.start << "\t"
             << proc.finish << "\t"
             << proc.waiting << "\t"
             << proc.turnaround << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";

    cout << "\nGantt Chart (Time: PID):\n";
    for (int i = 0; i < timeline.size(); ++i) {
        if (timeline[i] == -1)
            cout << i+1 << ": idle\n";
        else
            cout << i + 1 << ": P" << timeline[i] << "\n";
    }

    return 0;
}
