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

void Bubble_sort(int arr[], int n) // Best Case - O(n); Worst Case - O(n^2);
{
    int swap_count = 0;
    for (int i = 0; i < n -1 ; i++) // for n - 1 passes  if we have n elements.
    {
        for (int j = 0; j < n - 1 - i; j++) // for comparison in each pass.
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                swap_count++;
            }
        }
        if (swap_count == 0) // Bubble sort is not adaptive but can be made adaptive by checking 1st pass and
                             // and when we see that no swappings were made after 1st pass it can be well 
                             //infered that the array is already sorted hence we dont have to check for the condition
                             // again.Time complexity is O(n) if it is sorted and O(n^2) if it is not.It is 
                             // stable algorithm.
        {
            printf("\nArray Elements already sorted\n");
            print_array(arr, n);
            exit(0);
        }
        else
        {
            printf("\nValue after %d Pass\n",i+1);
            print_array(arr, n);
        }
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
    Bubble_sort(arr, n);
    return 0;
}