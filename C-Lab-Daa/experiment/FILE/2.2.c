#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid; 
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
    return -1; 
}

int main()
{
    srand(time(NULL)); 

        int n=250000;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
        arr[i] = rand() + 1;
        };
        printf("Array elements:\n");
        for (int i = 0; i < n; i++)
        {
        printf("%d ", arr[i]);
        }
        printf("\n");

        clock_t startBinary = clock();
        printf("Enter the number");
        int target;
        scanf("%d", &target);
        int binaryIndex = binarySearch(arr, n, target);
        clock_t endBinary = clock();
        double timeTakenBinary = ((double)(endBinary - startBinary)) / CLOCKS_PER_SEC;

        printf("For n = %d:\n", n);
        printf("Binary Search:\n");
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
