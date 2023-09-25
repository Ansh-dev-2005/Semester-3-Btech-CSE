#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex; // semaphore variable

/**
 * This function is called by child processes to acquire and release the lock.
 * @param i The index of the child process.
 */
void childP(int i, int pid)
{
    sem_wait(&mutex); // acquire the lock
    printf("\nLock acquired.");
    printf("PID: %d, Child: %d\n", pid, i);
    sem_post(&mutex); // release the lock
    printf("Lock released");
}

/**
 * The main function initializes the semaphore, creates child processes, and waits for them to finish.
 */
int main()
{
    sem_init(&mutex, 0, 1); // initialize the semaphore
    int a;
    printf("Enter number of child processes:");
    scanf("%d", &a);
    pid_t pid;
    for (int i = 1; i <= a; i++)
    {
        pid = fork(); // create child process
        if (pid < 0)
        {
            printf("Creation of child process failed.\n");
        }
        else if (pid == 0)
        {
            childP(i,getpid()); // call child function
            exit(0);
        }
        else
        {
            wait(NULL); // wait for child process to finish
        }
    }
    sem_destroy(&mutex); // destroy the semaphore
}
