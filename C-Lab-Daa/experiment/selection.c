// section sort
// create a function to generate random number
#include<stdio.h>




void Selectionsort( int arr[], int n, int *count)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        (*count)++;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(){

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
    Selectionsort(arr, n, &count);
    printf("\nAfter sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of iterations: %d\n", count);

    return 0;
}