#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement insertion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to generate random data
void generateRandomData(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; // Adjust range as needed
    }
}

int main()
{
    int maxN = 100000; // Set the maximum 'n' value
    int step = 10000;  // Set the step size for increasing 'n'
    int arr[maxN];
    clock_t start, end;

    FILE *fp; // Declare file pointer
    fp = fopen("output.csv", "w"); // Open file for writing

    printf("n,Time\n"); // Print a header for CSV output
    fprintf(fp, "n,Time\n"); // Write header to file

    for (int n = 1000; n <= maxN; n += step)
    {
        generateRandomData(arr, n); // Generate random data for 'n' elements

        start = clock();
        insertionSort(arr, n);
        end = clock();

        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d,%lf\n", n, cpu_time_used); // Print 'n' and time
        fprintf(fp, "%d,%lf\n", n, cpu_time_used); // Write 'n' and time to file
    }

    fclose(fp); // Close file

    return 0;
}
