#include <stdio.h>

int main()
{
    FILE *file;
    char filename[100];
    char text[1000];

    // Prompt the user for the file name
    printf("Enter the name of the file to write: ");
    scanf("%s", filename);

    // Prompt the user to enter text to write to the file
    printf("Enter the text to write to the file:\n");
    scanf(" %[^\n]", text); // %[^\n] allows reading spaces

    // Open the file for writing
    file = fopen(filename, "w");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Write the text to the file
    fprintf(file, "%s", text);

    // Close the file
    fclose(file);

    printf("Text written to the file successfully.\n");

    return 0;
}
