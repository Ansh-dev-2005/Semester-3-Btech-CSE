#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    // Create a new process
    child_pid = fork();

    if (child_pid < 0)
    {
        // Error occurred
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    if (child_pid == 0)
    {
        // This code is executed by the child process
        printf("Child Process: PID = %d\n", getpid());
    }
    else
    {
        // This code is executed by the parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    }

    return 0;
}
