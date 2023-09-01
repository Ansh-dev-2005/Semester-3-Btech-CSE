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

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid; // Return the index if element is found
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
    return -1; // Return -1 if element is not found
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int n=500000;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1; // Initialize the array with sorted values
        }
        int target;
        printf("Enter the element to search: \n");
        scanf("%d", &target);

        // Linear Search
        clock_t startLinear = clock();
        int linearIndex = linearSearch(arr, n, target);
        clock_t endLinear = clock();
        double timeTakenLinear = ((double)(endLinear - startLinear)) / CLOCKS_PER_SEC;

        // Binary Search
        clock_t startBinary = clock();
        int binaryIndex = binarySearch(arr, n, target);
        clock_t endBinary = clock();
        double timeTakenBinary = ((double)(endBinary - startBinary)) / CLOCKS_PER_SEC;

        printf("For n = %d:\n", n);
        printf("Linear Search:\n");
        if (linearIndex != -1)
        {
            printf("Element %d found at index %d.\n", target, linearIndex);
        }
        else
        {
            printf("Element %d not found.\n", target);
        }
        printf("Time taken for linear search: %lf seconds\n", timeTakenLinear);

        printf("\nBinary Search:\n");
        if (binaryIndex != -1)
        {
            printf("Element %d found at index %d.\n", target, binaryIndex);
        }
        else
        {
            printf("Element %d not found.\n", target);
        }
        printf("Time taken for binary search: %lf seconds\n", timeTakenBinary);

        printf("\n-----------------\n");
   

    return 0;
}
