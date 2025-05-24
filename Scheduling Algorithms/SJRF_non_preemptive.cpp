#include <bits/stdc++.h>
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

int32_t  main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for Process P" << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time for Process P" << p[i].pid << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int completed = 0, current_time = 0;
    vector<int> timeline;
    double total_waiting = 0, total_turnaround = 0;

    while (completed != n) {
        int idx = -1;
        int shortest = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= current_time && !p[i].completed && p[i].burst < shortest) {
                shortest = p[i].burst;
                idx = i;
            }
        }

        if (idx != -1) {
            for (int t = 0; t < p[idx].burst; ++t) {
                timeline.push_back(p[idx].pid);
                current_time++;
            }

            p[idx].completed = true;
            p[idx].finish = current_time;
            p[idx].turnaround = p[idx].finish - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_waiting += p[idx].waiting;
            total_turnaround += p[idx].turnaround;
            completed++;
        } 
        else {
          
            timeline.push_back(-1);
            current_time++;
        }
    }

    cout << "\nNon-Preemptive SJF Scheduling:\n";
    cout << "PID\tArrival\tBurst\tFinish\tWaiting\tTurnaround\n";
    for (auto& proc : p) {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t"
             << proc.burst << "\t" << proc.finish << "\t"
             << proc.waiting << "\t" << proc.turnaround << "\n";
    }

    cout << "\nAverage Waiting Time: " << total_waiting / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";


    cout << "\nGantt Chart (Time: PID):\n";
    for (int i = 0; i < timeline.size(); ++i) {
        if (timeline[i] == -1)
            cout << i+1 << ": idle\n";
        else
            cout << i+1 << ": P" << timeline[i] << "\n";
    }

    return 0;
}
