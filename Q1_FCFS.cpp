// Q1. FCFS (First Come First Serve) Scheduling
// Calculates Completion Time, Turnaround Time, Waiting Time, and Average Waiting Time.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
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
        p[i].id = i + 1;
        cout << "Enter arrival time of process " << p[i].id << ": ";
        cin >> p[i].arrivalTime;
        cout << "Enter burst time of process " << p[i].id << ": ";
        cin >> p[i].burstTime;
    }

    // FCFS: sort by arrival time (ties broken by original order/id)
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        if (a.arrivalTime != b.arrivalTime)
            return a.arrivalTime < b.arrivalTime;
        return a.id < b.id;
    });

    int currentTime = 0;
    double totalWaiting = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime)
            currentTime = p[i].arrivalTime;

        currentTime += p[i].burstTime;
        p[i].completionTime = currentTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;
    }

    cout << "\n" << left
         << setw(10) << "Process"
         << setw(10) << "Arrival"
         << setw(10) << "Burst"
         << setw(12) << "Completion"
         << setw(12) << "Turnaround"
         << setw(10) << "Waiting" << "\n";

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << p[i].id
             << setw(10) << p[i].arrivalTime
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
