// perform linear search and find the time required to search an element
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL)); // Seed the random number generator

    // Generate random elements for the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000; // Generating random numbers between 0 and 999
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    clock_t start = clock();
    int index = linearSearch(arr, n, target);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index != -1)
    {
        printf("Element %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }

    printf("Time taken for linear search: %lf seconds\n", timeTaken);

    return 0;
}
