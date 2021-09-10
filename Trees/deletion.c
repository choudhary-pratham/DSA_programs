// Program to delete an element in an array

#include <stdio.h>
#include <stdlib.h>
int check_pos(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
void deletion(int arr[], int *n, int pos)
{
    for (int i = pos+1 ; i< (*n); i++)
    {
        arr[i-1] = arr[i];
    }
    (*n)--;
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
    int t_size, element, pos, max_size;

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

    printf("Enter the element you want to delete in this array:");
    scanf("%d", &element);

    pos = check_pos(ptr, t_size, element);
    if (pos != -1)
    {
        deletion(ptr, &t_size, pos);
        print_array(ptr, t_size);
    }

    else
    {
        printf("Element not found!");
    }
    return 0;
}