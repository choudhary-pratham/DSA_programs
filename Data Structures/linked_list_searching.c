#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linked_list_search(struct Node *head, int element)
{
    struct Node *ptr = head;
    int i=0;
    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            printf("Element is present at index : %d\n",i);
            exit(0);
        }
        i++;
        ptr = ptr->next;
    }
    printf("Element not present");
}

int main()
{
    int element;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));
    third = (struct Node *)malloc(sizeof(struct Node *));
    fourth = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 68;
    fourth->next = NULL;

    printf("Enter the element you are searching for in your given linked list: ");
    scanf("%d", &element);
    linked_list_search(head, element);
    return 0;
}