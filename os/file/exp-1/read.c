#include <stdio.h>

int main()
{
    FILE *file;
    char filename[100];
    char ch;

    // Prompt the user for the file name
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read and print the contents of the file character by character
    printf("Contents of the file:\n");
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
