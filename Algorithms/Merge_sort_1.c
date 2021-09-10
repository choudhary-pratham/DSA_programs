// To merge 2 sorted arrays in ascending order.

#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void Merge_sort(int arr1[], int arr2[], int n1, int n2) // Best Case - O(n); Worst Case - O(n^2);
{
    int *arr3, k = 0;
    arr3 = (int *)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0;

    while (k < n1 + n2)
    {
        if (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[k++] = arr1[i++];
            }
            else
            {
                arr3[k++] = arr2[j++];
            }
        }
        else if (i >= n1)
        {
            arr3[k++] = arr2[j++];
        }
        else if (j >= n2)
        {
            arr3[k++] = arr1[i++];
        }
    }
    printf("\nSorted Array :\n");
    print_array(arr3, k);
}
int main()
{
    int n1, n2;
    int *arr1;
    int *arr2;
    printf("Enter the number of elements you want to enter in the array1: \n");
    scanf("%d", &n1);
    printf("Enter the number of elements you want to enter in the array2: \n");
    scanf("%d", &n2);
    arr1 = (int *)malloc(n1 * sizeof(int));
    arr2 = (int *)malloc(n2 * sizeof(int));
    printf("Enter element of the sorted Array1 :");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter element of the sorted Array2 :");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    Merge_sort(arr1, arr2, n1, n2);
    return 0;
}

