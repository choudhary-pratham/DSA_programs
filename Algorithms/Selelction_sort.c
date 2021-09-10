#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Selection_sort(int arr[], int n) // Time Complexity - O(n^2);
{
    int index, value;
    for (int i = 0; i < n - 1; i++) // No of passes
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            Swap(&arr[index], &arr[i]);
        }
        printf("\nValue after %d Pass\n", i + 1);
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
    Selection_sort(arr, n);
    return 0;
}