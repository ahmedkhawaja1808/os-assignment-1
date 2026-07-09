// Q4. Round Robin Scheduling
// All processes are assumed to arrive at time 0.
// Calculates waiting time and turnaround time using a time quantum.

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time for process " << p[i].id << ": ";
        cin >> p[i].burstTime;
        p[i].remainingTime = p[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    queue<int> q; // stores indices into p
    for (int i = 0; i < n; i++) q.push(i);

    int currentTime = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        int execTime = min(quantum, p[i].remainingTime);
        currentTime += execTime;
        p[i].remainingTime -= execTime;

        if (p[i].remainingTime > 0) {
            q.push(i);
        } else {
            p[i].completionTime = currentTime;
            p[i].turnaroundTime = p[i].completionTime; // arrival time = 0
            p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        }
    }

    double totalWaiting = 0, totalTurnaround = 0;

    cout << "\n" << left
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

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time    = " << totalWaiting / n << "\n";
    cout << "Average Turnaround Time = " << totalTurnaround / n << "\n";

    return 0;
}
