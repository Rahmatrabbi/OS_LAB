#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void printBar(int length, char symbol) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
}

void printGanttChart(const vector<Process>& processes, int quantum) {
    int n = processes.size();
    int totalTime = 0;
    for (const Process& process : processes) {
        totalTime += process.burst_time;
    }

    cout << " ";
    printBar(totalTime, '-');
    cout << " " << endl;

    int currentTime = 0;
    while (currentTime < totalTime) {
        for (Process& process : processes) {
            if (process.burst_time > 0) {
                int executionTime = min(quantum, process.burst_time);
                printBar(executionTime, '-');
                cout << "P" << process.pid;
                printBar(executionTime, '-');

                process.burst_time -= executionTime;
                currentTime += executionTime;
            }
        }
    }

    cout << endl;
    cout << " ";
    printBar(totalTime, '-');
    cout << " " << endl;
}

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the burst time for each process:" << endl;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> processes[i].burst_time;
        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    cout << "Enter the time quantum: ";
    cin >> quantum;

    cout << "\nGantt Chart:" << endl;
    printGanttChart(processes, quantum);

    return 0;
}
