// Program to search for a given element in an array using binary search technique(recursive).

#include <stdio.h>
#include <stdlib.h>
void binary_search_recursion(int arr[], int n, int element, int low, int high)
{
    int mid = (high + low) / 2;
    if (low >= high)
    {
        printf("Element not found");
        exit(0);
    }
    if (arr[mid] == element)
    {
        printf("Element found at position %d", mid);
        exit(0);
    }
    else if (arr[mid] > element)
    {
        binary_search_recursion(arr,n, element, low,  mid - 1);
    }
    else if (arr[mid] < element)
    {
        binary_search_recursion(arr,n, element, mid + 1,  high);
    }
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
    binary_search_recursion(ptr, t_size, element, low, high);
    return 0;
}