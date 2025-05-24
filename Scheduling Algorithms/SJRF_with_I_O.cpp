#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int cpu1;
    int io;
    int cpu2;
    int remaining1;
    int remaining2;
    int start = -1;
    int finish = 0;
    int waiting = 0;
    int turnaround = 0;
    bool in_io = false;
    int io_complete_time = -1;
    bool first_done = false;
    bool completed = false;
};

int32_t main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for P" << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter First CPU Burst: ";
        cin >> p[i].cpu1;
        cout << "Enter I/O Time: ";
        cin >> p[i].io;
        cout << "Enter Second CPU Burst: ";
        cin >> p[i].cpu2;

        p[i].remaining1 = p[i].cpu1;
        p[i].remaining2 = p[i].cpu2;
    }

    int current_time = 0;
    int completed = 0;
    vector<int> gantt;

    double total_waiting = 0, total_turnaround = 0;

    while (completed < n) {
        for (int i = 0; i < n; ++i) {
            if (p[i].in_io && p[i].io_complete_time == current_time) {
                p[i].in_io = false;
            }
        }

        int idx = -1;
        int min_remaining = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].arrival <= current_time && !p[i].completed && !p[i].in_io) {
                if (!p[i].first_done && p[i].remaining1 > 0 && p[i].remaining1 < min_remaining) {
                    min_remaining = p[i].remaining1;
                    idx = i;
                }
                if (p[i].first_done && p[i].remaining2 > 0 && p[i].remaining2 < min_remaining) {
                    min_remaining = p[i].remaining2;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (p[idx].start == -1) p[idx].start = current_time;
            gantt.push_back(p[idx].pid);
            if (!p[idx].first_done) {
                p[idx].remaining1--;

                if (p[idx].remaining1 == 0) {
                    p[idx].in_io = true;
                    p[idx].io_complete_time = current_time + p[idx].io;
                    p[idx].first_done = true;
                }
            }
            else {
                p[idx].remaining2--;
                if (p[idx].remaining2 == 0) {
                    p[idx].completed = true;
                    p[idx].finish = current_time + 1;
                    p[idx].turnaround = p[idx].finish - p[idx].arrival;
                    p[idx].waiting = p[idx].turnaround - (p[idx].cpu1 + p[idx].cpu2);
                    total_waiting += p[idx].waiting;
                    total_turnaround += p[idx].turnaround;
                    completed++;
                }
            }
        }
         else {
            gantt.push_back(-1);
        }
        current_time++;
    }

    cout << "\nSRTF Scheduling with I/O Burst:\n";
    cout << left << setw(5) << "PID" << setw(10) << "Arrival" << setw(10)
         << "Start" << setw(10) << "Finish" << setw(12) << "Waiting" << setw(15)
         << "Turnaround" << "\n";

    for (auto& proc : p) {
        cout << left << setw(5) << proc.pid << setw(10) << proc.arrival
             << setw(10) << proc.start << setw(10) << proc.finish
             << setw(12) << proc.waiting << setw(15) << proc.turnaround << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_waiting / n;
    cout << "\nAverage Turnaround Time: " << total_turnaround / n << "\n";

    cout << "\nGantt Chart (time : PID):\n";
    for (int i = 0; i < gantt.size(); ++i) {
        if (gantt[i] == -1)
            cout << i +1<< ": idle\n";
        else
            cout << i+1 << ": P" << gantt[i] << "\n";
    }

    return 0;
}
