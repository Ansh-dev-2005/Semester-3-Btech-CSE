#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
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

    // Bubble Sort
    int arrBubble[n];
    for (int i = 0; i < n; i++)
    {
        arrBubble[i] = arr[i];
    }
    clock_t startBubble = clock();
    bubbleSort(arrBubble, n);
    clock_t endBubble = clock();
    double timeTakenBubble = ((double)(endBubble - startBubble)) / CLOCKS_PER_SEC;

    // Selection Sort
    int arrSelection[n];
    for (int i = 0; i < n; i++)
    {
        arrSelection[i] = arr[i];
    }
    clock_t startSelection = clock();
    selectionSort(arrSelection, n);
    clock_t endSelection = clock();
    double timeTakenSelection = ((double)(endSelection - startSelection)) / CLOCKS_PER_SEC;

    printf("Sorted array using Bubble Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arrBubble[i]);
    }
    printf("\nTime taken by Bubble Sort: %lf seconds\n", timeTakenBubble);

    // printf("\nSorted array using Selection Sort:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arrSelection[i]);
    // }
    // printf("\nTime taken by Selection Sort: %lf seconds\n", timeTakenSelection);

    return 0;
}
