#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*  
   Time Complexity- 
    best case- O(nlogn)----when the middle of the array is a pivot.
    worst case-O(n^2)----when the middle is not a pivot .for n elements (n-1)
    times the partition needs to be done.
    average case-O(nlogn).    
*/
int partition(int arr[], int low, int high)
{
    int pivot, i, j;
    pivot = arr[low];
    i = low + 1;
    j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            Swap(&arr[i], &arr[j]);
        }
    } while (i < j);
    Swap(&arr[j], &arr[low]);
    return j;
}

void Quick_sort(int arr[], int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition(arr, low, high);
        Quick_sort(arr, low, partition_index - 1);
        Quick_sort(arr, partition_index + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements you want to enter in the array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter element in an array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Quick_sort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}