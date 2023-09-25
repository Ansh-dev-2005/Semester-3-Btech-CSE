#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// include gnuplot_i.h
#include "gnuplot_i.h"

// Linear search function
int divideAndConquerLinearSearch(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid; // Element found
    }

    int leftResult = divideAndConquerLinearSearch(arr, left, mid - 1, target);
    int rightResult = divideAndConquerLinearSearch(arr, mid + 1, right, target);

    if (leftResult != -1)
    {
        return leftResult; // Element found in the left subarray
    }
    else if (rightResult != -1)
    {
        return rightResult; // Element found in the right subarray
    }
    else
    {
        return -1; // Element not found
    }
}

int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid; // Return the index if the element is found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the element is not found
}

int main()
{
    // Define the size of the array
    int n = 100000;

    // Create a dynamic array of size n
    int *arr = (int *)malloc(n * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random values
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand(); // Generates a random integer
    }

    // Create a data file to store the array values
    FILE *dataFile = fopen("array_data.txt", "w");
    if (dataFile == NULL)
    {
        printf("Error opening data file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(dataFile, "%d\n", arr[i]);
    }

    fclose(dataFile);

    // Initialize arrays to store execution times
    double linearSearchTimes[n];
    double binarySearchTimes[n];

    for (int i = 0; i < n; i++)
    {
        // Measure the execution time of divide-and-conquer linear search
        clock_t start = clock();
        int target = arr[i];
        int result = divideAndConquerLinearSearch(arr, 0, n - 1, target);
        clock_t end = clock();
        linearSearchTimes[i] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Measure the execution time of binary search
        clock_t startBinary = clock();
        int resultBinary = binarySearch(arr, n - 1, target);
        clock_t endBinary = clock();
        binarySearchTimes[i] = ((double)(endBinary - startBinary)) / CLOCKS_PER_SEC;
    }

    // Plot the execution times
    gnuplot_ctrl *h;
    h = gnuplot_init();
    gnuplot_setstyle(h, "lines");

    // Plot linear search times
    gnuplot_cmd(h, "plot '-' with lines title 'Linear Search'");
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot_get_handle(), "%d %f\n", i, linearSearchTimes[i]);
    }
    gnuplot_close(h);

    // Plot binary search times
    h = gnuplot_init();
    gnuplot_setstyle(h, "lines");
    gnuplot_cmd(h, "plot '-' with lines title 'Binary Search'");
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot_get_handle(), "%d %f\n", i, binarySearchTimes[i]);
    }
    gnuplot_close(h);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}