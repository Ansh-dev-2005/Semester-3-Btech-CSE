#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to perform Quicksort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to measure execution time
double measure_time(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);

    // Generate random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    clock_t start_time = clock();
    quicksort(arr, 0, n - 1);
    clock_t end_time = clock();

    free(arr);

    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(NULL));

    int n_values[] = {10000, 50000, 100000, 250000, 350000};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("n\tTime (seconds)\n");
    for (int i = 0; i < num_values; i++)
    {
        int n = n_values[i];
        double execution_time = measure_time(n);
        printf("%d\t%.6f\n", n, execution_time);
    }

    return 0;
}
