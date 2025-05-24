#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid; 
    int arrival;
    int burst; 
    int start;
    int finish; 
    int turnaround; 
    int waiting; 
};

int32_t main() {
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    vector<Process>p(n);

    for(int i=0; i<n; i++){
        p[i].pid =i+1;
        cout<<"Enter Arrival Time for Process " << p[i].pid << ": ";
        cin>>p[i].arrival;
        cout << "Enter Burst Time for Process " << p[i].pid << ": ";
        cin >> p[i].burst;
    }

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int current_time = 0;
    for (int i = 0; i < n; ++i) {
        if (current_time < p[i].arrival)
            current_time = p[i].arrival;
 
        p[i].start = current_time;
        p[i].finish = p[i].start + p[i].burst;
        p[i].turnaround = p[i].finish - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        current_time = p[i].finish;
    }

    double total_waiting = 0, total_turnaround = 0;
    cout << "\nFCFS Scheduling:\n";
    cout << left << setw(10) << "PID" << setw(15) << "Arrival" << setw(15)
         << "Burst" << setw(15) << "Start" << setw(15) << "Finish"
         << setw(15) << "Waiting" << setw(15) << "Turnaround" << endl;

    for (auto& proc : p) {
        cout << left << setw(10) << proc.pid << setw(15) << proc.arrival
             << setw(15) << proc.burst << setw(15) << proc.start
             << setw(15) << proc.finish << setw(15) << proc.waiting
             << setw(15) << proc.turnaround << endl;

        total_waiting += proc.waiting;
        total_turnaround += proc.turnaround;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (total_waiting / n);
    cout << "\nAverage Turnaround Time: " << (total_turnaround / n) << endl;

    return 0;
}
