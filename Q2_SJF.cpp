// Q2. Non-Preemptive Shortest Job First (SJF) Scheduling
// All processes are assumed to arrive at time 0.
// Displays execution order and average waiting time.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID for process " << i + 1 << ": ";
        cin >> p[i].id;
        cout << "Enter burst time for process " << p[i].id << ": ";
        cin >> p[i].burstTime;
    }

    // Non-preemptive SJF (all arrive at time 0): sort by burst time ascending
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.burstTime < b.burstTime;
    });

    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    cout << "\nExecution Order: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id;
        if (i != n - 1) cout << " -> ";

        p[i].waitingTime = currentTime;
        currentTime += p[i].burstTime;
        p[i].completionTime = currentTime;
        p[i].turnaroundTime = p[i].completionTime; // arrival time = 0

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;
    }
    cout << "\n\n";

    cout << left
         << setw(10) << "Process"
         << setw(10) << "Burst"
         << setw(12) << "Completion"
         << setw(12) << "Turnaround"
         << setw(10) << "Waiting" << "\n";

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << p[i].id
             << setw(10) << p[i].burstTime
             << setw(12) << p[i].completionTime
             << setw(12) << p[i].turnaroundTime
             << setw(10) << p[i].waitingTime << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time    = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
