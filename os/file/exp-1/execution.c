#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command[100];

    // Prompt the user for a command
    printf("Enter a command to execute: ");
    fgets(command, sizeof(command), stdin);

    // Execute the command using system()
    int result = system(command);

    if (result == -1)
    {
        printf("Command execution failed.\n");
    }
    else
    {
        printf("Command executed successfully with return code: %d\n", result);
    }

    return 0;
}
