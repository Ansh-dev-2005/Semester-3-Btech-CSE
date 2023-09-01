#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key, int *count)
{
    int i;
    for (i = 0; i < n; i++)
    {
        (*count)++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int random(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int n, i, count = 0, key, index;

    printf("Enter number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:");
    for (i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    // Measure time taken for linear search
    clock_t start_time = clock(); // Record start time

    index = linearSearch(arr, n, key, &count);

    clock_t end_time = clock(); // Record end time
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", index);
    }

    printf("Number of iterations: %d\n", count);
    printf("Time taken: %f seconds\n", time_taken);
}
