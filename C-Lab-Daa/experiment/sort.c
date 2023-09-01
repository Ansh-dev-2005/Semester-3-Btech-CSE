#include <stdio.h>
void bubbleSort(int arr[], int a, int *count)
{
    int c, d, x;
    for (c = 0; c < a - 1; c++)
    {
        for (d = 0; d < a - c - 1; d++)
        {
            if (arr[d] > arr[d + 1])
            {
                x = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = x;
            }
        }
        (*count)++;
    }
}
int main()
{
    int n, i, count = 0;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, n, &count);
    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of iterations: %d\n", count);

    return 0;
}