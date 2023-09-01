#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t target_pid;
    int seconds;

    // Prompt the user to enter the PID of the process to pause and resume
    printf("Enter the PID of the process to pause and resume: ");
    scanf("%d", &target_pid);

    // Prompt the user to enter the number of seconds to pause the process
    printf("Enter the number of seconds to pause the process: ");
    scanf("%d", &seconds);

    if (seconds < 0)
    {
        printf("Invalid input. Please enter a non-negative number of seconds.\n");
        return 1;
    }

    // Pause the process with SIGSTOP
    if (kill(target_pid, SIGSTOP) == -1)
    {
        perror("Failed to pause the process");
        return 1;
    }

    printf("Process with PID %d paused for %d seconds...\n", target_pid, seconds);
    sleep(seconds); // Sleep for the specified duration

    // Resume the process with SIGCONT
    if (kill(target_pid, SIGCONT) == -1)
    {
        perror("Failed to resume the process");
        return 1;
    }

    printf("Process with PID %d resumed.\n", target_pid);

    return 0;
}
