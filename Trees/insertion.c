// Program to insert an element in an array

#include <stdio.h>
#include <stdlib.h>

void insertion(int arr[], int *n, int element, int pos)
{
    for (int i = (*n) - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    (*n)++;
}

void print_array(int arr[], int n)
{
    printf("The elements inside the modified array are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int t_size, new_element, new_pos, max_size;

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

    printf("Enter the new element you want to enter in this array:");
    scanf("%d", &new_element);

    printf("Enter the position where you want your new element to be inserted:");
    scanf("%d", &new_pos);
    if(new_pos>max_size)
    {
        printf("size limit exceeded");
        exit(0);
    }
    insertion(ptr, &t_size, new_element, new_pos);
    print_array(ptr, t_size);
    return 0;
}