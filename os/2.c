#include <stdio.h>
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int priority_time;
    int completion_time;
    int turnaround_time;
    int response_time;
    int waiting_time;
};

int main()
{
    int num_process;
    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    struct process p[num_process], temp;

    for (int i = 0; i < num_process; i++)
    {
        printf("Enter the Process ID, Arrival Time, Burst Time, and Priority Time of process %d: ", i + 1);
        scanf("%d %d %d %d", &p[i].process_id, &p[i].arrival_time, &p[i].burst_time, &p[i].priority_time);
    }

    int current = 0;
    int completed_time = 0;
    int shortest_burst = -1;

    while (completed_time < num_process)
    {
        int shortest_index = -1;

        for (int i = 0; i < num_process; i++)
        {
            if (p[i].arrival_time <= current && p[i].burst_time > 0 && (shortest_index == -1 || p[i].burst_time < shortest_burst))
            {
                shortest_index = i;
                shortest_burst = p[i].burst_time;
            }
        }

        if (shortest_index == -1)
        {
            current++;
        }
        else
        {
            p[shortest_index].response_time = current - p[shortest_index].arrival_time;
            p[shortest_index].completion_time = current + p[shortest_index].burst_time;
            p[shortest_index].turnaround_time = p[shortest_index].completion_time - p[shortest_index].arrival_time;
            p[shortest_index].waiting_time = p[shortest_index].turnaround_time - p[shortest_index].burst_time;

            current = p[shortest_index].completion_time;
            p[shortest_index].burst_time = 0;
            completed_time++;
        }
    }

    printf("\nOutput: \n");
    for (int i = 0; i < num_process; i++)
    {
        printf("%d %d %d %d\n", p[i].completion_time, p[i].turnaround_time, p[i].response_time, p[i].waiting_time);
    }

    printf("\nGantt Chart:\n");
    for (int i = 0; i < num_process; i++)
    {
        printf("| P%d  ", p[i].process_id);
    }
    printf("|\n");
    printf("0");
    current = 0;
    for (int i = 0; i < num_process; i++)
    {
        while (current < p[i].completion_time)
        {
            printf(" ");
            current++;
        }
        printf("%d", p[i].completion_time);
    }
    printf("\n");

    return 0;
}