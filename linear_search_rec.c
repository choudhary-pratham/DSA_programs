// Program to search for a given element in an array using linear search technique(recursive).

#include <stdio.h>
#include <stdlib.h>
int linear_search_recursion(int arr[], int n, int element)
{
    static int i = 0;
    if (i == n)
    {
        printf("Element not found");
        return 0;
    }
    else
    {
        if (arr[i] == element)
        {
            return i;
        }
        else
        {
            i++;
            linear_search_recursion(arr, n, element);
        }
    }
}
int main()
{
    int t_size, element, max_size, pos;

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
    pos = linear_search_recursion(ptr, t_size, element);
    if (pos)
    {
        printf("Element found at position %d", pos);
    }
    return 0;
}