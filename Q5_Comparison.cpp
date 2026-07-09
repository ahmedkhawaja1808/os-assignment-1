// Q5. Comparison of Scheduling Algorithms
// Runs the same set of processes using FCFS, SJF, and Priority Scheduling,
// then compares average waiting time and reports the best-performing algorithm.
// All processes are assumed to arrive at time 0 so the three algorithms
// can be compared fairly on the same input (id, burst time, priority).

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
};

// Generic helper: given an order of process indices, compute average waiting time
double computeAverageWaiting(const vector<Process> &procs, const vector<int> &order) {
    int currentTime = 0;
    double totalWaiting = 0;

    for (int idx : order) {
        totalWaiting += currentTime;      // waiting time = time already elapsed
        currentTime += procs[idx].burstTime;
    }
    return totalWaiting / procs.size();
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time for process " << p[i].id << ": ";
        cin >> p[i].burstTime;
        cout << "Enter priority for process " << p[i].id << " (lower = higher priority): ";
        cin >> p[i].priority;
    }

    // ---- FCFS: original submission order ----
    vector<int> fcfsOrder(n);
    for (int i = 0; i < n; i++) fcfsOrder[i] = i;
    double fcfsAvgWaiting = computeAverageWaiting(p, fcfsOrder);

    // ---- SJF: order by burst time ascending ----
    vector<int> sjfOrder(n);
    for (int i = 0; i < n; i++) sjfOrder[i] = i;
    sort(sjfOrder.begin(), sjfOrder.end(), [&](int a, int b) {
        return p[a].burstTime < p[b].burstTime;
    });
    double sjfAvgWaiting = computeAverageWaiting(p, sjfOrder);

    // ---- Priority: order by priority ascending (lower number = higher priority) ----
    vector<int> prioOrder(n);
    for (int i = 0; i < n; i++) prioOrder[i] = i;
    sort(prioOrder.begin(), prioOrder.end(), [&](int a, int b) {
        return p[a].priority < p[b].priority;
    });
    double prioAvgWaiting = computeAverageWaiting(p, prioOrder);

    // ---- Display results ----
    cout << fixed << setprecision(2);
    cout << "\n" << left << setw(25) << "Algorithm" << "Average Waiting Time\n";
    cout << left << setw(25) << "FCFS"               << fcfsAvgWaiting  << "\n";
    cout << left << setw(25) << "SJF (Non-Preemptive)" << sjfAvgWaiting << "\n";
    cout << left << setw(25) << "Priority Scheduling" << prioAvgWaiting << "\n";

    // ---- Identify the best-performing algorithm (lowest average waiting time) ----
    string bestName = "FCFS";
    double bestValue = fcfsAvgWaiting;

    if (sjfAvgWaiting < bestValue) {
        bestValue = sjfAvgWaiting;
        bestName = "SJF (Non-Preemptive)";
    }
    if (prioAvgWaiting < bestValue) {
        bestValue = prioAvgWaiting;
        bestName = "Priority Scheduling";
    }

    cout << "\nBest-performing algorithm: " << bestName
         << " with average waiting time = " << bestValue << "\n";

    return 0;
}
