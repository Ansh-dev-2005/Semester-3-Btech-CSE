#include <stdio.h>
#include <string.h>

// Function to perform brute force string matching
int bruteForceStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i; // Pattern found at index i in the text
        }
    }
    return -1; // Pattern not found
}

int main()
{
    char text[1000], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text); // Read up to 999 characters until newline

    printf("Enter the pattern: ");
    scanf("%99s", pattern); // Read up to 99 characters as a string

    int position = bruteForceStringMatch(text, pattern);

    if (position != -1)
    {
        printf("Pattern found at position: %d\n", position);
    }
    else
    {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
