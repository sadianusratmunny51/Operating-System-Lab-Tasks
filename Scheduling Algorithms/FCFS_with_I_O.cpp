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
    bool in_io = false;
    int io_completion_time = -1;

    int start = -1;
    int finish = 0;
    int waiting = 0;
    int turnaround = 0;
    bool first_cpu_done = false;
    bool completed = false;
};

int32_t main(){
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
        cout << "Enter I/O Burst (0 if none): ";
        cin >> p[i].io;
        cout << "Enter Second CPU Burst (0 if none): ";
        cin >> p[i].cpu2;

        p[i].remaining1 = p[i].cpu1;
        p[i].remaining2 = p[i].cpu2;
    }

    queue<int> q;
    vector<int> gantt;
    int current_time = 0, completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; ++i)
            if (p[i].arrival == current_time)
                q.push(i);

        for (int i = 0; i < n; ++i) {
            if (p[i].in_io && current_time == p[i].io_completion_time) {
                p[i].in_io = false;
                q.push(i);
            }
        }

        if (!q.empty()) {
            int idx = q.front(); q.pop();
            if (!p[idx].first_cpu_done) {
                if (p[idx].start == -1)
                    p[idx].start = current_time;

                for (int t = 0; t < p[idx].remaining1; ++t) {
                    gantt.push_back(p[idx].pid);
                    current_time++;

                    for (int i = 0; i < n; ++i) {
                        if (p[i].arrival == current_time)
                            q.push(i);
                        if (p[i].in_io && p[i].io_completion_time == current_time) {
                            p[i].in_io = false;
                            q.push(i);
                        }
                    }
                }

                p[idx].remaining1 = 0;
                p[idx].first_cpu_done = true;

                if (p[idx].io > 0) {
                    p[idx].in_io = true;
                    p[idx].io_completion_time = current_time + p[idx].io;
                } else {
                    q.push(idx);
                }

            } else if (!p[idx].completed) {
                for (int t = 0; t < p[idx].remaining2; ++t) {
                    gantt.push_back(p[idx].pid);
                    current_time++;

                    for (int i = 0; i < n; ++i) {
                        if (p[i].arrival == current_time)
                            q.push(i);
                        if (p[i].in_io && p[i].io_completion_time == current_time) {
                            p[i].in_io = false;
                            q.push(i);
                        }
                    }
                }

                p[idx].remaining2 = 0;
                p[idx].completed = true;
                p[idx].finish = current_time;
                p[idx].turnaround = p[idx].finish - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - (p[idx].cpu1 + p[idx].cpu2);
                completed++;
            }

        }
        else {
            gantt.push_back(-1);
            current_time++;
        }
    }

    cout << "\nPID\tArrival\tStart\tFinish\tWaiting\tTurnaround\n";
    for (auto& proc : p) {
        cout << "P" << proc.pid << "\t" << proc.arrival << "\t"
             << proc.start << "\t" << proc.finish << "\t"
             << proc.waiting << "\t" << proc.turnaround << "\n";
    }

    cout << "\nGantt Chart (Time: PID):\n";
    for (int i = 0; i < gantt.size(); ++i) {
        if (gantt[i] == -1)
            cout << i+1 << ": idle\n";
        else
            cout << i+1 << ": P" << gantt[i] << "\n";
    }

    return 0;
}
