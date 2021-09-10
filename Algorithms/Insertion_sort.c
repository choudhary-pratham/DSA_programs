#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Insertion_sort(int arr[], int n) // Best Case - O(n); Worst Case - O(n^2);
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // for n - 1 passes  if we have n elements.
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("\nValue after %d Pass\n", i);
        print_array(arr, n);
    }
    printf("\nSorted Array :\n");
    print_array(arr, n);
}

int main()
{
    int n;
    printf("Enter the number of elements you want to enter in the array: \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element :", i + 1);
        scanf("%d", &arr[i]);
    }
    Insertion_sort(arr, n);
    return 0;
}