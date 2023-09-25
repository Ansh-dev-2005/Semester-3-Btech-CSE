/* The input will be in the format given below- First line tells the number of
resources (here- 3). Second line tells the number of instances of each resource (here10, 5 and 7). Third line tells the number of processes (here- 5). The subsequent
lines contain the allocation array and the max need array for each process. So, here
as the number of resources are 3, for each process, first three numbers represent the
allocated resources (here- 0 1 0) and the next three numbers denote the max need
of that process (here- 7 5 3).*/
/*Using Banker Algo*/

/*Example Input :
3
10 5 7
5
0 1 0 7 5 3
2 0 0 3 2 2
3 0 2 9 0 2
2 1 1 2 2 2
0 0 2 4 3 3
Output : The output will be the execution sequence of processes so that the deadlock
does not occur.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num_resources, num_processes;

    scanf("%d", &num_resources);

    int max_res[num_resources];
    for (int i = 0; i < num_resources; i++)
    {
        scanf("%d", &max_res[i]);
    }

    scanf("%d", &num_processes);

    int allocation[num_processes][num_resources];
    int max_need[num_processes][num_resources];

    // Input the maximum need and allocation arrays for each process
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &max_need[i][j]);
        }
    }
    // make sum of allocation array
    int sum_alloc[num_resources];
    for (int i = 0; i < num_resources; i++)
    {
        sum_alloc[i] = 0;
        for (int j = 0; j < num_processes; j++)
        {
            sum_alloc[i] += allocation[j][i];
        }
    }
    // subtract sum of allocation array from max_res array
    for (int i = 0; i < num_resources; i++)
    {
        max_res[i] -= sum_alloc[i];
    }

    

    bool finished[num_processes];
    for (int i = 0; i < num_processes; i++)
    {
        finished[i] = false;
    }

    int safe_sequence[num_processes];
    int work[num_resources];
    for (int i = 0; i < num_resources; i++)
    {
        work[i] = max_res[i];
    }

    int count = 0;
    while (count < num_processes)
    {
        bool found = false;
        for (int i = 0; i < num_processes; i++)
        {
            if (!finished[i])
            {
                bool can_allocate = true;
                for (int j = 0; j < num_resources; j++)
                {
                    if (max_need[i][j] - allocation[i][j] > work[j])
                    {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate)
                {
                    for (int j = 0; j < num_resources; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count] = i;
                    finished[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (!found)
        {
            printf("Deadlock detected!\n");
            return 0;
        }
    }

    printf("Safe Sequence: <");
    for (int i = 0; i < num_processes; i++)
    {
        printf("P%d", safe_sequence[i]);
        if (i < num_processes - 1)
        {
            printf(", ");
        }
    }
    printf(">\n");

    return 0;
}
