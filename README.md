# Assignment 1 — CPU Scheduling Algorithms 

This repository contains solutions to Assignment 1 on CPU Scheduling.

## Files

| File | Description |
|---|---|
| `Q1_FCFS.cpp` | First Come First Serve scheduling. Takes arrival + burst time; outputs Completion, Turnaround, Waiting time, and Average Waiting Time. |
| `Q2_SJF.cpp` | Non-Preemptive Shortest Job First scheduling. Takes Process ID + burst time; outputs execution order and average waiting time. |
| `Q3_Priority.cpp` | Non-Preemptive Priority Scheduling. Takes Process ID, burst time, priority (lower number = higher priority); outputs waiting and turnaround time. |
| `Q4_RoundRobin.cpp` | Round Robin scheduling. Takes number of processes, burst times, and a time quantum; outputs waiting and turnaround time. |
| `Q5_Comparison.cpp` | Runs the same set of processes through FCFS, SJF, and Priority Scheduling, compares their average waiting times, and reports the best-performing algorithm. |

## Assumptions

- For Q2, Q3, Q4, and Q5, the assignment statement doesn't ask for arrival times, so all processes are assumed to arrive at time 0 (a standard simplification for these scheduling exercises). Q1 is the only one that explicitly takes arrival time as input.
- Priority: **lower number = higher priority**, per the assignment.
- Round Robin uses a simple FIFO ready queue; a process is re-queued at the back if it hasn't finished after using one time quantum.

## Build & Run

Each file is a standalone C++17 program. Compile and run individually, e.g.:

```bash
g++ -std=c++17 -o Q1_FCFS Q1_FCFS.cpp
./Q1_FCFS
```

Repeat the same pattern (`g++ -std=c++17 -o <name> <name>.cpp && ./<name>`) for Q2–Q5.

## Sample Run (Q1 — FCFS)

Input: 3 processes
| Process | Arrival | Burst |
|---|---|---|
| 1 | 0 | 5 |
| 2 | 1 | 3 |
| 3 | 2 | 8 |

Output:
```
Process   Arrival   Burst     Completion  Turnaround  Waiting
1         0         5         5           5           0
2         1         3         8           7           4
3         2         8         16          14          6

Average Waiting Time    = 3.33
Average Turnaround Time = 8.67
```

All five programs were compiled and tested with sample input before submission.
