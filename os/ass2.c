#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int responseTime;
    int waitingTime;
};

void swap(struct Process *xp, struct Process *yp)
{
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcesses(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime)
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void SRTF(struct Process processes[], int n)
{
    int currentTime = 0;
    int completedProcesses = 0;
    int currentProcessIndex = -1;

    while (completedProcesses < n)
    {
        int shortestRemainingTime = -1;
        int nextProcessIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0)
            {
                if (shortestRemainingTime == -1 || processes[i].remainingTime < shortestRemainingTime)
                {
                    shortestRemainingTime = processes[i].remainingTime;
                    nextProcessIndex = i;
                }
            }
        }

        if (nextProcessIndex != -1)
        {
            if (currentProcessIndex != nextProcessIndex)
            {
                processes[nextProcessIndex].responseTime = currentTime - processes[nextProcessIndex].arrivalTime;
            }
            processes[nextProcessIndex].remainingTime--;
            currentTime++;

            if (processes[nextProcessIndex].remainingTime == 0)
            {
                processes[nextProcessIndex].completionTime = currentTime;
                processes[nextProcessIndex].turnaroundTime = processes[nextProcessIndex].completionTime - processes[nextProcessIndex].arrivalTime;
                processes[nextProcessIndex].waitingTime = processes[nextProcessIndex].turnaroundTime - processes[nextProcessIndex].burstTime;
                completedProcesses++;
            }
            currentProcessIndex = nextProcessIndex;
        }
        else
        {
            currentTime++;
        }
    }

    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tResponse\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime,
               processes[i].responseTime, processes[i].waitingTime);
    }
}

void SJF(struct Process processes[], int n)
{
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n)
    {
        int shortestBurstTime = INT_MAX;
        int shortestBurstIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0)
            {
                if (processes[i].burstTime < shortestBurstTime)
                {
                    shortestBurstTime = processes[i].burstTime;
                    shortestBurstIndex = i;
                }
            }
        }

        if (shortestBurstIndex != -1)
        {
            processes[shortestBurstIndex].remainingTime--;
            currentTime++;

            if (processes[shortestBurstIndex].remainingTime == 0)
            {
                processes[shortestBurstIndex].completionTime = currentTime;
                processes[shortestBurstIndex].turnaroundTime = processes[shortestBurstIndex].completionTime - processes[shortestBurstIndex].arrivalTime;
                processes[shortestBurstIndex].waitingTime = processes[shortestBurstIndex].turnaroundTime - processes[shortestBurstIndex].burstTime;
                completedProcesses++;
            }
        }
        else
        {
            currentTime++;
        }
    }

    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tResponse\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].completionTime, processes[i].turnaroundTime,
               processes[i].responseTime, processes[i].waitingTime);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    printf("Enter process details (PID ArrivalTime BurstTime Priority):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].remainingTime = processes[i].burstTime;
    }

    sortProcesses(processes, n);

    printf("\n--- Shortest Remaining Time First (SRTF) ---\n");
    SRTF(processes, n);

    printf("\n--- Shortest Job First (SJF) ---\n");
    SJF(processes, n);

    return 0;
}
