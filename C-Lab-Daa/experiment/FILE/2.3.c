#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000; // Generating random numbers between 0 and 999
        }

        clock_t startMerge = clock();
        mergeSort(arr, 0, n - 1);
        clock_t endMerge = clock();
        double timeTakenMerge = ((double)(endMerge - startMerge)) / CLOCKS_PER_SEC;

        printf("For n = %d:\n", n);
        printf("Merge Sort:\n");
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nTime taken for Merge Sort: %lf seconds\n", timeTakenMerge);

        printf("\n-----------------\n");
    

    return 0;
}
