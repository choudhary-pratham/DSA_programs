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

void count_sort(int arr[], int n)
{
    //Fastest sorting technique with time complexity O(n)
    // Disadvantage - Consumes extra space.
    int max = arr[0], k = 0, i, j;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *ind_arr = (int *)malloc((max + 1) * sizeof(int));
    int *new_arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < (max + 1); i++)
    {
        ind_arr[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        ind_arr[arr[i]] += 1;
    }

    i = 0;

    while (i <= max)
    {
        if (ind_arr[i] > 0)
        {
            arr[k++] = i;
            ind_arr[i] -= 1;
        }
        else
        {
            i++;
        }
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
    count_sort(arr, n);
    printArray(arr, n);
    return 0;
}