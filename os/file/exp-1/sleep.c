#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seconds;

    // Prompt the user to enter the number of seconds to sleep
    printf("Enter the number of seconds to sleep: ");
    scanf("%d", &seconds);

    if (seconds < 0)
    {
        printf("Invalid input. Please enter a non-negative number of seconds.\n");
        return 1;
    }

    // Build the sleep command and execute it
    char command[100];
    sprintf(command, "sleep %d", seconds);

    int result = system(command);

    if (result == -1)
    {
        printf("Command execution failed.\n");
    }
    else
    {
        printf("Slept for %d seconds.\n", seconds);
    }

    return 0;
}
