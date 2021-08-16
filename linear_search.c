// Program to search for a given element in an array using linear search technique(iterative).

#include<stdio.h>
#include<stdlib.h>
void linear_search(int arr[],int n, int element)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            printf("Element found at position %d",i);
            exit(0);
        }
    }
    printf("Element not found");
}
int main()
{
    int t_size, element, max_size;

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
    linear_search(ptr,t_size,element);
    return 0;
}