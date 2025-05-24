#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int start = -1;
    int finish = 0;
    int waiting = 0;
    int turnaround = 0;
    bool in_queue = false;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    vector<Process> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for Process " << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time for Process " << p[i].pid << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    queue<int> q;
    vector<int> timeline;
    int current_time = 0, completed = 0;
    double total_waiting = 0, total_turnaround = 0;

    while (completed < n) {
        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= current_time && p[i].remaining > 0 && !p[i].in_queue) {
                q.push(i);
                p[i].in_queue = true;
            }
        }

        if (!q.empty()) {
            int idx = q.front(); q.pop();

            if (p[idx].start == -1)
                p[idx].start = current_time;

            int exec_time = min(quantum, p[idx].remaining);
            for (int i = 0; i < exec_time; ++i)
                timeline.push_back(p[idx].pid);

            current_time += exec_time;
            p[idx].remaining -= exec_time;

            for (int i = 0; i < n; ++i) {
                if (p[i].arrival > current_time - exec_time &&
                    p[i].arrival <= current_time &&
                    p[i].remaining > 0 && !p[i].in_queue) {
                    q.push(i);
                    p[i].in_queue = true;
                }
            }

            if (p[idx].remaining > 0) {
                q.push(idx);
            } else {
                p[idx].finish = current_time;
                p[idx].turnaround = p[idx].finish - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                total_turnaround += p[idx].turnaround;
                total_waiting += p[idx].waiting;
                completed++;
            }
        } 
        else {
            timeline.push_back(-1);
            current_time++;
        }
    }

    cout << "\nRound Robin Scheduling (Preemptive):\n";
    cout << "PID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    for (const auto& proc : p) {
        cout << "P" << proc.pid << "\t"
             << proc.arrival << "\t"
             << proc.burst << "\t"
             << proc.start << "\t"
             << proc.finish << "\t"
             << proc.waiting << "\t"
             << proc.turnaround << "\n";
    }

    cout << fixed << setprecision(2);
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