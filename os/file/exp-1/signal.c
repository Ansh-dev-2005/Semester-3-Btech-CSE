#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void custom_signal_handler(int signum)
{
    printf("Signal %d received.\n", signum);
}

int main()
{
    pid_t target_pid;

    signal(10, custom_signal_handler); // Use 10 for SIGUSR1

    printf("Enter the PID of the process to send a custom signal: ");
    scanf("%d", &target_pid);

    if (kill(target_pid, 10) == -1)
    { // Use 10 for SIGUSR1
        perror("Failed to send the custom signal");
        return 1;
    }

    printf("Custom signal sent to process with PID %d.\n", target_pid);

    return 0;
}
