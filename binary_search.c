// Program to search for a given element in an array using binary search technique(iterative).

#include <stdio.h>
#include <stdlib.h>
void binary_search(int arr[], int n, int element, int low, int high)
{
    for (int i = 0; i < n; i++)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            printf("Element found at position %d", mid);
            exit(0);
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
    }
    printf("Element not found");
}
int main()
{
    int t_size, element, max_size, low, high;

    printf("Enter the maximum size of the array :");
    scanf("%d", &max_size);

    printf("Enter the size of the array :");
    scanf("%d", &t_size);

    int *ptr = (int *)malloc(max_size * sizeof(int));
    printf("Enter array:\n");

    for (int i = 0; i < t_size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("Enter the element you want to search for :");
    scanf("%d", &element);
    low = 0;
    high = t_size - 1;
    binary_search(ptr, t_size, element, low, high);
    return 0;
}