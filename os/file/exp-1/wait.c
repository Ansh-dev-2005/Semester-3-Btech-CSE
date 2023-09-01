#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
        sleep(3);
        exit(42);
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());

        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child process did not exit normally.\n");
        }
    }

    return 0;
}
